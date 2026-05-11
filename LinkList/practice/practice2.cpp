#include<bits/stdc++.h>
using namespace std;

int prime(int n){
    for(int i = 2; i < sqrt(n); i++){
        if(abs(n) % i == 0){
            return 0;
        }
    }
    return abs(n) > 1;
}
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
    while(head !=NULL){
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
void popFront(node *&head){
    if(head == NULL) return;
    node *tmp = head;
    head = head->next;
    delete tmp;
}
void popBack(node *&head){
    if(head == NULL) return;
    if(size(head) == 1){
        head = NULL;
        return;
    }
    node *tmp = head;
    while(tmp->next->next != NULL){
        tmp = tmp->next;
    }
    node *last = tmp->next;
    tmp->next = NULL;
    delete last;
}
void erase(node *&head, int q){
    int n = size(head);
    if(q < 1 || q > n + 1){
        return;
    }
    if(q == 1){
        popFront(head);
        return;
    }
    node *tmp = head;
    for(int i = 1; i < q - 1; i++){
        tmp = tmp->next;
    }
    node *ans = tmp->next;
    tmp->next = ans->next;
    delete ans;
}
void eraseK(node *&head, int k){
    if(head == NULL){
        return;
    }
    node *tmp = head;
    if(size(head) == 1){
        if(head->data == k){
            popFront(head);
            return;
        }
    }
    int cnt = 0;
    while(tmp != NULL){
        if(tmp->data == k){
            erase(tmp, cnt++);
            tmp = tmp->next;
        }else{
        cnt++;
        tmp = tmp->next;}
    }
}
void erasePrime(node *&head){
    if(head == NULL){
        return;
    }
    node *tmp = head;
    if(size(head) == 1){
        if(prime(head->data)){
            popFront(head);
            return;
        }
    }
    int cnt = 0;
    while(tmp != NULL){
        if(prime(tmp->data)){
            erase(tmp, cnt++);
            tmp = tmp->next;
        }
        cnt++;
        tmp = tmp->next;
    }
}
int main(){
  node *head = NULL;
  while(1){
   system("cls");
   cout << "--------------------" << endl;
   cout << "1. Them phan tu vao cuoi" << endl;
   cout << "2. Xoa phan tu dau tien" << endl;
   cout << "3. Xoa phan tu cuoi cung" << endl;
   cout << "4. Xoa phan tu tai vi tri q" << endl;
   cout << "5. Xoa phan tu truoc vi tri q" << endl;
   cout << "6. Xoa phan tu co gia tri k" << endl;
   cout << "7. Xoa tat ca cac so nguyen to" << endl;
   cout << "8. In ds" << endl;
   cout << "\nMoi ban chon: ";
   int t; cin >> t;
   if(t < 1 || t > 8) continue;
   switch(t){
    case 1:{
        int x;
        cin >> x;
        pushBack(head,x);
        break;
    }
    case 2:{
        popFront(head);
        cout << "Da xoa phan tu dau tien !";
        break;
    }
    case 3:{
        popBack(head);
        cout << "Da xoa phan tu cuoi cung !";
        break;
    }
    case 4:{
        int q;
        cout << "Nhap q: ";
        cin >> q;
        erase(head,q);
        cout << "Da xoa phan tu tai q!";
        break;
    }
    case 5:{
        int q;
        cout << "Nhap q: ";
        cin >> q;
        erase(head,q - 1);
        cout << "Da xoa phan tu truoc q!";
        break;
    }
    case 6:{
        int k;
        cout << "Nhap k: ";
        cin >> k;
        eraseK(head, k);
        cout << "Da xoa cac phan tu bang k!";
        break;
    }
    case 7:{
        erasePrime(head);
        cout << "Da xoa tat ca so nguyen to!";
        break;
    }
    case 8:{
        duyet(head);
        break;
    }
    default: break;
   } 
   system("pause");
  }
}