#include "GLengine.h"

GLengine::GLengine()
{
}

GLengine::~GLengine()
{
    delete render;
    delete window;
}

void GLengine::clear()
{
    render->clear();
}

void GLengine::draw(Model& model)
{
    render->draw(model);
}

void GLengine::swapAndPool()
{
    window->swapBuffer();
    window->pollEvent();
}

Window& GLengine::getWindow() const
{
    return *window;
}
