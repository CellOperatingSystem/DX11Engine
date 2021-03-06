#pragma once
#include "window/window.h"
#include "gui/engine_gui.h"
#include "timer.h"

class EngineApplication : public Window
{
private:
	std::vector<std::unique_ptr<EngineGUI>> engineGUIs;
	Timer frameTimer;

public:
	EngineApplication();

public:
	void Run();

private:
	void DrawGUI();
	void BindBackbuffer();
};