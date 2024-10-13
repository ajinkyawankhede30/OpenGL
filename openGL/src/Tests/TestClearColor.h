#pragma once
#include "Test.h"

namespace test
{
	class TestClearColor : public Test
	{
	private:
		float m_clearcolor[4];

	public:
			TestClearColor();
			~TestClearColor();

			void OnUpdate(float deltatime) override;
			void OnRender() override;
			void OnImGuiRender() override;
	};
}