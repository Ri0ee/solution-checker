#pragma once

#include <string>

#include "gui.h"
#include "options.h"



class Instance
{
public:
	Instance() {}
	~Instance() {}

	bool Initialize(char file_location_[]);
	bool Run();
	void Shutdown();

private:
	Gui* m_gui_ptr = nullptr;
	OptionsManager* m_options_manager = nullptr;

	std::string m_current_dir;
};