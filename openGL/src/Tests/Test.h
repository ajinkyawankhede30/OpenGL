#pragma once

namespace test
{
	class Test
	{
	public:
		virtual ~Test() {}

		virtual void OnUpdate(float deltatime) {}
		virtual void OnRender() {}
		virtual void OnImGuiRender() {}

	};
}