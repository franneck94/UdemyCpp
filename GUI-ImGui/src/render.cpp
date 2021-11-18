#include <cmath>

#include "imgui.h"
#include "implot.h"

#include "render.hpp"


void render()
{
    ImGui::NewFrame();

    ImGui::Begin("Test");
    {
        ImGui::Text("hello world!");
    }
    ImGui::End();

    ImGui::Render();
}
