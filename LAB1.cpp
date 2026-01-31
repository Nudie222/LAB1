#define GLEW_DLL
#define GLFW_DLL
#include <iostream>
#include "GL/glew.h"
#include "GLFW/glfw3.h"

int main()
{
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3.\n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(512, 512, "Mainwindow", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    GLenum ret = glewInit();
    if (ret != GLEW_OK) {
        fprintf(stderr, "ERROR: %s\n", glewGetErrorString(ret));
        return 1;
    }

    const GLubyte* version_str = glGetString(GL_VERSION);
    const GLubyte* device_str = glGetString(GL_RENDERER);

    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    printf("This version OpenGL running is %s\n", version_str);
    printf("This device OpenGL running is %s\n", device_str);

    while (!glfwWindowShouldClose(window)) {
        
        glClearColor(1.0f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);

        // Вершина 1 (право-центр)
        glColor3f(0.2f, 0.4f, 1.0f);
        glVertex2f(0.5f, 0.0f);

        // Вершина 2 (право-верх)
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.25f, 0.433f);

        // Вершина 3 (лево-верх)
        glColor3f(0.4f, 0.6f, 1.0f);
        glVertex2f(-0.25f, 0.433f);

        // Вершина 4 (лево-центр)
        glColor3f(0.1f, 0.2f, 0.8f);
        glVertex2f(-0.5f, 0.0f);

        // Вершина 5 (лево-низ)
        glColor3f(0.3f, 0.5f, 1.0f);
        glVertex2f(-0.25f, -0.433f);

        // Вершина 6 (право-низ)
        glColor3f(0.0f, 0.3f, 0.9f);
        glVertex2f(0.25f, -0.433f);

        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();

    return 0;
}