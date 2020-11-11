#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <gtc/matrix_transform.hpp>
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
	window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
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

	std::cout << glGetString(GL_VERSION) << std::endl;

    float positions[] = {
        -0.5f, -0.5f, 0.0f, 0.0f,
         0.5f, -0.5f, 1.0f, 0.0f,
         0.5f,  0.5f, 1.0f, 1.0f,
        -0.5f,  0.5f, 0.0f, 1.0f
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

    glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -0.75f, 0.75f, -1.0f, 1.0f);

    Shader shader("res/shader/basic.shader");
    Renderer renderer;

    Texture texture("res/texture/test-texture.png");
    texture.bind();
    shader.bind();
    shader.setUniform1i("u_Texture", 0);
    shader.setUniformMat4f("u_MVP", projection);

    shader.unbind();
    vertexArray.unbind();
    vertexBuffer.unbind();
    indexBuffer.unbind();

    // loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        shader.bind();
        renderer.clear();
        renderer.draw(vertexArray, indexBuffer, shader);

        // swap front and back buffers
        glfwSwapBuffers(window);

        // poll for and process events
        glfwPollEvents();
    }

	glfwTerminate();
	return 0;
}
