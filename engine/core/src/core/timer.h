#pragma once

#include "time.h"
#include <chrono>

namespace Bubble
{
	using namespace std::chrono;

	class Timer
	{
		static high_resolution_clock::time_point ProgramStartTime;
		high_resolution_clock::time_point mLastTime = Now();
		DeltaTime mDeltatime;

	public:
		void Update();
		DeltaTime GetDeltaTime();

		// Time from the program start
		static Time GetTime();

	private:
		static high_resolution_clock::time_point Now();
	};

}
