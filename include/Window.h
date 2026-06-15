#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <string>

class Window {
private:
	GLFWwindow* window = nullptr;
	
	int windowWidth = 0;
	int windowHeight = 0;
	int oldWindowWidth = 0;
	int oldWindowHeight = 0;
	bool isFullScreen = false;

	const char* windowTitle;

	GLFWmonitor* monitor = nullptr;
	const GLFWvidmode* monitorInfo = nullptr;

public:
	Window(int InitialWidth = 800, int InitialHeight = 800, const char* InitialTitle = "Title");
	~Window();
	void swapBuffer();
	void pollEvent();
	bool getWindowShouldClose();

	void setSize(int width, int height);
	void setFullScreen();
	void setTitle(const char* title);

	GLFWwindow* getGLFWwindow() const;
};