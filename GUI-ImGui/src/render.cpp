#include <cmath>

#include "imgui.h"
#include "implot.h"

#include "render.hpp"


static ImS8 midtm[10] = {83, 67, 23, 89, 83, 78, 91, 82, 85, 90};
static ImS16 final[10] = {80, 62, 56, 99, 55, 78, 88, 78, 90, 100};
static ImS32 grade[10] = {80, 69, 52, 92, 72, 78, 75, 76, 89, 95};

static const char *labels[] = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10"};
static const double positions[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};


void render()
{
    static bool pressed = false;

    ImGui::NewFrame();

    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(300, 200));
    ImGui::Begin("ButtonWindow",
                 nullptr,
                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
    {
        if (ImGui::Button("Button"))
        {
            pressed = !pressed;
        }

        if (pressed)
        {
            ImGui::Text("Pressed");
        }
    }
    ImGui::End();

    ImGui::SetNextWindowPos(ImVec2(0, 400));
    ImGui::SetNextWindowSize(ImVec2(300, 200));
    if (ImGui::Begin("TableWindow",
                     nullptr,
                     ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize))
    {
        if (ImGui::BeginTable("Table", 2, ImGuiTableFlags_Borders))
        {
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::Text("%d", midtm[0]);
            ImGui::TableNextColumn();
            ImGui::Text("%d", final[0]);

            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::Text("%d", midtm[1]);
            ImGui::TableNextColumn();
            ImGui::Text("%d", final[1]);

            ImGui::EndTable();
        }

        ImGui::End();
    }

    ShowDemo_BarPlots();

    ImGui::Render();
}

void ShowDemo_BarPlots()
{
    static bool horz = false;

    ImPlot::CreateContext();
    ImGui::SetNextWindowPos(ImVec2(400, 400));
    ImGui::SetNextWindowSize(ImVec2(880, 320));
    if (ImGui::Begin("PlotWindow",
                     nullptr,
                     ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize))
    {
        ImGui::Checkbox("Horizontal", &horz);

        if (ImPlot::BeginPlot("Bar Plot"))
        {
            ImPlot::SetupLegend(ImPlotLocation_East, ImPlotLegendFlags_Outside);
            if (horz)
            {
                ImPlot::SetupAxesLimits(0, 110, -0.5, 9.5, ImGuiCond_Always);
                ImPlot::SetupAxes("Score", "Student", 0, ImPlotAxisFlags_Invert);
                ImPlot::SetupAxisTicks(ImAxis_Y1, positions, 10, labels);
                ImPlot::PlotBarsH("Midterm Exam", midtm, 10, 0.2, -0.2);
                ImPlot::PlotBarsH("Final Exam", final, 10, 0.2, 0);
                ImPlot::PlotBarsH("Course Grade", grade, 10, 0.2, 0.2);
            }
            else
            {
                ImPlot::SetupAxesLimits(-0.5, 9.5, 0, 110, ImGuiCond_Always);
                ImPlot::SetupAxes("Student", "Score");
                ImPlot::SetupAxisTicks(ImAxis_X1, positions, 10, labels);
                ImPlot::PlotBars("Midterm Exam", midtm, 10, 0.2, -0.2);
                ImPlot::PlotBars("Final Exam", final, 10, 0.2, 0);
                ImPlot::PlotBars("Course Grade", grade, 10, 0.2, 0.2);
            }

            ImPlot::EndPlot();
        }

        ImGui::End();
    }
}
