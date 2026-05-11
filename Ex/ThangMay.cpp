//Thang máy có n tầng, mỗi lần có thể lên m tầng, xuống k tầng
//Có bao nhiêu bước để đi từ tầng s đến f
#include<bits/stdc++.h>
using namespace std;

int bfs(int n, int m, int k, int s, int f){
    unordered_map<int, int> mp;
    mp[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        int up = curr + m;
        int down = curr - k;
        unordered_map<int, int>::iterator it1 = mp.find(up);
        unordered_map<int, int>::iterator it2 = mp.find(down);
        if(up <= n && up != s && it1 == mp.end()){
            q.push(up);
            mp[up] = mp[curr] + 1;
        }
        if(down > 0 && down != s && it2 == mp.end()){
            q.push(down);
            mp[down] = mp[curr] + 1;
        }
    }
    return mp[f];
}
int main(){
    int n, m, k, s, f;
    cin >> n >> m >> k >> s >> f;
    cout << bfs(n,m,k,s,f);
}