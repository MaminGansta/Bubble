#pragma once

namespace Bubble
{
	class Time
	{
		float m_Time = 0.0f;

	public:
		Time() = default;
		// Time in seconds
		Time(float time);

		float GetSeconds();
		float GetMilliseconds();
	};


	typedef Time DeltaTime;
}