#include "admin_pm.h"
#include "admin.h"
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

void admin_pm::Load(){
	system("cls");
	cout<<"\t\tAdmin - Training Manager\n\n";
	while(1){
	cout<<"\n1.View Project Manager\n2.Insert Project Manager\n";
	cin>>choice;
	switch(choice){
		case '1':
			cout<<"\n";
			view_pm();
			break;
		case '2':
			insert_pm();
			cout<<"\n\nProject Manager inserted\n\n";
			break;
		case 'b':
			admin a;
			a.Load();
			break;
	}
}
}

void admin_pm::view_pm(){
	vec.clear();
	fstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\pm.txt");
	if(file.is_open()){
	while(getline(file,line)){
		istringstream xstream(line);
		vector<string> vcol;
		while(getline(xstream,word,',')){
			vcol.push_back(word);
		}
		vec.push_back(vcol);
	}
	
	for(vector< vector<string> >::iterator itr=vec.begin();itr!=vec.end();itr++){
		for(vector<string>::iterator itr2=itr->begin();itr2!=itr->end();itr2++){
			cout<<*itr2<<",";
		}
		cout<<"\n";
	}
}
}

void admin_pm::insert_pm(){
	try{
		cin.ignore();
	cout<<"Enter Project Manager no:\n";
    getline(cin , no );
	cout<<"Enter Project Manager name:\n";
	getline(cin,name);
	cout<<"Enter Project Manager username:\n";
    getline(cin,username);
	cout<<"Enter Project Manager password:\n";
	getline(cin,password);
	ofstream file2;
	file2.open("C:\\Users\\Sidharth\\Desktop\\pm.txt",ios::app);
	file2<<no<<","<<name<<","<<username<<","<<password<<",\n";
	file2.close();
}catch(...){
	cout<<"Exception :(\n";
}
}
