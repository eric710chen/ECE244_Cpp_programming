#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <stdio.h>
using namespace std;
typedef string treeType;
#include "DBentry.h"
DBentry::DBentry()
{
}
DBentry::DBentry(string newname, int newIPaddress, bool newactive)
{
    name = newname;
    IPaddress = newIPaddress;
    active = newactive;
}
string DBentry::getName() {
    return name;
}
int DBentry::getIPaddress() {
    return IPaddress;
}
bool getActive () {
    return active;
}
void DBentry::setName(string newname) {
    name = newname;
}
void DBentry::setIPaddress(int newIPaddress) {
    IPaddress = newIPaddress;
}
void DBentry::setactive (bool newactive) {
    active = newactive;
}
string DBentry::printactive (bool ifactive) {
    if (ifactive == true) {
        return "active";
        }
    else if (ifactive == false) {
        return "inactive";
        }
}
