/* Assignment: 1
Author1: Eyal Zvi,
ID: 319067732
Author2: Saar Ben-Yochana,
ID: 313234155
*/

#include "Teacher.h"

Teacher::Teacher() :
	Worker::Worker()
	//Default Ctor
{
	this->subjects_arr;
	this->num_of_subjects = 0;
}

Teacher::Teacher(string First_name, string Last_name, int Teaching_seniority, int Managing_seniority, vector<string> Subjects_arr, int Num_of_subjects) :
	Worker::Worker(First_name,Last_name,Teaching_seniority,Managing_seniority)
{
	//Normal Ctor
	this->set_first_name(First_name);
	this->set_last_name(Last_name);
	this->set_teaching_seniority(Teaching_seniority);
	this->set_managing_seniority(Managing_seniority);
	this->subjects_arr = Subjects_arr;
	this->num_of_subjects = Num_of_subjects;

}

const vector<string> Teacher::get_subjects_arr()
{
	//subjects_arr Getter
	return this->subjects_arr;
}

const int Teacher::get_num_of_subjects()
{
	//num_of_subjects Getter
	return this->num_of_subjects;
}

void Teacher::set_subjects_arr(vector<string> Subjects_arr)
{
	//subjects_arr Setter
	this->subjects_arr = Subjects_arr;
}

void Teacher::set_num_of_subjects(int Num_of_subjects)
{
	//num_of_subjects Setter
	this->num_of_subjects = Num_of_subjects;
}

float Teacher::get_salary()
{
	// Salary calculation - Teacher type : [Basis*(1 + (number of subjects)/10) + 300 * teaching_seniority]
	return float(Worker::basis * (1 + (this->num_of_subjects) / 10) + 300 * this->get_teaching_seniority());
}

bool Teacher::is_excellent()
{
	//check if teacher is excellent
	if(this->num_of_subjects >= 5)			// by checking number of subjects that he/she is teaching 
		return true;
	return false;
}

void Teacher::print_subjects()
{
	//Print subjects of teacher
	int i;
	if (this->num_of_subjects == 0) {
		cout << "\tThis teacher does not teach any subjects." << endl;
		return;
	}

	cout << "\tTeacher subject list including: " << endl;
	cout << "\t";
	for (i = 0; i < this->num_of_subjects-1; i++)
		cout << this->subjects_arr[i] << ", ";
	cout << this->subjects_arr[i] << endl;
}

void Teacher::print_obj()
{
	//Teacher type - Print object
	Worker::print_obj();
	cout << "\tSalary: " << this->get_salary() << "$" << endl;
	cout << "\tThis teacher teaches " << this->num_of_subjects << " subjects" << endl;
	this->print_subjects();
}

Teacher::~Teacher()
{
	//Dtor
	subjects_arr.clear();
}

//Overrides

int Teacher::get_teaching_seniority() {
	return Worker::get_teaching_seniority();
}

int Teacher::get_managing_seniority() {
	return Worker::get_managing_seniority();
}

void Teacher::set_teaching_seniority(int teaching_years)
{
	Worker::set_teaching_seniority(teaching_years);
}

void Teacher::set_managing_seniority(int managing_years)
{
	Worker::set_managing_seniority(managing_years);
}

string Teacher::get_first_name()
{
	return Person::get_first_name();
}

string Teacher::get_last_name()
{
	return Person::get_last_name();
}
