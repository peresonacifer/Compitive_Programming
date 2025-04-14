#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            q.push(i);
        }
        while(q.size() > 1) {
            for(int i = 1; i < k; i++) {
                q.push(q.front());
                q.pop();
            }
            q.pop();
        }
        cout << q.front() << '\n';
    }


    return 0;
}
