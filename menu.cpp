#include "menu.h"
#include "settings.h"
#include "functions.h"
#include "imguipp.h"
#include "icons.h"


enum esp_info_position
{
	RIGHT,
	CENTER_DOWN,
	CENTER_UP
};





		

		void Menu::Render()
{
	ImGui::Columns(2);
	ImGui::SetColumnOffset(1, 230);

	{
		//Left side

		static ImVec4 active = imguipp::to_vec4(41, 40, 41, 255);
		static ImVec4 inactive = imguipp::to_vec4(31, 30, 31, 255);

		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 1 ? active : inactive);
		

		ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 2 ? active : inactive);
		if (ImGui::Button(ICON_FA_BOOK "Cheat Options", ImVec2(230 - 15, 41)))
			Settings::Tab = 2;

		ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 3 ? active : inactive);
		if (ImGui::Button(ICON_FA_BOMB "Exploits", ImVec2(230 - 15, 41)))
			Settings::Tab = 3;

		ImGui::Spacing();
		ImGui::PushStyleColor(ImGuiCol_Button, Settings::Tab == 4 ? active : inactive);
		if (ImGui::Button(ICON_FA_DOWNLOAD "Spoof", ImVec2(230 - 15, 41)))
			Settings::Tab = 4;
		ImGui::Spacing();

		if (ImGui::Button( "Exit", ImVec2(230 - 15, 41)))
			Settings::Tab = 1;


		ImGui::PopStyleColor(4);

		ImGui::SetCursorPosY(ImGui::GetWindowHeight() - 30);
		imguipp::center_text_ex("Hope#5708", 230, 1, false);
	}

	ImGui::NextColumn();
	
	float target_x = 0;
	float target_y = 0;
	//exploit tab
	if (Settings::Tab == 3)
	{
		ImGui::Button("Force Glider Deployment");
		ImGui::Button("Vehicule Fly");
		ImGui::Button("( Local ) Lag");
		ImGui::Button("Top 1 Animation");
		ImGui::Button("Spin");
		ImGui::Button("Force Glider Deployment");

	}
	//Right side
	if (Settings::Tab == 1)
	{
		exit(10);
	}
	{
		//Dumper Tab
		if (Settings::Tab == 2)
		{

			static ImGuiTextFilter filter;
			static std::vector<std::string> resources =
			{
				"Visual",
				"Targetting",
				"World ",
				"Streaming Mode",
				
			};

		

			filter.Draw(ICON_FA_SEARCH" Search", 240);
			ImGui::PushStyleColor(ImGuiCol_FrameBg, IM_COL32(0, 0, 0, 0));
			if (ImGui::ListBoxHeader("##ResourcesList", ImVec2(imguipp::getx(), imguipp::gety() - 35)))
			{
				for (const auto& resource : resources)
				{
					if (filter.PassFilter(resource.c_str()))
					{
						if (ImGui::TreeNode(resource.c_str()))
							ImGui::TreePop();				
					}
				}
				ImGui::ListBoxFooter();
			}
			ImGui::PopStyleColor();
			if (ImGui::Button(ICON_FA_FOLDER_OPEN" Save Config to folder", ImVec2(205, 34))) {}
		}		
	}
}

void Menu::Theme()
{
	ImGuiStyle* style = &ImGui::GetStyle();

	style->WindowBorderSize = 0;
	style->WindowTitleAlign = ImVec2(0.4, 0.4);
	style->WindowMinSize = ImVec2(500, 500);

	style->FramePadding = ImVec2(7, 5);

	style->Colors[ImGuiCol_TitleBg] = ImColor(0,0,0);
	style->Colors[ImGuiCol_TitleBgActive] = ImColor(0,0,0);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImColor(0, 0, 0);

	style->Colors[ImGuiCol_Button] = ImColor(216,34,64);
	style->Colors[ImGuiCol_ButtonActive] = ImColor(31, 30, 31, 255);
	style->Colors[ImGuiCol_ButtonHovered] = ImColor(41, 40, 41, 255);

	style->Colors[ImGuiCol_Separator] = ImColor(70, 70, 70, 255);
	style->Colors[ImGuiCol_SeparatorActive] = ImColor(76, 76, 76, 255);
	style->Colors[ImGuiCol_SeparatorHovered] = ImColor(76, 76, 76, 255);

	style->Colors[ImGuiCol_FrameBg] = ImColor(37, 36, 37, 255);
	style->Colors[ImGuiCol_FrameBgActive] = ImColor(37, 36, 37, 255);
	style->Colors[ImGuiCol_FrameBgHovered] = ImColor(37, 36, 37, 255);

	style->Colors[ImGuiCol_Header] = ImColor(0, 0, 0, 0);
	style->Colors[ImGuiCol_HeaderActive] = ImColor(0, 0, 0, 0);
	style->Colors[ImGuiCol_HeaderHovered] = ImColor(46, 46, 46, 255);
}