#include "window.h"
#include "../../utils/Log.h"
#include "../../graphics/render/RenderAPI.h"
#include "..\..\..\tests\Game.h"
//#include <gl\glew.h>

void windowResize(GLFWwindow * window, int width, int height);
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

Window::Window(const char* title, const int width, const int height) 
	: m_Title(title), m_Width(width), m_Height(height), m_cxpos(0), m_cypos(0)
{
	if (!init()) {
		LOG_ERROR("Context could not get initialized.");
		glfwTerminate();
	}
}

Window::~Window() {
	glfwTerminate();
}

const bool Window::init() {
	if (!glfwInit()) {
		LOG_ERROR("Failed to initialize GLFW!");
		return false;
	}
	else LOG("Open GL Window created.");

	/* Create a windowed mode window and its OpenGL context */

	m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
	if (!m_Window)
	{
		glfwTerminate();
		return false;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(m_Window);

	if (glewInit() != GLEW_OK) {
		LOG_ERROR("Could not initialize GLEW!");
		return false;
	}
	else LOG("GLEW successfully initialized.");

	printRenderAPI();

	glClearColor(0.39f, 0.65f, 1.0f, 1.0f);

	glfwSetWindowSizeCallback(m_Window, windowResize);
	
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	return true;
}

void Window::setCursorCallback(GLFWcursorposfun cbfun){
	glfwSetCursorPosCallback(m_Window, cbfun);
}

void Window::setKeyboardCallback(GLFWkeyfun cbfun) {
	glfwSetKeyCallback(m_Window, cbfun);
}

void Window::setMouseButtonCallback(GLFWmousebuttonfun mbfun) {
	glfwSetMouseButtonCallback(m_Window, mbfun);
}

void Window::setCharCallback(GLFWcharfun ccb) {
	glfwSetCharCallback(m_Window, ccb);
}

GLFWwindow * const Window::getContext() const {
	return m_Window;
}

void Window::clear() const {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::update() const {
	
	/* Poll for and process events */
	glfwPollEvents();
	/* Swap front and back buffers */
	glfwSwapBuffers(m_Window);	
}

// returns
const bool Window::isClosed() const {
	return glfwWindowShouldClose(m_Window) == 1;
}

int Window::getWidth() const {
	return m_Width;
}

int Window::getHeight() const {
	return m_Height;
}


// Events
void windowResize(GLFWwindow * window, int width, int height) {
	glViewport(0, 0, width, height);
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	LOG("MousePositon: " + std::to_string(xpos) + " , " + std::to_string(ypos));
}