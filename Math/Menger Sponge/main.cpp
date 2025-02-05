#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "menger_sponge.h"
#include <vector>
#include <iostream>

int main() {
    GLFWwindow* window;
    if (!initializeOpenGL(window)) {
        std::cerr << "Failed to initialize OpenGL" << std::endl;
        return -1;
    }

    // Set up perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);

    std::vector<Vertex> vertices;
    generateMengerSponge(vertices, 1.0f, 0.0f, 0.0f, 0.0f, 3); // Depth = 3

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -2.5f); // Adjusted zoom for better view
        glRotatef((float)glfwGetTime() * 46.0f, 0.2f, 1.0f, 0.0f);

        render(vertices);

        glFlush();
        glFinish();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
