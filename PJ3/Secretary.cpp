#include "Secretary.h"

Secretary::Secretary()
{	// Default Secretary Constructor 
	this->num_of_children = 0;
}

Secretary::Secretary(string first_name, string last_name, int teaching_seniority, int managing_seniority, string office_number, int Num_of_children) :
	AdministrationPersonal::AdministrationPersonal(first_name, last_name, teaching_seniority, managing_seniority, office_number)
{	// Regular Secretary Constructor
	this->num_of_children = Num_of_children;
}

float Secretary::get_salary()
{
	// Secretary Salary Function: basis + number_of_childrens x 200
	return float(basis + num_of_children * 200);
}

bool Secretary::is_excellent()
{
	// Excellent secretary defined as one that has managing seniority which is greater than 10
	if (this->get_managing_seniority() > 10)
		return true;
	return false;
}

void Secretary::print_obj()
{
	// Secretary type - Print object
	AdministrationPersonal::print_obj();
	cout << "\tSalary: " << this->get_salary() << "$" << endl;
	cout << "\tNumber of Children: " << this->num_of_children << endl;
}

Secretary::~Secretary()
{
	// Secretary Distructor
}
