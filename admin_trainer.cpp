#include "admin_trainer.h"
#include "admin.h"
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

void admin_trainer::Load(){
	system("cls");
	cout<<"\t\tAdmin - Trainer\n\n";
	while(1){
	cout<<"\n1.View Trainers\n2.Insert Trainer\n";
	cin>>choice;
	switch(choice){
		case '1':
			cout<<"\n";
			view_trainer();
			break;
		case '2':
			insert_trainer();
			cout<<"\n\nTrainer inserted\n\n";
			break;
		case 'b':
			admin a;
			a.Load();
			break;
	}
}
}

void admin_trainer::view_trainer(){
	vec.clear();
	fstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\trainer.txt");
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

void admin_trainer::insert_trainer(){
	try{
		cin.ignore();
	cout<<"Enter Trainer no:\n";
    std::getline(std::cin , no );
	cout<<"Enter Trainer name:\n";
	std::getline(std::cin,name);
	cout<<"Enter Trainer username:\n";
    cin>>username;
	cout<<"Enter Trainer password:\n";
	cin>>password;
	ofstream file2;
	file2.open("C:\\Users\\Sidharth\\Desktop\\trainer.txt",ios::app);
	file2<<no<<","<<name<<","<<username<<","<<password<<",\n";
	file2.close();
}catch(...){
	cout<<"Exception :(\n";
}
}
