#pragma once

#include "engine.h"

#include "viewport/viewport_array.h"
#include "imgui_controll/imgui_controll.h"
#include "sdl_window/sdl_window.h"
#include "scene_camera/scene_camera_controller.h"

#include "file_dialog/file_dialog.h"

namespace Bubble
{
	class EditorLayer : public Layer
	{
		ImGuiControll m_ImGuiControll;
		ViewportArray m_ViewportArray;
		Ref<Scene> m_Scene;
		SceneCameraController m_SceneCamera;

		// Temp:
		LightArray  m_Lights;
		Ref<Shader> m_ShaderPhong;
		Ref<Model>  m_NanoSuit;
		Ref<Model>  m_GrassPlane;
		Ref<Model>  m_Tree;

		std::vector<Entity> Entities;

		Ref<Shader> m_ShaderSkybox;
		Ref<Skybox> m_Skybox;

	public:
		EditorLayer();
		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate(DeltaTime dt) override;
		void OnEvent(SDL_Event& event) override;
	};
}