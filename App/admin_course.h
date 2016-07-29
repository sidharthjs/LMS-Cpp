#ifndef ADMIN_COURSE_H
#define ADMIN_COURSE_H
#include<string>
#include<vector>
using namespace std;
class admin_course
{
	public:
		char choice;
		string courseno,title,duration,description;
		void Load();
		void view_course();
		void insert_course();
		vector< vector<string> > vec;
		string line,word;
	protected:
};

#endif
