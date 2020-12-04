#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[1005];

int main() {
    string S;
    cin >> S;
    ll N = S.length();
    memset(A, 0, sizeof(A));
    for (ll i = N - 1; i >= 0; --i) {
        if (S[i] == ')')
            A[i]++;
        A[i] += A[i + 1];
    }

    ll s = 0;
    ll max = 0;
    REP(i, N) {
        if (S[i] == '(')
            s++;
        max = std::max(max, std::min(s, A[i]));
    }

    if (max == 0)
        cout << 0 << endl;
    else {
        cout << 1 << endl;
        cout << max * 2 << endl;
        vector<ll> v;
        REP(i, N) {
            if (S[i] == '(')
                v.push_back(i + 1);
            if (v.size() == max)
                break;
        }
        REP(i, v.size()) {
            cout << v[i] << " ";
        }
        v.clear();
        for (ll i = N - 1; i >= 0; --i) {
            if (S[i] == ')')
                v.push_back(i + 1);
            if (v.size() == max)
                break;
        }
        REP(i, v.size()) {
            cout << v[v.size() - 1 - i];
            if (i < v.size() - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}