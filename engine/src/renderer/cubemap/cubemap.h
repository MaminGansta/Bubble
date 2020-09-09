#pragma once

#include "renderer_base.h"
#include "texture/texture.h"

#include "stb_image.h"
#include <string>


namespace Bubble
{
	struct Cubemap
	{
		uint32_t m_RendererID;
		Cubemap(int width, int height, const Texture2DSpecification& spec);
		// Open skybox (files in dir: right, left, top, bottom, front, back |.jpg, .png, ...|)
		Cubemap(const std::string& dir, const std::string& ext = ".jpg");
		~Cubemap();

		Cubemap(const Cubemap&) = delete;
		Cubemap& operator=(const Cubemap&) = delete;

		Cubemap(Cubemap&&);
		Cubemap& operator=(Cubemap&&);

		void Bind();
	};

}