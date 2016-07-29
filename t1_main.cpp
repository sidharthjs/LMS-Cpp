#include "t1_main.h"
#include"login.h"
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;
void t1_main::Load(){
	system("cls");
	while(1){
			cout<<"Welcome "<<LoginID<<"\n\n";
		cout<<"\t\t\tList of courses Available:\n";
		get_courses();
		display_courses();
		cout<<"\nEnter the respective course no. to apply\nm-My cources.\nb-Back\n";
	    cin>>choice;
	    if(choice=="b"){
	    	login a;
	    	a.Load();
	    }
	    else if(choice=="m"){
	    	my_courses();
		}
	    else{
	    	system("cls");
	    	course_click();
	    }
	}
}

void t1_main::get_courses(){
		vec.clear();
	fstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\course.txt");
	if(file.is_open()){
	while(getline(file,line)){
		istringstream xstream(line);
		vector<string> vcol;
		while(getline(xstream,word,',')){
			vcol.push_back(word);
		}
		vec.push_back(vcol);
	}
	
}
    else
    cout<<"File open error\n";
}


void t1_main::display_courses(){
	if(!vec.empty()){
	for(int i=0;i<vec.size();i++){
		//(courseno,course name,duration,description)
		cout<<"\t\t\t"<<vec[i][0]<<"-"<<vec[i][1]<<"\n";
	}		
	}
}

void t1_main::course_click(){
    char c='0';
	for(int i=0;i<vec.size();i++)
	if(vec[i][0]==choice){
	cout<<"Course no.: ";
	try{
	cout<<vec[i][0]<<"\n";
	cout<<"Course title: ";
	cout<<vec[i][1]<<"\n";
	cout<<"Course duration: ";
	cout<<vec[i][2]<<"\n";
	cout<<"Course description: ";
	cout<<vec[i][3]<<"\n\n\n";
}catch(...){
	cout<<"Exception:(\n";
}
	cout<<"1.Apply this course\nb.Back\n";
	cin>>c;
	switch(c){
		case '1':
		{
			
			ofstream file2;
	        file2.open("C:\\Users\\Sidharth\\Desktop\\apply.txt",ios::app);
	        file2<<LoginID<<","<<name<<","<<vec[i][0]<<","<<vec[i][1]<<",\n";
	        cout<<"Successfully applied for "<<vec[i][1]<<"\n\n";
	        file2.close();
	    }
	    
	    default:
	    	system("cls");
	    	break;
	}
	break;
}
}

void t1_main::my_courses(){
	//Get_courses in approve.txt
	string p;
		mycourses.clear();
	fstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\approve.txt");
	if(file.is_open()){
	while(getline(file,line)){
		istringstream xstream(line);
		vector<string> vcol;
		while(getline(xstream,word,',')){
			vcol.push_back(word);
		}
		mycourses.push_back(vcol);
	}  
    }
    while(1){
    cout<<"Your enrolled courses:\n";
    for(int i=0;i<mycourses.size();i++){
    	if(mycourses[i][0]==LoginID){
    		cout<<mycourses[i][2]<<"-"<<mycourses[i][3]<<"\n";
    	}
    }
    
    cout<<"\nEnter respective course number to give feedback\nb-back\n";
    cin>>p;
    if(p=="b"){
    Load();
    }
    else{
        for(int i=0;i<mycourses.size();i++){
    	if(mycourses[i][2]==p){
    		cout<<"Enter feedback for "<<mycourses[i][2]<<"-"<<mycourses[i][3]<<":\n";
    		cin.ignore();
    		getline(cin,feedback);
    		
    			vec_trainer.clear();
	fstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\approve_courses.txt");
	if(file.is_open()){
	while(getline(file,line)){
		istringstream xstream(line);
		vector<string> vcol;
		while(getline(xstream,word,',')){
			vcol.push_back(word);
		}
		vec_trainer.push_back(vcol);
	}  
    }
        for(int j=0;j<vec_trainer.size();j++){
        	if(vec_trainer[j][2]==p){
        		trainer_no=vec_trainer[j][0];
        		trainer_name=vec_trainer[j][1];
        		break;
        	}
        }
        ofstream file3;
	        file3.open("C:\\Users\\Sidharth\\Desktop\\feedback.txt",ios::app);
	        file3<<LoginID<<","<<name<<","<<mycourses[i][2]<<","<<mycourses[i][3]<<","<<trainer_no<<","<<trainer_name<<","<<feedback<<",\n";
	        cout<<"\n\nFeedback for "<<mycourses[i][2]<<"-"<<mycourses[i][3]<<" successfully sent\n\n\n";
	        p="0";
	        file3.close();
        
    
    	}
    }
    }
	}
}

