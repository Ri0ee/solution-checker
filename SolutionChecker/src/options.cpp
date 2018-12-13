#include "options.h"



bool OptionsManager::GetOptions()
{
	if (m_path_to_options_file.empty())
	{
		std::cerr << "Cannot find options file, path was not set" << std::endl;
		return false;
	}

	std::fstream in_file;
	in_file.open(m_path_to_options_file, std::ios::in);
	if (!in_file.is_open())
	{
		std::cerr << "Cannot open options file, setting default settings" << std::endl;
		SetDefaults();
		return false;
	}

	std::string line;
	while (std::getline(in_file, line))
	{
		int delim_pos = line.find_first_of(":");
		std::string param_name = line.substr(0, delim_pos);
		
		if (param_name == "WindowPosX")
		{
			std::stringstream param_value(line.substr(delim_pos + 1, line.size()));
			float window_pos_x = 0;
			param_value >> window_pos_x;
			m_window_pos_x = window_pos_x;
			continue;
		}

		if (param_name == "WindowPosY")
		{
			std::stringstream param_value(line.substr(delim_pos + 1, line.size()));
			float window_pos_y = 0;
			param_value >> window_pos_y;
			m_window_pos_y = window_pos_y;
			continue;
		}

		if (param_name == "WorkingDir")
		{
			m_working_dir = line.substr(delim_pos + 1, line.size());
			continue;
		}

		if (param_name == "LastProblem")
		{
			m_last_problem = line.substr(delim_pos + 1, line.size());
			continue;
		}

		if (param_name == "ProblemDir")
		{
			m_problem_dir = line.substr(delim_pos + 1, line.size());
			continue;
		}

		if (param_name == "LastExecutableDir")
		{
			m_last_exe_dir = line.substr(delim_pos + 1, line.size());
			continue;
		}

		if (param_name == "UseOnlyOneTest")
		{
			std::string temp_param_value = line.substr(delim_pos + 1, line.size());
			if (temp_param_value == "true")
			{
				m_use_only_one_test = true;
				m_use_multiple_tests = false;
			}
			else
			{
				m_use_only_one_test = false;
				m_use_multiple_tests = true;
			}
			continue;
		}

		if (param_name == "Theme")
		{
			m_theme = line.substr(delim_pos + 1, line.size());
			continue;
		}
	}

	in_file.close();
	
	return true;
}

void OptionsManager::SetDefaults()
{
	m_window_pos_x = 100;
	m_window_pos_y = 100;
	m_last_exe_dir = "C:\\";
	m_last_problem = "";
	m_problem_dir = "C:\\";
	m_working_dir = "C:\\";
	m_theme = "none";
	m_use_only_one_test = false;
}

bool OptionsManager::UpdateOptionsFile()
{
	if (m_path_to_options_file.empty())
	{
		std::cerr << "Cannot update options file, creating new one" << std::endl;
		return false;
	}

	std::fstream out_file;
	out_file.open(m_path_to_options_file, std::ios::out);
	if (!out_file.is_open())
	{
		std::cerr << "Cannot open or create options file to update settings" << std::endl;
		return false;
	}

	out_file << "WindowPosX:" << m_window_pos_x << "\n";
	out_file << "WindowPosY:" << m_window_pos_y << "\n";
	out_file << "WorkingDir:" << m_working_dir << "\n";
	out_file << "ProblemDir:" << m_problem_dir << "\n";
	out_file << "LastExecutableDir:" << m_last_exe_dir << "\n";
	out_file << "LastProblem:" << m_last_problem << "\n";
	out_file << "UseOnlyOneTest:" << (m_use_only_one_test ? "true" : "false") << "\n";
	out_file << "Theme:" << m_theme << "\n";

	out_file.close();

	return true;
}