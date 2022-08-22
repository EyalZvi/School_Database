#include "VecAnalyser.h"

template <typename T>
VecAnalyser<T>::VecAnalyser(T T_vector) {
    //Normal Ctor
    for (int i = 0; i < int(T_vector.size()); i++) {
        this->obj_ptr_arr.push_back(T_vector[i]);        // Push the Pupil pointers / Worker pointers to the T vector
    }
}

template<typename T>
Person* VecAnalyser<T>::operator[](int index)
{
    // Operater [] overlaoding
    if (int(this->obj_ptr_arr.size()) == 0) {
        cout << "\tEmpty list, no value returned " << endl;     // If the T vector is empty/ index of of range return nullptr
        return nullptr;                                         // Else return the pointer in the index
    }
    if (index < 0 || index >= int(this->obj_ptr_arr.size())) {
        cout << "\tIndex " << index << " is out of range, try [0 - " << int(this->obj_ptr_arr.size()) - 1 << "]" << endl;
        return nullptr;
    }
    else
        return this->obj_ptr_arr[index];

}


template<typename T>
void VecAnalyser<T>::swap(int index1, int index2, vector<Pupil*> vec)
{
    //swap method - swaping two items in T vector (Pupil* type)
    Pupil* tmp_pupil;
    if (int(this->obj_ptr_arr.size()) == 0) {
        cout << "\tEmpty list, no switch was made " << endl;        // If the list is empty or index out of range return 
        return;                                                     // Else switch the objects
    }
    if (index1 < 0 || index1 >= int(this->obj_ptr_arr.size()) || index2 < 0 && index2 >= int(this->obj_ptr_arr.size())) {
        cout << "\tIndices inserted: " << index1 << ", " << index2 << " are out of range, try [0 - " << int(this->obj_ptr_arr.size()) - 1 << "]" << endl;
        return;
    }
    else {
        tmp_pupil = this->obj_ptr_arr[index1];
        this->obj_ptr_arr[index1] = this->obj_ptr_arr[index2];
        this->obj_ptr_arr[index2] = tmp_pupil;
    }
}
template<typename T>
void VecAnalyser<T>::swap(int index1, int index2, vector<Worker*> vec)
{
    //swap method - swaping two items in T vector (Worker* type)
    Worker* tmp_worker;
    if (int(this->obj_ptr_arr.size()) == 0) {                  // If the list is empty or index out of range return 
        cout << "\tEmpty list, no switch was made " << endl;   // Else switch the objects
        return;
    }
    if (index1 < 0 || index1 >= int(this->obj_ptr_arr.size()) || index2 < 0 && index2 >= int(this->obj_ptr_arr.size())) {
        cout << "\tIndices inserted: " << index1 << ", " << index2 << " are out of range, try [0 - " << int(this->obj_ptr_arr.size()) - 1 << "]" << endl;
        return;
    }
    else {
        tmp_worker = this->obj_ptr_arr[index1];
        this->obj_ptr_arr[index1] = this->obj_ptr_arr[index2];
        this->obj_ptr_arr[index2] = tmp_worker;
    }
}

template<typename T>
void VecAnalyser<T>::printElement(int index)
{
    //PrintElement method - print a specific person the T vector by index
    if (int(this->obj_ptr_arr.size()) == 0) {
        cout << "\tEmpty list, no value returned " << endl;
        return;                                             
    }                                                           // If empty vector / index out of range return 
    if (index >= 0 && index < int(this->obj_ptr_arr.size()))    // Else print the person
        this->obj_ptr_arr[index]->print_obj();
    else
    cout  << "\tIndex " << index << " is out of range, try [0 - " << int(this->obj_ptr_arr.size()) - 1 << "]" << endl;
}

template<typename T>
void VecAnalyser<T>::printAll()
{
    //PrintAll - print all database
    for (int i = 0; i < int(this->obj_ptr_arr.size()); i++) {
        this->obj_ptr_arr[i]->print_obj();
        cout << endl;                        // use print_obj polymorphism method to print all people (disregarding classes types) 
    }
}
template<typename T>
void VecAnalyser<T>::printMax(vector<Worker*> vec)
{
    //PrintMax - print the oustanding people in the database - Worker type
    if (vec.size() == 0)
        return; //Max Salary Workers Details:
    vector<Worker*> outstanding_worker_vec;
    cout << "\tHighest Salary Workers Details:" << endl << endl;
    int i, j, highest_sal = 0;
    for (i = 0; i < vec.size(); i++) {
        if (vec[i]->get_salary() == highest_sal) {          // By get_salary methof we get and print the correct worker
            outstanding_worker_vec.push_back(vec[i]);
        }
        else if (vec[i]->get_salary() > highest_sal) {
            highest_sal = vec[i]->get_salary();
            outstanding_worker_vec.clear();
            outstanding_worker_vec.push_back(vec[i]);
        }
    }
    for (j = 0; j < int(outstanding_worker_vec.size()); j++) {
        outstanding_worker_vec[j]->print_obj();
        cout << endl;
    }
    return;
}

template<typename T>
void VecAnalyser<T>::printMax(vector<Pupil*> vec)
{
    //PrintMax - print the oustanding people in the database - Student type
    vector<Pupil*> outstanding_pupil_vec;
    if (vec.size() == 0)
        return;
    cout << "\tHighest Average Pupils Details:" << endl << endl;
    int i, j, highest_avg = 0;
    for (i = 0; i < vec.size(); i++) {
        if (vec[i]->get_avg() == highest_avg) {
            outstanding_pupil_vec.push_back(vec[i]);
        }
        else if (vec[i]->get_avg() > highest_avg) {
            highest_avg = vec[i]->get_avg();                // By get_avg methof we get and print the correct worker
            outstanding_pupil_vec.clear();
            outstanding_pupil_vec.push_back(vec[i]);
        }
    }
    for(j=0; j < outstanding_pupil_vec.size(); j++) {
        outstanding_pupil_vec[j]->print_obj();
        cout << endl;
    }
    return;
}
template<typename T>
bool VecAnalyser<T>::is_manager(int index)
{
    // Checking if the person in a specific index is a manager
    if (typeid(this->obj_ptr_arr[index]) == typeid(Manager*))   // return true/false accordingly
        return true;    
    return false;
}

template<typename T>
T VecAnalyser<T>::get_vec_type()
{
    //get_vec_type - Returning a vector type
    return obj_ptr_arr;
}

template<typename T>
VecAnalyser<T>::~VecAnalyser()
{
    //Dtor
    this->obj_ptr_arr.clear();
}

