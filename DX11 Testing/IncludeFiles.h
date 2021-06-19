#pragma once
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_internal.h"
#include "d3d11.h"
#pragma comment(lib, "d3d11.lib")
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>
#include <sstream>
#include <thread>
#include <vector>
#include <iostream>
#include <Windows.h>
#include <consoleapi.h>

//Menu Stuff
#include "Normal UI.h"
#include "Normal Menu.h"