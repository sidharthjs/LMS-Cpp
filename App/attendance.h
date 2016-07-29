#ifndef ATTENDANCE_H
#define ATTENDANCE_H
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

class attendance
{
	public:
		void Load();
		void get_approve_list();
		void generate();
		string line,word;
		vector< vector<string> > vec_list;
	protected:
};

#endif
