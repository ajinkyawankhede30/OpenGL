#include "TestClearColor.h"
#include "imgui/imgui.h"
#include "Renderer.h"


	test::TestClearColor::TestClearColor()
		:m_clearcolor{ 0.2f,0.5f, 0.8f, 1.0f }
	{
	}

	test::TestClearColor::~TestClearColor()
	{

	}


	void test::TestClearColor::OnUpdate(float deltatime)
	{

	}

	void test::TestClearColor::OnRender() 
	{
		CallLog(glClearColor(m_clearcolor[0], m_clearcolor[1], m_clearcolor[2], m_clearcolor[3]));
		CallLog(glClear(GL_COLOR_BUFFER_BIT));
	}

	void test::TestClearColor::OnImGuiRender()
	{
		ImGui::ColorEdit4("Clear Color", m_clearcolor);
	}
