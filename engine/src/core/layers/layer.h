#pragma once

#include "SDL2/SDL_events.h"
#include "time/time.h"

#include <string>


namespace Bubble
{
	class Layer
	{
	public:
		std::string m_Name;

		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(DeltaTime delta_time) {}
		virtual void OnEvent(SDL_Event& event) {}
	};
}
