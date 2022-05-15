/* Assignment: 1
Author1: Eyal Zvi,
ID: 319067732
Author2: Saar Ben-Yochana,
ID: 313234155
*/
#include <iostream>
#include "VecAnalyser.h"
#include "VecAnalyser.cpp"
#include "Manager.h"
#include "Secretary.h"
#include "Class.h"
#include "Tutor.h"
#include "School.h"
using namespace std;
int main(){
	School* s = s->getInstance();   // School Initialization
	s->menu();                      // Run User's Menu
	delete s->get_school_ptr();     // Delete School when user exits
	                                // [dynamically allocated]
	return 0;                       // End
}