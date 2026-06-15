#include "KeyboardInput.h"

KeyboardInput::KeyboardInput(const Window& window) :
	window(window.getGLFWwindow())
{
}

bool KeyboardInput::isPressed(int key)
{
	return glfwGetKey(window, key) == GLFW_PRESS;
}
