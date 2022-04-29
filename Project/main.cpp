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

struct ShaderProgramSource
{
  std::string VertexSource;
  std::string FragmentSource;
};

static ShaderProgramSource ParseShader(const std::string &filepath)
{
  std::ifstream stream(filepath);

  enum class ShaderType
  {
    NONE = -1,
    VERTEX = 0,
    FRAGMENT = 1
  };

  std::string line;
  std::stringstream ss[2];
  ShaderType type = ShaderType::NONE;
  while (getline(stream, line))
  {
    if (line.find("#shader") != std::string::npos)
    {
      if (line.find("vertex") != std::string::npos)
        type = ShaderType::VERTEX;
      else if (line.find("fragment") != std::string::npos)
        type = ShaderType::FRAGMENT;
    }
    else
    {
      ss[(int)type] << line << '\n';
    }
  }
  return {ss[0].str(), ss[1].str()};
}

static unsigned int CompileShader(unsigned int type, const std::string &source)
{
  GLCall(unsigned int id = glCreateShader(type););
  const char *src = source.c_str();
  GLCall(glShaderSource(id, 1, &src, nullptr););
  GLCall(glCompileShader(id););

  int result;
  GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result););
  if (result == GL_FALSE)
  {
    int length;
    GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length););
    char *message = (char *)alloca(length * sizeof(char));
    GLCall(glGetShaderInfoLog(id, length, &length, message););
    std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader\n";
    std::cout << message << std::endl;
    GLCall(glDeleteShader(id););
    return 0;
  }

  return id;
}

static unsigned int CreateShader(const std::string &vertexShader, const std::string &fragmentShader)
{
  GLCall(unsigned int program = glCreateProgram(););
  unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
  unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

  GLCall(glAttachShader(program, vs););
  GLCall(glAttachShader(program, fs););
  GLCall(glLinkProgram(program););
  GLCall(glValidateProgram(program););

  GLCall(glDeleteShader(vs););
  GLCall(glDeleteShader(fs););

  return program;
}

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
  window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
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
  {
    float positions[]{
        -0.5f,
        -0.5f,
        0.5f,
        -0.5f,
        0.5f,
        0.5f,
        -0.5f,
        0.5f,
    };

    unsigned int indices[]{
        0, 1, 2,
        2, 3, 0};

    unsigned int vao;
    GLCall(glGenVertexArrays(1, &vao));
    GLCall(glBindVertexArray(vao));

    VertexArray va;
    VertexBuffer vb(positions, 4 * 2 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push<float>(2);
    va.AddBuffer(vb, layout);

    IndexBuffer ib(indices, 6);

    ShaderProgramSource source = ParseShader("res/shaders/basic.glsl");
    // std::cout << source.VertexSource << std::endl;
    // std::cout << source.FragmentSource << std::endl;
    unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
    GLCall(glUseProgram(shader););

    GLCall(int location = glGetUniformLocation(shader, "u_Color"););
    ASSERT(location != -1);
    GLCall(glUniform4f(location, 0.2f, 0.3f, 0.8f, 1.0f););

    GLCall(glBindVertexArray(0));
    GLCall(glUseProgram(0));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

    float r{0.0f};
    float increment{0.25f};
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
      /* Render here */
      GLCall(glClear(GL_COLOR_BUFFER_BIT););

      GLCall(glUseProgram(shader));
      GLCall(glUniform4f(location, r, 0.3f, 0.8f, 1.0f););

      va.Bind();
      ib.Bind();

      GLCall(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr););

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

    GLCall(glDeleteProgram(shader));
  }
  glfwTerminate();
  return 0;
}