#include <GLFW/glfw3.h>
#include <stdio.h>

void error_callback(int error, const char* description)
{
        fprintf(stderr, "Error: %s\n", description);
}

int main()
{

        glfwSetErrorCallback(error_callback);
        if (!glfwInit()) {
                // Initialization failed
                return 63;
        }

#ifdef __APPLE__
        glfwWindowHint(GLFW_SAMPLES, 4);               // 4x antialiasing
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // To make MacOS happy; should not be needed
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL
#endif

        GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
        if (!window) {
                // Window or OpenGL context creation failed
                return 64;
        }

        glfwMakeContextCurrent(window);

        while (!glfwWindowShouldClose(window)) {

                glfwSwapBuffers(window);

                /* Poll for and process events */
                glfwPollEvents();
        }
        glfwTerminate();

        return 0;
}
