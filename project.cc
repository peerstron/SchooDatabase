#include <iostream>
#include <string>
#include <fstream>
#include "database.h"
//#include <conio.h>

using namespace std;

string array[]={"admin", "staff", "student"};


short adminInBase;
short staffInBase;
short studentInBase;

void loginPage();

void adminPage();
void staffPage();
void studentPage();
bool signIn(string);




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
	Database db;
	string userId;
		cout<<"Welcome! Please login with your ID: "<<endl;
	cin>>userId;
	

	string user_type = db.fetchStatus(userId);
	if(signIn(userId)){

	if(user_type==array[0]){
		cout<<endl<<endl;
		cout<<"Welcome to Admin Page"<<endl;
		adminPage();
		cout<<endl<<endl;
	}

	else if(user_type==array[1]){

		cout<<"Welcome to Staff Page"<<endl;
		staffPage();
	}

	else if(user_type==array[2]){

		cout<<"Welcome to Student Page"<<endl;
	}
		
	}
	
}


void adminPage(){	//--------------------------------------------------------------------Admin Page
  system("clear");
  Database db;
	cout<<"Welcome Admin"<<endl<<endl;

	int choice;
	cout<<"Select 1 for staff page."<<endl;
	cout<<"Select 2 for student page."<<endl;
	cout<<"Select 3 for course page."<<endl;
	cout<<"Select 4 to Exit."<<endl;
	cin>>choice;

	if(choice==1){

		cout<<"Welcome Staff Details."<<endl<<endl;
		cout << "Select 1 to add staff\nSelect 2 to remove staff\n";
		int option;
		School staff_add;
		cin >> option;

		switch(option)
		{
			case 1:
				cout << "\t\tAdd Staff\n";
				cout << "Please enter staff id: ";
				cin >> staff_add.id;
				cout << "Please enter staff's first name: ";
				cin >> staff_add.firstname;
				cout << "Please enter staff's last name: ";
				cin >> staff_add.lastname;
				staff_add.level = "no-level";
				staff_add.program = "no-programme";
				cout << "Please enter staff's gender: ";
				cin >> staff_add.gender;
				cout << "Please enter staff's date of birth: ";
				cin >> staff_add.dob;
				staff_add.status = "staff";
				// calling the create function from database
				db.create(staff_add);

				int choose;
				cout << "Please enter 1 to continue: ";
				cin >> choose;
				if(choose == 1){
					adminPage();
				}
				break;
			
			case 2:
				cout << "\t\tEdit Staff\n";
				string staffId;
				cout << "Please enter the Staff's id you want to remove: ";
				cin >> staffId;
				// calling the remove method		
				db.remove(staffId);
				int choose1;
				cout << "Please enter 1 to continue: ";
				cin >> choose1;
				if(choose1 == 1){
					adminPage();
				}
				break;
		}

		
	}

	else if(choice==2){

		cout<<"Welcome Student Details."<<endl<<endl;
		cout << "Select 1 to add student\nSelect 2 to remove student\n";
		int option1;
		School student_add;
		cin >> option1;

		switch(option1)
		{
			case 1:
				cout << "\t\tAdd Student\n";
				cout << "Please enter staff id: ";
				cin >> student_add.id;
				cout << "Please enter staff's first name: ";
				cin >> student_add.firstname;
				cout << "Please enter staff's last name: ";
				cin >> student_add.lastname;
				student_add.level = "100";
				cout << "Please enter student's programme: ";
				cin >> student_add.program;
				cout << "Please enter staff's gender: ";
				cin >> student_add.gender;
				cout << "Please enter staff's date of birth: ";
				cin >> student_add.dob;
				student_add.status = "student";
				// calling the create function from database
				db.create(student_add);

				int choose2;
				cout << "Please enter 1 to continue: ";
				cin >> choose2;
				if(choose2 == 1){
					adminPage();
				}
				break;
			
			case 2:
				cout << "\t\tDelete Student\n";
				string studentId;
				cout << "Please enter the Student's id you want to remove: ";
				cin >> studentId;
				// calling the remove method		
				db.remove(studentId);
				int choose3;
				cout << "Please enter 1 to continue: ";
				cin >> choose3;
				if(choose3 == 1){
					adminPage();
				}
				break;
		}
		
	}

	else if(choice==3){

		cout<<"Welcome to Course Details."<<endl<<endl;
		cout << "Select 1 to add course\nSelect 2 to remove course\n";
		int option4;
		staff_course course_add;
		cin >> option4;

		switch(option4)
		{
			case 1:
				cout << "\t\tAdd Course\n";
				cout << "Please enter Course Code: ";
				cin >> course_add.course_code;
				cout << "Please enter Course Title: ";
				cin >> course_add.course_title;
				cout << "Please enter Course's Lecturer: ";
				cin >> course_add.course_lecturer;
				// calling the create function from database
				db.createCourse(course_add);

				int choose;
				cout << "Please enter 1 to continue: ";
				cin >> choose;
				if(choose == 1){
					adminPage();
				}
				break;
			
			case 2:
				cout << "\t\tRemove Course\n";
				string courseCode;
				cout << "Please enter the Course Code you want to remove: ";
				cin >> courseCode;
				// calling the remove method		
				db.deleteCourse(courseCode);
				int choose1;
				cout << "Please enter 1 to continue: ";
				cin >> choose1;
				if(choose1 == 1){
					adminPage();
				}
				break;
		}
	}

	else if(choice==4){

		cout << "Have a nice day\n";
		exit(1);
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

// for authentication
bool signIn(string user_id){
	Database db;
	if(db.authenticate(user_id)){
		return true;
	}
}
