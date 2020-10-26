#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <stdio.h>
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
    DBentry tmp;
    DBentry tmp1;
    b.print_preorder();
    while(1)
    {
       cout<<endl<<endl;
       cout<<" Binary Search Tree Operations "<<endl;
       cout<<" ----------------------------- "<<endl;
       cout<<" 0. Search             "<<endl;
       cout<<" 1. Insertion/Creation "<<endl;
       cout<<" 2. In-Order Traversal "<<endl;
       cout<<" 3. Pre-Order Traversal "<<endl;
       cout<<" 4. Post-Order Traversal "<<endl;
       cout<<" 5. Removal "<<endl;
       cout<<" 6. Change a IPaddress "<<endl;
       cout<<" 7. Exit "<<endl;
       cout<<" Enter your choice : ";
       cin>>ch;
       switch(ch)
       {
           case 0 : cout <<" Enter the name of the DBentry to search for: "<<endl;
                    cin>>key;
                    b.search(key);
                    break;
           case 1 : cout<<" Enter name to be inserted: ";
                    cin>>name;
                    cout << endl << " Enter phone number: " << endl;
                    cin >> IPaddress;
                    tmp.setName(name);
                    tmp.setIPaddress(IPaddress);
                    b.insert(tmp);
                    break;
           case 2 : cout<<endl;
                    cout<<" In-Order Traversal "<<endl;
                    cout<<" -------------------"<<endl;
                    b.print_inorder();
                    break;
           case 3 : cout<<endl;
                    cout<<" Pre-Order Traversal "<<endl;
                    cout<<" -------------------"<<endl;
                    b.print_preorder();
                    break;
           case 4 : cout<<endl;
                    cout<<" Post-Order Traversal "<<endl;
                    cout<<" --------------------"<<endl;
                    b.print_postorder();
                    break;
           case 5 : cout<<" Enter data to be deleted : ";
                    //cout << "Deletion needs to be implemented." << endl;
                    cin>>key;
                    b.remove(key);
                    break;
           case 6 : cout<<" Enter the name of the DBentry whose number you wish to change: " <<endl;
                    cin>>name;
                    cout<<endl<<" Enter the new IPaddress: " <<endl;
                    cin>>IPaddress;
                    cout<<endl;
                    b.changeIPaddress(name, IPaddress);
                    break;
           case 7 : return 0;
       }
    }
}
