#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S;
ll P[25];

ll calc(vector<ll> &C) {
    ll s = 0;
    REP(i, 26) {
        s += C[i];
    }
    ll p = P[s];
    REP(i, 26) {
        p /= P[C[i]];
    }
    return p;
}

ll dfs(ll index, vector<ll> &C) {
    if (index == S.length())
        return 0;
    ll ret = 0;
    ll c = S[index] - 'A';
    REP(i, 26) {
        if (C[i] == 0)
            continue;
        if (i < c) {
            C[i]--;
            ret += calc(C);
            C[i]++;
            continue;
        }
        C[i]--;
        ret += dfs(index + 1, C);
        C[i]++;
        break;
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    ll N = S.length();
    vector<ll> C(30, 0);
    REP(i, N) {
        C[S[i] - 'A']++;
    }

    P[0] = 1;
    REP(i, N) {
        P[i + 1] = P[i] * (i + 1);
    }
    cout << dfs(0, C) + 1 << endl;
    return 0;
}