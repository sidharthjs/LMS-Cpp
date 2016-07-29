#include "registeration.h"
#include "login.h"
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
void registeration::Load(){
	cout<<"\t\t\tNew User Registeration:\n\n";
				login b;
	while(1){
	cout<<"\nFunctions:\n1-Registeration\nb-Back\n";
	cin>>choice;
	switch(choice){
		case '1':
			getdata();
			storedata();
			break;
		case 'b':
			b.Load();
			break;
		default:
			cout<<"Value choosed is not a valid option\n";
			break;
	}
}
	
}

void registeration::getdata(){
	cin.ignore();
	cout<<"Enter your name:\n";
	getline(cin,name);
	cout<<"Enter your mail-id:\n";
	getline(cin,mailid);
	cout<<"Enter your username:\n";
	getline(cin,username);
	cout<<"Enter your password:\n";
	getline(cin,password);
	cout<<"Enter your phone:\n";
	getline(cin,phone);
	cout<<"Enter your department:\n";
	getline(cin,department);
	cout<<"Enter your address:\n";
	getline(cin,address);
}

void registeration::storedata(){
	ofstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\registeration.txt",ios::app);
	file<<name<<","<<mailid<<","<<username<<","<<password<<","<<phone<<","<<department<<","<<address<<","<<"\n";
	file.close();
	cout<<"Successfully Registered\n\n";
}

