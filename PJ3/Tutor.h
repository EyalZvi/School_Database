#pragma once
/* Assignment: 1
Author1: Eyal Zvi,
ID: 319067732
Author2: Saar Ben-Yochana,
ID: 313234155
*/
#include "Teacher.h"
#include "Class.h"
class Tutor: public Teacher  // Class with inherritence, 'has a' relationship with Class-pointer
{
private:					// Tutor attribute
	Class* classroom_ptr;	

public:						// Tutor methods
	Tutor();
	Tutor(string First_name, string Last_name, int Teaching_seniority, int Managing_seniority, vector<string> Subjects_arr, int Num_of_subjects,Class* Classroom_ptr);
	Class* get_class_ptr();
	void set_class_ptr(Class* Classroom_ptr);
	float get_salary();
	bool is_excellent();
	void print_obj();
	void fire_last_tutor() { this->classroom_ptr = nullptr; };
	~Tutor();
};

