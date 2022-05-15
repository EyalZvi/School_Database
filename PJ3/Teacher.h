#pragma once
/* Assignment: 1
Author1: Eyal Zvi,
ID: 319067732
Author2: Saar Ben-Yochana,
ID: 313234155
*/
#include "Worker.h"

class Teacher :virtual public Worker	// class with inherritance
{
private:
	vector<string> subjects_arr;		// Teacher attributes
	int num_of_subjects;
public:									// Teacher metods
	Teacher();
	Teacher(string First_name, string Last_name, int Teaching_seniority, int Managing_seniority, vector<string> Subjects_arr, int Num_of_subjects);
	const vector<string> get_subjects_arr();
	const int get_num_of_subjects();
	void set_subjects_arr(vector<string> Subjects_arr);
	void set_num_of_subjects(int Num_of_subjects);
	float get_salary();
	bool is_excellent();
	void print_subjects();
	void print_obj();
	virtual ~Teacher();

	//Overrides

	int get_teaching_seniority();   
	int get_managing_seniority();
	void set_teaching_seniority(int teaching_years);
	void set_managing_seniority(int managing_years);
	string get_first_name();
	string get_last_name(); // note: We go directly to Person class - no need to override in Worker Class
};

