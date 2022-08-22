#include "Menu.h"
#include "Manager.h"
#include <iostream>
using namespace std;

Menu::Menu(vector<Pupil*> Pupil_ptr_arr, vector<Worker*>Worker_ptr_arr, vector<Layer*> Layer_ptr_arr, int Num_of_layers)
{
	// Normal Ctor - build the different vectors and vector analysers to use
	this->pupil_ptr_arr = Pupil_ptr_arr;
	this->worker_ptr_arr = Worker_ptr_arr;
	this->pupil_analyse = VecAnalyser<vector<Pupil*>>(this->pupil_ptr_arr);
	this->worker_analyse = VecAnalyser<vector<Worker*>>(this->worker_ptr_arr);
	this->layer_ptr_arr = Layer_ptr_arr;
	this->num_of_layers = Num_of_layers;
}

void Menu::mainMenu()
{
	//Main menu method - this method is the core of the code, from here we can use the different methods to buil our school database
	int user_choice = 0;
	while (user_choice == 0) {
		cout << endl;																	// Main menu text
		cout << "\tPlease choose one of the following options:" << endl;
		cout << "\t==========================================================" << endl;
		cout << "\t1) Add a pupil to school's database." << endl;
		cout << "\t2) Add a teacher to school's database." << endl;
		cout << "\t3) Add a tutor to school's database." << endl;
		cout << "\t4) Add a manager to school's database." << endl;
		cout << "\t5) Add a secretary to school's database." << endl;
		cout << "\t6) Print all database (pupils and workers)" << endl;						
		cout << "\t7) Print all oustanding people" << endl;
		cout << "\t8) Print a tutor's class" << endl;
		cout << "\t9) Print highest paid worker/s." << endl;
		cout << "\t10) Quit the program." << endl;
		cout << "\t==========================================================" << endl;
		cout << "\t> ";
		clean_buff();
		cin >> user_choice;
		switch (user_choice) {
		case 1: {
			// Case 1 - Add a pupil to database
			string f_name_pupil, l_name_pupil;
			vector <int> grades_arr;
			char layer;
			int  class_num;
			int input = 0;
			cout << "\tPlease enter new pupil details:" << endl;
			cout << "\tFirst name: " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> f_name_pupil;

			cout << "\tLast name: " << endl;
			cout << "\t> ";
			clean_buff();							// Insert relevent information, checking for correct inputs
			cin >> l_name_pupil;

			cout << "\tLayer name (a-f): " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> layer;
			while (layer < 'a' || layer > 'f') {
				cout << "\tInvalid input - (Layer range is from a to f)" << endl;
				cout << "\tPlease try again: > ";
				clean_buff();
				cin >> layer;
			}

			cout << "\tClass number (1-3): " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> class_num;
			while (class_num < 1 || class_num > 3) {
				cout << "\tInvalid input - (Class number range is from 1 to 3)" << endl;
				cout << "\tPlease try again: > ";
				clean_buff();
				cin >> class_num;
			}
			cout << "\tEnter pupil's grades:" << endl;
			cout << "\tEnd insertion with '-1' value" << endl;
			cout << "\t> ";
			clean_buff();
			cin >> input;
			if (input != -1) {
				if (input >= 0 && input <= 100)
					grades_arr.push_back(input);
				else
					cout << "\tInvalid input - grades should be 0 - 100 " << endl;
			}
			while (input != -1) {
				cout << "\tEnter another grade: (End insertion with '-1' value)" << endl;
				cout << "\t> ";
				clean_buff();
				cin >> input;
				if (input >= 0 && input <= 100)
					grades_arr.push_back(input);
				else
					if(input != -1)
						cout << "\tInvalid input - grades should be 1 - 100 " << endl;
			}
			bool class_flag = false , layer_flag = false;	// This section checks if the pupil's layer/class exists an create/link accordingly

			Pupil* new_pupil_ptr = add_Pupil(f_name_pupil, l_name_pupil, layer, class_num, grades_arr);
			for (int i = 0; i < int(this->layer_ptr_arr.size()); i++) {
				if (layer_ptr_arr[i]->get_layer() == layer) {
					layer_flag = true;
					for (int j = 0; j < int(this->layer_ptr_arr[i]->get_class_ptr().size()); j++) {
						if (this->layer_ptr_arr[i]->get_class_ptr()[j]->get_class_num() == class_num) {
							this->layer_ptr_arr[i]->get_class_ptr()[j]->add_Pupil(new_pupil_ptr);
							class_flag = true;
							break;
						}													// Also the creation of the pupil is done here 
					}
					if (class_flag == false && layer_flag == true) {
						vector <Pupil*> pupil_class_vec;
						pupil_class_vec.push_back(new_pupil_ptr);
						Class* new_class_ptr = new Class(layer, class_num, pupil_class_vec, pupil_class_vec.size(),nullptr);
					}
				}
			}
			if (class_flag == false && layer_flag == false) {				// We check all cases with flags

				vector <Pupil*> pupil_class_vec;						
				pupil_class_vec.push_back(new_pupil_ptr);
				Class* new_class_ptr = new Class(layer, class_num, pupil_class_vec, pupil_class_vec.size(),nullptr);
				vector<Class*> class_vec;
				Layer* new_layer = new Layer(layer,new_class_ptr);
				this->layer_ptr_arr.push_back(new_layer);
				this->num_of_layers++;
			}
			user_choice = 0;
			break;
		}
		case 2: {
			// Case 2 - Add a teacher to database
			cout << "\tPlease enter new teacher details:" << endl;
			string f_name_teach, l_name_teach;
			vector <string> subj_vec;
			int teach_senior = 0;
			string input;

			cout << "\tFirst name: " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> f_name_teach;

			cout << "\tLast name: " << endl;
			cout << "\t> ";
			clean_buff();							// Insert relevent information, checking for correct inputs
			cin >> l_name_teach;

			cout << "\tTeaching seniority: " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> teach_senior;
			while (teach_senior < 0) {
				cout << "\tInvalid input - (Teaching seniority should be 0 and above)" << endl;
				cout << "\tPlease try again: > ";
				clean_buff();
				cin >> teach_senior;
			}
			cout << "\tEnter teacher's subjects: " << endl;
			while (input != "-") {
				cout << "\tEnter subject: (End insertion with '-' symbol)" << endl;
				cout << "\t> ";
				clean_buff();
				cin >> input;
				if (input != "-")
					subj_vec.push_back(input);
			}

			Teacher* new_teacher = add_Teacher(f_name_teach, l_name_teach, teach_senior, 0, subj_vec, subj_vec.size());
			// Add the teacher to the database
			user_choice = 0;
			break;
		}
		case 3: {
			// Case 3 - Add a tutor to database
			cout << "\tPlease enter new tutor details:" << endl;
			string f_name_tutor, l_name_tutor;
			vector <string> subj_vec;
			int teach_senior = 0;
			string input;					// Local variables 
			Class* class_ptr;
			char layer;
			int class_num;

			cout << "\tFirst name: " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> f_name_tutor;

			cout << "\tLast name: " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> l_name_tutor;


			cout << "\tLayer name (a-f): " << endl;				// Insert relevent information, checking for correct inputs
			cout << "\t> ";
			clean_buff();
			cin >> layer;
			while (layer < 'a' || layer > 'f') {
				cout << "\tInvalid input - (Layer range is from a to f)" << endl;
				cout << "\tPlease try again: > ";
				clean_buff();
				cin >> layer;
			}

			cout << "\tClass number (1-3): " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> class_num;
			while (class_num < 1 || class_num > 3) {
				cout << "\tInvalid input - (Class number range is from 1 to 3)" << endl;
				cout << "\tPlease try again: > ";
				clean_buff();
				cin >> class_num;
			}

			cout << "\tTeaching seniority: " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> teach_senior;
			while (teach_senior < 0) {
				cout << "\tInvalid input - (Teaching seniority should be 0 and above)" << endl;
				cout << "\tPlease try again: > ";
				clean_buff();
				cin >> teach_senior;
			}
			cout << "\tEnter tutor's subjects: " << endl;
			while (input != "-") {
				cout << "\tEnter subject: (End insertion with '-' symbol)" << endl;
				cout << "\t> ";
				clean_buff();
				cin >> input;
				if (input != "-")
					subj_vec.push_back(input);
			}
			bool class_flag = false, layer_flag = false;	              // This section is the connecting link between a tutor and her/his class
																		  // Here we check if the layer/class/both exist and creating/linking accordingly 
			for (int i = 0; i < int(this->layer_ptr_arr.size()); i++) {	  // A new tutor will replace the old one in a class (if there is one)
				if (layer_ptr_arr[i]->get_layer() == layer) {			  
					layer_flag = true;
					for (int j = 0; j < int(this->layer_ptr_arr[i]->get_class_ptr().size()); j++) {
						if (this->layer_ptr_arr[i]->get_class_ptr()[j]->get_class_num() == class_num) {
							if(this->layer_ptr_arr[i]->get_class_ptr()[j]->get_Tutor_ptr() != nullptr){
								this->layer_ptr_arr[i]->get_class_ptr()[j]->get_Tutor_ptr()->fire_last_tutor();
								}
							Tutor* new_Tutor_ptr = add_Tutor(f_name_tutor, l_name_tutor, teach_senior, 0, subj_vec, subj_vec.size(),this->layer_ptr_arr[i]->get_class_ptr()[j]);
							class_flag = true;
							break;						
						}										// In every case we create a new tutor and link her/him to her/his class
					}
					if (layer_flag == true && class_flag == false) {
						Tutor* new_Tutor_ptr = add_Tutor(f_name_tutor, l_name_tutor, teach_senior, 0, subj_vec, subj_vec.size(), nullptr);
						vector <Pupil*> pupil_class_vec;
						pupil_class_vec.clear();
						Class* new_class_ptr = new Class(layer, class_num, pupil_class_vec, pupil_class_vec.size(), new_Tutor_ptr);
						new_Tutor_ptr->set_class_ptr(new_class_ptr);
					}
				}														// We check all cases with flags
			}	
			if (layer_flag == false && class_flag == false) {
				Tutor* new_Tutor_ptr = add_Tutor(f_name_tutor, l_name_tutor, teach_senior, 0, subj_vec, subj_vec.size(), nullptr);
				vector <Pupil*> pupil_class_vec;
				pupil_class_vec.clear();
				Class* new_class_ptr = new Class(layer, class_num, pupil_class_vec, pupil_class_vec.size(), new_Tutor_ptr);
				vector<Class*> class_vec;
				Layer* new_layer = new Layer(layer, new_class_ptr);
				this->layer_ptr_arr.push_back(new_layer);
				new_Tutor_ptr->set_class_ptr(new_class_ptr);
				this->num_of_layers++;
			}
			user_choice = 0;
			break;
		}
		case 4: {
			// Case 4 - Add manager to database
			cout << "\tPlease enter new manager details: (**please note that only one manager can be assinged)" << endl;
			string f_name_manange, l_name_manage, office_num;
			vector <string> subj_vec;
			int man_senior = 0, teach_senior = 0;
			char YN = '\0';
			string input;

			cout << "\tFirst name: " << endl;
			cout << "\t> ";
			clean_buff();								// Insert relevent information, checking for correct inputs
			cin >> f_name_manange;

			cout << "\tLast name: " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> l_name_manage;

			cout << "\tManagment seniority: " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> man_senior;
			while (man_senior < 0) {
				cout << "\tInvalid input - (Managment seniority should be 0 and above)" << endl;
				cout << "\tPlease try again: > ";
				clean_buff();
				cin >> man_senior;
			}

			cout << "\tTeaching seniority: " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> teach_senior;
			while (teach_senior < 0) {
				cout << "\tInvalid input - (Teaching seniority should be 0 and above)" << endl;
				cout << "\tPlease try again: > ";
				clean_buff();
				cin >> teach_senior;
			}

			cout << "\tOffice number: " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> office_num;

			cout << "\tIs this manager also a teacher? Y/N" << endl; // Checking if the manager is also a teacher then acting accordingly
			cout << "\t> ";
			clean_buff();
			cin >> YN;
			while (YN != 'Y' && YN != 'N' && YN != 'y' && YN != 'n') {
				cout << "\tInvalid input (Y/N)" << endl;
				cout << "\tPlease try again: > ";
				clean_buff();
				cin >> YN;
			}
			if (YN == 'y' || YN == 'Y') {
				cout << "\tPlease enter the manager's teaching subjects:" << endl;
				cout << "\tEnd insertion with '-' symbol." << endl;
				clean_buff();
				cout << "\t> ";					// Manager is also a teacher -> Push subjects to subject vector  
				cin >> input;
				if (input != "-")
					subj_vec.push_back(input);
				else {
					cout << "\tManager without subjects is a regular manager, continues accordingly." << endl; 
					add_Manager(f_name_manange, l_name_manage, teach_senior, man_senior, office_num);
					user_choice = 0;
					break;					// Manager without any subjects is not a teacher -> 'Y' insertion was wrong 
				}
				while (input != "-") {
					cout << "\tEnter another subject: (End insertion with '-' symbol)" << endl;
					cout << "\t> ";
					clean_buff();
					cin >> input;
					if (input != "-")
						subj_vec.push_back(input);
				}
				add_Manager(f_name_manange, l_name_manage, teach_senior, man_senior, office_num,subj_vec,subj_vec.size());
				user_choice = 0;
				break;
			}						//Adding the manager to the database

			add_Manager(f_name_manange, l_name_manage, teach_senior, man_senior, office_num);

			user_choice = 0;
			break;
		}
		case 5: {
			// Case 5 - Add secretary to database
			cout << "\tPlease enter new secretary details: " << endl;
			string f_name_sec, l_name_sec, office_num;
			int num_of_children;
			int man_senior = 0;
			string input;

			cout << "\tFirst name: " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> f_name_sec;

			cout << "\tLast name: " << endl;
			cout << "\t> ";
			clean_buff();			// Insert relevent information, checking for correct inputs
			cin >> l_name_sec;									

			cout << "\tManagment seniority: " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> man_senior;
			while (man_senior < 0) {
				cout << "\tInvalid input - (Managment seniority should be 0 and above)" << endl;
				cout << "\tPlease try again: > ";
				clean_buff();
				cin >> man_senior;
			}
			cout << "\tOffice number: " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> office_num;

			cout << "\tNumber of children in school: " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> num_of_children;
			while (num_of_children < 0) {
				cout << "\tInvalid input - (Number of children should be 0 and above)" << endl;
				cout << "\tPlease try again: > ";
				clean_buff();
				cin >> num_of_children;
			}

			Secretary* new_secretary = add_Secretary(f_name_sec, l_name_sec, 0, man_senior, office_num,num_of_children);
			//Adding the secretary
			user_choice = 0;
			break;
		}
		case 6: {
			//Case 7 - Print all database
			this->pupil_analyse.set_obj_ptr(this->pupil_ptr_arr);
			this->worker_analyse.set_obj_ptr(this->worker_ptr_arr); 	// update vecAnalyser items before printing
			print_Person_Details();
			// Found below
			user_choice = 0;
			break;
		}
		case 7: {
			//Case 7 - Print oustanding people
			this->pupil_analyse.set_obj_ptr(this->pupil_ptr_arr);
			this->worker_analyse.set_obj_ptr(this->worker_ptr_arr);	// update vecAnalyser items before printing
			print_outstanding_ppl();
			user_choice = 0;
			break;
		}
		case 8: {
			//Case 8 - Print tutor's class by her name
			this->pupil_analyse.set_obj_ptr(this->pupil_ptr_arr);
			this->worker_analyse.set_obj_ptr(this->worker_ptr_arr); // update vecAnalyser items before printing
			cout << "\tPlease enter tutor's full name:" << endl;
			string f_name_tutor, l_name_tutor;

			cout << "\tFirst name: " << endl;				
			cout << "\t> ";
			clean_buff();					// Enter needed info then send to print_Tutors_class (found below)
			cin >> f_name_tutor;

			cout << "\tLast name: " << endl;
			cout << "\t> ";
			clean_buff();
			cin >> l_name_tutor;

			print_Tutors_class(f_name_tutor, l_name_tutor); // Found below
			user_choice = 0;
			break;
		}
		case 9: {
			//Case 9 - Print highest paid worker
			if (this->worker_ptr_arr.size() == 0) {
				cout << endl << "\tNo workers in database." << endl;
			}
			else {
				this->pupil_analyse.set_obj_ptr(this->pupil_ptr_arr);
				this->worker_analyse.set_obj_ptr(this->worker_ptr_arr); // update vecAnalyser items before printing
				highest_Paid_worker();
				//Method found below 
			}
			user_choice = 0;
			break;
		}
		case 10: {
			//Case 10 - Exit
			break;
		}
		default: {
			//Defalut
			user_choice = 0;
			break;
		}
		}
	}
}

