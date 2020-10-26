#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <stdio.h>
using namespace std;
typedef string treeType;
#include "BinarySearchTree.h"
void BinarySearchTree::insert(DBentry p)
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
void BinarySearchTree::search(string key)
{
     bool found = false;
    if(isEmpty())
    {
        cout<<"Error: entry does not exist"<<endl;
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
            cout << "The phone number for " << key << " is " << curr->data.getIPaddress() << endl;
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
        cout<<"Error: entry does not exist"<<endl;
        return;
    }
}
void BinarySearchTree::remove(string p)
{
    //Locate the element
    bool found = false;
    if(isEmpty())
    {
        cout<<"Error: entry does not exist"<<endl;
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
        cout<<"Error: entry does not exist"<<endl;
        return;
    }
		 // 3 cases :
    // 1. We're removing a leaf node
    // 2. We're removing a node with a single child
    // 3. we're removing a node with 2 children
    // Node with single child
    if((curr->left == NULL && curr->right != NULL)|| (curr->left != NULL && curr->right == NULL))
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
        x<<p->data.getActive();
        cout<<p->data.getName()<<" : "<<p->data.getIPaddress()<<" : "<<p->data.printactive(x)<<endl;
        if(p->right) inorder(p->right);
    }
    else return;
}
int BinarySearchTree::searchprobes(string key)
{
     bool found = false;
    if(isEmpty())
    {
        cout<<"Error: entry does not exist"<<endl;
        return 0;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL)
    {
         if(curr->data.getName() == key)
         {
            found = true;
            cout << probes << endl;
            break;
         }
         else
         {
             parent = curr;
             if(key>curr->data.getName()) {
                    curr = curr->right;
                    probes++;
             }
             else {
                    curr = curr->left;
                    probes++;
            }
        }
    if(!found)
		 {
        cout<<"Error: entry does not exist"<<endl;
        return 0;
    }
}
}
void BinarySearchTree::deleteall()
{
    delete_tree(root);
}
void BinarySearchTree::delete_tree(tree_node* p)
{
    if(p!=NULL)
    {
        delete_tree(p->left);
        delete_tree(p->right);
        delete(p);
    }
}
void BinarySearchTree::print_active()
{
    countactive(root);
}
int BinarySearchTree::countactive(tree_node* p)
{
    if(p != NULL)
    {
        if(p->left) inorder(p->left);
        {
            if (p->data.getActive() == true)
                cactive++;
        }
        if(p->right) inorder(p->right);
    }
    else return cactive;
}
void BinarySearchTree::changeIPaddress(string p, bool newactive) {
    bool found = false;
    if(isEmpty())
    {
        cout<<"Error: entry does not exist"<<endl;
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
        cout<<"Error: entry does not exist"<<endl;
        return;
    }
    //change the active associated with the node
    curr->data.setactive(newactive);
}//end changeIPaddress
