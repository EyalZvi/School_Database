#pragma once
#include <vector>
#include "Person.h"

class Worker : public Person		// Abstract class with inherritance
{
private:							// Worker attributes
	int teaching_seniority;
	int managing_seniority;
public:								// Worker methods
	static int basis;
	Worker();
	Worker(string First_name, string Last_name, int Teaching_seniority, int Managing_seniority);
	virtual int get_teaching_seniority() = 0;
	virtual int get_managing_seniority() = 0;
	virtual void set_teaching_seniority(int teaching_years) = 0;
	virtual void set_managing_seniority(int managing_years) = 0;
	virtual float get_salary() { return 0; };
	virtual void print_obj() = 0;
	virtual ~Worker();


};

