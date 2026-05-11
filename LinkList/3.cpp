#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};
typedef struct node node;

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
int size(node *head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}

void pushFront(node *&head, int x){
    node *newNode = makeNode(x);
    newNode->next = head;
    head = newNode; 
}
void pushBack(node *&head, int x){
    node *newNode = makeNode(x);
    node *temp = head;
    if(head == NULL){
        head = newNode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void insert(node *&head, int k, int x){
    node *newNode = makeNode(x);
    int n = size(head);
    if(k < 1 || k > n + 1){
        return;
    }
    if(head == NULL){
        pushFront(head, x);
        return;
    }
    node *temp = head;
    for(int i = 0; i <= k - 2; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
int main(){
    node *head = NULL;
    for(int i = 1; i <= 10; i++){
        pushBack(head, i);
    }
    duyet(head);
    cout << endl;
    cout << "size: " << size(head) << endl;
    insert(head, 4, 100);
    duyet(head);
    cout << endl;
    cout << "size: " << size(head);
}