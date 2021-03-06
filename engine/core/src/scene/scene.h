#pragma once

#include "core/base.h"
#include "core/time.h"
#include "entt/entt.hpp"

namespace Bubble
{
	class Entity;

	class Scene
	{
	public:
		entt::registry mRegistry;
		friend class Entity;

	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());
		void DeleteEntity(entt::entity entity);

		void OnUpdate(DeltaTime delta_time);
		void OnViewportResize(uint32_t width, uint32_t height);

		template <typename ...Args>
		auto GetView() { return mRegistry.view<Args...>(); }
	};

}