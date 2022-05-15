/* Assignment: 1
Author1: Eyal Zvi,
ID: 319067732
Author2: Saar Ben-Yochana,
ID: 313234155
*/
#include "AdministrationPersonal.h"

AdministrationPersonal::AdministrationPersonal(): 
	Worker::Worker()
{
	// AdminstraionPersonal Default Constructor
	this->office_number = '0';
}

AdministrationPersonal::AdministrationPersonal(string First_name, string Last_name, int Teaching_seniority, int Manage_seniority, string Office_Number) :
	Worker::Worker(First_name, Last_name, Teaching_seniority, Manage_seniority)
{
	// AdministrationsPersonal Regular Constructor
	this->Person::set_first_name(First_name);
	this->Person::set_last_name(Last_name);
	this->Worker::set_teaching_seniority(Teaching_seniority);
	this->Worker::set_managing_seniority(Manage_seniority);
	this->office_number = Office_Number;


}

const string AdministrationPersonal::get_office_num()
{
	// AdministrationPersonal Office Number Getter
	return this->office_number;
}

void AdministrationPersonal::set_office_num(string New_Office_Number)
{
	// AdministrationPersonal Office Number Setter
	this->office_number = New_Office_Number;
}

void AdministrationPersonal::print_obj() {
	// AdministrationPersonal type - Print object
	Worker::print_obj();
	cout << "\tOffice Number: " << this->office_number << endl;
}


AdministrationPersonal::~AdministrationPersonal()
{
	// AdministrationPersonal Destructor
}
