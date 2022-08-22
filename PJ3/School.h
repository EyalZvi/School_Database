#pragma once
#include "Manager.h"
#include "Secretary.h"
#include "Tutor.h"
#include "Layer.h"
class School
{
private:
    // School object fields & static pointer declaration
	vector<Layer*> layer_ptr_arr;
	int num_of_layers;
	vector<Pupil*> pupil_ptr_arr;
	vector<Worker*> worker_ptr_arr;
	static School* school_ptr;
	School();
public:
    // Singleton: School Get Instance Implement
	static School* getInstance();
	void menu();                            // Generating Menu Method
	vector<Layer*> get_layer_ptr_arr();     // Layers vector getter
	int get_num_of_layers();                // Number of layers getter
	vector<Pupil*> get_pupil_ptr_arr();     // Pupils vector getter
	vector<Worker*> get_worker_ptr_arr();   // Workers vector getter
	School* get_school_ptr() { return school_ptr; }; // School pointer getter
	~School();                              // School Destructor

};

