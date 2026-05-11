#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> se; // {}
    se.insert(2); //{2}
    se.insert(3);  //{2,3}
    se.insert(1);  //{1,2,3}
    se.insert(2);  // {1,2,3}
    se.insert(0);  // {0,1,2,3}
    se.insert(3);  // {0,1,2,3}
    se.insert(4);  // {0,1,2,3,4}
    cout << se.size() << endl;
    for(int x:se){
        cout << x << " ";
    }
    cout << endl;
    for(auto it = se.begin(); it!=se.end() ; it++ ){
        cout << *it << " ";
    }
}