#include "Person.h"
#include <iostream>
using namespace std;

Person::Person()			
{
	// Default Ctor
	this->first_name = "\0";							
	this->last_name = "\0";
}

Person::Person(string First_name, string Last_name)
{
	//Normal Ctor
	first_name = First_name;
	last_name = Last_name;
}
string Person::get_first_name() 
{
	//first_name Getter
	return this->first_name;
}

string Person::get_last_name() 
{
	//last_name Getter
	return this->last_name;
}
void Person::set_first_name(string new_first_name)
{
	//first_name Setter
	this->first_name = new_first_name;
}
void Person::set_last_name(string new_last_name)
{
	//last_name Setter
	this->last_name = new_last_name;
}
void Person::Person::print_obj()
{
	//Person type - Print object
	cout << "\tName: " << this->first_name << " " << this->last_name << endl;
}
Person::~Person() {
	//Dtor
}

