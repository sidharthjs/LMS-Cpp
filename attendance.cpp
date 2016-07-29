#include "attendance.h"
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<sstream>
#include<fstream>
using namespace std;

void attendance::Load(){
	system("cls");
}

void attendance::generate(){
	get_approve_list();
	ofstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\attendance.txt",ios::app);
	file<<"Date,";
	for(int i=0;i<vec_list.size();i++){
		file<<vec_list[i][0]<<"-"<<vec_list[i][3]<<",";
	}
	file<<"\n";
	file.close();
	cout<<"Successfully Generated\n\n";
}

void attendance::get_approve_list(){
	vec_list.clear();
	fstream file;
	file.open("C:\\Users\\Sidharth\\Desktop\\approve.txt");
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
}
