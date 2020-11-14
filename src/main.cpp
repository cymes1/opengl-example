#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <gtc/matrix_transform.hpp>
#include <imgui.h>
#include <glfw/imgui_impl_glfw.h>
#include <opengl3/imgui_impl_opengl3.h>
#include "renderer.h"
#include "texture.h"
#include "vertex-buffer.h"
#include "vertex-buffer-layout.h"
#include "vertex-array.h"
#include "index-buffer.h"
#include "shader.h"

void GLFW_error(int error, const char* description)
{
    fputs(description, stderr);
}

int main()
{
	GLFWwindow* window;

    glfwSetErrorCallback(GLFW_error);

	// initialize glfw library
	if(!glfwInit())
	{
		std::cout << "unable to initialize glfw" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(960, 540, "Hello World", nullptr, nullptr);
	if(!window)
	{
		
		std::cout << "unable to create window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// make the window's context current
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	// initialize glew library
	if(glewInit() != GLEW_OK)
	{
		std::cout << "Unable to initialize glew library" << std::endl;
		glfwTerminate();
		return -1;
	}

	// initialize imgui
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	std::cout << glGetString(GL_VERSION) << std::endl;

    float positions[] = {
        -50.0f, -50.0f, 0.0f, 0.0f,
         50.0f, -50.0f, 1.0f, 0.0f,
         50.0f,  50.0f, 1.0f, 1.0f,
        -50.0f,  50.0f, 0.0f, 1.0f
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    VertexArray vertexArray;
    VertexBuffer vertexBuffer(positions, 4 * 4 * sizeof(float));
    VertexBufferLayout layout;
    layout.push<float>(2);
    layout.push<float>(2);
    vertexArray.addBuffer(vertexBuffer, layout);

    IndexBuffer indexBuffer(indices, 6);

    glm::mat4 projection = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0));

    Shader shader("res/shader/basic.shader");
    Renderer renderer;

    Texture texture("res/texture/test-texture.png");
    texture.bind();
    shader.bind();
    shader.setUniform1i("u_Texture", 0);

    shader.unbind();
    vertexArray.unbind();
    vertexBuffer.unbind();
    indexBuffer.unbind();

    glm::vec3 translationA(200, 200, 0);
    glm::vec3 translationB(400, 200, 0);

    // loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        renderer.clear();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), translationA);
            glm::mat4 mvp = projection * view * model;
            shader.bind();
            shader.setUniformMat4f("u_MVP", mvp);
            renderer.draw(vertexArray, indexBuffer, shader);
        }
        {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), translationB);
            glm::mat4 mvp = projection * view * model;
            shader.bind();
            shader.setUniformMat4f("u_MVP", mvp);
            renderer.draw(vertexArray, indexBuffer, shader);
        }

        ImGui::SliderFloat3("Translation A", &translationA.x, 0.0f, 960.0f);
        ImGui::SliderFloat3("Translation B", &translationB.x, 0.0f, 960.0f);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // swap front and back buffers
        glfwSwapBuffers(window);

        // poll for and process events
        glfwPollEvents();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}
