#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <stdio.h>
using namespace std;
typedef string treeType;
class Person{
    private:
    string name;
    int phonenumber;
    public:
    Person();
    Person(string name, int phonenumber);
    string getName();
    int getPhonenumber();
    void setName(string newname);
    void setPhonenumber(int newphonenumber);
};
class BinarySearchTree
{
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           //treeType data;
           Person data;
        };
        tree_node* root;
    public:
        BinarySearchTree()
        {
           root = NULL;
        }
        bool isEmpty() const { return root==NULL; }
        void print_inorder();
        void inorder(tree_node*);
        void print_preorder();
        void preorder(tree_node*);
        void print_postorder();
        void postorder(tree_node*);
        void insert(Person);
        void remove(string);
        void search(string key);
        void changePhonenumber(string key, int newnumber);
};
Person::Person()
{
}
Person::Person(string newname, int newphonenumber)
{
    name = newname;
    phonenumber = newphonenumber;
}
string Person::getName() {
    return name;
}
int Person::getPhonenumber() {
    return phonenumber;
}
void Person::setName(string newname) {
    name = newname;
}
void Person::setPhonenumber(int newphonenumber) {
    phonenumber = newphonenumber;
}
// Smaller elements go left
// larger elements go right
void BinarySearchTree::insert(Person p)
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = p;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    // is this a new tree?
    if(isEmpty()) root = t;
    else
    {
        //Note: ALL insertions are as leaf nodes
        tree_node* curr;
        curr = root;
        // Find the Node's parent
        while(curr)
        {
            parent = curr;
            if(t->data.getName() > curr->data.getName()) curr = curr->right;
            else curr = curr->left;
        }
        if(t->data.getName() < parent->data.getName())
           parent->left = t;
        else
           parent->right = t;
    }
}
void BinarySearchTree::remove(string p)
{
    //Locate the element
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
         if(curr->data.getName() == p)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(p>curr->data.getName()) curr = curr->right;
             else curr = curr->left;
         }
    }
    if(!found)
		 {
        cout<<" Data not found! "<<endl;
        return;
    }
		 // 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children
    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL
&& curr->right == NULL))
    {
       if(curr->left == NULL && curr->right != NULL)
       {
           if(parent->left == curr)
           {
             parent->left = curr->right;
             delete curr;
           }
           else
           {
             parent->right = curr->right;
             delete curr;
           }
       }
       else // left child present, no right child
       {
          if(parent->left == curr)
           {
             parent->left = curr->left;
             delete curr;
           }
           else
           {
             parent->right = curr->left;
             delete curr;
           }
       }
     return;
    }
		 //We're looking at a leaf node
		 if( curr->left == NULL && curr->right == NULL)
    {
        if(parent->left == curr) parent->left = NULL;
        else parent->right = NULL;
		 		 delete curr;
		 		 return;
    }
    //Node with 2 children
    // replace node with smallest value in right subtree
    if (curr->left != NULL && curr->right != NULL)
    {
        tree_node* chkr;
        chkr = curr->right;
        if((chkr->left == NULL) && (chkr->right == NULL))
        {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else // right child has children
        {
            //if the node's right child has a left child
            // Move all the way down left to locate smallest element
            if((curr->right)->left != NULL)
            {
                tree_node* lcurr;
                tree_node* lcurrp;
                lcurrp = curr->right;
                lcurr = (curr->right)->left;
                while(lcurr->left != NULL)
                {
                   lcurrp = lcurr;
                   lcurr = lcurr->left;
                }
		curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = NULL;
           }
           else
           {
               tree_node* tmp;
               tmp = curr->right;
               curr->data = tmp->data;
	       curr->right = tmp->right;
               delete tmp;
           }
        }
		 return;
    }
}
void BinarySearchTree::print_inorder()
{
  inorder(root);
}
void BinarySearchTree::inorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left) inorder(p->left);
        cout<<" "<<p->data.getName()<<" ";
        if(p->right) inorder(p->right);
    }
    else return;
}
void BinarySearchTree::print_preorder()
{
    preorder(root);
}
void BinarySearchTree::preorder(tree_node* p)
{
    if(p != NULL)
    {
        cout<<" "<<p->data.getName()<<" ";
        if(p->left) preorder(p->left);
        if(p->right) preorder(p->right);
    }
    else return;
}
void BinarySearchTree::print_postorder()
{
    postorder(root);
}
void BinarySearchTree::postorder(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left) postorder(p->left);
        if(p->right) postorder(p->right);
        cout<<" "<<p->data.getName()<<" ";
    }
    else return;
}
//////////////////new/////////////////////////
void BinarySearchTree::search(string key)
{
     bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
         if(curr->data.getName() == key)
         {
            found = true;
            cout << "The phone number for " << key << " is " << curr->data.getPhonenumber() << endl;
            break;
         }
         else
         {
             parent = curr;
             if(key>curr->data.getName()) curr = curr->right;
             else curr = curr->left;
         }
    }
    if(!found)
		 {
        cout<<" Data not found! "<<endl;
        return;
    }
}
void BinarySearchTree::changePhonenumber(string p, int newnumber) {
    bool found = false;
    if(isEmpty())
    {
        cout<<" This Tree is empty! "<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
         if(curr->data.getName() == p)
         {
            found = true;
            break;
         }
         else
         {
             parent = curr;
             if(p>curr->data.getName()) curr = curr->right;
             else curr = curr->left;
         }
    }
    if(!found)
		 {
        cout<<" Person not found. "<<endl;
        return;
    }
    //change the phonenumber associated with the node
    curr->data.setPhonenumber(newnumber);
    cout<< "Number changed successfully. " << endl;
}//end changePhonenumber


int main()
{
    BinarySearchTree b;
    int ch;
    string name;
    string key;
    int phonenumber;
    Person tmp;
    Person tmp1;
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
       cout<<" 6. Change a Phonenumber "<<endl;
       cout<<" 7. Exit "<<endl;
       cout<<" Enter your choice : ";
       cin>>ch;
       switch(ch)
       {
           case 0 : cout <<" Enter the name of the person to search for: "<<endl;
                    cin>>key;
                    b.search(key);
                    break;
           case 1 : cout<<" Enter name to be inserted: ";
                    cin>>name;
                    cout << endl << " Enter phone number: " << endl;
                    cin >> phonenumber;
                    tmp.setName(name);
                    tmp.setPhonenumber(phonenumber);
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
           case 6 : cout<<" Enter the name of the person whose number you wish to change: " <<endl;
                    cin>>name;
                    cout<<endl<<" Enter the new phonenumber: " <<endl;
                    cin>>phonenumber;
                    cout<<endl;
                    b.changePhonenumber(name, phonenumber);
                    break;
           case 7 : return 0;
       }
    }
}
