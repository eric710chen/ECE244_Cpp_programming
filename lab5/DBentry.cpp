# include <iostream>
# include <cstdlib>
#include <fstream>
#include <iomanip>
#include <stdio.h>
using namespace std;

DBentry::DBentry()
{
}
DBentry::DBentry(string newname, int newIPaddress)
{
    name = newname;
    IPaddress = newIPaddress;
}
string DBentry::getName() {
    return name;
}
int DBentry::getIPaddress() {
    return IPaddress;
}
bool DBentry::getActive() {
    return active;
}
void DBentry::setName(string newname) {
    name = newname;
}
void DBentry::setIPaddress(int newIPaddress) {
    IPaddress = newIPaddress;
}
void DBentry::setActive (bool newactive) {
    active = newactive;
}
// Smaller elements go left
// larger elements go right
