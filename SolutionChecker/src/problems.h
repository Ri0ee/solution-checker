#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include <Windows.h>



struct Problem
{
	int m_id;
	int m_test_count;
	int m_memory_limit;
	double m_time_limit;
	std::string m_caption;
	std::string m_path;
	std::string m_folder_name;
	std::string m_input_file_name;
	std::string m_output_file_name;
	std::string m_description_file_name;
};

class ProblemManager
{
public:
	ProblemManager() {}
	~ProblemManager() {}

	bool Initialize(const std::string& path_to_problems_folder_);
	void Shutdown();
	void SearchForProblems(const std::string& path_to_problems_folder_);
	void ShowTaskDescription(int problem_id_);

	std::vector<Problem> GetProblemList() { return m_problem_list; }

private:
	std::string m_path;
	std::vector<Problem> m_problem_list;
};