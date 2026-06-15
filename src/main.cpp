#include "GLengine.h"

int main()
{
    GLengine engine;

    Shader shader(
        "shaders/default.vert",
        "shaders/default.frag");

    Model triangle(shader, glm::vec3(0.0f, 0.0f, 0.0f));

    triangle.setColor(glm::vec3( 0.0f, 1.0f, 0.0f));

    while (!engine.getWindow().getWindowShouldClose())
    {
        engine.clear();

        engine.draw(triangle);

        engine.swapAndPool();
    }

    return 0;
}