#pragma once
#include "Pupil.h"
class Tutor;

class Class			// Class with 'has a' relationship with Tutor-pointer and Vector of Pupil-pointers
{
private:						// Class attributes
	char layer;
	int class_num;
	vector<Pupil*> pupils_ptr_arr;
	int num_of_pupils;
	Tutor* tutor_ptr;

public:							// Class methods
	Class();
	Class(char Layer, int Class_num, vector<Pupil*> Pupils_ptr_arr, int Num_of_pupils, Tutor* Tutor_ptr);
	void add_Pupil(Pupil* Pupil_ptr);
	Pupil operator [](int index);
	~Class();

	int get_num_of_pupils(); // Helper methods - getters and print_class_pupils
	char get_layer();
	int get_class_num();
	vector<Pupil*> get_pupils_ptr_arr();
	void print_class_pupils();
	void set_Tutor_ptr(Tutor* tut_ptr);
	Tutor* get_Tutor_ptr() { return this->tutor_ptr; };

};
