

#ifndef DATABASE_USER_H
#define DATABASE_USER_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include "datatypes.h"
using namespace std;



class Database_User
{
    fstream afile;
    ofstream tmp_file;
    string user_line;
    string arr[10];

  public:
    bool createUser(User);
    string readUser(string);
    void udpdateUser(User);
    void deleteUser(string);
    bool compareUser(string);
    string returnStatus(string);
    string returnName(string);
    string returnFirstName(string);
    string returnLastName(string);
    string returnLevel(string);
    string returnSex(string);
    string returnDepartment(string);
    
    template <size_t N>
		void splitString(string (&arr)[N], string str){
		    int n = 0;
		    istringstream iss(str);
		    for (auto it = istream_iterator<string>(iss); it != istream_iterator<string>() && n < N; ++it, ++n)
		        arr[n] = *it;
		}
};


bool Database_User::createUser(User user)
{
    afile.open("Database files/databaseUser.txt", ios::out | ios::app);

    string data[7];
    data[0] = user.first_name;
    data[1] = user.last_name;
    data[2] = user.level;
    data[3] = user.sex;
    data[4] = user.department;
    data[5] = user.status;
    data[6] = user.index_number;

    for (int i = 0; i < 7; i++)
    {   
        afile << data[i] << "  ";
    }
    afile << endl;
    afile.close();

    cout << "Written to file successfully" << endl;
    return true;
}

string Database_User::readUser(string search_id)
{
    string user_collect;
    afile.open("Database files/databaseUser.txt");
    while(!afile.eof())
    {
        getline(afile,user_collect);
        splitString(arr,user_collect);
        if(arr[6] == search_id){
            break;
        }
    }
    afile.close();
    return user_collect;
}

// update user

void Database_User::udpdateUser(User user)
{
   string exist_user;
   string new_user;
   string temp_user;
   exist_user = this->readUser(user.index_number);
    new_user = user.first_name + " " + user.last_name + " " + user.level + " " + user.sex + " " + user.department + " " + user.status + " " + user.index_number;
    afile.open("Database files/databaseUser.txt");
    tmp_file.open("Database files/tmp_file.txt");
    while(!afile.eof())
    {
        getline(afile,temp_user);
        if(temp_user == exist_user){
            temp_user = new_user;
        }
        tmp_file << temp_user << endl;
    }
    tmp_file.close();
    afile.close();
    remove("Database files/databaseUser.txt");
    rename("Database files/tmp_file.txt", "Database files/databaseUser.txt");
    cout << "Updated successfully\n";
}

// delete user

void Database_User::deleteUser(string search_id)
{
    string user_collect = this->readUser(search_id);
    string exist_user;
    afile.open("Database files/databaseUser.txt");
    tmp_file.open("Database files/tmp_file.txt");
    while(!afile.eof())
    {
        getline(afile,exist_user);
        if(exist_user == user_collect){
            continue;
        }else{
            tmp_file << exist_user << endl;
        }
    }
    tmp_file.close();
    afile.close();
    remove("Database files/databaseUser.txt");
    rename("Database files/tmp_file.txt", "Database files/databaseUser.txt");
    cout << "user deleted successfully\n";
}

// for the authentication class
bool Database_User::compareUser(string id)
{
    string user_collect;
    afile.open("Database files/databaseUser.txt");
    while(afile.eof())
    {
        getline(afile,user_collect);
        splitString(arr,user_collect);
        if(arr[6] == id){
            return true;
            break;
        }
    }
    afile.close();
}

string Database_User::returnStatus(string id){
    string user_collect;
    afile.open("Database files/databaseUser.txt");
    while(!afile.eof())
    {
        getline(afile,user_collect);
        splitString(arr,user_collect);
        if(arr[6] == id){
            user_collect = arr[5];
            return user_collect;
            break;   
        }
    }

    afile.close();

}


string Database_User::returnName(string id){

    string user_collect;
    afile.open("Database files/databaseUser.txt");
    while(!afile.eof())
    {
        getline(afile,user_collect);
        splitString(arr,user_collect);
        if(arr[6] == id){
            user_collect = arr[1] + " " + arr[0];
            return user_collect;
            break;   
        }
    }

    afile.close();
}


string Database_User::returnFirstName(string id){

   string user_collect;
    afile.open("Database files/databaseUser.txt");
    while(!afile.eof())
    {
        getline(afile,user_collect);
        splitString(arr,user_collect);
        if(arr[6] == id){
            user_collect = arr[0];
            return user_collect;
            break;   
        }
    }

    afile.close();
}

string Database_User::returnLastName(string id){

    string user_collect;
    afile.open("Database files/databaseUser.txt");
    while(!afile.eof())
    {
        getline(afile,user_collect);
        splitString(arr,user_collect);
        if(arr[6] == id){
            user_collect = arr[1];
            return user_collect;
            break;   
        }
    }

    afile.close();
}

string Database_User::returnLevel(string id){

   string user_collect;
    afile.open("Database files/databaseUser.txt");
    while(!afile.eof())
    {
        getline(afile,user_collect);
        splitString(arr,user_collect);
        if(arr[6] == id){
            user_collect = arr[2];
            return user_collect;
            break;   
        }
    }

    afile.close();
}

string Database_User::returnSex(string id){

   string user_collect;
    afile.open("Database files/databaseUser.txt");
    while(!afile.eof())
    {
        getline(afile,user_collect);
        splitString(arr,user_collect);
        if(arr[6] == id){
            user_collect = arr[3] ;
            return user_collect;
            break;   
        }
    }

    afile.close();
}

string Database_User::returnDepartment(string id){

    string user_collect;
    afile.open("Database files/databaseUser.txt");
    while(!afile.eof())
    {
        getline(afile,user_collect);
        splitString(arr,user_collect);
        if(arr[6] == id){
            user_collect = arr[4];
            return user_collect;
            break;   
        }
    }

    afile.close();
}





#endif //DATABASE_USER_H