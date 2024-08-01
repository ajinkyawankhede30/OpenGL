#pragma once
#include <iostream>
#include <GL/glew.h>
#include <glfw3.h>
#include <fstream>
#include <string>
#include <sstream>

#include "Renderer.h"
#include "VertexBuffClass.h"
#include "VertexBufferLayout.h"
#include "IndexBuffClass.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Texture.h"

//#pragma region ShaderFunctions
//static int CompileShader(unsigned int type, const std::string& source)
//{
//	unsigned int id = glCreateShader(type);
//	const char* src = source.c_str();
//	glShaderSource(id, 1, &src, NULL); //Replaces the source code in a shader object
//	glCompileShader(id);
//
//	//error handling
//	int result;
//	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
//	if (result == GL_FALSE)
//	{
//		int length;
//		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
//		char* message = (char*)alloca(length * sizeof(char));
//		glGetShaderInfoLog(id, length, &length, message);
//		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vetex" : "fragment") << std::endl;
//		std::cout << message << std::endl;
//		glDeleteShader(id);
//		return 0;
//	}
//
//	return id;
//}
//
//static int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
//{
//	unsigned int program = glCreateProgram();
//	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
//	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
//
//	glAttachShader(program, vs);
//	glAttachShader(program, fs);
//	glLinkProgram(program);
//	glValidateProgram(program);
//
//	glDeleteShader(vs);
//	glDeleteShader(fs);
//
//	return program;
//}
//
//struct ShaderProgramSource
//{
//	std::string VertexShader;
//	std::string FragmentShader;
//};
//
//static ShaderProgramSource ParseShader(const std::string& filePath)
//{
//	enum class ShaderType
//	{
//		NONE = -1,
//		VERTEX = 0,
//		FRAGMENT = 1,
//	};
//
//	std::fstream read(filePath);
//	std::string line;
//	ShaderType type = ShaderType::NONE;
//	std::stringstream ss[2];
//	while (std::getline(read, line))
//	{
//		if (line.find("#shader") != std::string::npos)
//		{
//			if (line.find("vertex") != std::string::npos)
//				type = ShaderType::VERTEX;
//			else if (line.find("fragment") != std::string::npos)
//				type = ShaderType::FRAGMENT;
//		}
//		else
//		{
//			ss[(int)type] << line << "\n";
//		}
//	}
//
//	return { ss[0].str(), ss[1].str() };
//}
//
//#pragma endregion

int main()
{
	GLFWwindow* window;

	//Initialize the library
	if (!glfwInit())
	{
		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE); //user for vertex arrays
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE); //default 

	//Create window
	window = glfwCreateWindow(650, 450, "My_Window", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	//Make window context current
	glfwMakeContextCurrent(window);

	glfwSwapInterval(1);

	//initialize glew lib
	if (glewInit() != GLEW_OK)
		std::cout << "Error initializing glew..." << std::endl;

	//print version og 
	std::cout << glGetString(GL_VERSION) << std::endl;
	{

		float positions[] = {
			-0.5f, -0.5f,	0.0f, 0.0f, //0th index
			 0.5f,  -0.5f,	1.0f, 0.0f,	//1 
			 0.5f,	0.5f,	1.0f, 1.0f,	//2
			-0.5f,	0.5f,	0.0f, 1.0f	//3rd index
		};

		unsigned int indicies[] = {
		0,1,2,
		2,3,0
		};

		CallLog(glEnable(GL_BLEND));
		CallLog(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		//Create vertex array
		VertexArray va;

		//VertexBuffer* vbo = new VertexBuffer(positions,  4*2*sizeof(float));
		VertexBuffer vbo(positions, 4 * 4 * sizeof(float));
		
		VertexBufferLayout layout;
		layout.Push<float>(2);
		layout.Push<float>(2);

		//Add buffer to array
		va.AddBuffer(vbo, layout);

		//enable vertex attribute
		glEnableVertexAttribArray(0);

		//assign attributes
		//glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);

		//Create index buffer object - ibo
		//IndexBuffer* ibo = new IndexBuffer(indicies, 6);
		IndexBuffer ibo(indicies, 6);

#pragma region shader_String
		std::string vertexShader =
			"#version 330 core\n"
			"\n"
			"layout(location = 0) in vec4 position;\n"
			"void main()\n"
			"{\n"
			"	gl_position = position;\n"
			"}\n";

		std::string fragmentShader =
			"#version 330 core\n"
			"\n"
			"layout(location = 0) out vec4 color;\n"
			"void main()\n"
			"{\n"
			"	color = vec4(1.0,0.0,0.0,1.0);\n"
			"}\n";
#pragma endregion

#pragma region ShaderSrcProgram
		std::string vertexShad =
			"#version 330 core\n"
			"\n"
			"layout(location = 0) in vec4 position;\n"
			"void main()\n"
			"{\n"
			"	gl_position = position;\n"
			"}\n";

		std::string fragmentShad =
			"#version 330 core\n"
			"\n"
			"layout(location = 0) out vec4 color;\n"
			"void main()\n"
			"{\n"
			"	color = vec4(1.0,0.5f,0.25f,0.0);\n"
			"}\n";
#pragma endregion

		Shader shader("src/Basic_uniform.shader");
		shader.Bind();
		shader.SetUniform4f("u_color", 0.8f, 0.3f, 0.8f, 1.0f);

		Texture texture("resource/textures/the_Cherno.png");
		texture.Bind();
		shader.SetUniform1i("u_Texture", 0);

		//unbind buffer
		va.Unbind();
		vbo.Unbind();
		ibo.Unbind();
		shader.UnBind();

		Renderer renderer;

		float r = 0.1f;
		float increment = 0.05f;

		//loop till window is closed by user
		while (!glfwWindowShouldClose(window))
		{
			//Render
			//glClear(GL_COLOR_BUFFER_BIT);
			renderer.Clear();

			//bind shader
			shader.Bind();
			shader.SetUniform4f("u_color", r, 0.3f, 0.8f, 1.0f);

			renderer.Draw(va, ibo, shader);

			/*Note: After vertex array is created, there is no need to bind vertex buffer & assign vertex attribute
			Just need to bind the vertex array */

			//glBindBuffer(GL_ARRAY_BUFFER, buffer);
			//glEnableVertexAttribArray(0);
			//glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0);

			//bind vertex array
			//va.Bind();

			//bind index buffer
			//ibo->Bind();
			//ibo.Bind();

			//CallLog(glDrawElements(GL_TRIANGLES, 6, GL_INT, nullptr));


			//CallLog(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));

			if (r > 1.0f)
			{
				increment = -0.05f;
			}
			else if (r < 0.0f)
			{
				increment = 0.05f;
			}

			r += increment;
			//Swap front and back buffer
			glfwSwapBuffers(window);

			//Poll for and process events
			glfwPollEvents();

		}

		//delete vbo;
		//delete ibo;
	}
	glfwTerminate();
	return 0;
}