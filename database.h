
#ifndef DATABASE_H
#define DATABASE_H

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <iterator>
#include <string>

using namespace std;

struct School{
    string id;
    string lastname;
    string firstname;
    string level;
    string program;
    string gender;
    string dob;
    string status;
};

struct student_course{
    std::string student_index;
	std::string course_code;
    std::string course_title;
    std::string student_mark_IA = "NA";
    std::string student_mark_EXAM = "NA";
    std::string student_grade = "NA";
};

struct staff_course{
    std::string course_code;
	std::string course_title;
    std::string course_lecturer;
};

struct Database {
    fstream file;
    ofstream temp_file;
    string user_collect_line, course_line;
    string arr[100];

    bool create(School user){
        file.open("student.txt",ios::out | ios::app);
        user_collect_line = user.id + " " + user.lastname + " " + user.firstname + " " + user.level + " " + user.program + " " + user.gender + " " + user.dob + " " + user.status;
        file << user_collect_line << endl;
        cout << "Record added successfully\n";
        file.close();
        return true;
    }

    // creating a course by staff
    bool createCourse(staff_course course)
    {
        file.open("databaseCourses.txt",ios::out | ios::app);
        course_line = course.course_code + " " + course.course_title + " " + course.course_lecturer;
        file << course_line << endl;
        cout  << "Course added successfully\n";
        file.close();
        return true;
    }

    // creating a course byy student
    bool create(student_course course)
    {
        file.open("databaseCourseForStudent.txt");
        course_line = course.student_index + " " + course.course_code + " " + course.course_title + " " + course.student_mark_IA + " " + course.student_mark_EXAM + " " + course.student_grade;
        file << course_line << endl;
        cout << "Course of student added succesfully\n";
        file.close();
        return true;
    }

    string fetch(string user_id)
    {
        file.open("student.txt");
        while(!file.eof()){
            getline(file,user_collect_line);
            splitString(arr,user_collect_line);
			if(arr[0] == user_id){
        		return user_collect_line;		
                break;
			}
        }   
        file.close();
    }

    // reading courses
    string readStaffCourse(string course_code)
    {
		string course_collected;
        file.open("databaseCourses.txt");
        while(!file.eof()){
            getline(file,course_collected);
            splitString(arr,course_collected);
			if(arr[0] == course_code){
				break;
			}
    }
    file.close();
	return course_collected;
    }

    void coursesAvailable()
    {
        string course_collected;
        file.open("databaseCourses.txt");
        while(!file.eof()){
            getline(file,course_collected);
            cout << course_collected << endl;
        }
        file.close();
    }

    string readStaffCourse(string course_code,string student_index)
    {
		string course_collected;
        file.open("databaseCourseForStudent.txt");
        while(!file.eof()){
            getline(file,course_collected);
            splitString(arr,course_collected);
			if(arr[0] == student_index && arr[1] == course_code){
                break;
			}
    }
    file.close();
	return course_collected;
    }

    bool fetchIdStaff(string user_id){
        file.open("student.txt");
        while(!file.eof()){
            getline(file,user_collect_line);
            splitString(arr,user_collect_line);
			if(arr[0] == user_id && arr[7] == "staff"){
                return true;
				break;
			}
        }   
        file.close();
    }

    bool authenticate(string user_id)
    {
        file.open("student.txt");
        while(!file.eof()){
            getline(file,user_collect_line);
            splitString(arr,user_collect_line);
            if(arr[0] == user_id){
                return true;
                break;
            }
        }
        file.close();
    }

    string fetchStatus(string user_id)
    {
        file.open("student.txt");
        while(!file.eof()){
            getline(file,user_collect_line);
            splitString(arr,user_collect_line);
            if(arr[0] == user_id){
                return arr[7];
                break;
            }
        }
        file.close();   
    }

