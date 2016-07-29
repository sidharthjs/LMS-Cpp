#include "t2_main.h"
#include "login.h"
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include<vector>
using namespace std;
void t2_main::Load(){
	while(1){
	system("cls");
	name=get_name(LoginID);
	my_course=get_course(name);
	cout<<"Course="<<my_course<<"\n";
		cout<<"Name="<<name<<"\n";
	cout<<"Welcome"<<name<<":\n";
	cout<<"\t\tTrainer Dashboard\n\n";
	char p;
	cout<<"1.Select Date\n2.Add Date\nb-Back\n";
	cin>>p;
	switch(p){
		case '1':
			select_date();
			break;
		case '2':
			add_date();
			break;
		case 'b':
			{
			login obj;
			obj.Load();
			break;
		}
	}
    }
}

string t2_main::get_name(string ID){
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
    }
    
    file.close();
    for(int i=0;i<vec_trainers.size();i++)
    if(ID==vec_trainers[i][2]){
    return vec_trainers[i][1];
}
    return "not found";
}

string t2_main::get_course(string ID){
	vec_approve_courses.clear();
	fstream file2;
	file2.open("C:\\Users\\Sidharth\\Desktop\\approve_courses.txt");
	if(file2.is_open()){
	while(getline(file2,line)){
		istringstream xstream(line);
		vector<string> vcol;
		while(getline(xstream,word,',')){
			vcol.push_back(word);
		}
		vec_approve_courses.push_back(vcol);
	}  
    }
    file2.close();
    
    for(int i=0;i<vec_approve_courses.size();i++)
    if(ID==vec_approve_courses[i][1])
    return vec_approve_courses[i][3];
    return "not found";
}

void t2_main::select_date(){
	string date;
//	system("cls");
	vec_att.clear();
	fstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\attendance.txt");
	if(file.is_open()){
	while(getline(file,line)){
		istringstream xstream(line);
		vector<string> vcol;
		while(getline(xstream,word,',')){
			vcol.push_back(word);
		}
		vec_att.push_back(vcol);
	}  
    }
    file.close();
    
    if(vec_att.size()==1)
    cout<<"Attendance database is empty\n";
    
    else{
    	cout<<"Select any of the following Dates:\n";
    	for(int i=1;i<vec_att.size();i++)
    	cout<<vec_att[i][0]<<"\n";
    }
        cin.ignore();
    getline(cin,date);
    if(date=="b")
    Load();
    for(int i=1;i<vec_att.size();i++)
    	if(date==vec_att[i][0]){
    	row=i;
    	take_attendance(date);
    	break;
    }
    
}

void t2_main::take_attendance(string date){
//	system("cls");
	vec_approve.clear();
	fstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\approve.txt");
	if(file.is_open()){
	while(getline(file,line)){
		istringstream xstream(line);
		vector<string> vcol;
		while(getline(xstream,word,',')){
			vcol.push_back(word);
		}
		vec_approve.push_back(vcol);
	}  
    }
    
    vec_my_mates.clear();
    for(int i=0;i<vec_approve.size();i++){
    	cout<<"Generating my mates";
    	if(vec_approve[i][3]==my_course)
    	vec_my_mates.push_back(vec_approve[i]);
    }
    cout<<"mymates size="<<vec_my_mates.size();
    
    vec_att2.clear();
	ifstream file5;
	file5.open("C:\\Users\\Sidharth\\Desktop\\attendance.txt",ios::in);
	if(file5.is_open()){
		cout<<"Reading in att2";
	while(getline(file5,line)){
		istringstream xstream(line);
		vector<string> vcol;
		while(getline(xstream,word,',')){
			vcol.push_back(word);
		}
		vec_att2.push_back(vcol);
	}  
    }
        file5.close();
            cout<<"size of att2="<<vec_att2.size();


        int a=0;
    cout<<"my_mates_vector size="<<vec_my_mates.size()<<"\n";
    cout<<"1-Present\n0-Absent\n";
    for(int k=0;k<vec_my_mates.size();k++){
    	cout<<"("<<k+1<<"/"<<vec_my_mates.size()<<") "<<vec_my_mates[k][1]<<" - \t";
    	cin>>a;
    	ifstream file4;
	    file4.open("C:\\Users\\Sidharth\\Desktop\\attendance.txt");
	    getline(file4,line);
	    istringstream linestream(line);
	    col=-1;
	    while(getline(linestream,word,',')){
	    	col++;
	    	istringstream wordstream(word);
	    	vector<string> vec_word2;
	    	while(getline(wordstream,word2,'-')){
	    		vec_word2.push_back(word2);
	    }
	    	if(vec_word2[0]==vec_my_mates[k][0]&&vec_word2[1]==my_course){
	    		if(a==1)
	    		vec_att2[row][col]="1";
	    		else if(a==0)
	    		vec_att2[row][col]="0";
	    	}
	    	
	    }
    }
    cout<<"size of att2="<<vec_att2.size();
    ofstream file6;
	file6.open("C:\\Users\\Sidharth\\Desktop\\attendance.txt",ios::out);
	for(vector< vector<string> >::iterator itr=vec_att2.begin();itr!=vec_att2.end();itr++){
		for(vector<string>::iterator itr2=itr->begin();itr2!=itr->end();itr2++){
			file6<<*itr2<<",";
		}
		file6<<"\n";
	}
	file6.close();
    
    
}

void t2_main::add_date(){
	string pdate;
	cout<<"Enter the date:\n";
	cin>>pdate;
	if(pdate=="b")
	Load();
	fstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\attendance.txt",ios::app|ios::in|ios::out);
	getline(file,line);
	vector<string> vcol;
	istringstream xstream(line);
	while(getline(xstream,word,','))
	vcol.push_back(word);
	int no=vcol.size();
		


	file<<pdate;
	for(int i=0;i<vcol.size();i++)
	file<<",";
	file<<"\n";
	file.close();
	cout<<"Successfully added "<<pdate<<"\n";
}

