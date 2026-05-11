#include<bits/stdc++.h>
using namespace std;

int prime(int n){
    for(int i = 2; i < sqrt(n); i++){
        if(n % i == 0) return 0;
    }
    return n > 1;
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
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
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
int maxNode(node *head){
    int max = -1e9;
    while(head != NULL){
        if(head->data > max){
            max = head->data;
            head = head->next;
        } else head = head->next;
    }
    return max;
}
int sumNode(node *head){
    int s = 0;
    while(head != NULL){
        s += head->data;
        head = head->next;
    }
    return s;
}
int cntPrime(node *head){
    int cnt = 0;
    while(head != NULL){
        if(prime(head->data) == 1){
            cnt++;
            head = head->next;
        }else head = head->next;
    }
    return cnt;
}
bool cond(int n, string s){
    if(s == "am"){
        return n < 0;
    }
    if(s == "duong"){
        return n > 0;
    }
    if(s == "khong"){
        return n == 0;
    }
}
int demDk(node *head, string s){
    int cnt = 0;
    while(head != NULL){
        if(cond(head->data, s) == true){
            cnt++;
            head = head->next;
        }
        else head = head->next;
    }
    return cnt;
}
int demX(node *head, int x){
    int cnt = 0;
    while(head != NULL){
        if(head->data == x){
            cnt++;
            head = head->next;
        } head = head->next;
    }
    return cnt;
}
int minPos(node *head){
    int min = 1e9;
    while(head != NULL){
        if((head->data > 0) && (head->data < min)){
            min = head->data;
            head = head->next;
        }
        head = head->next;
    }
    return min;
}
int main(){
    node *head = NULL;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pushBack(head, x);
    }
    cout << "Danh sach: ";
    duyet(head);
    cout << endl;
    cout << "Phan tu lon nhat: " << maxNode(head) << endl;
    cout << "Tong cac phan tu: " << sumNode(head) << endl;
    cout << "So luong so nguyen to: " << cntPrime(head) << endl;
    cout << "So luong so am: " << demDk(head, "am") << endl;
    cout << "So luong so duong: " << demDk(head, "duong") << endl;
    cout << "So luong so bang khong: " << demDk(head, "khong") << endl;
    int x;
    cout << "Nhap x: ";
    cin >> x;
    cout << "\nSo luong so bang x: " << demX(head, x)<< endl;
    cout << "Phan tu duong nho nhat: " << minPos(head);
}