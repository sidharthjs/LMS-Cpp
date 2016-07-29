#include "admin.h"
#include "login.h"
#include "admin_trainer.h"
#include "admin_course.h"
#include "admin_TM.h"
#include "admin_pm.h"
#include "attendance.h"
#include<iostream>
#include<string>
using namespace std;

void admin::Load(){
	system("cls");
	cout<<"\t\tAdmin Dashboard\n\n";
					admin_course b;
					admin_trainer trainer;
					admin_TM tm;
					admin_pm pm;

	while(1){
		cout<<"\nFunctions:\n1.Course\n2.Trainer\n3.Training Manager\n4.Project Manager\n5.Generate Attendance\n";
		cin>>choice;
		switch(choice){
			case '1':
				b.Load();
				break;
				
			case '2':
				trainer.Load();
				break;
				
			case '3':
				tm.Load();
				break;
				
			case '4':
				pm.Load();
				break;
				
			case '5':
				{
				attendance at;
				at.generate();
				break;
			}
				
			case 'b':
				login a;
				a.Load();
		}
	}
}
