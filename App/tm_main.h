#ifndef TM_MAIN_H
#define TM_MAIN_H
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;
class tm_main
{
	public:
		void Load();
		void approve_courses();
		void get_courses();
		void get_trainers();
		void view_attendance();
		int row,col;
		string choice;
		string LoginID,name,line,word;
		vector< vector<string> > vec_courses;
		vector< vector<string> > vec_trainers;
		vector< vector<string> > vec_att;
	protected:
};

#endif
