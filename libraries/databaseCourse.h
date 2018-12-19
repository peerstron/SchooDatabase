

#ifndef DATABASE_COURSE_H
#define DATABASE_COURSE_H


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"
using namespace std;

/**
 * creating methods for both the staff(thus they adding courses editing and removing) 
 * and the student(thus their marks and grades)
 */


class Database_course
{
    fstream afile;
    ofstream tmp_file;
    string course_line;
    string arr[10];

    public:

    // creating a course by staff
    bool create(staff_course course)
    {
        afile.open("Database files/databaseCourses.txt",ios::out | ios::app);
        course_line = course.course_code + " " + course.course_title + " " + course.course_lecturer;
        afile << course_line << endl;
        cout  << "Course added successfully\n";
        afile.close();
        return true;
    }

    // creating a course byy student
    bool create(student_course course)
    {
        afile.open("Database files/databaseCourseForStudent.txt");
        course_line = course.student_index + " " + course.course_code + " " + course.course_title + " " + course.student_mark_IA + " " + course.student_mark_EXAM + " " + course.student_grade;
        afile << course_line << endl;
        cout << "Course of student added succesfully\n";
        afile.close();
        return true;
    }

    // reading courses
    string readStaffCourse(string course_code)
    {
		string course_collected;
        afile.open("Database files/databaseCourses.txt");
        while(!afile.eof()){
            getline(afile,course_collected);
            splitString(arr,course_collected);
			if(arr[0] == course_code){
				break;
			}
    }
    afile.close();
	return course_collected;
    }

    void coursesAvailable()
    {
        string course_collected;
        afile.open("Database files/databaseCourses.txt");
        while(!afile.eof()){
            getline(afile,course_collected);
            cout << course_collected << endl;
        }
        afile.close();
    }

    string readStaffCourse(string course_code,string student_index)
    {
		string course_collected;
        afile.open("Database files/databaseCourseForStudent.txt");
        while(!afile.eof()){
            getline(afile,course_collected);
            splitString(arr,course_collected);
			if(arr[0] == student_index && arr[1] == course_code){
				
                break;
			}
    }
    afile.close();
	return course_collected;
    }


    void deleteCourse(string course_code)
    {
        string course = this->readStaffCourse(course_code);
        string exist_course;
        afile.open("Database files/databaseCourses.txt");
        tmp_file.open("Database files/tmp_file.txt");
        while(!afile.eof())
        {
            getline(afile,exist_course);
            splitString(arr,exist_course);
            if(exist_course == course && arr[0] == course_code){
                continue;
            }else{
                tmp_file << exist_course << endl;
            }
        }
        tmp_file.close();
        afile.close();
        remove("Database files/databaseCourses.txt");
        rename("Database files/tmp_file.txt","Database files/databaseCourses.txt");
        cout << "Course successfully deleted" << endl;
    }

    void deleteCourse(string course_code,string user_index)
    {
        string course = this->readStaffCourse(course_code,user_index);
        string exist_course;
        afile.open("Database files/databaseCourseForStudent.txt");
        tmp_file.open("Database files/tmp_file.txt");
        while(!afile.eof())
        {
            getline(afile,exist_course);
            splitString(arr,exist_course);
            if(exist_course == course && arr[0] == user_index){
                continue;
            }else{
                tmp_file << exist_course << endl;
            }
        }
        tmp_file.close();
        afile.close();
        remove("Database files/databaseCourseForStudent.txt");
        rename("Database files/tmp_file.txt","Database files/databaseCourseForStudent.txt");
        cout << "Course successfully deleted" << endl;
    }


    // update

    void updateCourse(staff_course course)
    {
        string exist_course;
        string temp_course;
        exist_course = this->readStaffCourse(course.course_code);
        string updated_course = course.course_code + " " + course.course_title + " " + course.course_lecturer;
        afile.open("Database files/databaseCourses.txt");
        tmp_file.open("Database files/tmp_file.txt");
        while (!afile.eof())
        {
            getline(afile,temp_course);
            if(temp_course == exist_course){
                temp_course = updated_course;
            }
            tmp_file << temp_course << endl;
        }
        tmp_file.close();
        afile.close();
        remove("Database files/databaseCourses.txt");
        rename("Database files/tmp_file.txt","Database files/databaseCourses.txt");
        cout << "Course updated successfully\n";
    }