Pupil* Menu::add_Pupil(string First_name, string Last_name, char Layer, int Class_num, vector<int> Grades_arr)
{
	//Adding a pupil to the pupil's vector 
	Pupil* pupil_to_add = new Pupil(First_name, Last_name, Layer, Class_num, Grades_arr);
	this->pupil_ptr_arr.push_back(pupil_to_add);
	return pupil_to_add;
}

Teacher* Menu::add_Teacher(string First_name, string Last_name, int Teaching_seniority, int Managing_seniority, vector<string> Subjects_arr, int Num_of_subjects)
{
	//Adding a teacher to the worker's vector 
	Teacher* teacher_to_add= new Teacher(First_name, Last_name, Teaching_seniority, Managing_seniority, Subjects_arr, Num_of_subjects);
	this->worker_ptr_arr.push_back(teacher_to_add);
	return teacher_to_add;
}

Tutor* Menu::add_Tutor(string First_name, string Last_name, int Teaching_seniority, int Managing_seniority, vector<string> Subjects_arr, int Num_of_subjects, Class* Classroom_ptr)
{
	//Adding a tutor to the worker's vector 
	Tutor* tutor_to_add = new Tutor(First_name,Last_name,Teaching_seniority,Managing_seniority,Subjects_arr,Num_of_subjects,Classroom_ptr);
	this->worker_ptr_arr.push_back(tutor_to_add);
	tutor_to_add->set_class_ptr(Classroom_ptr);
	return tutor_to_add;
}

