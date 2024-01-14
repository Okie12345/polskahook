/*
 * drawmgr.cpp
 *
 *  Created on: May 22, 2017
 *      Author: nullifiedcat
 */

#include <MiscTemporary.hpp>
#include <hacks/hacklist.hpp>
#if ENABLE_IMGUI_DRAWING
#include "imgui/imrenderer.hpp"
#elif ENABLE_GLEZ_DRAWING
#include <glez/glez.hpp>
#include <glez/record.hpp>
#include <glez/draw.hpp>
#endif
#include <settings/Bool.hpp>
#include <menu/GuiInterface.hpp>
#include "common.hpp"
#include "visual/drawing.hpp"
#include "hack.hpp"
#include "drawmgr.hpp"

static settings::Boolean info_text{ "hack-info.enable", "true" };
static settings::Int info_style{ "hack-info.style", "0" };
static settings::Rgba info_background_color{"hack-info.background", "00000b3"};
static settings::Rgba info_foreground_color{"hack-info.foreground", "ffffff"};
static settings::Int info_x{"hack-info.x", "10"};
static settings::Int info_y{"hack-info.y", "10"};

void RenderCheatVisuals()
{
    {
        PROF_SECTION(BeginCheatVisuals)
        BeginCheatVisuals();
    }
    {
        PROF_SECTION(DrawCheatVisuals)
        DrawCheatVisuals();
    }
    {
        PROF_SECTION(EndCheatVisuals)
        EndCheatVisuals();
    }
}
#if ENABLE_GLEZ_DRAWING
glez::record::Record bufferA{};
glez::record::Record bufferB{};

glez::record::Record *buffers[] = { &bufferA, &bufferB };
#endif
int currentBuffer = 0;

void BeginCheatVisuals()
{
#if ENABLE_IMGUI_DRAWING
    im_renderer::bufferBegin();
#elif ENABLE_GLEZ_DRAWING
    buffers[currentBuffer]->begin();
#endif
    ResetStrings();
}

void DrawCheatVisuals()
{
    {
        std::string name_s, reason_s;
        if (info_text)
        {
            float w, h;
            std::string hack_info_text;
            if (*info_style == 0) {
                hack_info_text = "PolskaHook";
                fonts::center_screen->stringSize(hack_info_text, &w, &h);
                draw::String(*info_x, *info_y, *info_foreground_color, hack_info_text.c_str(), *fonts::center_screen);
        }
    }
    if (spectator_target)
        AddCenterString("Press SPACE to stop spectating");
    {
        PROF_SECTION(DRAW_WRAPPER)
        EC::run(EC::Draw);
    }
    if (CE_GOOD(LOCAL_E))
    {
        PROF_SECTION(DRAW_skinchanger)
        hacks::skinchanger::DrawText();
        Prediction_PaintTraverse();
    }
    {
        PROF_SECTION(DRAW_strings)
        DrawStrings();
    }
#if ENABLE_GUI
    {
        PROF_SECTION(DRAW_GUI)
        gui::draw();
    }
#endif
}

void EndCheatVisuals()
{
#if ENABLE_GLEZ_DRAWING
    buffers[currentBuffer]->end();
#endif
#if ENABLE_GLEZ_DRAWING || ENABLE_IMGUI_DRAWING
    currentBuffer = !currentBuffer;
#endif
}

void DrawCache()
{
#if ENABLE_GLEZ_DRAWING
    buffers[!currentBuffer]->replay();
#endif
}
