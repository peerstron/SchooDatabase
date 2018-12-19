#include <iostream>
#include <string>
#include "database.h"

using namespace std;

main(int argc, char const *argv[])
{
    Database db;
    cout << db.fetch("10670196");
    // db.remove("10670196");
    return 0;
}
