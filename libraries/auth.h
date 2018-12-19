

#ifndef AUTH_H
#define AUTH_H

#include <iostream>
#include <string>

using namespace std;

    class Auth{
        public:
            bool signIn(string);

        private:
            string index_number;
    };

      bool Auth::signIn(string id)
    {
        Database_User db;
        if(db.compareUser(id) == true)
        {
            return true;
        }else
            return false;
        
    }



#endif //AUTH_H