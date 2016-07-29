#ifndef PM_MAIN_H
#define PM_MAIN_H
#include<string>
#include<stdlib.h>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

class pm_main
{
	public:
		vector< vector<string> > vec_list;
		string line,word,choice,LoginID,name;
		void get_list();
		void approve();
		void Load();

	protected:
};

#endif
