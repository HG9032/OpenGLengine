#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <string>

class Window {
private:
	GLFWwindow* window = nullptr;
	
	int windowWidth;
	int windowHeight;
	int oldWindowWidth;
	int oldWindowHeight;
	bool isFullScreen = false;

	const char* windowTitle;

	GLFWmonitor* monitor;
	const GLFWvidmode* monitorInfo;

public:
	Window(int InitialWidth, int InitialHeight, const char* InitialTitle);
	~Window();
	void swapBuffer();
	void pollEvent();
	bool getWindowShouldClose();

	void setSize(int width, int height);
	void setFullScreen();
	void setTitle(const char* title);

	GLFWwindow* getGLFWwindow() const;
};