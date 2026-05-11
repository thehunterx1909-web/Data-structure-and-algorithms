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

//xoá một phần tử ở đầu dslk
void popFront(node *&head){
    if(head == NULL){
        return;
    }
    node *temp = head;
    head = head->next; //Cho node head lưu node thứ 2 của dslk
    delete temp; //giải phóng node đầu tiên của dslk 
}

//xoá một phần tử ở cuối dslk
void popBack(node *&head){
    if(head == NULL){
        return;
    }
    node *temp = head;
    if(temp->next == NULL){
        head = NULL;
        delete temp;
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    node *last = temp->next;
    temp->next = NULL;
    delete last;
}
int main(){
    node *head = NULL;
    for(int i = 1; i <= 10; i++){
        pushBack(head, i);
    }
    duyet(head);
    cout << "\n" << size(head) << endl;
    popFront(head);
    duyet(head);
    cout << "\n" << size(head) << endl;
    popBack(head);
    duyet(head);
    cout << "\n" << size(head) << endl;
}