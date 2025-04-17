#include <iostream>
#include <unordered_map>
#include <tuple>
using namespace std;

struct State {
    int a6, a10, a12, a16, xor_val;
    bool operator==(const State& other) const {
        return tie(a6, a10, a12, a16, xor_val) == tie(other.a6, other.a10, other.a12, other.a16, other.xor_val);
    }
};

namespace std {
    template <>
    struct hash<State> {
        size_t operator()(const State& s) const {
            return (((((s.a6 * 31 + s.a10) * 31 + s.a12) * 31 + s.a16) * 31) ^ s.xor_val);
        }
    };
}

unordered_map<State, int> memo;

int dfs(int a6, int a10, int a12, int a16, int xor_val) {
    if (a6 + a10 + a12 + a16 == 0) return 0;
    State key{a6, a10, a12, a16, xor_val};
    if (memo.count(key)) return memo[key];

    int max_score = 0;
    if (a6 > 0)
        max_score = max(max_score, ((xor_val ^ 6) == 0) + dfs(a6 - 1, a10, a12, a16, xor_val ^ 6));
    if (a10 > 0)
        max_score = max(max_score, ((xor_val ^ 10) == 0) + dfs(a6, a10 - 1, a12, a16, xor_val ^ 10));
    if (a12 > 0)
        max_score = max(max_score, ((xor_val ^ 12) == 0) + dfs(a6, a10, a12 - 1, a16, xor_val ^ 12));
    if (a16 > 0)
        max_score = max(max_score, ((xor_val ^ 16) == 0) + dfs(a6, a10, a12, a16 - 1, xor_val ^ 16));

    return memo[key] = max_score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a6, a10, a12, a16;
    cin >> a6 >> a10 >> a12 >> a16;

    int total = a6 + a10 + a12 + a16;
    int astra_score = dfs(a6, a10, a12, a16, 0);
    int byte_score = total - astra_score;

    if (astra_score > byte_score) {
        cout << "Astra\n" << astra_score << '\n';
    } else if (astra_score < byte_score) {
        cout << "Byte\n" << byte_score << '\n';
    } else {
        cout << "Tie\n" << astra_score << '\n';
    }

    return 0;
}
