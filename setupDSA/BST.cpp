#include<bits/stdc++.h>
using namespace std;

class node{
    public:
       int data;
       node *left, *right;

       node(int x){
        data = x;
        left = right = NULL;
       }
};
class BST{
    private:
       node *root;

       node *insert(node *root, int x){
        if(root == NULL) return new node(x);
        if(x <= root->data) root->left = insert(root->left, x);
        else root->right = insert(root->right, x);
        return root;
       }
       bool search(node *root, int x){
        if(root == NULL) return false;
        if(root->data == x) return true;
        else if(x < root->data) return search(root->left, x);
        else return search(root->right, x);
       }
       node* minNode(node *root){
        while(root != NULL && root->left != NULL){
            root = root->left;
        }
        return root;
       }
       node* maxNode(node *root){
        while(root != NULL && root->right != NULL){
            root = root->right;
        }
        return root;
       }
};