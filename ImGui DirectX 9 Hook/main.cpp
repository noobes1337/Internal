#include "includes.h"
#include "phook.h"
#include "overlay.h"
#include <string>
#include "unbanner.h"
HWND window;
void* pDevice[119];
PTR EndSceneAddress;
EndScene oEndScene;
WNDPROC oWndProc;
using namespace std;
void InitImGui(LPDIRECT3DDEVICE9 device)
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX9_Init(device);
}

bool initialized = false;
long __stdcall PHook::hkEndScene(LPDIRECT3DDEVICE9 device)
{
	if (!initialized)
	{
		InitImGui(device);
		initialized = true;
	}
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
	colors[ImGuiCol_ChildBg] = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
	colors[ImGuiCol_Border] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.20f, 0.21f, 0.22f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.40f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.18f, 0.18f, 0.18f, 0.67f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.29f, 0.29f, 0.29f, 1.00f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.94f, 0.94f, 0.94f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.44f, 0.44f, 0.44f, 0.40f);
	colors[ImGuiCol_Tab] = ImVec4(0.44f, 0.44f, 0.44f, 0.40f);
	colors[ImGuiCol_TabActive] = ImVec4(0.44f, 0.44f, 0.44f, 0.40f);
	colors[ImGuiCol_TabHovered] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.46f, 0.47f, 0.48f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.42f, 0.42f, 0.42f, 1.00f);
	colors[ImGuiCol_Header] = ImVec4(0.70f, 0.70f, 0.70f, 0.31f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.70f, 0.70f, 0.70f, 0.80f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.48f, 0.50f, 0.52f, 1.00f);
	colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.72f, 0.72f, 0.72f, 0.78f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(0.91f, 0.91f, 0.91f, 0.25f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.81f, 0.81f, 0.81f, 0.67f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.46f, 0.46f, 0.46f, 0.95f);
	colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
	colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
	colors[ImGuiCol_PlotHistogram] = ImVec4(0.73f, 0.60f, 0.15f, 1.00f);
	colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.87f, 0.87f, 0.87f, 0.35f);
	colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
	colors[ImGuiCol_NavHighlight] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
	colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	static bool no_move = false;
	static char show_pussy = 0;
	static bool no_background = false; static bool no_resize = true;
	ImGuiWindowFlags window_flags = 0;
	if (no_move)            window_flags |= ImGuiWindowFlags_NoMove;
	if (no_resize)          window_flags |= ImGuiWindowFlags_NoResize;
	if (no_background)      window_flags |= ImGuiWindowFlags_NoBackground;
	ImGui::Begin("Internal", NULL, window_flags | ImGuiWindowFlags_NoCollapse);
	static char ip[20] = "growtopia1.com";
	static char port[10] = "17092";
	static char flags[10] = "lk";
	if (GetAsyncKeyState(VK_F6)) {
		ImVec2 lastpos;
		if (show_pussy == 1) {
			lastpos = ImGui::GetWindowPos();
			show_pussy = 0;
			ImGui::SetWindowPos(ImVec2(1005, -362));
			no_background = true;
			no_move = true;
			Sleep(120);
		}
		else {
			ImGui::SetWindowPos(lastpos);
			show_pussy = 1;
			no_background = false;
			no_move = false;
			Sleep(120);
		}
	}
	ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
	if (ImGui::BeginTabBar("Tabs", tab_bar_flags))
	{
		if (ImGui::BeginTabItem("Executor"))
		{
			ImGui::Text("Executor");
			ImGuiTabBarFlags tab_bar_flags = ImGuiTabBarFlags_None;
			if (ImGui::BeginTabBar("debugtab", tab_bar_flags))
			{
				if (ImGui::BeginTabItem("debug"))
				{
					static char text[1024 * 16];
					static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput;
					flags |= ImGuiInputTextFlags_ReadOnly;
					ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 16), flags);
					ImGui::EndTabItem();
					const char* stringthatchanges = "Press F6 to hide/show the Internal window.";
					ImGui::Text(stringthatchanges);
				}
				if (ImGui::BeginTabItem("executor"))
				{
					static char text[1024 * 16];
					static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput;

					ImGui::InputTextMultiline("##source", text, IM_ARRAYSIZE(text), ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 16), flags);
					if (ImGui::Button("Execute")) {

					}
					static char str0[128];
					ImGui::InputText("", str0, IM_ARRAYSIZE(str0));
					static int i0 = 2;
					ImGui::InputInt("packet type", &i0);
					if (ImGui::Button("send packet")) {


					}
					ImGui::EndTabItem();
				}
				ImGui::EndTabBar();
			}
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Cheats"))
		{
			ImGui::Text("Cheats");
			if (ImGui::Button("sendPacket action|respawn")) {
				typedef void(__cdecl * _contoutf)(const char* string, ...);
				//_contoutf contoutf = (_contoutf)0x46b060;
				//contoutf((char*)"action|respawn");

				//one line method:
				((void(__cdecl*)(const char* string))0x19ECDDA4128)("action|respawn");
				//	((void(__cdecl)(const char string))0x46b060)("action|respawn");
			}
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("Misc"))
		{
			ImGui::Text("Misc");
			if (ImGui::CollapsingHeader("Server Connector"))
			{
				ImGui::Text("Server Connector");
				ImGui::InputText("Server", ip, IM_ARRAYSIZE(ip));
				ImGui::InputText("Port", port, IM_ARRAYSIZE(port));


				if (ImGui::Button("Connect")) {
					DWORD oldProtect = 0;
					DWORD OLDPROTECT;
					int oldprot = 0;
					LPVOID entrys = (LPVOID)((uintptr_t)GetModuleHandle(NULL) + 0x44B6A8);
					HANDLE as = GetCurrentProcess();
					VirtualProtectEx(as, entrys, sizeof(ip), PAGE_EXECUTE_READWRITE, &OLDPROTECT);

					memcpy(entrys, ip, sizeof(ip));
					LPVOID entryss = (LPVOID)((uintptr_t)GetModuleHandle(NULL) + 0x465995);
					HANDLE ass = GetCurrentProcess();
					VirtualProtectEx(ass, entryss, sizeof(port), PAGE_EXECUTE_READWRITE, &OLDPROTECT);

					memcpy(entryss, port, sizeof(port));
				}
			}
			if (ImGui::CollapsingHeader("Flag Changer"))
			{
				ImGui::Text("Flag Changer");
				ImGui::InputText("flag name", flags, IM_ARRAYSIZE(flags));
				if (ImGui::Button("change flag")) {
					DWORD oldProtect = 0;
					DWORD OLDPROTECT;
					int oldprot = 0;
					LPVOID entrys = (LPVOID)((uintptr_t)GetModuleHandle(NULL) + 0x44B6A8);
					HANDLE as = GetCurrentProcess();
					VirtualProtectEx(as, entrys, sizeof(flags), PAGE_EXECUTE_READWRITE, &OLDPROTECT);
					memcpy(entrys, flags, sizeof(flags));
				}
			}
			if (ImGui::CollapsingHeader("Unbanner"))
			{
				ImGui::Text("Unbanner");
				if (ImGui::Button("Mac Unban")) {
					macunban();
				}
				ImGui::SameLine();
				if (ImGui::Button("Rid Unban")) {
					ridunban();
				}

			}
			ImGui::EndTabItem();
		}
		if (ImGui::BeginTabItem("settings"))
		{
			ImGui::Text("Overlay Settings");
			if (ImGui::Button("hide overlay##3")) {
				removeOverlay();
			}
			if (ImGui::Button("show overlay##2")) {
				initOverlay();
			}
			ImGui::Separator();
			ImGui::EndTabItem();
		}
		ImGui::EndTabBar();
	}


	ImGui::End();

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

	return oEndScene(device);
}


extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT __stdcall PHook::WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hMod);
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)PHook::Init, hMod, 0, nullptr);
		initOverlay();
		break;
	case DLL_PROCESS_DETACH:
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)PHook::Shutdown, hMod, 0, nullptr);
		break;
	}
	return TRUE;
}