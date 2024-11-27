#ifndef MENGER_SPONGE_H
#define MENGER_SPONGE_H

#include <vector>
#include <GLFW/glfw3.h>

struct Vertex {
    float x, y, z;
};

std::vector<Vertex> generateCube(float size, float xOffset, float yOffset, float zOffset);
void generateMengerSponge(std::vector<Vertex>& vertices, float size, float x, float y, float z, int depth);
bool initializeOpenGL(GLFWwindow*& window);
void render(const std::vector<Vertex>& vertices);

#endif // MENGER_SPONGE_H
