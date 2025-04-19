#include<bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> bpq;
    priority_queue<int> spq;
    int n;
    while(cin >> n) {
        if(spq.size() >= bpq.size()) bpq.push(n);
        else spq.push(n);
        
        if(!spq.empty() && spq.top() > bpq.top()) {
            bpq.push(spq.top());
            spq.push(bpq.top());
            bpq.pop();
            spq.pop();
        }    

        if(!((bpq.size() + spq.size()) % 2)) cout << (bpq.top() + spq.top()) / 2<< '\n';
        else cout << bpq.top() << '\n' ;
        
    }

    return 0;
}