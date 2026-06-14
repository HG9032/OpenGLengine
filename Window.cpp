#include "Window.h"
#include <stdexcept>

Window::Window(int InitialWidth, int InitialHeight, const char* InitialTitle) :
	windowWidth(InitialWidth), windowHeight(InitialHeight), windowTitle(InitialTitle)
{
	if (!glfwInit())
	{
		throw std::runtime_error("Failed to initialize GLFW");
	}

	if ((monitor = glfwGetPrimaryMonitor()) == NULL) {
		throw std::runtime_error("Failed get primary monitor");
	}

	if ((monitorInfo = glfwGetVideoMode(monitor)) == NULL) {
		throw std::runtime_error("Failed get primary monitor info");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(windowWidth, windowHeight, windowTitle, NULL, NULL);

	if (window == NULL) {
		throw std::runtime_error("Window is not created");
	}

	glfwMakeContextCurrent(window);

	int version = gladLoadGL();

	if (version == 0)
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		throw std::runtime_error("Failed to initialize GLAD");
	}

	glViewport(0, 0, windowWidth, windowHeight);
	glEnable(GL_DEPTH_TEST);
}

Window::~Window(){
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Window::swapBuffer(){
	glfwSwapBuffers(window);
}

void Window::pollEvent(){
	glfwPollEvents();
}

bool Window::getWindowShouldClose(){
	return glfwWindowShouldClose(window);
}

void Window::setSize(int width, int height){
	windowWidth = width;
	windowHeight = height;

	int x = (monitorInfo->width - width) / 2;
	int y = (monitorInfo->height - height) / 2;

	if(!isFullScreen){
		glfwSetWindowSize(window, width, height);
		glfwSetWindowPos(window, x, y);
	}
	else{
		glfwSetWindowMonitor(window, NULL, x, y, windowWidth, windowHeight, NULL);
		isFullScreen = false;
	}

	glViewport(0, 0, windowWidth, windowHeight);
}

void Window::setFullScreen(){
	glfwSetWindowMonitor(window, monitor, 0, 0, monitorInfo->width, monitorInfo->height, monitorInfo->refreshRate);
	isFullScreen = true;
	glViewport(0, 0, windowWidth, windowHeight);
}

void Window::setTitle(const char* title){
	windowTitle = title;
	glfwSetWindowTitle(window, title);
}

GLFWwindow* Window::getGLFWwindow() const
{
	return window;
}