void Menu::add_Manager(string First_name, string Last_name, int Teaching_seniority, int Managing_seniority, string Office_Number, vector<string> Subjects_arr, int Num_of_subjects)
{
	//Adding a manager to the worker's vector 
	const Manager* curr_manager_ptr = curr_manager_ptr->current_manger();

	Manager* new_manager = new_manager->appointment_manager(First_name, Last_name, Teaching_seniority, Managing_seniority, Office_Number, Subjects_arr, Num_of_subjects);
	if (curr_manager_ptr == new_manager->current_manger())
		return;
	this->worker_ptr_arr.push_back(new_manager);
}

Secretary* Menu::add_Secretary(string First_name, string Last_name, int Teaching_seniority, int Managing_seniority, string Office_number, int Num_of_childrens)
{
	//Adding a secretary to the worker's vector 
	Secretary* secretary_to_add = new Secretary(First_name, Last_name, Teaching_seniority, Managing_seniority, Office_number, Num_of_childrens);
	this->worker_ptr_arr.push_back(secretary_to_add);
	return secretary_to_add;
}

void Menu::print_Person_Details()
{
	//Method that prints all database (every kind of non - abstract class will be printed)
	if (this->pupil_ptr_arr.size() == 0 && this->worker_ptr_arr.size() == 0) {
		cout << "\tEmpty database" << endl << endl;										//Empty database - print accordingly
		return;
	}

	cout << "\t-----------------------------------------" << endl;
	cout << "\t| Printing all people in school databse | " << endl;
	cout << "\t-----------------------------------------" << endl << endl;				// Send to printAll (Template method) one for each type of  vector
	cout << "\tPrinting all pupils in school: " << endl << endl;
	pupil_analyse.printAll();
	cout << endl;
	cout << "\tPrinting all Workers in school: " << endl << endl;
	worker_analyse.printAll();
	
}

