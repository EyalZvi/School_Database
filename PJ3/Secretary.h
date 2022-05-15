#pragma once
/* Assignment: 1
Author1: Eyal Zvi,
ID: 319067732
Author2: Saar Ben-Yochana,
ID: 313234155
*/
#include "AdministrationPersonal.h"
class Secretary	: public AdministrationPersonal
{
private:
	int num_of_children;
public:
	Secretary();
	Secretary(string First_name, string Last_name, int Teaching_seniority, int Managing_seniority, string Office_number, int Num_of_children);
	~Secretary();
	float get_salary();
	bool is_excellent();
	void print_obj();


	//Overrides

	const string get_office_num() { return AdministrationPersonal::get_office_num(); };
	void set_office_num(string Office_Num) { AdministrationPersonal::set_office_num(Office_Num); };
	int get_teaching_seniority() { return Worker::get_teaching_seniority(); };
	int get_managing_seniority() { return Worker::get_managing_seniority(); };
	void set_teaching_seniority(int teaching_years) { Worker::set_teaching_seniority(teaching_years); };
	void set_managing_seniority(int managing_years) { Worker::set_managing_seniority(managing_years); };
	string get_first_name() { return Person::get_first_name(); };
	string get_last_name() { return Person::get_last_name(); };

	// note: We go directly to Person class - no need to override in Worker Class
};

