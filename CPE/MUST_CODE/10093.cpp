//A easy problem
#include <bits/stdc++.h>
using namespace std;
set<string> st;
int main() {
	string s;
	while(getline(cin, s)) {
		vector<int> v(s.size());
		int base = -1;
		int sum = 0;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] >= 'A' && s[i] <= 'Z') v[i] = s[i] - 'A' + 10;
			else if(s[i] >= 'a' && s[i] <= 'z')v[i] = s[i] - 'a' + 36;
			else if(s[i] >= '0' && s[i] <= '9')v[i] = s[i] - '0';	
            else continue;
			base = max(base, v[i]);
			sum += v[i];
		}
        if(base == -1) break;
		base++;
		if(sum == 0) {
			cout << 2 << '\n';
			continue;
		}
		int z = 0;
		for(; base < 63; base++) {
			if(sum % (base - 1) == 0) {
				z = 1;
				break;
			}
		}
		if(z) cout << base << '\n';
		else cout << "such number is impossible!" << '\n';
	}
	return 0;
	
}