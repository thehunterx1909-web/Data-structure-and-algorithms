#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    int data;
    node *next;
};
node *makeNode(int x){
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void duyet(node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}
int count(node *head){
    int dem = 0;
    while(head != NULL){
        dem++;
        head = head->next;
    }
    return dem;
}

//Thêm một phần tử vào cuối
void pushBack(node *&head, int x){
    node *newNode = makeNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
int main(){
    node *head = NULL;
    for(int i = 0; i <= 10; i++){
        pushBack(head, i);
    }
    duyet(head);
    cout << endl;
    cout << count(head);
}