#include<bits/stdc++.h>
using namespace std;

template<class T>
class node{
    private:
       T data;
       node *next;
    public:
       node(){}
       node(T x, node<T> *N = NULL){
        data = x;
        next = N;
       }
       void setdata(T x){
        data = x;
       }
       void setnext(node<T> *N = NULL){
        next = N;
       }
       T &getdata(){
        return data;
       }
       node<T> *&getnext(){
        return next;
       }
};
template<class T>
class LIST{
    private:
       unsigned int n;
       node<T> *head, *tail;
    public:
       LIST(){
        head = tail = NULL;
        n = 0;
       }
       unsigned int size(){
        return n;
       }
       bool empty(){
        return n == 0;
       }
       void duyet(){
        while(head != NULL){
            cout << head->getdata() << " ";
            head = head->getnext();
        }
       }
       void pushfront(T x){
        node<T> *tmp = head;
        head = new node<T>(x, tmp);
        if(n == 0) tail = head;
        n++;
       }
       void pushback(T x){
        if(n == 0){
            pushfront(x);
            return;
        }
        node<T> *tmp = tail;
        tail = new node<T>(x, NULL);
        tmp->setnext(tail);
        n++;
       }
       void popfront(){
        if(n == 0){
            return;
        }
        node<T> *tmp = head;
        head = head->getnext();
        delete tmp;
        n--;
       }
       void popback(){
        if(n == 0){
            return;
        }
        if(n == 1){
            delete head;
            head = tail = NULL;
            n--;
            return;
        }
        node<T> *tmp = head;
        while(tmp->getnext() != tail){
            tmp = tmp->getnext();
        }
        delete tail;
        tail = tmp;
        tail->setnext(NULL);
        n--;
       }
       void insert(T x, int k){
        if(k < 1 || k > n){
            return;
        }
        if(k == 0){
            pushfront(x);
            return;
        }
        if(k == n){
            pushback(x);
            return;
        }
        node<T> *tmp = head;
        for(int i = 0; i < k - 1; i++){
            tmp = tmp->getnext();
        }
        node<T> *newNode = new node<T>(x, tmp->getnext());
        tmp->setnext(newNode);
        n++;
       }
       void erase(int k){
        if(k < 1 || k > n){
            return;
        }
        if(k == 1){
            popfront();
            return;
        }
        if(k == n){
            popback();
            return;
        }
        node<T> *tmp = head;
        for(int i = 0; i < k - 1; i++){
            tmp = tmp->getnext();
        }
        node<T> *del = tmp->getnext();
        tmp->setnext(tmp->getnext()->getnext());
        delete del;
        n--;
       }
};