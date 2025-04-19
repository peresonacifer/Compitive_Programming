#include<bits/stdc++.h>
using namespace std;

int main() {
    
    struct data{
        int n, m;
    }ar[10005];

    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) {
            cout << n << " " << m << '\n';
            break;
        }
        for(int i = 0; i < n; i++) {
            cin >> ar[i].n;
            ar[i].m = (m) ? ar[i].n % m : 0;
        }

        sort(ar, ar + n, [](data a, data b) {
            if(a.m == b.m) {
                if(!(a.n % 2) && !(b.n % 2)) return a.n < b.n;
                else if(a.n % 2 && b.n % 2) return a.n > b.n;
                else return (a.n % 2) && !(b.n % 2);
            }
            else return a.m < b.m;
        });

        cout << n << " " << m << '\n';
        for(int i = 0; i < n; i++) {
            cout << ar[i].n << '\n';
        }
    }
    return 0;
}
//AC
#include<bits/stdc++.h>
using namespace std;

struct info {
    int n, m;
}arr[10005];

bool cmp(info a, info b) {
    if(a.m == b.m) {
        if(!(a.n&1) && !(b.n&1)) return a.n < b.n;
        else if((a.n&1) && (b.n&1)) return a.n > b.n;
        else return (a.n&1);
    }
    else return a.m < b.m;
}

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m)) {
        if(m == 0 && n == 0) break;

        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i].n);
            arr[i].m = arr[i].n % m;
        }

        sort(arr, arr + n, cmp);
        printf("%d %d\n", n ,m);
        for(int i = 0; i < n; i++) {
            printf("%d\n", arr[i].n);
        }
    }
    puts("0 0");
    return 0;
}

