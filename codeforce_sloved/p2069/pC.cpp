#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 998244353;
int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		int dp = 0, ans = 0;
		int empty = 0;
		for (int i = 0; i < N; i++) {
			int a; cin >> a;
			if (a == 1) {
				dp++;
				empty++;
			} else if (a == 2) {
				dp += dp;
			} else if (a == 3) {
				ans += dp - empty;
			}
		}
		cout << ans << '\n';
	}
 
	return 0;
}