    void updateCourse(student_course course)
    {
        string exist_course;
        string temp_course;
        exist_course = this->readStaffCourse(course.course_code);
        string updated_course = course.student_index + " " + course.course_code + " " + course.course_title + " " + course.student_mark_IA + " " + course.student_mark_EXAM + " " + course.student_grade;
        afile.open("Database files/databaseCourseForStudent.txt");
        tmp_file.open("Database files/tmp_file.txt");
        while (!afile.eof())
        {
            getline(afile,temp_course);
            if(temp_course == exist_course){
                temp_course = updated_course;
            }
            tmp_file << temp_course << endl;
        }
        tmp_file.close();
        afile.close();
        remove("Database files/databaseCourseForStudent.txt");
        rename("Database files/tmp_file.txt","Database files/databaseCourseForStudent.txt");
        cout << "Course updated successfully\n";
    }

    // view courses of a student
    bool view_courses(string user_id)
    {
        string course_collected;
        afile.open("Database files/databaseCourseForStudent.txt");
        cout << "Courses offered by " << user_id << endl;
        while(!afile.eof()){
            getline(afile,course_collected);
            splitString(arr,course_collected);
            if(arr[0] == user_id){
                course_collected = arr[1] + " " + arr[2] + " " + arr[3] + " " + arr[4] + " " + arr[5];
                cout << course_collected << endl;
                return true;
                break;
            }

        }
        afile.close();
    }

    bool assign_IA_marks(string user_id,string course_code,string IA_mark){
    string course = readStaffCourse(course_code,user_id);
    if(course.size() > 0){
      splitString(arr,course);
      student_course course;
      course.student_index = arr[0];
      course.course_code = arr[1];
      course.course_title = arr[2];
      arr[3] = IA_mark;
      course.student_mark_IA = arr[3];
      course.student_mark_EXAM = arr[4];
      course.student_grade = arr[5];
      this->updateCourse(course);
      return true;
    }
    return false;
    }

    bool assign_EXAM_marks(string user_id,string course_code,string EXAM_mark){
    int sum = 0,ia = 0,exam = 0;
    string course = readStaffCourse(course_code,user_id);
    if(course.size() > 0){
      splitString(arr,course);
      arr[4] = EXAM_mark;
      student_course course;
      course.student_index = arr[0];
      course.course_code = arr[1];
      course.course_title = arr[2];
      course.student_mark_IA = arr[3];
      stringstream change(arr[3]);
        change >> ia;
      course.student_mark_EXAM = arr[4];
      stringstream change2(arr[4]);
        change2 >> exam;
      sum = ia + exam;
      course.student_grade = this->grading(sum);
      this->updateCourse(course);
      return true;
    }
    return false;
  }

    template <size_t N>
		void splitString(string (&arr)[N], string str){
		    int n = 0;
		    istringstream iss(str);
		    for (auto it = istream_iterator<string>(iss); it != istream_iterator<string>() && n < N; ++it, ++n)
		        arr[n] = *it;
		}

    string grading(int sum){
      if(sum > 79 && sum < 100){
        return "A";
      }else if(sum > 74 && sum < 80){
        return "B+";
      }else if(sum > 69 && sum < 75){
        return "B";
      }else if(sum > 64 && sum < 70){
        return "C+";
      }else if(sum > 59 && sum < 65){
        return "C";
      }else if(sum > 54 && sum < 60){
        return "D+";
      }else if(sum > 49 && sum < 55){
        return "D";
      }else if(sum > 44 && sum < 50){
        return "E";
      }else if(sum > -1 && sum < 45){
        return "F";
      }else{
        return "NA";
      }
    }


};

#endif//DATABASE_COURSE_H