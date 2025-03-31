
#include "Menus.h"


MenuManager::MenuManager(GLFWwindow* window, int& ScreenWidth, int& ScreenHeight)
{
    MenuInit(window, ScreenWidth, ScreenHeight);
}

void MenuManager::MenuInit(GLFWwindow* window, int& ScreenWidth, int& ScreenHeight)
{
    screenHeight = &ScreenHeight;
    screenWidth = &ScreenWidth;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 450");
    ImGui::StyleColorsDark();
}

void MenuManager::MenuShutdown()
{
    ImGui_ImplGlfw_Shutdown();
    ImGui_ImplOpenGL3_Shutdown();
    ImGui::DestroyContext();
}

void MenuManager::MenuRender()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Debuuu");

    ImGui::ColorEdit3("Light Color", &lightColor[0]);
    ImGui::SliderFloat("Light Orbit Radius", &lightOrbitRadius, 0, 50);
    ImGui::SliderFloat("Light Orbit Speed", &lightOrbitSpeed, 0, 1000);
    ImGui::ColorEdit3("Material Surface Color", &materialSurfaceColor[0]);
    ImGui::ColorEdit3("Material Specular Color", &materialSpecular[0]);
    ImGui::SliderFloat("Material Shininess", &materialShininess, 0, 19);
    /*std::cout << Menus::objectColor.r << " " << Menus::objectColor.g << " " << Menus::objectColor.b << " ";
    std::cout << Menus::lightColor.r << " " << Menus::lightColor.g << " " << Menus::lightColor.b << std::endl;*/
    ImGui::End();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
