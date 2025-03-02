
#include "Menus.h"

int* screenWidth;
int* screenHeight;



enum MenuEnum
{
    BROWSEPROJECTS,
    PROJECT
};
// maybe another day...
//namespace Menus
//{
//    struct Button
//    {
//        float x, y, w, h;
//        bool clicked;
//
//        bool registerClick(double mouseX, double mouseY)
//        {
//            clicked = (mouseY > y && mouseY < y + h) && (mouseX > x && mouseX < x + w);
//            return clicked;
//        }
//
//        explicit operator bool() const { return clicked; }
//        bool operator!() const { return !clicked; }
//    };
//
//
//}

MenuEnum currentMenu = BROWSEPROJECTS;

void menuInit(GLFWwindow* window, int& ScreenWidth, int& ScreenHeight)
{
    screenHeight = &ScreenHeight;
    screenWidth = &ScreenWidth;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 450");
    ImGui::StyleColorsDark();
    ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;


   
}

void menuShutdown()
{
    ImGui_ImplGlfw_Shutdown();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui::DestroyContext();
}

void menuRender()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    //ImGuiViewport* viewport = ImGui::GetMainViewport();

    //// Now you can pass the ImGuiID to DockSpaceOverViewport
    //ImGui::DockSpaceOverViewport(viewport->ID, viewport);

    //ImGui::Begin("Hellow!");

    //ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
