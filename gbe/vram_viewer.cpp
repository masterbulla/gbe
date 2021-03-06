#include <imgui.h>
#include <imgui_impl_sdl.h>
#include <SDL_opengl.h>
#include "base.h"
#include "defines.h"
#include "mmu.h"
#include "vram_viewer.h"

static string sRadioButtonsText[5] { "TData 1", "TData 2", "TMap 1", "TMap 2", "OAM" };
static u32 sPalette[4] = { 0xFF000000, 0xFF7F7F7F, 0xFF404040, 0xFFFFFFFF };

//--------------------------------------------
// --
//--------------------------------------------
VRAMViewer::VRAMViewer(const MMU &_mmu) : mMmu(_mmu)
{
}

//--------------------------------------------
// --
//--------------------------------------------
void VRAMViewer::Init()
{
    glGenTextures(1, &mTextureId);

    glBindTexture(GL_TEXTURE_2D, mTextureId);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}

//--------------------------------------------
// --
//--------------------------------------------
void VRAMViewer::Render()
{
    ImGui::SetNextWindowPos(ImVec2(560, 0));

    if (ImGui::Begin("VRAM", nullptr, ImVec2(464, 468), 1.0f, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings))
    {
        for (int i = 0; i < 5; ++i)
        {
            ImGui::SameLine();
            ImGui::RadioButton(sRadioButtonsText[i].c_str(), &mActiveVRam, i);
        }
        
        switch(mActiveVRam)
        {
            case 0:
            case 1:
                BuildTileData(mActiveVRam == 0 ? Memory::VRamTileData1StartAddr : Memory::VRamTileData2StartAddr);
                ImGui::Image((ImTextureID)mTextureId, ImVec2(384, 384), ImVec2(0.0f, 0.0f), ImVec2(0.5664f, 0.5664f));
                break;

            case 2:
            case 3:
            {
                ImVec2 screenPos = ImGui::GetCursorScreenPos();
                u16 tileData = (mMmu.ReadU8(0xFF40) & 1 << 4) != 0 ? Memory::VRamTileData1StartAddr : Memory::VRamTileData2StartAddr;

                BuildTileMap(mActiveVRam == 2 ? Memory::VRamTileMap1StartAddr : Memory::VRamTileMap2StartAddr, tileData);
                ImGui::Image((ImTextureID)mTextureId, ImVec2(256, 256), ImVec2(0, 0), ImVec2(1, 1), ImVec4(1, 1, 1, 1), ImVec4(0.2265f, 0.2265f, 0.4492f, 1.0f));

                // ...                
                float sx = screenPos.x + 1;
                float sy = screenPos.y + 1;
                float x = (float)((256 + mMmu.ReadU8(IOReg::SCX)) % 256);
                float y = (float)((256 + mMmu.ReadU8(IOReg::SCY)) % 256);
                float x2 = (float)(((int)x + Screen::Width) % 256);
                float y2 = (float)(((int)y + Screen::Height) % 256);

                if (x2 < x)
                {
                    ImGui::GetWindowDrawList()->AddLine(ImVec2(sx, sy + y), ImVec2(sx + x2, sy + y), ImColor(ImGui::GetStyle().Colors[ImGuiCol_ButtonActive]));
                    ImGui::GetWindowDrawList()->AddLine(ImVec2(sx + x, sy + y), ImVec2(sx + 256, sy + y), ImColor(ImGui::GetStyle().Colors[ImGuiCol_ButtonActive]));

                    ImGui::GetWindowDrawList()->AddLine(ImVec2(sx, sy + y2), ImVec2(sx + x2, sy + y2), ImColor(ImGui::GetStyle().Colors[ImGuiCol_ButtonActive]));
                    ImGui::GetWindowDrawList()->AddLine(ImVec2(sx + x, sy + y2), ImVec2(sx + 256, sy + y2), ImColor(ImGui::GetStyle().Colors[ImGuiCol_ButtonActive]));
                }
                else
                {
                    ImGui::GetWindowDrawList()->AddLine(ImVec2(sx + x, sy + y), ImVec2(sx + x + Screen::Width, sy + y), ImColor(ImGui::GetStyle().Colors[ImGuiCol_ButtonActive]));
                    ImGui::GetWindowDrawList()->AddLine(ImVec2(sx + x, sy + y2), ImVec2(sx + x + Screen::Width, sy + y2), ImColor(ImGui::GetStyle().Colors[ImGuiCol_ButtonActive]));
                }

                if (y2 < y)
                {
                    ImGui::GetWindowDrawList()->AddLine(ImVec2(sx + x, sy), ImVec2(sx + x, sy + y2), ImColor(ImGui::GetStyle().Colors[ImGuiCol_ButtonActive]));
                    ImGui::GetWindowDrawList()->AddLine(ImVec2(sx + x, sy + y), ImVec2(sx + x, sy + 256), ImColor(ImGui::GetStyle().Colors[ImGuiCol_ButtonActive]));

                    ImGui::GetWindowDrawList()->AddLine(ImVec2(sx + x2, sy), ImVec2(sx + x2, sy + y2), ImColor(ImGui::GetStyle().Colors[ImGuiCol_ButtonActive]));
                    ImGui::GetWindowDrawList()->AddLine(ImVec2(sx + x2, sy + y), ImVec2(sx + x2, sy + 256), ImColor(ImGui::GetStyle().Colors[ImGuiCol_ButtonActive]));
                }
                else
                {
                    ImGui::GetWindowDrawList()->AddLine(ImVec2(sx + x, sy + y), ImVec2(sx + x, sy + y + Screen::Height), ImColor(ImGui::GetStyle().Colors[ImGuiCol_ButtonActive]));
                    ImGui::GetWindowDrawList()->AddLine(ImVec2(sx + x2, sy + y), ImVec2(sx + x2, sy + y + Screen::Height), ImColor(ImGui::GetStyle().Colors[ImGuiCol_ButtonActive]));
                }
            }
            break;

            case 4:
                BuildOAMData();
                ImGui::Image((ImTextureID)mTextureId, ImVec2(384, 384), ImVec2(0.0f, 0.0f), ImVec2(0.5664f, 0.53125f));
                break;
        }
    }
    ImGui::End();
}

