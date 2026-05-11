#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct province{
    string name;
    ll area;
    ll population;
};
typedef struct province province;

province Nhap(){
    province a;
    cout << "Nhap ten tinh: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, a.name);
    cout << "Nhap dien tich: ";
    cin >> a.area;
    cout << "Nhap dan so: ";
    cin >> a.population;
    return a;
}
void xuat(province a){
    cout << a.name << " " << a.area << " " << a.population << endl;
}
struct node{
    province data;
    node* next;
};
typedef struct node node;

node *makeNode(province a){
    node *newNode = new node();
    newNode->data = a;
    newNode->next = NULL;
    return newNode;
}
int size(node *head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}
void pushFront(node *&head, province a){
    node *newNode = makeNode(a);
    newNode->next = head;
    head = newNode;
}
void pushBack(node *&head, province a){
    node *newNode = makeNode(a);
    if(head == NULL){
        pushFront(head, a);
        return;
    }
    node *tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void fix(node *&head, string s){
    int n = size(head);
    if(head == NULL){
        return;
    } 
    if(head->data.name == s){
        cout << "Nhap thong tin moi" << endl;
        province b = Nhap();
        head->data = b;
        return;
    }   
    node *tmp = head;
    while(tmp->next != NULL){
        if(tmp->next->data.name == s){
            cout << "Nhap thong tin moi" << endl;
            province b = Nhap();
            tmp->next->data = b;
            return;
        }
        tmp = tmp->next;
    }
}
void erase(node *&head, string s){
    if(head == NULL){
        return;
    }
    if(head->data.name == s){
        node *del = head;
        head = head->next;
        delete del;
        return;
    }
    node *tmp = head;
    while(tmp->next != NULL){
        if(tmp->next->data.name == s){
            node *del = tmp->next;
            tmp->next = del->next;
            delete del;
            return;
        }
        tmp = tmp->next;
    }
}
void duyet(node *head){
    while(head != NULL){
        xuat(head->data);
        head = head->next;
    }
}
int SumArea(node *head){
    int S = 0;
    while(head != NULL){
        S += head->data.area;
        head = head->next;
    }
    return S;
}
void MaxPP(node *head){
    int max = -1e9;
    province tmp;
    while(head != NULL){
        if(head->data.population > max){
            tmp = head->data;
            max = head->data.population;
            head = head->next;
        }
        head = head->next;
    }
    xuat(tmp);
}
int main(){
    node *head = NULL;
    while(1){
        system("cls");
        cout << "1. Them vao 1 tinh" << endl;
        cout << "2. In danh sach" << endl;
        cout << "3. Sua thong tin mot tinh" << endl;
        cout << "4. Xoa mot tinh" << endl;
        int t;
        cin >> t;
        switch(t){
            case 1:{
                province a = Nhap();
                pushBack(head, a);
                break;
            }
            case 2:{
                duyet(head);
                break;
            }
            case 3:{
                cout << "Nhap ten tinh can sua: ";
                string s;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, s);
                fix(head, s);
                cout << "Thong tin da duoc sua!";
                break;
            }
            case 4:{
                cout << "Nhap ten tinh can sua: ";
                string s;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, s);
                erase(head, s);
                cout << "Thong tin da duoc xoa!";
                break;
            }
            case 5:{
                
            }
            default: break;
        }
        system("pause");
    }
}