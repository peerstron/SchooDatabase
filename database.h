
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

struct Database {
    fstream file;
    ofstream temp_file;
    string user_collect_line;
    string arr[100];

    bool create(School user){
        file.open("student.txt",ios::out | ios::app);
        user_collect_line = user.id + " " + user.lastname + " " + user.firstname + " " + user.level + " " + user.program + " " + user.gender + " " + user.dob + " " + user.status;
        file << user_collect_line << endl;
        cout << "Record added successfully\n";
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
				break;
			}
        }   
        file.close();
		return user_collect_line;
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
    }

    void update(School user){
        string e_user;
        string t_user;
        e_user = this->fetch(user.id);
        string n_user = user.id + " " + user.lastname + " " + user.firstname + " " + user.level + " " + user.program + " " + user.gender + " " + user.dob;
        cout << "New User : " << n_user << endl;
        file.open("database.txt");
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
        remove("database.txt");
        rename("temp_file","database.txt");
        cout << "Record updated successfully\n";
	}

    void remove(string id){
    string user = this->fetch(id);
    string e_user;
    file.open("database.txt");
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
    remove("database.txt");
    rename("temp_file.txt","database.txt");
    cout << "User deleted successfully .. " << endl;
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