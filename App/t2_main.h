#ifndef T2_MAIN_H
#define T2_MAIN_H
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

class t2_main
{
	public:
		string line,word,word2,LoginID,name,my_course;
		int row,col;
		void Load();
		void select_date();
		void add_date();
		void take_attendance(string);
		string get_name(string);
		string get_course(string);
		vector< vector<string> > vec_trainers;
		vector< vector<string> > vec_att;
		vector< vector<string> > vec_att2;
		vector< vector<string> > vec_approve_courses;
		vector< vector<string> > vec_approve;
		vector< vector<string> > vec_my_mates;
	protected:
};

#endif
