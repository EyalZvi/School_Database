#pragma once
/* Assignment: 1
#include <iostream>
#include <string>
using namespace std;	
class Person			// Abstract class
{
private:
	string first_name;									// Person attributes
	string last_name;

public:													// Person methods
	Person();	
	Person(string First_name, string Last_name);
	virtual string get_first_name() = 0;
	virtual string get_last_name() = 0;
	virtual void set_first_name(string new_first_name);
	virtual void set_last_name(string new_last_name);
	virtual bool is_excellent(){ return false; };
	virtual void print_obj() = 0;
	virtual ~Person();
};
