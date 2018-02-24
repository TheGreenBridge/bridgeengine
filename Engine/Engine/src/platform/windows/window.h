#pragma once


#include <GLFW\glfw3.h>

class Window {
private:
	const char *m_Title;
	int m_Width, m_Height;
	bool m_Closed;

	GLFWwindow *m_Window;

	int m_cxpos, m_cypos;
	  
public:
	Window(const char* title, const int width, const int height);
	~Window();

	void clear() const;
	void update() const;
	const bool init();
	const bool isClosed() const;

	GLFWwindow * const getContext() const;

	int getWidth() const;
	int getHeight() const;

	int getCXPosition() const { return m_cxpos; };
	int getCYPosition() const { return m_cypos; };

	// Callbacks
	void setCursorCallback(GLFWcursorposfun cbfn);
	void setKeyboardCallback(GLFWkeyfun cbfun);
	void setMouseButtonCallback(GLFWmousebuttonfun mbfun);
	void setCharCallback(GLFWcharfun ccb);
	
	//friend void window_size_callback(GLFWwindow* window, int width, int height);
};