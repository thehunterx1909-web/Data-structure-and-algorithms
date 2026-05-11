#include<bits/stdc++.h>
using namespace std;

template<class T>
class node{
private:
    T elem;
    node *next;
public:
    node() : next(NULL) {}
    node(T x, node<T> *N = NULL){
        elem = x;
        next = N;
    }
    T &getelem(){
        return elem;
    }
    node<T> *&getnext(){
        return next;
    }
    void setelem(T x){
        elem = x;
    }
    void setnext(node<T> *N = NULL){
        next = N;
    }
};

template<class T>
class QUEUE{
private:
    unsigned int num;
    node<T> *F, *L;
public:
    QUEUE(){
        num = 0;
        F = L = NULL;
    }
    unsigned int size(){
        return num;
    }
    T &front(){
        return F->getelem();
    }
    T &back(){
        return L->getelem();
    }
    void push(T x){
        if(num == 0){
            F = L = new node<T>(x);
        }else {
            L->setnext(new node<T>(x));
            L = L->getnext();
        }
        num++;
    }
    void pop(){
        if(num == 0) return;

        node<T>* tmp = F;
        F = F->getnext();
        delete tmp;

        num--;
        if(num == 0) F = L = NULL;  // hàng rỗng
    }
};

int main(){
    QUEUE<int> q;
    for(int i = 0; i <= 10; i++){
        q.push(i);
    }
    cout << q.front() << endl;
}
