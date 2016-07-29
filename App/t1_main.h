#ifndef T1_MAIN_H
#define T1_MAIN_H
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;
class t1_main
{
	public:
		void Load();
		void get_courses();
		void display_courses();
		void course_click();
		void my_courses();
		string choice,feedback;
		string LoginID,name,line,word,trainer_no,trainer_name;
		vector< vector<string> > vec;
		vector< vector<string> > mycourses;
		vector< vector<string> > vec_trainer;
	protected:
};

#endif

