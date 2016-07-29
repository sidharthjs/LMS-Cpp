#include "pm_main.h"
#include "login.h"
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
#include<stdlib.h>
#include<vector>
using namespace std;

void pm_main::Load(){
	system("cls");
	cout<<"Welcome "<<LoginID<<"\n\n";
	while(1){
		cout<<"\t\t\tProject Managaer Dashboard\n";
		cout<<"1.Approve Trainees\n2.View status of Trainers\n3.View status of Trainees\nb.Back\n";
	    cin>>choice;
	    if(choice=="b"){
	    	login a;
	    	a.Load();
	    }
	    else if(choice=="1"){
	    	get_list();
	    	approve();
	    	cout<<"Finished approval\n";
	    }
	    else{
	    }
	}
}

void pm_main::get_list(){
	vec_list.clear();
	fstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\apply.txt");
	if(file.is_open()){
	while(getline(file,line)){
		istringstream xstream(line);
		vector<string> vcol;
		while(getline(xstream,word,',')){
			vcol.push_back(word);
		}
			vec_list.push_back(vcol);

	}
	
}
    else
    cout<<"File open error\n";
}

void pm_main::approve(){
    cout<<"1-Approve\n0-Don't Allocate\n'";
    int p;
    for(int i=0;i<vec_list.size();i++){
    cout<<"("<<i+1<<"/"<<vec_list.size()<<")"<<" Approve "<<vec_list[i][1]<<" for "<<vec_list[i][2]<<"-"<<vec_list[i][3]<<"?\t";
    cin>>p;
    if(p==1){
    ofstream file2;
	file2.open("C:\\Users\\Sidharth\\Desktop\\approve.txt",ios::app);
	file2<<vec_list[i][0]<<","<<vec_list[i][1]<<","<<vec_list[i][2]<<","<<vec_list[i][3]<<",\n";
	file2.close();
    }
    }
    system("cls");
}
