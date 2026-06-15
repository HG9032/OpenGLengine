#pragma once
#include "Window.h"

class KeyboardInput {
	//const Window& window;
	GLFWwindow* window;

public:
	KeyboardInput(const Window& windwo);
	bool isPressed(int key);
};