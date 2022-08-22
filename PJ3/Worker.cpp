#include "Worker.h"

int Worker::basis = 25;

Worker::Worker() :				// Abstract class with inherritance
	Person::Person()
{
	//Default Ctor
	this->teaching_seniority = 0;
	this->managing_seniority = 0;
}

Worker::Worker(string First_name, string Last_name, int Teaching_seniority, int Managing_seniority) :
	Person::Person(First_name, Last_name)
{
	//Normal Ctor
	this->teaching_seniority = Teaching_seniority;
	this->managing_seniority = Managing_seniority;
}

int Worker::get_teaching_seniority()
{
	//teaching_seniority Getter
	return this->teaching_seniority;
}

int Worker::get_managing_seniority()
{
	//managing_seniority Getter
	return this->managing_seniority;
}

void Worker::set_teaching_seniority(int teaching_years)
{
	//teaching_seniority Setter
	this->teaching_seniority = teaching_years;
}

void Worker::set_managing_seniority(int managing_years)
{
	//managing_seniority Setter
	this->managing_seniority = managing_years;
}

void Worker::print_obj() {
	//Worker type - Print object
	Person::print_obj();
	if (this->teaching_seniority > 0)
		cout << "\tTeaching seniority: " << this->teaching_seniority << endl;
	if (this->managing_seniority > 0)
		cout << "\tManaging seniority: " << this->managing_seniority << endl;
}

Worker::~Worker()
{
	//Dtor
}


