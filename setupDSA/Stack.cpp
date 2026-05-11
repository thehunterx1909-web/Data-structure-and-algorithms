#include<bits/stdc++.h>
using namespace std;

template<class T>
class node{
    private:
       T data;
       node *next;
    public:
       node(){
        data = 0;
        next = NULL;
       }
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
class STACK{
    private:
       unsigned int n;
       node<T> *head;
    public:
       STACK(){
        n = 0;
        head = NULL;
       }
       unsigned int size(){
        return n;
       }
       bool empty(){
        return n == 0;
       }
       T &top(){
        return head->getdata();  
       }
       void push(T x){
        head = new node<T>(x, head);
        n++;
       }
       void pop(){
        if(n == 0){
            return;
        }
        if(n == 1){
            head = NULL;
            n = 0;
            return;
        }
        node<T> *tmp = head;
        head = head->getnext();
        delete tmp;
        n--;
       }
};