void Menu::print_outstanding_ppl() {
	// Method that prints all outstanding people by their is_excellent boolean value 
	int i;
	bool found_oustanding_pup = false;	// Flags to check if any person was found -> if not print accordingly 
	bool found_oustanding_wrkr = false;
	cout << "\t-----------------------------------------------------" << endl;
	cout << "\t| Printing all outstanding people in school database | " << endl;
	cout << "\t-----------------------------------------------------" << endl << endl;
	cout << "\tPrinting all outstanding pupils in school: " << endl << endl;
	for (i = 0; i< int(this->pupil_ptr_arr.size()); i++) {  
		if (this->pupil_analyse[i]->is_excellent()) {								
			this->pupil_analyse.printElement(i);
			cout << endl;
			found_oustanding_pup = true;
		}
	}										// Going over Pupil array, then worker array and printing the outstanding people with printElement method
	if (found_oustanding_pup == false) 
		cout << "\tNone found" << endl;

	cout << endl << "\tPrinting all outstanding workers in school: " << endl << endl;
	for (i = 0; i< int(this->worker_ptr_arr.size()); i++) {  
		if (this->worker_analyse[i]->is_excellent()) {
			this->worker_analyse.printElement(i);
			cout << endl;
			found_oustanding_wrkr = true;
		}
	}										// Printing accordingly "None found" in both cases (every vector)
	if (found_oustanding_wrkr == false)
		cout << "\tNone found" << endl;
	if (found_oustanding_wrkr == false && found_oustanding_pup == false)
		cout << endl << "\tNo oustanding people found in school  :( " << endl;		// <-  A VERY SAD MESSEGE!
}

