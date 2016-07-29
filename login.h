#ifndef LOGIN_H
#define LOGIN_H
#include<string>
#include<stdlib.h>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

class login
{
	public:
		char choice;
		typedef vector< vector<string> > Vector;
				Vector vec;

		string LoginID,Password,line,word;
		
		void Load();
		void verifyt1(string,string);
				void verifyt2(string,string);
	protected:
};

#endif
