#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

constexpr auto WINDOW_WIDTH = 800;
constexpr auto WINDOW_HEIGHT = 600;

void onWindowResize(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void render();

int main()
{
	// Initialize GLFW and configure it to use OpenGL 4.6 with Core Profile
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create the window
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT,
		"OpenGL", nullptr, nullptr);

	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window." << std::endl;
		glfwTerminate();

		return -1;
	}

	// Set the created window as GLFW's current context
	glfwMakeContextCurrent(window);

	// Initialize GLAD
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
	{
		std::cout << "Failed to initialize GLAD." << std::endl;
		return -1;
	}

	// Set glfw callbacks
	glfwSetFramebufferSizeCallback(window, onWindowResize);

	// Run main loop
	while (!glfwWindowShouldClose(window))
	{
		// Handle inputs
		processInput(window);

		// Handle rendering
		render();

		// Check and call glfw events then swap the buffers
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	// Clean-up
	glfwTerminate();
	return 0;
}

void onWindowResize(GLFWwindow* window, const int width, const int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