void Menu::print_Tutors_class(string First_name, string Last_name) {
	//Method that print a tutor's class by name

	bool found_Tutor = false, excellent_found = false;				// 2 bool variables - flags for validation
	float calc_total_avg = 0;										// calc_total_avg - for calculating class average
	for (int i = 0; i< int(this->worker_ptr_arr.size()); i++) {	 
		if (typeid(*(this->worker_analyse[i])) == typeid(Tutor) && (this->worker_analyse[i]->get_first_name() == First_name) && (this->worker_analyse[i]->get_last_name() == Last_name)) {
			//For every worker in the worker vector check if it is the wanted Tutor by name and type - if found found_Tutor <- true
			found_Tutor = true;
			Class* class_ptr = dynamic_cast<Tutor*>(worker_analyse[i])->get_class_ptr();
			cout << endl;																		// If found print to screen
			cout << "\t-------------------------------" << endl;
			cout << "\t" << First_name << " " << Last_name << "'s class: " << endl;
			cout << "\tClass: " << class_ptr->get_layer() << " " << class_ptr->get_class_num() << endl;
			cout << "\tPupils: "<< endl;
			class_ptr->print_class_pupils();
			vector<Pupil*> tmp_pupil(class_ptr->get_pupils_ptr_arr());
			cout << "\t-------------------------------" << endl;
			cout <<"\tExcellent pupils in class: " << endl;
			for (int j = 0; j < class_ptr->get_num_of_pupils(); j++) {							// Print all excelent pupils by using the is_excellent method
				if (tmp_pupil[j]->is_excellent()) {				
					tmp_pupil[j]->print_obj();
					cout << endl;
					excellent_found = true;
				}
				calc_total_avg += tmp_pupil[j]->get_avg();										// Calculate class average and print (print accordingly for empty class)
			}
			if (excellent_found == false)
				cout << "\tNo excellent pupils found" << endl;
			cout << "\t-------------------------------" << endl;
			if (class_ptr->get_num_of_pupils() != 0)
				cout << "\tClass average: " << calc_total_avg / class_ptr->get_num_of_pupils() << endl;
			else
				cout << "\tClass average: 0 (No pupils)" << endl;
			cout << "\t-------------------------------" << endl;
			tmp_pupil.clear();
		}
	}
	if (found_Tutor == false)																		// If tutor not found print accordingly
		cout << "\tNo Tutor " << First_name << " " << Last_name << " found in database" << endl;
}

