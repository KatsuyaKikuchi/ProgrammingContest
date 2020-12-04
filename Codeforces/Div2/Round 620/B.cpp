#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[105];
bool L[105];
bool U[105];

bool check(string s) {
    ll n = s.length();
    REP(i, n) {
        if (s[i] != s[n - 1 - i])
            return false;
    }
    return true;
}

bool check(string a, string b) {
    ll n = a.length();
    REP(i, n) {
        if (a[i] != b[n - 1 - i])
            return false;
    }
    return true;
}

int main() {
    ll N, M;
    cin >> N >> M;
    memset(U, 0, sizeof(U));
    memset(L, 0, sizeof(L));
    REP(i, N) {
        cin >> S[i];
        L[i] = check(S[i]);
    }

    vector<pll> v;
    REP(i, N) {
        if (U[i])
            continue;
        FOR(j, N, i + 1) {
            if (U[j])
                continue;
            if (check(S[i], S[j])) {
                v.push_back(pll(i, j));
                U[i] = U[j] = true;
            }
        }
    }

    ll num = v.size() * M * 2;
    REP(i, N) {
        if (U[i])
            continue;
        if (L[i]) {
            v.push_back(pll(i, -1));
            num += M;
            break;
        }
    }

    cout << num << endl;
    if (num > 0) {
        REP(i, v.size()) {
            if (v[i].first >= 0)
                cout << S[v[i].first];
        }
        for (ll i = v.size() - 1; i >= 0; --i) {
            if (v[i].second >= 0)
                cout << S[v[i].second];
        }
        cout << endl;
    }

    return 0;
}