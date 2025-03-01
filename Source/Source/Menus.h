#include "Imgui/imgui.h"
#include "Imgui/backends/imgui_impl_glfw.h"
#include "Imgui/backends/imgui_impl_opengl3.h"
// maybe not need ^^^^


#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "stb_image/stb_image.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

void menuInit(GLFWwindow* window, int& ScreenWidth, int& ScreenHeight);
void menuShutdown();

void menuRender();

