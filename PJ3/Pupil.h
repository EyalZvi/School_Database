#pragma once
/* Assignment: 1
Author1: Eyal Zvi,
ID: 319067732
Author2: Saar Ben-Yochana,
ID: 313234155
*/
#include <vector>
#include "Person.h"
class Pupil : public Person
{
private:
	vector<int> grades_arr;			// Pupil attributes
	char layer;
	int class_num;
public:								// Pupil Methods
	Pupil();
	Pupil(string First_name, string Last_name, char Layer, int Class_num, vector<int> Grades_arr);
	const char get_layer();
	const int get_class_num();
	void set_layer(char Layer);
	void set_class_number(int Class_num);
	const vector<int> get_grades_arr();
	void set_grades_arr(vector<int> Grades_arr);
	bool is_excellent();
	void print_obj();
	float get_avg();
	virtual ~Pupil();

	//Overrides

	string get_first_name();
	string get_last_name();
};