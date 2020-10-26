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
        bool x;
        int probes = 0;
        int cactive = 0;
    public:
        BinarySearchTree()
        {
           root = NULL;
        }
        bool isEmpty() const { return root==NULL; }
        void print_inorder();
        void inorder(tree_node*);
        int searchprobes(string key);
        void print_active();
        void deleteall();
        void delete_tree(tree_node*);
        int countactive(tree_node*);
        void insert(DBentry);
        void remove(string);
        void search(string key);
        void changeIPaddress(string key, bool newactive);
};
#endif // BINARYSEARCHTREE_H
