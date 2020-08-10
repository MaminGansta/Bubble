#pragma once

#define GLEW_STATIC
#include "GL/glew.h"

#include "log/log.h"

#include <memory>
#include <cassert>


// Error handler
#if _DEBUG
#define ASSERT(x) if (!(x)) assert(false);
#define glcall(func) GLClearError();\
        func;\
        ASSERT(GLLogCall(#func, __FILE__, __LINE__))

static void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}
static bool GLLogCall(const char* function, const char* file, int line)
{
	while (GLenum error = glGetError())
	{
		LOG_CORE_ERROR("[OpenGL Error] > {0} \n {1} : {2} \n", error, file, line);
		return false;
	}
	return true;
}
#else
#define glcall(func) (func);
#endif

// Assert
#ifdef BUBBLE_ASSERT_UNABLE
#define BUBBLE_ASSERT(x, ...)
#define BUBBLE_CORE_ASSERT(x, ...)
#else
#define BUBBLE_ASSERT(x, ...) { if(!(x)) { LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); assert(false) } }
#define BUBBLE_CORE_ASSERT(x, ...) { if(!(x)) { LOG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); assert(false); } }
#endif

#define BIT(x) (1 << x)

namespace Bubble
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}