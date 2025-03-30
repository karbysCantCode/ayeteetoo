#include "Imgui/imgui.h"
#include "Imgui/backends/imgui_impl_glfw.h"
#include "Imgui/backends/imgui_impl_opengl3.h"
// maybe not need ^^^^


#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "stb_image/stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <iostream>

class MenuManager
{
private:
	void MenuInit(GLFWwindow* window, int& ScreenWidth, int& ScreenHeight);

	int* screenWidth;
	int* screenHeight;
public:
	glm::vec3 objectColor = { 1.0f, 0.5f, 0.31f };
	glm::vec3 lightColor = {0.0f, 1.0f, 1.0f};
	float lightOrbitRadius = 5.0f;
	float lightOrbitSpeed = 20.0f;

	MenuManager(GLFWwindow* window, int& ScreenWidth, int& ScreenHeight);
	void MenuShutdown();

	void MenuRender();
};

