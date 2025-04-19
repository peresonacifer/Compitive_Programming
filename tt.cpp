#include<bits/stdc++.h>
using namespace std;

int cpt = 0;

char query(char a, char b) {
    cout << "? " << a << " " << b << '\n';
    fflush(stdout);
    char res;
    cin >> res;
    cpt++;

    return res;
}

void merge(string &s, int left, int right) {
    int mid = (left + right) / 2;
    string s1, s2;
    for(int i = left; i < mid + 1; i++) s1 += s[i];
    for(int i = mid + 1; i < right + 1; i++) s2 += s[i];
    int i = 0, j = 0;
    for(int k = left; k < right + 1; k++) {
        if(i > s1.length() - 1 || j > s2.length() - 1) {
            if(i > s1.length() - 1) {
                s.replace(k, right - k + 1, s2, j, s2.length() - j);
            }
            else{
                s.replace(k, right - k + 1, s1, i, s1.length() - i);
            }
            break;
        }

        if(query(s1[i], s2[j]) == '>') s[k] = s2[j++];
        else s[k] = s1[i++];
    } 
}

void merge_sort(string &s, int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        merge_sort(s, left, mid);
        merge_sort(s, mid + 1, right);
        merge(s, left, right);
    }
}

pair<string, string> choose_str(string &s) {
    vector<pair<char, char>> vtr;
    pair<string, string> div;

    for(int i = 0; i < s.size() / 2; i++) {
        char a = s[2 * i] , b = s[2 * i + 1];
        
        if(query(a, b) == '>') swap(a, b);
        vtr.push_back(make_pair(a, b));
        div.first += b;
    }
    if(s.size() % 2) div.first += s[s.size() - 1];
    merge_sort(div.first, 0, div.first.size() - 1);

    for(auto p : vtr) {
        if(p.second == div.first[0]) {
            string str;
            str += p.first;
            div.first.insert(0, str);
        }
        else div.second += p.first;
    }
    
    return div;
}

string binary_insert(string s1, string s2) {
    
}


int main() {
    int N, Q;
    cin >> N >> Q;
    string s;
    for(int i = 0; i < N; i++) s += 'A' + i;
    
    pair<string, string> div = choose_str(s);

    string ans = binary_insert(div.first, div.second);

    // merge_sort(s, 0, s.length() - 1);

    cout << "! " << s << '\n';
    cout << "cpt: " << cpt << '\n';

    return 0;
}