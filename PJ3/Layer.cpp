#include "Layer.h"

Layer::Layer()
{
    // Layer Default Constructor
	this->layer = '\0';
	this->Class_ptr_arr;
}

Layer::Layer(char Layer, Class* Class_ptr_to_add)
{
    // Layer Constructor
	this->layer = Layer;
	this->Class_ptr_arr.push_back(Class_ptr_to_add);
}

Class* Layer::operator[](int index)
{
    // Layer Index Operator
	if(index < this->Class_ptr_arr.size() && index >= 0)
		return this->Class_ptr_arr[index];
	return nullptr;
}

bool Layer::Add_class_ptr_to_layer(Class* Class_ptr_to_add)
{
    // Class Insertion Method
	if (this->Class_ptr_arr.size() >= 3)
		return false;
	this->Class_ptr_arr.push_back(Class_ptr_to_add);
	return true;
}

Layer::~Layer()
{
    // Layer Destructor
	this->Class_ptr_arr.clear();
}

