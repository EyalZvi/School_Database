/* Assignment: 1
Author1: Eyal Zvi,
ID: 319067732
Author2: Saar Ben-Yochana,
ID: 313234155
*/
#include "School.h"
#include "Menu.h"
#include "Layer.h"

// Set Default Static School Pointer
School* School::school_ptr = 0;

School::School() {
    // School Constructor
	this-> layer_ptr_arr;
	this->num_of_layers = 0;
	this-> pupil_ptr_arr;
	this->worker_ptr_arr;
}

School* School::getInstance() {
    // Singleton: School Get Instance Implement
	if (school_ptr == nullptr) {
		School* new_school_ptr = new School();
		School::school_ptr = new_school_ptr;
	}
	return school_ptr;
}

void School::menu()
{
    // Menu Method: Create Menu object and open it for the user.
	Menu menu(this->pupil_ptr_arr, this->worker_ptr_arr, this->layer_ptr_arr, this->num_of_layers);
	menu.mainMenu();
}

vector<Layer*> School::get_layer_ptr_arr()
{
    // Layers array pointer getter
	return this->layer_ptr_arr;
}

int School::get_num_of_layers()
{
    // Number of layers getter
	return this->num_of_layers;
}

vector<Pupil*> School::get_pupil_ptr_arr()
{
    // Pupils array pointer getter
	return this->pupil_ptr_arr;
}

vector<Worker*> School::get_worker_ptr_arr()
{
    // Workers array pointer getter
	return this->worker_ptr_arr;
}

School::~School()
{
    // School Destructor
	this->layer_ptr_arr.clear();
	this->pupil_ptr_arr.clear();
	this->worker_ptr_arr.clear();
}
