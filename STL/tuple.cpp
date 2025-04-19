#include<iostream>
#include<tuple>
#include<algorithm>
using namespace std;

tuple<string, int, int, double> item[10];
int main(){
    string s; int a, b; double d;
    for(int i = 0; i < 5; i++){
        cin >> s >> a >> b >> d;
        item[i] = make_tuple(s, a, b, d);
    }
    sort(item, item+5, [](auto const& a, auto const& b){
        return get<2>(a) > get<2>(b);
    }); 
    tie(s, a, b, d) = item[0];
    cout << s << " " << b << " " << d << " " << get<0>(item[1]) << endl;
    return 0;
}