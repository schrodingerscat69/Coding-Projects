#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "menger_sponge.h"
#include <cmath>
#include <iostream>

std::vector<Vertex> generateCube(float size, float xOffset, float yOffset, float zOffset) {
    float half = size / 2.0f;
    return {
        {xOffset - half, yOffset - half, zOffset + half},
        {xOffset + half, yOffset - half, zOffset + half},
        {xOffset + half, yOffset + half, zOffset + half},
        {xOffset - half, yOffset + half, zOffset + half},

        {xOffset - half, yOffset - half, zOffset - half},
        {xOffset + half, yOffset - half, zOffset - half},
        {xOffset + half, yOffset + half, zOffset - half},
        {xOffset - half, yOffset + half, zOffset - half},
    };
}

void generateMengerSponge(std::vector<Vertex>& vertices, float size, float x, float y, float z, int depth) {
    if (depth == 0) {
        std::vector<Vertex> cube = generateCube(size, x, y, z);
        vertices.insert(vertices.end(), cube.begin(), cube.end());
        return;
    }

    float newSize = size / 3.0f;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            for (int k = -1; k <= 1; ++k) {
                if ((std::abs(i) + std::abs(j) + std::abs(k)) > 1) {
                    generateMengerSponge(vertices, newSize, x + i * newSize, y + j * newSize, z + k * newSize, depth - 1);
                }
            }
        }
    }
}

bool initializeOpenGL(GLFWwindow*& window) {
    if (!glfwInit()) {
        return false;
    }

    window = glfwCreateWindow(800, 600, "Menger Sponge Fractal", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        return false;
    }

    glEnable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING); // Disable lighting for debugging
    return true;
}

void render(const std::vector<Vertex>& vertices) {
    glColor3f(0.0f, 1.0f, 0.0f); // Set the sponge color to green
    glBegin(GL_POINTS); // Render as points
    for (const auto& vertex : vertices) {
        glVertex3f(vertex.x, vertex.y, vertex.z);
    }
    glEnd();
}
