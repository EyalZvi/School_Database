#include "Class.h"

Class::Class()
{
	//Default Ctor
	this->layer = '\0';
	this->class_num = 0;
	this->num_of_pupils = 0;
	this->pupils_ptr_arr;
	this->tutor_ptr = nullptr;
}

Class::Class(char Layer, int Class_num, vector<Pupil*> Pupils_ptr_arr, int Num_of_pupils, Tutor* Tutor_ptr)
{
	//Regular Ctor
	this->layer = Layer;
	this->class_num = Class_num;
	this->num_of_pupils = Num_of_pupils;
	this->pupils_ptr_arr = Pupils_ptr_arr;
	this->tutor_ptr = Tutor_ptr;
}

void Class::add_Pupil(Pupil* Pupil_ptr)
{
	// adding a Pupil pointer to the class vector 
	this->pupils_ptr_arr.push_back(Pupil_ptr);
	this->num_of_pupils++;
}

Pupil Class::operator[](int index)
{
	// overloading the [] operator to return the CONTENT of the info directed by the Pupil-pointer in -> index   
	if (index >= this->num_of_pupils || index < 0) {
		cout << "\tInvlaid Student Index" << endl;
		return Pupil();  // Empty Pupil! - Will be checked outside to see if a 'real' Pupil was returned
	}
	return *(this->pupils_ptr_arr[index]); // Content of Pupil pointer numbered index 
}

int Class::get_num_of_pupils()
{
	//Helper - num_of_pupils Getter 
	return this->num_of_pupils;
}

char Class::get_layer()
{
	//Helper - layer Getter 
	return this->layer;
}

int Class::get_class_num()
{
	//Helper - class_num Getter 
	return this->class_num;
}

void Class::print_class_pupils()
{
	//Helper - print_class_pupils
	for (int i = 0; i < this->num_of_pupils; i++) {
		this->pupils_ptr_arr[i]->print_obj();
		cout << endl;
	}
}

void Class::set_Tutor_ptr(Tutor* tut_ptr)
{
    // Class's Tutor setter
	this->tutor_ptr = tut_ptr;
}


vector<Pupil*> Class::get_pupils_ptr_arr()
{
	//Helper - get_pupils_ptr_arr
	return this->pupils_ptr_arr;
}

Class::~Class()
{
	//Dtor
	this->pupils_ptr_arr.clear();
}

