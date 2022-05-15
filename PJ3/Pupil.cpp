/* Assignment: 1
Author1: Eyal Zvi,
ID: 319067732
Author2: Saar Ben-Yochana,
ID: 313234155
*/
#include "Person.h"
#include "Pupil.h"
#include <iostream>
#include <vector>

Pupil::Pupil() : 
	Person::Person()
{
	//Default Ctor
	this->layer = '\0';
	this->class_num = 0;
	this->grades_arr;
}

Pupil::Pupil(string First_name, string Last_name,char Layer, int Class_num, vector<int> Grades_arr) :
	Person::Person(First_name, Last_name)
{
	//Normal Ctor
	this->layer = Layer;
	this->class_num = Class_num;
	this->grades_arr = Grades_arr;
}

const char Pupil::get_layer()
{
	//layer Getter
	return this->layer;
}

const int Pupil::get_class_num()
{
	//class_num Getter
	return this->class_num;
}

void Pupil::set_layer(char Layer)
{
	//layer Setter
	this->layer = Layer;
}

void Pupil::set_class_number(int Class_num)
{
	//class_num Setter
	this->class_num = Class_num;
}

const vector<int> Pupil::get_grades_arr()
{
	//class_num Getter
	return this->grades_arr;
}

void Pupil::set_grades_arr(vector<int> Grades_arr)
{
	//class_num Setter
	this->grades_arr = Grades_arr;
}

bool Pupil::is_excellent()
{
	//check if pupil is excellent
	if (this->get_avg() <= 85)								// if avg <=85 not excellent - return flase
		return false;

	if (this->grades_arr.size() == 0) return false;
	for (int i = 0; i < this->grades_arr.size(); i++) {	    // if found grade <65 not excellent - return flase
		if (grades_arr[i] < 65)
			return false;
	}
	return true;											// else excellent - return true
}

void Pupil::print_obj()
{
	//Pupil type - Print object
	int i;
	Person::print_obj();
	cout << "\tClass: " << this->layer << " " << this->class_num << endl;
	if (this->grades_arr.size() != 0) {
		cout << "\tGrades: ";

		for (i = 0; i < this->grades_arr.size() - 1; i++)
			cout << this->grades_arr[i] << ", ";
		cout << this->grades_arr[i] << endl;
	}
	else {
		cout << "\tNo grades" << endl;
	}
	cout << "\tAverage: " << this->get_avg() << endl;
	if (this->is_excellent())
		cout << "\tIs an excellent pupil!" << endl;
	else
		cout << "\tIs not an excellent pupil" << endl;
}

	float Pupil::get_avg()
	{
		// Get Pupil's average
		float avg = 0;
		int i;
		if (this->grades_arr.size() == 0) {
			return avg;
		}
		for (i = 0; i < this->grades_arr.size(); i++) {
				avg += grades_arr[i];
		}
		avg /= grades_arr.size();
		return avg;
	}

	Pupil::~Pupil()
	{
		//Dtor
		this->grades_arr.clear();
	}

	//Overrides

	string Pupil::get_first_name() {
		return Person::get_first_name();
	}

	string Pupil::get_last_name() {
		return Person::get_last_name();
	}