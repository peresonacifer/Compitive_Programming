#include<bits/stdc++.h>
using namespace std;

int main() {
    auto cmp = [](const string &a, const string &b) {
        return a.size() > b.size(); 
    };
    priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        pq.push(s);
    }
    string ans;
    for(int i =0 ; i < n; i++) {
        ans += pq.top();
        pq.pop();
    }
    
    cout << ans << '\n';
    return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// ✅ (1) 使用函式
bool compare(int a, int b) {
    return a > b;
}

// ✅ (2) 使用 struct + operator()
struct Compare {
    bool operator()(int a, int b) {
        return a > b;
    }
};

// ✅ (3) 使用 Lambda
auto cmp = [](int a, int b) { return a > b; };

int main() {
    priority_queue<int, vector<int>, Compare> pq1; // 使用 struct
    priority_queue<int, vector<int>, decltype(cmp)> pq2(cmp); // 使用 Lambda

    pq1.push(3); pq1.push(1); pq1.push(5);
    pq2.push(3); pq2.push(1); pq2.push(5);

    cout << "Using struct: " << pq1.top() << endl; // 1
    cout << "Using lambda: " << pq2.top() << endl; // 1

    return 0;
}
