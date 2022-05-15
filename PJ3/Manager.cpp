/* Assignment: 1
Author1: Eyal Zvi,
ID: 319067732
Author2: Saar Ben-Yochana,
ID: 313234155
*/
#include "Manager.h"

// Set Default Static Pointer
Manager* Manager::curr_manager = 0;

Manager::Manager(string first_name, string last_name, int teaching_seniority, int managing_seniority, string office_number) :
	AdministrationPersonal::AdministrationPersonal(first_name, last_name, teaching_seniority, managing_seniority, office_number)
{
    // Non-Teacher Manager Constructor
	Manager::curr_manager = this;
}

Manager::Manager(string first_name, string last_name, int teaching_seniority, int managing_seniority, string office_number, vector<string> subjects_arr, int num_of_subjects) :
	AdministrationPersonal::AdministrationPersonal(first_name, last_name, teaching_seniority, managing_seniority, office_number), Teacher::Teacher(first_name, last_name, teaching_seniority, managing_seniority, subjects_arr, num_of_subjects)
{
    // Teacher Manager Constructor
	Manager::curr_manager = this;
}
Manager *Manager::appointment_manager(string Firstname, string Lastname, int Teaching_seniority, int Managing_seniority, string Office_Number, vector<string> Subjects_arr, int Num_of_subjects)
{
    // Singleton 'Get Instance' Implement
	if (curr_manager) {
		cout << "\tAnother manager is still in office, appointment cannot be done." << endl;
		return nullptr;
	}
	if (Num_of_subjects == 0) {
	    // Non-Teacher Manager Constructor Call
		Manager* curr_manager = new Manager(Firstname, Lastname, Teaching_seniority, Managing_seniority, Office_Number);
		return curr_manager;
	}
	if (Num_of_subjects > 0) {
        // Teacher Manager Constructor Call
		Manager* curr_manager = new Manager(Firstname, Lastname, Teaching_seniority, Managing_seniority, Office_Number, Subjects_arr, Num_of_subjects);
		return curr_manager;
	}
	return nullptr;
}
Manager* Manager::current_manger()
{
    // Current Manager Getter
	return Manager::curr_manager;
}
void Manager::print_obj()
{
    // Manager Print Obj Implement
	AdministrationPersonal::print_obj();
	cout << "\tSalary: " << this->get_salary() << "$" << endl;
	if (this->get_num_of_subjects() > 0) {
		cout << "\tThis manager is also a teacher who teaches " << this->get_num_of_subjects() << " subjects" << endl;
		this->print_subjects();
	}
}

float Manager::get_salary()
{
    // Manager Get Salary Implement
	if (this->get_teaching_seniority() == 0)
		// Non-Teaching Manager Salary Function: Basis x 2 + Managment_Years x 500
		return float(this->basis * 2 + this->get_managing_seniority() * 500);
	else
		// Teaching Manager Salary Function: Teacher salary + Basis x 2 + Managment_Years x 500
		return this->Teacher::get_salary() + float(this->basis * 2 + this->get_managing_seniority() * 500);
}

bool Manager::is_excellent()
{	// Manager isExcellent Implement
    // Excellent manager defined as one that his managing seniority is greater than 3 years.
	if (this->get_managing_seniority() > 3)
		return true;
	return false;
}

Manager::~Manager()
{
    // Manager Destructor
}
