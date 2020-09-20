#pragma once
#include <iostream>
#include <chrono>

#include "time.h"


namespace Bubble
{
	using namespace std::chrono;

	class Timer
	{
		static high_resolution_clock::time_point s_ProgramStart;
		high_resolution_clock::time_point m_LastTime = Now();
		DeltaTime m_Deltatime;

	public:
		void Update();
		DeltaTime GetDeltaTime();

		// Time from the program start
		static Time GetTime();

	private:
		static high_resolution_clock::time_point Now();
	};

}
