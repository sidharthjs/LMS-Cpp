#ifndef ADMIN_PM_H
#define ADMIN_PM_H
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

class admin_pm
{
	public:
		char choice;
		string no,name,username,password,line,word;
		vector< vector<string> > vec;
		void Load();
		void view_pm();
		void insert_pm();
	protected:
};

#endif
