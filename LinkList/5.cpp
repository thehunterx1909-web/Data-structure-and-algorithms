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
void pushBack(node *&head,int x){
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
void popFront(node *&head){
    if(head == NULL) return;
    node *temp = head;
    head = head->next;
    delete temp;
}
void erase(node *&head, int k){
    int n = size(head);
    if(k < 1 || k > n + 1){
        return;
    }
    if(k == 1) {
        popFront(head);
        return;
    }
    node *temp = head;
    for(int i = 1; i <= k - 2; i++){
        temp = temp->next;
    }
    node *ans = temp->next;
    temp->next = ans->next;
    delete ans;
}
int main(){
    node *head = NULL;
    for(int i = 1; i <= 10; i++){
        pushBack(head, i);
    }
    duyet(head);
    cout << "\nsize: " << size(head) << endl;
    erase(head, 5);
    duyet(head);
    cout << "\nsize: " << size(head) << endl;
}