//--------------------------------------------
// --
//--------------------------------------------
void VRAMViewer::BuildTileMap(u16 _addrMap, u16 _addrTiles)
{
    fill_n(mTextureArray, 256 * 256, 0xFF000000);

    int r = 0;
    int c = 0;

    for (int t = 0; t < 1024; ++t)
    {
        RenderTile(_addrTiles, mMmu.ReadU8(_addrMap + t), c * 8, r * 8);

        ++c;
        if (c == 32)
        {
            c = 0;
            ++r;
        }
    }

    glBindTexture(GL_TEXTURE_2D, mTextureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGBA, GL_UNSIGNED_BYTE, mTextureArray);
}

//--------------------------------------------
// --
//--------------------------------------------
void VRAMViewer::BuildOAMData()
{
    fill_n(mTextureArray, 256 * 256, 0xFF733A3A);

    int r = 0;
    int c = 0;
    u16 addr = Memory::OAMStartAddr;
    u8  objSize = (mMmu.ReadU8(IOReg::LCDC) & (1 << 2)) != 0 ? 16 : 8;

    for (int t = 0; t < 40; ++t)
    {
        addr += 2; // ignore sprite position
        u8 sprTile = mMmu.ReadU8(addr++);
        u8 sprAttr = mMmu.ReadU8(addr++);

        RenderTile(Memory::VRamTileData1StartAddr, sprTile, (c * 8) + c + 1, (r * objSize) + r + 1, objSize, (sprAttr & (1 << 5)) != 0, (sprAttr & (1 << 6)) != 0);

        ++c;
        if (c == 16)
        {
            c = 0;
            ++r;
        }
    }

    glBindTexture(GL_TEXTURE_2D, mTextureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGBA, GL_UNSIGNED_BYTE, mTextureArray);
}

//--------------------------------------------
// --
//--------------------------------------------
void VRAMViewer::BuildTileData(u16 _addr)
{
    fill_n(mTextureArray, 256 * 256, 0xFF733A3A);

    int r = 0;
    int c = 0;

    for (int t = 0; t < 256; ++t)
    {
        RenderTile(_addr, t, (c * 8) + c + 1, (r * 8) + r + 1);

        ++c;
        if (c == 16)
        {
            c = 0;
            ++r;
        }
    }

    glBindTexture(GL_TEXTURE_2D, mTextureId);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 256, 256, 0, GL_RGBA, GL_UNSIGNED_BYTE, mTextureArray);
}

//--------------------------------------------
// --
//--------------------------------------------
void VRAMViewer::RenderTile(u16 _tileDataAddr, u8 _numTile, u8 _x, u8 _y, u8 _h, bool _flipX, bool _flipY)
{
    u16 tileAddr;

    if (_tileDataAddr == Memory::VRamTileData2StartAddr)
        tileAddr = 0x9000 + ((i8)_numTile * 16);
    else
        tileAddr = _tileDataAddr + (_numTile * 16);

    for (int r = 0; r < _h; ++r)
    {
        u16 rta = tileAddr + ((_flipY ? (_h - r) : r) * 2);
        u8 b1 = mMmu.ReadU8(rta);
        u8 b2 = mMmu.ReadU8(rta + 1);

        for (int b = 7; b >= 0; --b)
        {
            int rb = _flipX ? (7 - b) : b;
            u8 cp = (((b1 >> rb) & 1) << 1) | ((b2 >> rb) & 1);
            u32 c = sPalette[cp];

            mTextureArray[((_y + r) * 256) + _x + (7 - b)] = c;
        }
    }
}