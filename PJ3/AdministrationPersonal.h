#pragma once
#include "Worker.h"

// Virtual Inheritance from: Worker Class
class AdministrationPersonal : virtual public Worker
{

private:
    // AdministrationPersonal Field
	string office_number;

public:
    // Constructors
	AdministrationPersonal();
	AdministrationPersonal(string First_name, string Last_name, int Teaching_seniority, int Manage_seniority, string Office_Number);
	// AdministrationPersonal Get & Set
	virtual const string get_office_num() = 0;
	virtual  void set_office_num(string New_Office_Number) = 0;
	// AdministrationPersonal - Worker Methods Declaration
	virtual float get_salary() { return 0; };
	virtual bool is_excellent(){ return false; };
	virtual void print_obj() = 0;
	// AdministrationPersonal Virtual Destructor
	virtual ~AdministrationPersonal();
};
