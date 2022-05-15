#pragma once
/* Assignment: 1
Author1: Eyal Zvi,
ID: 319067732
Author2: Saar Ben-Yochana,
ID: 313234155
*/
#include "Class.h"
class Layer				// Class that 'has a' relationship with Class pointer Class**
{
private:
    // Layer fields
	char layer;
	vector<Class*> Class_ptr_arr;
public:
	Layer();                                    // Layer Default Constructor
	Layer(char Layer,Class* Class_ptr_to_add);  // Layer Constructor
	Class* operator [](int index);              // Layer index operator
	bool Add_class_ptr_to_layer(Class* Class_ptr_to_add);   // class insertion method
	char get_layer() { return this->layer; };               // Layer name getter
	vector<Class*> get_class_ptr() { return this->Class_ptr_arr; }; // classes vector getter
	~Layer();                                    // Layer Destructor
};

