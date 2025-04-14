#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0) , cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        priority_queue<int> pq;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            pq.push(a);
        }
        int cnt = 0, cur = x, t = 0;
        while(!pq.empty()) {
            if(pq.top() >= x) cnt++;
            else {
                cur = pq.top();
                t++;
                if(cur * t >= x) {
                    t = 0;
                    cnt++;
                }
            }
            pq.pop();
        }
        cout << cnt << '\n';
    }
    return 0;
}