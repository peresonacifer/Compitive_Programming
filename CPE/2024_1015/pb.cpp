#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<char,int>& a, const pair<char,int>& b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
int main() {
    string str;
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> b;
    int N = 0;
    while(getline(cin, str)) {
        N++;
        stringstream ss(str);
        int n;
        if(!(ss >> n)) break;;
        if(s.size() >= b.size()) {
            s.push(n);
            b.push(s.top());
            s.pop();
        }
        else {
            b.push(n);
            s.push(b.top());
            b.pop();
        }
        cout << ((N % 2) ? b.top() : (b.top() + s.top()) / 2) << '\n';
    }
    return 0;
}
/*
1
3
4
60
70
50
2


*/