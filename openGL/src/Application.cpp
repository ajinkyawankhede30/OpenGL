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

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "imgui/imgui.h"
#include  "imgui/imgui_impl_opengl3.h"
#include <imgui/imgui_impl_glfw.cpp>

#include "Tests/TestClearColor.h"

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
	window = glfwCreateWindow(640, 440, "My_Window", NULL, NULL);
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

		CallLog(glEnable(GL_BLEND));
		CallLog(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		Renderer renderer;


		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;

		ImGui_ImplOpenGL3_Init();
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		
		//ImGui::StyleColorsDark();
		ImGui::StyleColorsClassic();

		test::TestClearColor test1;

		//loop till window is closed by user
		while (!glfwWindowShouldClose(window))
		{
			//Render
			//glClear(GL_COLOR_BUFFER_BIT);
			renderer.Clear();

			test1.OnUpdate(0.0f);
			test1.OnRender();

			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			test1.OnImGuiRender();

			CallLog(ImGui::Render());
			CallLog(ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData()));

			//Swap front and back buffer
			glfwSwapBuffers(window);

			//Poll for and process events
			glfwPollEvents();

		}

		//delete vbo;
		//delete ibo;
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwTerminate();
	return 0;
}