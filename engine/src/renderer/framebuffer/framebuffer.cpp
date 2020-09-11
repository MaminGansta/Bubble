
#include "framebuffer.h"
#include "application/application.h"


namespace Bubble
{
	Framebuffer::Framebuffer(const FramebufferSpecification& spec)
		: m_Specification(spec)
	{
		Invalidate();
	}

	Framebuffer::Framebuffer(Framebuffer&& other) noexcept
	{
		// Rebind
		m_RendererID = other.m_RendererID;
		m_ColorAttachment = other.m_ColorAttachment;
		m_DepthAttachment = other.m_DepthAttachment;
		m_Specification = other.m_Specification;

		// Make invalid
		other.m_RendererID = 0;
		other.m_ColorAttachment = 0;
		other.m_DepthAttachment = 0;
	}

	Framebuffer& Framebuffer::operator= (Framebuffer&& other) noexcept
	{
		if (this != &other)
		{
			// Clear
			glDeleteFramebuffers(1, &m_RendererID);
			glDeleteTextures(1, &m_ColorAttachment);
			glDeleteTextures(1, &m_DepthAttachment);

			// Rebind
			m_RendererID = other.m_RendererID;
			m_ColorAttachment = other.m_ColorAttachment;
			m_DepthAttachment = other.m_DepthAttachment;
			m_Specification = other.m_Specification;

			// Make invalid
			other.m_RendererID = 0;
			other.m_ColorAttachment = 0;
			other.m_DepthAttachment = 0;
		}
		return *this;
	}


	void Framebuffer::Create(const FramebufferSpecification& spec)
	{
		m_Specification = spec;
		Invalidate();
	}

	Framebuffer::~Framebuffer()
	{
		glDeleteFramebuffers(1, &m_RendererID);
		glDeleteTextures(1, &m_ColorAttachment);
		glDeleteTextures(1, &m_DepthAttachment);
	}

	void Framebuffer::Invalidate()
	{
		glDeleteFramebuffers(1, &m_RendererID);
		glDeleteTextures(1, &m_ColorAttachment);
		glDeleteTextures(1, &m_DepthAttachment);

		glcall(glGenFramebuffers(1, &m_RendererID));
		glcall(glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID));

		// Color
		glcall(glGenTextures(1, &m_ColorAttachment));
		glcall(glBindTexture(GL_TEXTURE_2D, m_ColorAttachment));
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8,
			GetWidth(), GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ColorAttachment, 0);

		// Depth
		glcall(glGenTextures(1, &m_DepthAttachment));
		glcall(glBindTexture(GL_TEXTURE_2D, m_DepthAttachment));
		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT,
			GetWidth(), GetWidth(), 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		
		float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
		glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, m_DepthAttachment, 0);

		// Something going wrong
		BUBBLE_CORE_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE, "Framebuffer is incomplete!");

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	int Framebuffer::GetWidth() const
	{
		return m_Specification.Size.x;
	}

	int Framebuffer::GetHeight() const
	{
		return m_Specification.Size.y;
	}

	void Framebuffer::Bind() const
	{
		glcall(glBindFramebuffer(GL_FRAMEBUFFER, m_RendererID));
		glViewport(0, 0, GetWidth(), GetHeight());
	}

	void Framebuffer::Unbind() const
	{
		glcall(glBindFramebuffer(GL_FRAMEBUFFER, 0));
	}

	glm::ivec2 Framebuffer::Size() const
	{
		return m_Specification.Size;
	}

	void Framebuffer::Resize(glm::ivec2 size)
	{
		if ((size.x * size.y) <= 0) {
			return;
		}
		else if (size.x < size.y) {
			size.x = size.y;
		}
		m_Specification.Size = size;
		Invalidate();
	}

	const FramebufferSpecification& Framebuffer::GetSpecification() const
	{
		return m_Specification;
	}

	void Framebuffer::BindDefault()
	{
		glcall(glBindFramebuffer(GL_FRAMEBUFFER, 0));
		glm::ivec2 window_size = Application::GetWindow()->GetSize();
		glViewport(0, 0, window_size.x, window_size.y);
	}

	uint32_t Framebuffer::GetColorAttachmentRendererID()
	{
		return m_ColorAttachment;
	}

}