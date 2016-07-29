#ifndef ADMIN_TM_H
#define ADMIN_TM_H
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;
class admin_TM
{
	public:
		char choice;
		string no,name,username,password,line,word;
		vector< vector<string> > vec;
		void Load();
		void view_tm();
		void insert_tm();
	protected:
};

#endif
