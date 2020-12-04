#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll T[15];

bool check(string S) {
    ll N = S.length();
    memset(T, 0, sizeof(T));
    REP(i, N) {
        T[S[i] - '0']++;
    }
    if (N <= 3) {
        vector<ll> v;
        REP(i, 10) {
            REP(j, T[i]) {
                v.push_back(i);
            }
        }
        vector<ll> t;
        REP(i, N) {
            t.push_back(i);
        }

        do {
            ll k = 0;
            REP(i, t.size()) {
                k = k * 10 + v[t[i]];
            }
            if (k % 8 == 0)
                return true;

        } while (next_permutation(t.begin(), t.end()));
        return false;
    }

    FOR(i, 1000, 1) {
        if (i % 8 != 0)
            continue;
        if (i < 100 && N >= 4)
            continue;
        vector<ll> P(10, 0);
        ll n = i;
        while (n > 0) {
            ll x = n % 10;
            n /= 10;
            P[x]++;
        }
        if (P[0] > 0)
            continue;

        bool exist = true;
        FOR(j, 10, 0) {
            if (P[j] > T[j])
                exist = false;
        }

        if (exist)
            return true;
    }

    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;

    if (check(S))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


    return 0;
}