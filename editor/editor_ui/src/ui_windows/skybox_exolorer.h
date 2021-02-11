#pragma once

#include "engine.h"
#include "ui_module.h"
#include "tools/file_dialog.h"
#include "viewport.h"


namespace Bubble
{
	struct SkyboxExplorer : UIModule
	{
		Ref<Skybox> mSelectedSkybox;
        Ref<Shader> mShader;
		FreeCamera  mCamera;
        Viewport    mViewport;

        inline SkyboxExplorer()
            : UIModule("Skybox explorer"),
              mSelectedSkybox(nullptr),
              mViewport(800, 600)
        {
            //mShader = Loader::LoadShader("resources/shaders/skybox.glsl");
            mCamera.Fov = PI / 3;
        }
        
		inline void Draw(UIArgs args, DeltaTime dt) override
		{
            //ImGui::Begin("Skybox explorer", &mIsOpen);
            //{
            //    ImVec2 window_size = ImGui::GetContentRegionAvail();
            //    ImVec2 pos = ImGui::GetCursorScreenPos();
            //
            //    // ==================== Viewport input ==================== 
            //    // Invisible drag able area over the viewport
            //    ImGui::InvisibleButton("##dummy", ImVec2{ window_size.x + 1, window_size.y * 0.7f + 1 });
            //
            //    // Moving by dragging
            //    if (ImGui::IsItemActive() && ImGui::IsMouseDragging(0))
            //    {
            //        mCamera.ProcessMouseMovementShift(Input::fGetMouseRelX(), Input::fGetMouseRelY());
            //        mCamera.Update(dt);
            //    }
            //
            //    //  ================= Render model =================
            //    if (mSelectedSkybox && ImGui::IsItemVisible()) {
            //        RenderSelectedSkybox();
            //    }
            //
            //    // ==================== Draw viewport ==================== 
            //    uint32_t textureId = mViewport.GetColorAttachmentRendererID();
            //    ImGui::GetWindowDrawList()->AddImage((void*)textureId, pos, ImVec2{ pos.x + window_size.x, pos.y + window_size.y * 0.7f }, ImVec2(1, 1), ImVec2(0, 0));
            //
            //    mViewport.mNewSize = { window_size.x, window_size.y * 0.6f };
            //
            //    // ==================== Model list ====================
            //    ImGui::BeginChild("Skybox list", ImVec2(window_size.x * 0.3f, window_size.y * 0.2f), true);
            //    {
            //        for (const auto& [path, skybox] : *Loader::sLoadedSkyboxes)
            //        {
            //            size_t pos = path.find_last_of("/") + 1;
            //            std::string name = path.substr(pos);
            //
            //            ImGui::Selectable(name.c_str(), mSelectedSkybox == skybox);
            //
            //            // Switch
            //            if (ImGui::IsItemClicked())
            //            {
            //                mSelectedSkybox = skybox;
            //                mCamera.Update(dt);
            //            }
            //        }
            //
            //        if (ImGui::IsMouseDown(0) && ImGui::IsWindowHovered())
            //        {
            //            mSelectedSkybox = nullptr;
            //        }
            //    }
            //    ImGui::EndChild();
            //
            //    // ==================== Buttons ====================
            //    if (ImGui::Button("Load", { 100, window_size.y * 0.05f }))
            //    {
            //        try
            //        {
            //            std::string path = OpenFileDialog();
            //            Loader::LoadSkybox(path);
            //        }
            //        catch (const std::exception& e)
            //        {
            //            LOG_ERROR(e.what());
            //        }
            //    }
            //}
            //ImGui::End();
		}


        inline void RenderSelectedSkybox()
        {
            //Renderer::SetViewport(mViewport);
            //Renderer::SetCamera(mCamera);
            //Renderer::ClearDepth();
            //
            //glm::mat4 view = Skybox::GetViewMatrix(Renderer::sActiveCamera->GetLookatMat());
            //Renderer::GetUBOPojectionView()[0].SetMat4("View", view);
            //
            //mShader->SetUni1f("u_Brightness", 1.0f);
            //mShader->SetUni1f("u_BlendFactor", 0.0f);
            //
            //Renderer::DrawSkybox(&mSelectedSkybox, 1, mShader);
            //Viewport::BindMainWindow();
        }


        void OnUpdate(UIArgs args, DeltaTime dt) override
        {
            mViewport.OnUpdate();
        }

    };
}