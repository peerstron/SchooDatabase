#include <iostream>
#include <string>
#include <fstream>
//#include <conio.h>

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

void loginPage();

void adminPage();
void staffPage();
void studentPage();




int main(){

	cout<<"*****************************************************"<<endl;
	cout<<"**********WELCOME TO PEERS INSTITUTE SCHOOL**********"<<endl;
	cout<<"*****************MANAGEMENT SYSTEM*******************"<<endl;
	cout<<"*****************************************************"<<endl<<endl<<endl<<endl;


	int option;

		cout<<"****Please Select An Option To Continue****"<<endl;
		cout<<"Select 1 to Login"<<endl;
		cout<<"Select 2 to Exit"<<endl;
    cin>>option;

    if(option==1){

        system("clear");
        cout<<endl;
        loginPage();

    }
		else if(option==2){

        cout<<"Pragram terminated."<<endl;
    }
    else{

      cout<<"Invalid selection"<<endl;
    }

	return 0;
}


void loginPage(){
  system("clear");
	string userId;
	cout<<"Welcome! Please login with your ID: "<<endl;
	cin>>userId;

	if(userId==array[0]){
		cout<<endl<<endl;
		cout<<"Welcome to Admin Page"<<endl;
		adminPage();
		cout<<endl<<endl;
	}

	else if(userId==array[1]){

		cout<<"Welcome to Staff Page"<<endl;
		staffPage();
	}

	else if(userId==array[2]){

		cout<<"Welcome to Student Page"<<endl;
	}
}


void adminPage(){	//--------------------------------------------------------------------Admin Page
  system("clear");
	cout<<"Welcome Admin"<<endl<<endl;

	int choice;
	cout<<"Select 1 for staff page."<<endl;
	cout<<"Select 2 for student page."<<endl;
	cout<<"Select 3 for course page."<<endl;
	cin>>choice;

	if(choice==1){

		cout<<"Welcome Staff Details."<<endl<<endl;
	}

	else if(choice==2){

		cout<<"Welcome Student Details."<<endl<<endl;

	}

	else if(choice==3){

		cout<<"Welcome to Course Details."<<endl<<endl;
	}

}


void staffPage(){		//-------------------------------------------------------Staff page

  system("clear");
	cout<<"Welcome Staff"<<endl<<endl;

	int choice;
	cout<<"Select 1 for View Course."<<endl;
	cout<<"Select 2 for View students."<<endl;
	cout<<"Select 3 for A."<<endl;
	cin>>choice;

	if(choice==1){

		cout<<"Welcome"<<endl<<endl;
	}

	else if(choice==2){

		cout<<"Welcome"<<endl<<endl;
	}

	else if(choice==3){

		cout<<"Welcome"<<endl<<endl;
	}

}
