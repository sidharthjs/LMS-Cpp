#ifndef ADMIN_TRAINER_H
#define ADMIN_TRAINER_H
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

class admin_trainer
{
	public:
		char choice;
		string no,name,username,password,line,word;
		vector< vector<string> > vec;
		void Load();
		void view_trainer();
		void insert_trainer();
	protected:
};

#endif
