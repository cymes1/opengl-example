#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glfw/imgui_impl_glfw.h>
#include <imgui.h>
#include <opengl3/imgui_impl_opengl3.h>
#include "vertex-buffer.h"
#include <states/roots/root.h>
#include <states/states/menu-state.h>

using namespace OpenGlExample;
using namespace OpenGlExample::States;

void GLFW_error(int error, const char* description)
{
    fputs(description, stderr);
}

bool initializeGLFWLibrary();
bool createGLFWWindow(GLFWwindow*& window);
void initializeImGuiLibrary(GLFWwindow* window);

int main()
{
	if(!initializeGLFWLibrary())
	{
		std::cout << "unable to initialize glfw" << std::endl;
		return -1;
	}

    GLFWwindow* window = nullptr;
	if(!createGLFWWindow(window))
    {
        std::cout << "unable to create window" << std::endl;
        return -1;
    }

	if(glewInit() != GLEW_OK)
	{
		std::cout << "Unable to initialize glew library" << std::endl;
		glfwTerminate();
		return -1;
	}

	initializeImGuiLibrary(window);
	std::cout << glGetString(GL_VERSION) << std::endl;

    Root root;
    root.initialize<States::MenuState>();

    while (!glfwWindowShouldClose(window))
    {
        GLCall(glClearColor(0.0f, 0.0f, 0.0f, 0.0f));
        GLCall(glClear(GL_COLOR_BUFFER_BIT));

        root.tick();
        root.render();
        root.renderImGui();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwTerminate();
	return 0;
}

bool initializeGLFWLibrary()
{
    glfwSetErrorCallback(GLFW_error);
    if(!glfwInit())
        return false;

    return true;
}

bool createGLFWWindow(GLFWwindow*& window)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(960, 540, "OpenGL Example", nullptr, nullptr);
    if(!window)
    {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);
    return true;
}

void initializeImGuiLibrary(GLFWwindow* window)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}