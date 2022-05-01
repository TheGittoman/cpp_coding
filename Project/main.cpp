#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "src/Renderer.hpp"
#include "src/vertexBuffer.h"
#include "src/IndexBuffer.h"
#include "src/VertexBufferLayout.h"
#include "src/VertexArray.h"
#include "src/Shader.h"
#include "src/Texture.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

// int main(int argc, char **argv)
// {
// }

int main(void)
{
  GLFWwindow *window;

  /* Initialize the library */
  if (!glfwInit())
    return -1;

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(960, 540, "Rectangle Program", NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    return -1;
  }

  /* Make the window's context current */
  glfwMakeContextCurrent(window);

  glfwSwapInterval(1);

  if (glewInit() != GLEW_OK)
  {
    std::cout << "Glew Error!\n";
  }

  std::cout << glGetString(GL_VERSION) << std::endl;

  { // setting up scope for terminating OpenGL stuff
    float positions[]{
        100.0f, 100.0f, 0.0f, 0.0f,
        200.0f, 100.0f, 1.0f, 0.0f,
        200.0f, 200.0f, 1.0f, 1.0f,
        100.0f, 200.0f, 0.0f, 1.0f};

    unsigned int indices[]{
        0, 1, 2,
        2, 3, 0};

    GLCall(glEnable(GL_BLEND));
    GLCall(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

    // unsigned int vao;
    // GLCall(glGenVertexArrays(1, &vao));
    // GLCall(glBindVertexArray(vao));

    VertexArray va;
    VertexBuffer vb(positions, 4 * 4 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push<float>(2);
    layout.Push<float>(2);
    va.AddBuffer(vb, layout);

    IndexBuffer ib(indices, 6);

    glm::mat4 proj = glm::ortho(0.0f, 960.0f, 0.0f, 540.0f, -1.0f, 1.0f);
    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(-100, 0, 0));
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(200, 200, 0));

    glm::mat4 mvp = proj * view * model;

    // glm::vec4 vp(100.0f, 100.0f, 0.0f, 1.0f); // example vector
    // glm::vec4 result = proj * vp; // converting vector to 0-1 space

    Shader shader("res/shaders/basic.glsl");
    shader.Bind();
    shader.SetUniform4f("u_Color", 0.8f, 0.3f, 0.8f, 1.0f);
    shader.SetUniformMat4f("u_MVP", mvp);

    Texture texture("res/textures/logo.png");
    texture.Bind();
    shader.SetUniform1i("u_Texture", 0);

    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();

    Renderer renderer;

    float r{0.0f};
    float increment{0.25f};
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
      /* Render here */
      renderer.Clear();

      shader.Bind();
      shader.SetUniform4f("u_Color", r, 0.3f, 0.8f, 1.0f);

      renderer.Draw(va, ib, shader);

      if (r > 1.0f)
        increment = -0.025f;
      else if (r < 0.0f)
        increment = 0.025f;

      r += increment;
      /* Swap front and back buffers */
      GLCall(glfwSwapBuffers(window););

      /* Poll for and process events */
      GLCall(glfwPollEvents();)
    }
  }
  glfwTerminate();
  return 0;
}