#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};
typedef struct node node;

node* makeNode(int x){
    node *newNode = new node();
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}
node* insert(node *root, int x){
    if(root == NULL){
        root = makeNode(x);
        return root;
    } else if(x <= root->data){
        root->left = insert(root->left, x);
    } else root->right = insert(root->right, x);
    return root;
}
bool Search(node *root, int x){
    if(root == NULL) return false;
    if(root->data == x) return true;
    else if(x <= root->data) return Search(root->left, x);
    else return Search(root->right, x);
}
int main(){
    node *root = NULL;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        root = insert(root, x);
    }
    int k;
    cout << "Nhap k: ";
    cin >> k;
    if(Search(root, k) == true) cout << "Found";
    else cout << "Not Found";
}