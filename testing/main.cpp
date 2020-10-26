#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include "DBentry.h"
#include "BinarySearchTree.h"
using namespace std;
typedef string treeType;

int main()
{
    BinarySearchTree b;
    int ch;
    string name;
    string key;
    int IPaddress;
    string actword;
    bool active;
    DBentry tmp;
    DBentry tmp1;
    b.print_preorder();
    while(1)
    {
        cout << "> ";
        string userinput;
        getline (cin, userinput);
        string command;
        string userx;
        string usery;
        string userz;
        stringstream userline;
        userinput<<userline;
        userline>>command>>userx>>usery>>userz;
       switch(command)
       {
           case "insert" :
                    userx >> name;
                    usery >> IPaddress;
                    userz >> actword;
                    bool active;
                    if (actword == "active") {
                        active = true;
                    }
                    else if (actword == "inactive") {
                        active = false;
                    }
                    else {
                        cout << endl << "Error: active unreadable" << endl;
                    }
                    tmp.setName(name);
                    tmp.setIPaddress(IPaddress);
                    tmp.setactive(active);
                    b.insert(tmp);
                    cout<<endl<<"Success";
                    break;
           case "find" :
                    userx >> key;
                    b.search(key);
                    cout<<endl<<"Success";
                    break;
           case "remove" :
                    userx>>key;
                    b.remove(key);
                    cout<<endl<<"Success";
                    break;
           case "printall" : cout<<endl;
                    b.print_inorder();
                    cout<<endl<<"Success";
                    break;
           case "printprobes" :
                    user >> key;
                    b.searchprobes(key);
                    cout<<endl<<"Success";
                    break;
           case "removeall" :
                    b.deleteall();
                    cout<<endl<<"Success";
                    break;
           case "countactive" :
                    b.print_active();
                    cout<<endl<<"Success";
                    break;
           case "updatestatus" :
                    userx>>name;
                    usery>>actword;
                    if (actword == "active") {
                        active = true;
                    }
                    else if (actword == "inactive") {
                        active = false;
                    }
                    else {
                        cout << endl << "Error: active unreadable" << endl;
                    }
                    b.changeIPaddress(name, active);
                    cout<<endl<<"Success";
                    break;
       }
    }
}
