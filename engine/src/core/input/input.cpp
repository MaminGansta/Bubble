
#include "input.h"


namespace Bubble
{
	short Input::s_KeyMap[256];
	int Input::s_MouseKeyMap[16];
	int Input::s_MouseWheelOffset;

	int Input::s_MousePosX;
	int Input::s_MousePosY;
	int Input::s_MouseRelPosX;
	int Input::s_MouseRelPosY;

	SDL_Window* Input::s_Window;

	void Input::OnEvent(SDL_Event& event)
	{
		switch (event.type)
		{
			case SDL_KEYUP:
				s_KeyMap[event.key.keysym.sym] = 0;
				break;

			case SDL_KEYDOWN:
				s_KeyMap[event.key.keysym.sym] = 1 + event.key.repeat;
				break;

			case SDL_MOUSEWHEEL:
				s_MouseWheelOffset = event.wheel.y;
				break;


			case SDL_MOUSEMOTION:
				s_MousePosX = event.motion.x;
				s_MousePosY = event.motion.y;
				s_MouseRelPosX = event.motion.xrel;
				s_MouseRelPosY = event.motion.yrel;
				break;

			case SDL_MOUSEBUTTONDOWN:
				s_MouseKeyMap[event.button.button] = event.button.clicks;
				break;

			case SDL_MOUSEBUTTONUP:
				s_MouseKeyMap[event.button.button] = 0;
				break;
			}
		
	}

	// SDLK_a, SDLK_1, ...
	bool Input::IsKeyPressed(SDL_Keycode code)
	{
		return s_KeyMap[code];
	}

	// SDLK_a, SDLK_1, ...
	bool Input::IsKeyClick(SDL_Keycode code)
	{
		return s_KeyMap[code] == 1;
	}

	/*
		SDL_BUTTON_LEFT
		SDL_BUTTON_MIDDLE
		SDL_BUTTON_RIGHT
		SDL_BUTTON_X1
		SDL_BUTTON_X2
	*/
	bool Input::IsMouseButtonPressed(int button)
	{
		return s_MouseKeyMap[button];
	}

	glm::ivec2 Input::GetMousePosition()
	{
		return glm::ivec2(s_MousePosX, s_MousePosY);
	}

	glm::vec2 Input::fGetMousePosition()
	{
		int width, height;
		SDL_GetWindowSize(s_Window, &width, &height);
		return glm::vec2((float)s_MousePosX / width, (float)s_MousePosY / height);
	}

	float Input::fGetMouseX()
	{
		int width, height;
		SDL_GetWindowSize(s_Window, &width, &height);
		return (float)s_MousePosX / width;
	}

	float Input::fGetMouseY()
	{
		int width, height;
		SDL_GetWindowSize(s_Window, &width, &height);
		return (float)s_MousePosY / height;
	}

	int Input::GetMouseX()
	{
		return s_MousePosX;
	}

	int Input::GetMouseY()
	{
		return s_MousePosY;
	}

	int Input::GetMouseWheelOffset()
	{
		int temp = s_MouseWheelOffset;
		s_MouseWheelOffset = 0;
		return temp;
	}

}