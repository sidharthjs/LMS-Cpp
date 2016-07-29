#ifndef REGISTERATION_H
#define REGISTERATION_H
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

class registeration
{
	public:
		char choice;
		string name,mailid,username,password,phone,department,address;
		typedef vector< vector<string> > Vector;
		Vector vec;
		
		void Load();
		void getdata();
		void storedata();
	protected:
};

#endif

