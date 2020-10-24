#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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

	// create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(1024, 768, "Hello World", NULL, NULL);
	if(!window)
	{
		
		std::cout << "unable to create window" << std::endl;
		glfwTerminate();
		return -1;
	}

	// make the window's context current
	glfwMakeContextCurrent(window);

	// initialize glew library
	if(glewInit() != GLEW_OK)
	{
		std::cout << "Unable to initialize glew library" << std::endl;
		glfwTerminate();
		return -1;
	}

	std::cout << glGetString(GL_VERSION) << std::endl;

	float positions[6] = {
		-0.5f, -0.5f,
		 0.0f,  0.5f,
		 0.5f, -0.5f
	};

	// create vertex buffer
	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	// loop until the user closes the window
	while(!glfwWindowShouldClose(window))
	{
		// render here
		glClear(GL_COLOR_BUFFER_BIT);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		// swap front and back buffers
		glfwSwapBuffers(window);

		// poll for and process events
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
