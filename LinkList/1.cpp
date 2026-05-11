#include<bits/stdc++.h>
using namespace std;

//Cấu trúc tự trỏ
struct node{
    int data;
    node *next; //link - con trỏ kiểu node
};
typedef struct node node;
//Hàm tạo một node mới
node* makeNode(int x){
    node *newNode = new node();
    newNode->data = x; //Vì node là con trỏ kiểu node nên dùng ->; newNode->data == (*newNode).data
    newNode->next = NULL;
    return newNode;
}

//Hàm duyệt phần tử
void duyet(node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next; //Gán địa chỉ thành địa chỉ của node tiếp theo
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

//Thêm một node vào đầu danh sách liên kết
// void push_Front(node **head, int x){
//     node *newNode = makeNode(x);
//     //Bước 1: phần next của newNode => head
//     newNode->next = *head; //*head => địa chỉ của node head trong dslk
//     //Bước 2: Cập nhật node head => newNode;
//     *head = newNode;
// }
void push_Front2(node *&head, int x){
    node *newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
}
int main(){
    node *head = NULL;
    for(int i = 0; i < 5; i++){
        push_Front2(head, i);
    }
    duyet(head);
    cout << endl;
    cout << count(head);
}