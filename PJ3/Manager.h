#pragma once
/* Assignment: 1
Author1: Eyal Zvi,
ID: 319067732
Author2: Saar Ben-Yochana,
ID: 313234155
*/
#include "AdministrationPersonal.h"
#include "Teacher.h"
#include "Tutor.h"
#include <vector>

// Inheritance from : AdministrationPersonal and Teacher Classes.
class Manager : public AdministrationPersonal, public Teacher
{
private:
	static Manager *curr_manager;   // Static pointer to current manager
	Manager() {};                   // Default Constructor
	// Non-Teacher Manager Constructor
	Manager(string first_name, string last_name, int teaching_seniority, int managing_seniority, string office_number);
	// Teacher Manager Constructor
	Manager(string first_name, string last_name, int teaching_seniority, int managing_seniority, string office_number, vector<string> subjects_arr, int num_of_subjects);

public:
	virtual ~Manager();             // Virtual Destructor
	// Singleton: Get-Instance Manager method
	static Manager *appointment_manager(string first_name, string last_name, int teaching_seniority, int managing_seniority, string Office_Number, vector<string> subjects_arr = vector<string>(), int num_of_subjects = 0);
	// Current Manager Pointer Getter
	static Manager *current_manger();
	// Manager - Worker methods declarations
	void print_obj();
	float get_salary();
	bool is_excellent();


	//Overrides

	const string get_office_num() { return AdministrationPersonal::get_office_num(); };
	void set_office_num(string Office_Num) { AdministrationPersonal::set_office_num(Office_Num); };
	int get_teaching_seniority() { return Worker::get_teaching_seniority(); };
	int get_managing_seniority() { return Worker::get_managing_seniority(); };
	void set_teaching_seniority(int teaching_years) { Worker::set_teaching_seniority(teaching_years); };
	void set_managing_seniority(int managing_years) { Worker::set_managing_seniority(managing_years); };
	string get_first_name() { return Person::get_first_name(); };
	string get_last_name() { return Person::get_last_name(); };
};

