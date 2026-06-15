#include "Render.h"

void Render::clear()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Render::draw(const Model& model)
{
    model.getShader().useProgram();
    model.getShader().setMat4("model", model.transform.getMatrix());
    model.getShader().setVec3("uColor", model.getColor());
    model.getMesh().draw();
}