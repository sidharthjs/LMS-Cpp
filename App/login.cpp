#include "login.h"
#include "t1_main.h"
#include "registeration.h"
#include "admin.h"
#include "tm_main.h"
#include "pm_main.h"
#include "t2_main.h"
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;


void login::Load(){
	system("cls");
	cout<<"LMS - Learning Management System\n\n";
    while(choice!='b'){
	cout<<"\nFunctions:\n1-Login\n2-Register\n\n";
	cin>>choice;
				registeration reg;

	switch(choice){
		case '1':
			cout<<"Enter LogniID:\n";
			cin.ignore();
            getline(cin,LoginID);
			cout<<"Enter Password:\n";
			getline(cin,Password);
			//Authenticate process:
			if(LoginID=="Trainee"){
				t1_main obj;
				obj.LoginID=LoginID;
				obj.Load();
			}
			if(LoginID=="Trainer"){
				t2_main obj;
				obj.LoginID=LoginID;
				obj.Load();
			}
			if(LoginID=="TM"){
				tm_main obj;
				obj.LoginID=LoginID;
				obj.Load();
			}
			if(LoginID=="PM"){
				pm_main obj;
				obj.LoginID=LoginID;
				obj.Load();
			}
			if(LoginID=="Admin"){
				admin obj;
				obj.Load();
			}
			
	        else
			verifyt1(LoginID,Password);
			verifyt2(LoginID,Password);
		
	
			break;
			
		case '2':
			cout<<"Getting to Register Page..";
			system("cls");
			reg.Load();
			break;
		
		

	}
}
}

void login::verifyt1(std::string ID,std::string pass){
				ifstream file2("C:\\Users\\Sidharth\\Desktop\\registeration.txt");

	if(file2.is_open()){

			while(getline(file2,line)){
				istringstream xstream(line);
				vector<string> vcol;
				while(getline(xstream,word,',')){
					vcol.push_back(word);
				}
				vec.push_back(vcol);
			}
			for(int i=0;i<vec.size();i++){
//				cout<<vec[i][2]<<"\n";
				if(vec[i][2]==ID&&vec[i][3]==pass){
					t1_main obj;
					obj.LoginID=ID;
					obj.name=vec[i][0];
					obj.Load();
				}
			}
			file2.close();
		}
}

void login::verifyt2(std::string ID,std::string pass){
				ifstream file2("C:\\Users\\Sidharth\\Desktop\\trainer.txt");

	if(file2.is_open()){

			while(getline(file2,line)){
				istringstream xstream(line);
				vector<string> vcol;
				while(getline(xstream,word,',')){
					vcol.push_back(word);
				}
				vec.push_back(vcol);
			}
			for(int i=0;i<vec.size();i++){
//				cout<<vec[i][2]<<"\n";
				if(vec[i][2]==ID&&vec[i][3]==pass){
					t2_main obj;
					obj.LoginID=ID;
					obj.name=vec[i][1];
					obj.Load();
				}
			}
			file2.close();
		}
}

