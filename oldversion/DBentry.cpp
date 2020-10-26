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
void DBentry::setName(string newname) {
    name = newname;
}
void DBentry::setIPaddress(int newIPaddress) {
    IPaddress = newIPaddress;
}
// Smaller elements go left
// larger elements go right
