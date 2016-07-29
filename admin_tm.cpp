#include "admin_tm.h"
#include "admin.h"
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

void admin_TM::Load(){
	system("cls");
	cout<<"\t\tAdmin - Training Manager\n\n";
	while(1){
	cout<<"\n1.View Training Manager\n2.Insert Training Manager\n";
	cin>>choice;
	switch(choice){
		case '1':
			cout<<"\n";
			view_tm();
			break;
		case '2':
			insert_tm();
			cout<<"\n\nTraining Manager inserted\n\n";
			break;
		case 'b':
			admin a;
			a.Load();
			break;
	}
}
}

void admin_TM::view_tm(){
	vec.clear();
	fstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\tm.txt");
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

void admin_TM::insert_tm(){
	try{
		cin.ignore();
	cout<<"Enter Training Manager no:\n";
    getline(cin , no );
	cout<<"Enter Training Manager name:\n";
	std::getline(std::cin,name);
	cout<<"Enter Training Manager username:\n";
    cin>>username;
	cout<<"Enter Training Manager password:\n";
	cin>>password;
	ofstream file2;
	file2.open("C:\\Users\\Sidharth\\Desktop\\tm.txt",ios::app);
	file2<<no<<","<<name<<","<<username<<","<<password<<",\n";
	file2.close();
}catch(...){
	cout<<"Exception :(\n";
}
}