void Menu::highest_Paid_worker() {
	//Method that calls printMax method in vecAnalyser - prints highest paid workers
	this->worker_analyse.printMax(this->worker_ptr_arr);
}

void Menu::clean_buff() {
	//Method that cleans the buffer after every cin use
	if (char(cin.peek()) == '\n')
		cin.ignore();

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
	}
}

Menu::~Menu()
{
	//Dtor 
	for (int i = 0; i<int(this->pupil_ptr_arr.size()); i++) {		// delete vector of pupil pointers (all pupils at school)
		delete this->pupil_ptr_arr[i];						
	}
	for (int i = 0; i<int(this->worker_ptr_arr.size()); i++) {		// delete vector of worker pointers (all workers at school)
		delete this->worker_ptr_arr[i];
	}
	this->pupil_ptr_arr.clear();									// clear both vectors after use
	this->worker_ptr_arr.clear();


	for (int i = 0; i < num_of_layers; i++) {						// delete all layers and classes then clear vectors needed
		for (int j = 0; j < this->layer_ptr_arr[i]->get_class_ptr().size(); j++) {	
			delete this->layer_ptr_arr[i]->get_class_ptr()[j];
		}														
		this->layer_ptr_arr[i]->get_class_ptr().clear();
		delete layer_ptr_arr[i];
	}
	this->layer_ptr_arr.clear();
}
