
#ifndef INCLUDES_H
#define INCLUDES_H

/**
 * this includes header file that contains all files from the whole program
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "datatypes.h"
#include "databaseUser.h"
#include "databaseCourse.h"
#include "../libraries/auth.h"

// namespaces
using namespace std;

// Function prototypes
void start_application();
int checkInt(int);
void login_screen();
void start_screen_for_admin(string);
void add_or_remove_staff(string);
void add_staff(string);
void remove_staff(string);
void add_or_remove_student(string);
void add_student(string);
void remove_student(string);
void add_admin(string);
void edit_account(string);
void add_or_remove_course(string);
void start_screen_for_staff(string);
void start_screen_for_student(string);
void view_student_courses(string);
void edit_student_details(string);
void add_courses_student(string);
void remove_course_student(string);
int checkForStudent(int);
int checkForStaff(int);
int checkForScores(int);
int validateToContinue(int);
void add_course(string);
void edit_course(string);
void remove_course(string);
void add_course_grades(string);
void add_IA(string);
void add_scores_and_grades(string indexNumber);
string index_number_generator();

// ************FUNCTIONS FOR THE APPLICATION*************************


void start_application()
{
    cout << "\t\t\t\t\t\t PEERS INSTITUTE SCHOOL MANAGEMENT SYSTEM\n";
    cout << "Welcome ...\n";
    cout << "Select 1 to Login \nSelect 2 to Exit\n";
    int choice;
    cin >> choice;
    switch(checkInt(choice))
    {
        case 1: 
            login_screen();
            break;
        case 2:
            cout << "Have a nice day :)\n";
            exit(1);
            break;

    }
}

int checkInt(int a)
{
    while(cin.fail() || a > 2 || a < 1)
    {
        cin.clear();
        cin.ignore(200,'\n');
        cout << "Please enter correct valid input: ";
        cin >> a;
    }
    return a;
}

void login_screen()
{
    system("clear");
    User user;
    Database_User db;
    cout << "\t\t\t\t\t\t PEERS INSTITUTE SCHOOL MANAGEMENT SYSTEM\n";
    cout << "Welcome! Please login with your ID: \n";
    cout << "Index Number: ";
    cin >> user.index_number;
    cout << endl; 
    Auth login;
    string status;
    if(login.signIn(user.index_number))
    {
        status = db.returnStatus(user.index_number);
        if(status == "1"){
            // return screen for admin
            start_screen_for_admin(user.index_number);
        }else 
        if(status == "2"){
            // return screen for staff
            start_screen_for_staff(user.index_number);
        }else 
        if(status == "3"){
            // return screen for student
            start_screen_for_student(user.index_number);
        }
    }else{
        cout << "Invalid details!!\n";
    }

}

void start_screen_for_admin(string indexNumber)
{
    system("clear");
    Database_User db; 
    cout << "\t\t\t\t\t\t PEERS INSTITUTE SCHOOL MANAGEMENT SYSTEM ADMIN PORTAL\n";
    cout << "Select 1 for staff page\nSelect 2 for student page\nSelect 3 to add Admin\nSelect 4 to Edit Account\nSelect 5 for course page\nSelect 6 to Logout\n";
    int choice;
    cin >> choice;

    if(choice == 1){
        // add or remove staff
        add_or_remove_staff(indexNumber);
    }else
    if(choice == 2){
        // add or remove student
        add_or_remove_student(indexNumber);
    }else
    if(choice == 3){
        // add admin
        add_admin(indexNumber);
    }else 
    if(choice == 4)
    {
        // edit account
        edit_account(indexNumber);
    }else
    if(choice == 5){
        // add_or_remove_course
        add_or_remove_course(indexNumber);
    }else
    if(choice == 6){
        // logout
        start_application();
    }

}

void add_or_remove_course(string indexNumber){
    system("clear");
    Database_User db_user;
    cout << "\t\t\t\t\t\t PEERS INSTITUTE SCHOOL MANAGEMENT SYSTEM ADMIN PORTAL\n";
    cout << "\tWelcome " << db_user.returnName(indexNumber) << endl;
    cout << "Select 1 to add course\nSelect 2 to edit course\nSelect 3 to remove course\nSelect 4 to go back\n";
    int choice;
    cin >> choice;
    

    if(choice == 1){
        // add course
        add_course(indexNumber);
    }else
    if(choice == 2){
        // edit course
        edit_course(indexNumber);
    }else
    if(choice == 3){
        // remove course
        remove_course(indexNumber);
    }else
    if(choice == 4){
        // Go back
        start_screen_for_admin(indexNumber);
    }
}

void add_admin(string indexNumber)
{
    User user;
    Database_User db;
    cout << "Enter first name: ";
    cin >> user.first_name;
    cout << "Enter last name: ";
    cin >> user.last_name;
    user.level = "admin";
    cout << "Please enter sex(m or f): ";
    cin >> user.sex;
    user.department = "no-department";
    user.status = "1";
    cout << "Please enter id: ";
    cin >> user.index_number;
    // calling the create user from database class
    db.createUser(user);

    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    
    if(validateToContinue(choice) == 1){
        start_screen_for_admin(indexNumber);
    }
}

void edit_account(string indexNumber)
{
    User user;
    Database_User db;
    cout << "Enter first name: ";
    cin >> user.first_name;
    cout << "Enter last name: ";
    cin >> user.last_name;
    user.level = "admin";
    cout << "Please enter sex(m or f): ";
    cin >> user.sex;
    user.department = "no-department";
    user.status = "1";
    user.index_number = indexNumber;
    // calling the create user from database class
    db.udpdateUser(user);    

    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    
    if(validateToContinue(choice) == 1){
        start_screen_for_admin(indexNumber);
    }
}

void add_or_remove_staff(string indexNumber)
{
    system("clear");
    Database_User db_user;
    cout << "\t\t\t\t\t\t PEERS INSTITUTE SCHOOL MANAGEMENT SYSTEM ADMIN PORTAL\n";
    cout << "\tWelcome " << db_user.returnName(indexNumber) << endl;
    cout << "Select 1 to add staff\nSelect 2 to remove Staff\nSelect 3 to go back\n";
    int choice;
    cin >> choice;
    

    if(checkForScores(choice) == 1){
        // add staff
        add_staff(indexNumber);
    }else
    if(checkForScores(choice) == 2){
        // add or remove student
        remove_staff(indexNumber);
    }else
    if(checkForScores(choice) == 3){
        // Go back
        start_screen_for_admin(indexNumber);
    }

}

void add_staff(string indexNumber)
{
    User user;
    Database_User db_user;
    cout << "Please enter first name: ";
    cin >> user.first_name;
    cout << "Please enter last name: ";
    cin >> user.last_name;
    user.level = "staff";
    cout << "Please enter sex(m or f): ";
    cin >> user.sex;
    user.department = "no-department";
    user.status = "2";
    cout << "Please enter id: ";
    cin >> user.index_number;

    // calling the create database method
    db_user.createUser(user);

    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    
    if(validateToContinue(choice) == 1){
        add_or_remove_staff(indexNumber);
    }
}

void remove_staff(string indexNumber)
{
    string search_id;
    Database_User db_user;
    cout << "Please enter the Staff's id you want to remove: ";
    cin >> search_id;
    // calling the deleteUser from database
    db_user.deleteUser(search_id);
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    
    if(validateToContinue(choice) == 1){
        add_or_remove_staff(indexNumber);
    }
}
void add_or_remove_student(string indexNumber)
{
    system("clear");
    Database_User db_user;
    cout << "\t\t\t\t\t\t PEERS INSTITUTE SCHOOL MANAGEMENT SYSTEM ADMIN PORTAL\n";
    cout << "\tWelcome " << db_user.returnName(indexNumber) << endl;
    cout << "Select 1 to add student\nSelect 2 to remove student\nSelect 3 to go back\n";
    int choice;
    cin >> choice;
    
    if(checkForScores(choice) == 1){
        // add staff
        add_student(indexNumber);
    }else
    if(checkForScores(choice) == 2){
        // add or remove student
        remove_student(indexNumber);
    }else
    if(checkForScores(choice) == 3){
        // logout
        start_screen_for_admin(indexNumber);
    }
}

void add_student(string indexNumber)
{
    User user;
    Database_User db_user;
    cout << "Please enter first name: ";
    cin >> user.first_name;
    cout << "Please enter last name: ";
    cin >> user.last_name;
    user.level = "100";
    cout << "Please enter sex(m or f): ";
    cin >> user.sex;
    cout << "Please enter deparment with all words together: ";
    cin >> user.department;
    user.status = "3";
    cout << "Please enter index number: ";
    cin >> user.index_number;

    // calling the create database method
    db_user.createUser(user);
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    
    if(validateToContinue(choice) == 1){
        add_or_remove_student(indexNumber);
    }
}

void remove_student(string indexNumber)
{
    string search_id;
    Database_User db_user;
    cout << "Please enter the Student's id you want to remove: ";
    cin >> search_id;
    // calling the deleteUser from database
    db_user.deleteUser(search_id);

    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    
    if(validateToContinue(choice) == 1){
        add_or_remove_student(indexNumber);
    }
}

void start_screen_for_staff(string indexNumber)
{
    system("clear");
    Database_User db_user;
    cout << "\t\t\t\t\t\t PEERS INSTITUTE SCHOOL MANAGEMENT SYSTEM STAFF PORTAL\n";
    cout << "\tWelcome " << db_user.returnName(indexNumber) << endl;
    cout << "Select 1 to add Course Grades And Marks\nSelect 2 to Logout\n";
    int choice;
    cin >> choice;
 
    if(choice == 1){
        // add course grades and marks
        add_scores_and_grades(indexNumber);
        
    }else
    if(choice == 2){
        // logout
        start_application();
    }
}

void add_scores_and_grades(string indexNumber)
{
    system("clear");
    Database_User db_user;
    cout << "\t\t\t\t\t\t PEERS INSTITUTE SCHOOL MANAGEMENT SYSTEM STAFF PORTAL\n";
        cout << "\tWelcome " << db_user.returnName(indexNumber) << endl;
        cout << "Select 1 to add IA marks\nSelect 2 to add Exam Score and Grade\n3. Go back\n";
        int choice;
        cin >> choice;
        
        if(checkForScores(choice) == 1){
            // Add IA marks
            add_IA(indexNumber);
        }else 
        if(checkForScores(choice) == 2) {
            // add exams and grade
            add_course_grades(indexNumber);
        }else
        if(checkForScores(choice) == 3){
            // go back
            start_screen_for_staff(indexNumber);
        }
}

void add_IA(string indexNumber)
{
    Database_course db_course;
    student_course course;
    cout << "Please enter the id of the user: ";
    cin >> course.student_index;
    cout << "Please enter course code: ";
    cin >> course.course_code;
    cout << "Please enter the mark of the student: ";
    cin >> course.student_mark_IA;
    // calling the assign ia mark method
    // db_course.assign_IA_marks(course.student_index,course.course_code,course.student_mark_IA);
    if(db_course.assign_IA_marks(course.student_index,course.course_code,course.student_mark_IA)){
        cout << "Successfully updated the record of " << course.student_index << endl;
    }
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
   
    if(validateToContinue(choice) == 1){
        add_scores_and_grades(indexNumber);
    }

}

void add_course_grades(string indexNumber)
{
    Database_course db_course;
    student_course course;
    cout << "Please enter the id of the user: ";
    cin >> course.student_index;
    cout << "Please enter course code: ";
    cin >> course.course_code;
    cout << "Please enter the mark of the student: ";
    cin >> course.student_mark_EXAM;
    // calling the assign exam mark and exam grade
    if(db_course.assign_EXAM_marks(course.student_index,course.course_code,course.student_mark_EXAM)){
        cout << "Successfully Updated the record of " << course.student_index << endl;
    }
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    
    if(validateToContinue(choice) == 1){
        add_scores_and_grades(indexNumber);
    }
}

void add_course(string indexNumber)
{
    Database_course db_course;
    staff_course course;
    cout << "Please enter course code: ";
    cin >> course.course_code;
    cout  << "Please enter course title: ";
    cin >> course.course_title;
    cout << "Please enter course lecturer: ";
    cin >> course.course_lecturer;
    // calling the create method
    db_course.create(course);

    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    
    if(validateToContinue(choice) == 1){
        add_or_remove_course(indexNumber);
    }
}

void edit_course(string indexNumber)
{
    Database_course db_course;
    staff_course course;
    cout << "Please enter course code: ";
    cin >> course.course_code;
    cout  << "Please enter course title: ";
    cin >> course.course_title;
    cout << "Please enter course lecturer: ";
    cin >> course.course_lecturer;
    // calling the update method
    db_course.updateCourse(course);
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    
    if(validateToContinue(choice) == 1){
        add_or_remove_course(indexNumber);
    }
}

void remove_course(string indexNumber)
{
    Database_course db_course;
    string course_code;
    cout << "Please type in the corresponding course code you want to delete: ";
    cin >> course_code;
    // calling the delete method
    db_course.deleteCourse(course_code);
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    
    if(validateToContinue(choice) == 1){
        add_or_remove_course(indexNumber);
    }
}


void start_screen_for_student(string indexNumber)
{
    system("clear");
    Database_User db;
    cout << "\t\t\t\t\t\t PEERS INSTITUTE SCHOOL MANAGEMENT SYSTEM STUDENT PORTAL\n";
    cout << "\tWelcome " << db.returnName(indexNumber) << endl;
    cout << "Select 1 to edit Student Profile\nSelect 2 to view Courses\nSelect 3 to add courses\nSelect 4 to remove Course\nSelect 5 to logout\n";
    int choice;
    cin >> choice;;

    if(checkForStudent(choice) == 1) {
        // edit student details
        edit_student_details(indexNumber);

    }else
    if(checkForStudent(choice) == 2){
        // view courses
        view_student_courses(indexNumber);
    }else
    if(checkForStudent(choice) == 3) {
        // add course
        add_courses_student(indexNumber);
    }else 
    if(checkForStudent(choice) == 4) {
        // remove course
        remove_course_student(indexNumber);
    }else
    if(checkForStudent(choice) == 5) {
        // logout redirect back to start_screen
        start_application();
    }

}

void view_student_courses(string indexNumber)
{
    Database_course course;
    if(!course.view_courses(indexNumber)){
        // cout << "No Courses registered for\n";
    }

    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    
    if(validateToContinue(choice) == 1){
        start_screen_for_student(indexNumber);
    }

}

void edit_student_details(string indexNumber)
{
    Database_User db;
    cout << "Student Details\n";
    cout << "Please enter new set of details: \n";
    User student;
    cout << "First Name: ";
    cin >> student.first_name;
    cout  << "Last Name: ";
    cin >> student.last_name;
    cout << "Sex: ";
    cin >> student.sex;
    student.level = db.returnLevel(indexNumber);
    student.department = db.returnDepartment(indexNumber);
    student.status = db.returnStatus(indexNumber);
    student.index_number = indexNumber;
    // updating
    db.udpdateUser(student);
    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;
    
    if(validateToContinue(choice) == 1){
        start_screen_for_student(indexNumber);
    }
}

void add_courses_student(string indexNumber)
{
    //course function should be here to show all courses added by the staff
    Database_course course;
    cout << "Courses available\n";
    course.coursesAvailable();
    student_course std_course;
    std_course.student_index = indexNumber;
    cout << "Please enter the course code: ";
    cin >> std_course.course_code;
    cout  << "Please enter the course title: ";
    cin >> std_course.course_title;
    // calling the create function
    course.create(std_course);

    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;

    if(validateToContinue(choice) == 1){
        start_screen_for_student(indexNumber);
    }

}

void remove_course_student(string id)
{
    // course function be here to delete a course
    Database_course course;
    string course_code;
    cout << "Please enter your the corressponding course code of the course you want to remove: ";
    cin >> course_code;
    // calling remove method
    course.deleteCourse(course_code,id);

    int choice;
    cout << "Please enter 1 to continue: " ;
    cin >> choice;

    if(validateToContinue(choice) == 1){
        start_screen_for_student(id);
    }
    
}


int checkForStudent(int a){
    while(cin.fail() || a > 5 || a < 1){
        cin.clear();
        cin.ignore(200,'\n');
        cout << "Please enter a valid number: ";
        cin >> a;
    }
    return a;
}

int checkForStaff(int a){
    while(cin.fail() || a > 5 || a < 1){
        cin.clear();
        cin.ignore(200,'\n');
        cout << "Please enter a valid number: ";
        cin >> a;
    }
    return a;
}


int checkForScores(int a){
    while(cin.fail() || a > 3 || a < 1){
        cin.clear();
        cin.ignore(200,'\n');
        cout << "Please enter a valid number: ";
        cin >> a;
    }
    return a;
}

int validateToContinue(int a)
{
    while(cin.fail() || a!=1){
        cin.clear();
        cin.ignore(200,'\n');
        cout << "Please enter 1: ";
        cin >> a;
    }
    return a;
}

#endif //INCLUDES_H