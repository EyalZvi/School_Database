#pragma once
/* Assignment: 1
Author1: Eyal Zvi,
ID: 319067732
Author2: Saar Ben-Yochana,
ID: 313234155
*/
#include <vector>
#include "Pupil.h"
#include "Manager.h"
#include "Tutor.h"
#include "Secretary.h"
template <typename T>
class VecAnalyser			// Template Vecanalyser Class
{		
private:
	T obj_ptr_arr;			// a T type of variable that is actively a Pupil* vector / Worker* vector
public:						
	VecAnalyser() {};
	VecAnalyser(T T_vector);						// Class methods
	Person* operator[](int index);
	void swap(int index1, int index2, vector<Pupil*> vec);
	void swap(int index1, int index2, vector<Worker*> vec);
	void printElement(int index);
	void printAll();
	void printMax(vector<Worker*> vec);
	void printMax(vector<Pupil*> vec);
	bool is_manager(int index);
	void set_obj_ptr(T T_vector) { this->obj_ptr_arr = T_vector; }
	T get_vec_type();
	~VecAnalyser();
};
