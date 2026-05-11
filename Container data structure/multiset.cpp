#include<bits/stdc++.h>
using namespace std;
int main(){
    multiset<int> se; // {}
    se.insert(2); 
    se.insert(3);  
    se.insert(1);  
    se.insert(2);  
    se.insert(0);  
    se.insert(3);  
    se.insert(4);  // {0,1,2,2,3,3,4}
    cout << se.size() << endl;
    for(int x:se){
        cout << x << " ";
    }
    cout << endl;
    auto it = se.find(3); // iterator tro den vi tri dau tien
    cout << *it << endl;
    cout << distance(se.begin() , it) << endl; //Ham distance tra ve khoang cach giua 2 iterator
    cout << se.count(3) << endl;
}