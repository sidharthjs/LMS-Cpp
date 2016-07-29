#include "tm_main.h"
#include "login.h"
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;
void tm_main::Load(){
	system("cls");
	cout<<"Welcome "<<LoginID<<"\n\n";
	while(1){
		cout<<"\t\t\tTraining Managaer Dashboard\n";
		cout<<"1.Allocate courses to trainers\n2.View Attendance\n3.View Feedback\nb.Back\n";
	    cin>>choice;
	    if(choice=="b"){
	    	login a;
	    	a.Load();
	    }
	    else if(choice=="1"){
	    	get_courses();
	    	get_trainers();
	    	approve_courses();
	    	cout<<"Finished approval\n";
	    }
	    else if(choice=="2"){
	    	cin.ignore();
	    	view_attendance();
	    }
	}
}

void tm_main::approve_courses(){
	cout<<"\n\nTrainer list:\n";
	for(int i=0;i<vec_trainers.size();i++){
	cout<<i+1<<"-"<<vec_trainers[i][2]<<"\n";
    }
    cout<<"Select appropriate number for approving the respective trainer:\n0-Don't Allocate\n'";
    int p;
    for(int i=0;i<vec_courses.size();i++){
    cout<<"("<<i+1<<"/"<<vec_courses.size()<<")"<<" Approve for "<<vec_courses[i][1]<<"\t";
    cin>>p;
    if(p!=0){
    ofstream file2;
	file2.open("C:\\Users\\Sidharth\\Desktop\\approve_courses.txt",ios::app);
	file2<<vec_trainers[p-1][0]<<","<<vec_trainers[p-1][1]<<","<<vec_courses[i][0]<<","<<vec_courses[i][1]<<",\n";
	file2.close();
    }
    }
    system("cls");
}

void tm_main::get_courses(){
		vec_courses.clear();
	fstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\course.txt");
	if(file.is_open()){
	while(getline(file,line)){
		istringstream xstream(line);
		vector<string> vcol;
		while(getline(xstream,word,',')){
			vcol.push_back(word);
		}
		vec_courses.push_back(vcol);
	}
	
}
    else
    cout<<"File open error\n";
}

void tm_main::get_trainers(){
		vec_trainers.clear();
	fstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\trainer.txt");
	if(file.is_open()){
	while(getline(file,line)){
		istringstream xstream(line);
		vector<string> vcol;
		while(getline(xstream,word,',')){
			vcol.push_back(word);
		}
		vec_trainers.push_back(vcol);
	}
	file.close();
}
    else
    cout<<"File open error\n";
}

void tm_main::view_attendance(){
	while(1){
		vec_att.clear();
		ifstream file;
		file.open("C:\\Users\\Sidharth\\Desktop\\attendance.txt");
		while(getline(file,line)){
		istringstream xstream(line);
		vector<string> vcol;
		col=-1;
		while(getline(xstream,word,',')){
			vcol.push_back(word);
			col++;
		}
		vec_att.push_back(vcol);
	}
	file.close();
	
	string date;
	cout<<"\nSelect any of the following dates:\n";
	for(int i=1;i<vec_att.size();i++){
		cout<<vec_att[i][0]<<"\n";
	}
	getline(cin,date);
	if(date=="b")
	Load();
	for(int i=1;i<vec_att.size();i++){
		if(vec_att[i][0]==date){
			row=i;
			break;
		}
	}
	for(int q=1;q<col;q++){
		if(vec_att[row][q]=="1")
		cout<<vec_att[0][q]<<" Present\n";
		else if(vec_att[row][q]=="0")
		cout<<vec_att[0][q]<<" Absent\n";
	}
}
}


