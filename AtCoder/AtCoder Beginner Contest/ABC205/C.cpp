#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve(ll A, ll B, ll C) {
    if (A == B) {
        return "=";
    }
    if (A == 0) {
        if (C % 2 == 0)
            return "<";
        if (B > 0)
            return "<";
        return ">";
    }

    if (B == 0) {
        if (C % 2 == 0)
            return ">";
        if (A > 0)
            return ">";
        return "<";
    }
    if (abs(A) == abs(B)) {
        if (C % 2 == 0)
            return "=";
        if (A < B)
            return "<";
        return ">";
    }
    if (A < 0 && B > 0) {
        // A<0<B
        if (C % 2 == 1)
            return "<";
        if (abs(A) > abs(B))
            return ">";
        return "<";
    }
    else if (A < 0 && B < 0 && A < B) {
        // A<B<0
        if (C % 2 == 0)
            return ">";
        return "<";
    }
    else if (A < 0 && B < 0 && B < A) {
        // B<A<0
        if (C % 2 == 0)
            return "<";
        return ">";
    }
    else if (B < 0 && A > 0) {
        // B<0<A
        if (C % 2 == 1)
            return ">";
        if (abs(A) > abs(B))
            return ">";
        return "<";
    }
    else if (A > 0 && B > 0 && A > B) {
        // 0<B<A
        return ">";
    }
    else if (A > 0 && B > 0 && B > A) {
        // 0<A<B
        return "<";
    }
    return "<";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, C;
    cin >> A >> B >> C;
    cout << solve(A, B, C) << endl;
    return 0;
}