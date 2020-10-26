#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "DBentry.h"
using namespace std;
typedef string treeType;

class BinarySearchTree {
    private:
        struct tree_node
        {
           tree_node* left;
           tree_node* right;
           //treeType data;
           DBentry data;
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
        void insert(DBentry);
        void remove(string);
        void search(string key);
        void changeIPaddress(string key, int newnumber);
};
#endif // BINARYSEARCHTREE_H
