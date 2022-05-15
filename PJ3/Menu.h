#pragma once
/* Assignment: 1
Author1: Eyal Zvi,
ID: 319067732
Author2: Saar Ben-Yochana,
ID: 313234155
*/
#include "VecAnalyser.h"
#include "VecAnalyser.cpp"
#include "Layer.h"
class Menu										    // Menu class
{
private:											// Menu attributes
	vector<Pupil*> pupil_ptr_arr;					// 2 pointer vectors, 2 vecAnalysers (on for each type Pupil/Worker)
	vector<Worker*> worker_ptr_arr;					// and a vector of the school's layers and in for number of layers
	VecAnalyser<vector<Pupil*>> pupil_analyse;
	VecAnalyser<vector<Worker*>> worker_analyse;
	vector<Layer*> layer_ptr_arr;
	int num_of_layers;
public:												// Menu methods (explenation in cpp file)
	Menu() {};	
	Menu(vector<Pupil*> Pupil_ptr_arr, vector<Worker*> Worker_ptr_arr, vector<Layer*> Layer_ptr_arr , int Num_of_layers);
	void mainMenu();
	Pupil* add_Pupil(string First_name, string Last_name, char Layer, int Class_num, vector<int> Grades_arr);
	Teacher* add_Teacher(string First_name, string Last_name, int Teaching_seniority, int Managing_seniority, vector<string> Subjects_arr, int Num_of_subjects);
	Tutor* add_Tutor(string First_name, string Last_name, int Teaching_seniority, int Managing_seniority, vector<string> Subjects_arr, int Num_of_subjects, Class* Classroom_ptr);
	void add_Manager(string Firstname, string Lastname, int Teaching_seniority, int Managing_seniority, string Office_Number, vector<string> Subjects_arr = vector<string>(), int Num_of_subjects=0);
	Secretary* add_Secretary(string First_name, string Last_name, int Teaching_seniority, int Managing_seniority, string Office_number, int Num_of_childrens);
	void print_Person_Details();
	void print_outstanding_ppl();
	void print_Tutors_class(string First_name, string Last_name);
	void highest_Paid_worker();
	void clean_buff();
	~Menu();
};