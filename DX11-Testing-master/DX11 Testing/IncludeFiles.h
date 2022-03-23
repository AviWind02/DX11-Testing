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
#include <timeapi.h>
#include <time.h>
#pragma comment(lib, "secur32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dmoguids.lib")
#pragma comment(lib, "wmcodecdspuuid.lib")
#pragma comment(lib, "msdmo.lib")
#pragma comment(lib, "Strmiids.lib")
//Menu Stuff
#include "UI.h"

#include "Normal UI.h"
#include "Normal Menu.h"

#include "Simple Menu.h"
#include "Simple UI.h"
