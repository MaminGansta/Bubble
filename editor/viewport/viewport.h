#pragma once

#include "framebuffer/framebuffer.h"

#include <string>


namespace Editor
{
	struct Viewport
	{
	private:
		std::string m_Name;
		Bubble::Framebuffer m_Framebuffer;

	public:
		Viewport() = default;
		Viewport(int width, int height, const std::string& name = "Viewport");
		
		Viewport(const Viewport&) = delete;
		Viewport& operator= (const Viewport&) = delete;
		
		Viewport(Viewport&& other) noexcept;
		Viewport& operator= (Viewport&& other) noexcept;

		void Bind();
		void Unbind();
		
		const glm::ivec2 Size() const;
		void Resize(const glm::ivec2& size);

		const std::string& GetName() const;
		void SetName(const std::string& name);

		Bubble::Framebuffer& GetFramebuffer();
	};
}