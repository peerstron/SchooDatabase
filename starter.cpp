#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

string array[]={"admin", "staff", "student"};

struct User{
	
	string id;
	string lastName;
	string firstName;
	string level;
	string programme;
	string gender;
	string dob;
};

User admin[5];
User staff;
User student;

short adminInBase;
short staffInBase;
short studentInBase;

void mustEnter();
void loginPage();

int main(){
	
	cout<<"*****************************************************"<<endl;
	cout<<"**********WELCOME TO PEERS INSTITUTE SCHOOL**********"<<endl;
	cout<<"*****************MANAGEMENT SYSTEM*******************"<<endl;
	cout<<"*****************************************************"<<endl<<endl<<endl<<endl;
	
	char option;
	do{
		
		cout<<"****Please Select An Option To Continue****"<<endl;
		cout<<"Select 1 to Login"<<endl;
		cout<<"Select 2 to Exit"<<endl;

		
		option = getch();
		
		switch(option)
		{
			case '1':
				system("cls");
				cout<<endl<<endl;
				loginPage();
				break;
				
			case '2':
				system("cls");
				cout<<endl<<endl;

				break;

		}
		mustEnter();
		system("cls");
	}
	while (option != 27);
	
	return 0;
}


void mustEnter(){
	cout<<"Press enter to continue..."<<endl;
	while(getch() != 13);
}


void loginPage(){
	
	string userId;
	cout<<"Welcome! Please login with your ID: "<<endl;
	cin>>userId;
	
	if(userId==array[0]){
		
		cout<<"Welcome to Admin Page"<<endl;
	}
	
	else if(userId==array[1]){
		
		cout<<"Welcome to Staff Page"<<endl;
	}
	
	else if(userId==array[2]){
		
		cout<<"Welcome to Student Page"<<endl;
	}
}


void admin(){
	
	
	
	
}