    void update(School user){
        string e_user;
        string t_user;
        e_user = this->fetch(user.id);
        string n_user = user.id + " " + user.lastname + " " + user.firstname + " " + user.level + " " + user.program + " " + user.gender + " " + user.dob;
        file.open("student.txt");
        temp_file.open("temp_file.txt");
        while(!file.eof()){
            getline(file,t_user);
            if(t_user == e_user){
                t_user = n_user;
            }
            temp_file << t_user << endl;
        }
        temp_file.close();
        file.close();
        remove("student.txt");
        rename("temp_file.txt","student.txt");
        cout << "Record updated successfully\n";
	}

    void updateCourse(staff_course course)
    {
        string exist_course;
        string temp_course;
        exist_course = this->readStaffCourse(course.course_code);
        string updated_course = course.course_code + " " + course.course_title + " " + course.course_lecturer;
        file.open("databaseCourses.txt");
        temp_file.open("temp_file.txt");
        while (!file.eof())
        {
            getline(file,temp_course);
            if(temp_course == exist_course){
                temp_course = updated_course;
            }
            temp_file << temp_course << endl;
        }
        temp_file.close();
        file.close();
        remove("databaseCourses.txt");
        rename("temp_file.txt","databaseCourses.txt");
        cout << "Course updated successfully\n";
    }

    void updateCourse(student_course course)
    {
        string exist_course;
        string temp_course;
        exist_course = this->readStaffCourse(course.course_code);
        string updated_course = course.student_index + " " + course.course_code + " " + course.course_title + " " + course.student_mark_IA + " " + course.student_mark_EXAM + " " + course.student_grade;
        file.open("databaseCourseForStudent.txt");
        temp_file.open("temp_file.txt");
        while (!file.eof())
        {
            getline(file,temp_course);
            if(temp_course == exist_course){
                temp_course = updated_course;
            }
            temp_file << temp_course << endl;
        }
        temp_file.close();
        file.close();
        remove("databaseCourseForStudent.txt");
        rename("temp_file.txt","databaseCourseForStudent.txt");
        cout << "Course updated successfully\n";
    }


    // delete methods

    void remove(string id){
        string user = this->fetch(id);
        string e_user;
        file.open("student.txt");
        temp_file.open("temp_file.txt");
        while(!file.eof()){
            getline(file,e_user);
            if(e_user == user){
                continue;
            }else{
                temp_file << e_user << endl;
            }
        }
        temp_file.close();
        file.close();
        remove("student.txt");
        rename("temp_file.txt","student.txt");
        cout << "User deleted successfully .. " << endl;
	}

    void deleteCourse(string course_code)
    {
        string course = this->readStaffCourse(course_code);
        string exist_course;
        file.open("databaseCourses.txt");
        temp_file.open("temp_file.txt");
        while(!file.eof())
        {
            getline(file,exist_course);
            splitString(arr,exist_course);
            if(exist_course == course && arr[0] == course_code){
                continue;
            }else{
                temp_file << exist_course << endl;
            }
        }
        temp_file.close();
        file.close();
        remove("databaseCourses.txt");
        rename("temp_file.txt","databaseCourses.txt");
        cout << "Course successfully deleted" << endl;
    }

    void deleteCourse(string course_code,string user_index)
    {
        string course = this->readStaffCourse(course_code,user_index);
        string exist_course;
        file.open("databaseCourseForStudent.txt");
        temp_file.open("temp_file.txt");
        while(!file.eof())
        {
            getline(file,exist_course);
            splitString(arr,exist_course);
            if(exist_course == course && arr[0] == user_index){
                continue;
            }else{
                temp_file << exist_course << endl;
            }
        }
        temp_file.close();
        file.close();
        remove("databaseCourseForStudent.txt");
        rename("temp_file.txt","databaseCourseForStudent.txt");
        cout << "Course successfully deleted" << endl;
    }


    template <size_t N>
		void splitString(string (&arr)[N], string str){
		    int n = 0;
		    istringstream iss(str);
		    for (auto it = istream_iterator<string>(iss); it != istream_iterator<string>() && n < N; ++it, ++n)
		        arr[n] = *it;
		}


};

    

#endif