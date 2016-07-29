#include "admin_course.h"
#include "admin.h"
#include<string>
#include<vector>
#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void admin_course::Load(){
	system("cls");
	cout<<"\t\tAdmin - Courses\n\n";
	while(1){
		cout<<"\nFunctions:\n1.View Course\n2.Insert Course\n\n";
		cin>>choice;
		cin.ignore();
		switch(choice){
			case '1':
				view_course();
				break;
			case '2':
				cout<<"(1/4)Enter course number:\n";
				getline(cin,courseno);
				cout<<"(2/4)Enter course title:\n";
				getline(cin,title);
				cout<<"(3/4)Enter duration:\n";
				getline(cin,duration);
				cout<<"(4/4)Enter description:\n";
				getline(cin,description);
				
				insert_course();
				cout<<"\nCourse inserted\n";
				break;
				
			case 'b':
				admin obj;
				obj.Load();
		}
	}
}

void admin_course::view_course(){
	if(vec.empty()){
	
	ifstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\course.txt");
	if(file.is_open()){
		
		while(getline(file,line)){
			istringstream xstream(line);
			vector<string> vcol;
			while(getline(xstream,word,','))
			{
				vcol.push_back(word);
			}
			vec.push_back(vcol);
		}
	}
	file.close();
}
	
	for(vector< vector<string> >::iterator itr=vec.begin();itr!=vec.end();itr++){
		for(vector<string>::iterator itr2=itr->begin();itr2!=itr->end();itr2++){
			cout<<*itr2<<",";
		}
		cout<<"\n";
	}
}

void admin_course::insert_course(){
	ofstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\course.txt",ios::app);
	file<<courseno<<","<<title<<","<<duration<<","<<description<<",\n";
	file.close();
}
