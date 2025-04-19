#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

#define F first
#define S second
#define all(x) begin(x), end(x)

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int i, j, n, k, x;
    cin >> k >> n;
    vector<pii> segs(n);
    for (int i = 0; i < n; i++) {
        cin >> segs[i].F >> segs[i].S;
        if (segs[i].F > segs[i].S) {
            swap(segs[i].F, segs[i].S);
        }
    }

    sort(all(segs), [](pii &a, pii &b) { return a.S < b.S; });

    vector<int> fills;
    vector<int>::iterator itst, ited;
    int inter_len, complement;
    for (int i = 0; i < n; i++) {
        itst = lower_bound(all(fills), segs[i].F);
        ited = upper_bound(all(fills), segs[i].S); //only greater
        inter_len = ited - itst; 
        // if (inter_len != 0) {
        //     cout << "Address of *ited: " << &(*ited) << "\n";
        //     cout << "Address of *itst: " << &(*itst) << "\n";
        // }
        // cout << "inter_len: " << inter_len << "\n";
        complement = k - inter_len;
        // cout << "complement: " << complement << "\n";

        for (x = segs[i].S; x >= segs[i].F && complement > 0; x--) {
            
            if (ited != fills.begin() && x == *(ited - 1)) {
                // cout << *ited << "#\n";
                ited--;
                fills.pop_back();
                continue;
            }
            // cout << *ited << "##\n";
            complement--;
        }

        for (x++; x <= segs[i].S; x++) {
            fills.push_back(x);
        }
    }

    cout << fills.size() << '\n';
    for (auto it : fills) {
        cout << it << '\n';
    }
    return 0;
}
