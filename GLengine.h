#pragma once

#include "Window.h"
#include "Shader.h"
#include "Render.h"
#include "Model.h"
#include "KeyboardInput.h"

class GLengine {
private:
    Window* window = new Window(800, 800, "SDF");
    Render* render = new Render();

public:
    KeyboardInput keyInput = KeyboardInput(*window);

    GLengine();
    ~GLengine();

    void clear();
    void draw(Model& model);
    void swapAndPool();

    Window& getWindow() const;
};