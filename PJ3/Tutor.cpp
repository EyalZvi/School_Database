/* Assignment: 1
Author1: Eyal Zvi,
ID: 319067732
Author2: Saar Ben-Yochana,
ID: 313234155
*/
#include "Tutor.h"

Tutor::Tutor() :
	Teacher::Teacher()
{
	//Default Ctor
	this->classroom_ptr = nullptr;
}

Tutor::Tutor(string First_name, string Last_name, int Teaching_seniority, int Managing_seniority, vector<string> Subjects_arr, int Num_of_subjects, Class* Classroom_ptr) :
	Teacher::Teacher(First_name, Last_name, Teaching_seniority,Managing_seniority,Subjects_arr, Num_of_subjects)
{
	//Normal Ctor
	this->classroom_ptr = Classroom_ptr;
}

Class* Tutor::get_class_ptr()
{
	//class_ptr Getter
	return this->classroom_ptr;
}

void Tutor::set_class_ptr(Class* Classroom_ptr)
{
	//class_ptr Setter
	this->classroom_ptr = Classroom_ptr;
}

float Tutor::get_salary()
{
	// Salary calculation - Tutor type
	return Teacher::get_salary() + 1000;
}

bool Tutor::is_excellent()
{
	// check if Tutor is excellent

	if ((*this->classroom_ptr).get_num_of_pupils() == 0)
		return false;
	int excellent_pupil_counter = 0;
	for (int i = 0; i < (*this->classroom_ptr).get_num_of_pupils(); i++) {
		if ((*this->classroom_ptr)[i].is_excellent())						// if Pupil is excellent +1 to excellent_pupil_counter
			excellent_pupil_counter++;
	}
	float div = float(excellent_pupil_counter / (*this->classroom_ptr).get_num_of_pupils());  // divide excellent pupils by  
	if (div >= 0.5)																			  // of pupils in class and check
		return true;																		  // if div >=0.5 - more than half are excllent
	return false;																			  // return true/false accordingly 
}

void Tutor::print_obj()
{
	//Tutor type - Print object
	Worker::print_obj();
	cout << "\tSalary: " << this->get_salary() << "$" << endl;
	cout << "\tThis teacher teaches " << this->get_num_of_subjects() << " subjects" << endl;
	this->print_subjects();
	if (this->classroom_ptr == nullptr)
		return;
	cout << "\tTutor's class: " << (*this->classroom_ptr).get_layer() << " " << (*this->classroom_ptr).get_class_num() << endl;
	cout << "\t-------------------------------------------" << endl;
	cout << "\tClass pupil list: ";
	if ((*this->classroom_ptr).get_num_of_pupils() == 0) {
		cout << "Empty class" << endl;
	cout << "\t-------------------------------------------" << endl;
		return;
	}
	cout << endl;
	for (int i = 0; i < (*this->classroom_ptr).get_num_of_pupils(); i++) {
		cout << endl;
		cout<<"\tPupil #"<< i+1 << " Details: " <<endl;
		(*this->classroom_ptr)[i].print_obj(); //Pupil printing
	}
	cout << "\t-------------------------------------------" << endl;
}

Tutor::~Tutor()
{
	//Dtor
}


