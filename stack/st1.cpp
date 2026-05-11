#include<bits/stdc++.h>
using namespace std;
 
// LIFO : Last in first out
// push : đẩy phần tử vào stack
// pop : xoá phần tử ở đỉnh 
// top : truy cập giá trị phần tử ở đỉnh
// size : trả về số lượng phần tử
// empty : check rỗng
// time complex : O(1)

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    st.pop();
    st.pop();
    if(st.empty()) cout << "EMPTY" << endl;
}