//#include "GL/glew.h"
//#include "GLFW/glfw3.h"
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//
//#include "stb_image/stb_image.h"
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream>
//
//#include "Camera.h"
//#include "Menus.h"
//#include "BasicShaders.h"
//
//
//
//
//
//
//
//
//int screenWidth = 960;
//int screenHeight = 540;
//
//float deltaTime = 0.0f;	// Time between current frame and last frame
//float lastFrame = 0.0f; // Time of last frame
//
//bool mouseLockedOnCamera = true;
//float lastMouseLockToggleTime = 0.0f;
//constexpr float mouseLockToggleDebounce = 0.2f; // in seconds
//
//
//Camera camera;
//
//
//
//
//
//
//
//static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//    screenWidth = width;
//    screenHeight = height;
//}
//
//static void processInput(GLFWwindow* window)
//{
//    //std::cout << "input recieved" << std::endl;
//    camera.registerRelativeCameraSpeed(deltaTime);
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//    if (mouseLockedOnCamera)
//    {
//        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//            camera.registerW();
//        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//            camera.registerS();
//        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//            camera.registerA();
//        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//            camera.registerD();
//    }
//    if ((glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) && ((glfwGetTime() - lastMouseLockToggleTime) > mouseLockToggleDebounce))
//    {
//        lastMouseLockToggleTime = glfwGetTime();
//        mouseLockedOnCamera = !mouseLockedOnCamera;
//        if (mouseLockedOnCamera)
//        {
//            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//        }
//        else
//        {
//            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
//        }
//    }
//    //std::cout << glfwGetTime() << " " << ((glfwGetTime() - lastMouseLockToggleTime) > mouseLockToggleDebounce) << std::endl;
//}
//
//static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//    if (mouseLockedOnCamera)
//    {
//        camera.registerScroll(yoffset);
//    }
//}
//
//static void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//    if (mouseLockedOnCamera)
//    {
//        camera.registerRelativeCameraSpeed(deltaTime);
//        camera.registerMouseMove(xpos, ypos);
//    }
//    else
//    {
//        camera.setLastPositions(xpos, ypos);
//    }
//}
//
//
//
//
//
//
//
//int main()
//{
//    // data
//    float vertices[] = {
//    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//
//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//
//    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//
//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//     0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//
//    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//    -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
//    };
//    glm::vec3 cubePositions[] = {
//        glm::vec3(0.0f,  0.0f,  0.0f),
//        glm::vec3(2.0f,  5.0f, -15.0f),
//        glm::vec3(-1.5f, -2.2f, -2.5f),
//        glm::vec3(-3.8f, -2.0f, -12.3f),
//        glm::vec3(2.4f, -0.4f, -3.5f),
//        glm::vec3(-1.7f,  3.0f, -7.5f),
//        glm::vec3(1.3f, -2.0f, -2.5f),
//        glm::vec3(1.5f,  2.0f, -2.5f),
//        glm::vec3(1.5f,  0.2f, -1.5f),
//        glm::vec3(-1.3f,  1.0f, -1.5f)
//    };
//
//
//
//
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//
//    GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//
//
//    glfwMakeContextCurrent(window);
//    if (glewInit() != GLEW_OK) { // get real angy if you havent checked this :)
//        std::cerr << "Failed to initialize GLEW" << std::endl;
//        return -1;
//    }
//
//
//    glViewport(0, 0, screenWidth, screenHeight);
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//    glfwSetCursorPosCallback(window, mouse_callback);
//    glfwSetScrollCallback(window, scroll_callback);
//
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//    glfwSwapInterval(1);  // Enable V-Sync // vsync
//
//
//
//
//
//
//
//
//    // shaders
//    BasicShader shader(SHADERS "Vertex.Shader", SHADERS "Fragment.Shader");
//
//    //vertex array
//    unsigned int VAO;
//    glGenVertexArrays(1, &VAO);
//    glBindVertexArray(VAO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    unsigned int VBO;
//    glGenBuffers(1, &VBO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0); // positions
//    glEnableVertexAttribArray(0);
//
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float))); // tex coords
//    glEnableVertexAttribArray(1);
//
//
//
//    unsigned int lightVAO;
//    glGenVertexArrays(1, &lightVAO);
//    glBindVertexArray(lightVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//
//
//
//
//
//
//    //texture loading
//    stbi_set_flip_vertically_on_load(true);
//
//    int texWidth, texHeight, nrChannels;
//    unsigned char* data = stbi_load(TEXTURES "container.jpg", &texWidth, &texHeight, &nrChannels, 0);
//
//    //texture gen
//    unsigned int texture1;
//    glGenTextures(1, &texture1);
//    glBindTexture(GL_TEXTURE_2D, texture1);
//    //tex params
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//    stbi_image_free(data);
//
//
//
//    data = stbi_load(TEXTURES "awesomeface.png", &texWidth, &texHeight, &nrChannels, 0);
//
//    unsigned int texture2;
//    glGenTextures(1, &texture2);
//    glBindTexture(GL_TEXTURE_2D, texture2);
//    //tex params
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//
//    stbi_image_free(data);
//    shader.Bind();
//    glUniform1i(shader.GetUniformLocation("texture1"), 0);
//    glUniform1i(shader.GetUniformLocation("texture2"), 1);
//
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, texture1);
//    glActiveTexture(GL_TEXTURE1);
//    glBindTexture(GL_TEXTURE_2D, texture2);
//
//
//
//
//
//    int projectionLocation = shader.GetUniformLocation("projection");
//
//    int viewLocation = shader.GetUniformLocation("view");
//
//    int modelLocation = shader.GetUniformLocation("model");
//
//
//    glm::mat4 proj;
//    glm::mat4 view;
//
//
//
//
//
//
//
//
//
//    while (!glfwWindowShouldClose(window))
//    {
//        // input processing
//        float currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//
//        processInput(window);
//
//
//
//        // rendering
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//        //priming + draw calls
//        shader.Bind();
//
//        glBindVertexArray(VAO);
//
//
//
//        proj = glm::perspective(glm::radians(camera.currentFov), (float)screenWidth / (float)screenHeight, 0.1f, 1000.0f);
//        glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, &proj[0][0]);
//
//        view = glm::lookAt(camera.cameraPos, camera.cameraPos + camera.cameraFront, camera.cameraUp);
//        glUniformMatrix4fv(viewLocation, 1, GL_FALSE, &view[0][0]);
//
//
//
//        for (unsigned int i = 0; i < 10; i++)
//        {
//            glm::mat4 model = glm::mat4(1.0f);
//            model = glm::translate(model, cubePositions[i]);
//            float angle = 20.0f * i;
//            model = glm::rotate(model, (float)glfwGetTime() * glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
//            glUniformMatrix4fv(modelLocation, 1, GL_FALSE, &model[0][0]);
//
//            glDrawArrays(GL_TRIANGLES, 0, 36);
//        }
//
//
//
//
//        // check and call events and swap the buffer
//        glfwPollEvents();
//        glfwSwapBuffers(window);
//    }
//    glfwTerminate();
//    return 0;
//}