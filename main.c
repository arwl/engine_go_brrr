#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv)
{

    // Initialise the GLFW context
    glfwInit();

    // Configure the window before creation
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL w/ GLFW", NULL, NULL);

    // Activate OpenGL context
    glfwMakeContextCurrent(window);

    // Required for modern OpenGL
    glewExperimental = GL_TRUE;

    glewInit();

    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    printf("%u\n",vertexBuffer);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);


    // Event loop
    while(!glfwWindowShouldClose(window)) {
        // glfwSwapBuffers(window);
        glfwPollEvents();
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, GL_TRUE);
        }
    }

    // Destroy the GLFW context
    glfwTerminate();

    return 0;

}
