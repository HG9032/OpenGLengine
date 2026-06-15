#pragma once

#include "Window.h"
#include "Shader.h"
#include "Render.h"
#include "Model.h"

class GLengine {
private:
    Window* window = new Window(800, 800, "SDF");
    Render* render = new Render();

public:

    GLengine();
    ~GLengine();

    void clear();
    void draw(Model& model);
    void swapAndPool();

    Window& getWindow() const;
};