#pragma once

//#include "GL/glew.h"
//#include <cstdint>
//#include <cassert>

namespace Bubble
{
	struct FramebufferSpecification
	{
		glm::ivec2 Size;
		int Samples = 1;
		bool SwapChainTarget = false;
	};

	struct Framebuffer
	{
		uint32_t m_RendererID = 0;
		uint32_t m_ColorAttachment = 0, m_DepthAttachment = 0;
		FramebufferSpecification m_Specification;

		Framebuffer() = default;
		Framebuffer(const FramebufferSpecification& spec);
		void Create(const FramebufferSpecification& spec);

		~Framebuffer();

		void Bind();
		void Unbind();
		void Invalidate();

		const glm::ivec2& GetSize() const;
		void Resize(const glm::ivec2& size);

		uint32_t GetColorAttachmentRendererID();
		const FramebufferSpecification& GetSpecification() const;

		//static Framebuffer Create(const FramebufferSpecification& spec);
	};
}