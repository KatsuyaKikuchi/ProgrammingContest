#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve(const ll &m, const string &s) {
    ll n = s.length();
    vector<ll> v0(n + 1, 0);//! 短い方
    vector<ll> v1(n + 1, 0);//! 長い方
    {
        vector<bool> u(n + 2, false);

        ll small = 1;
        for (ll i = n - 1; i >= 0; --i) {
            if (s[i] == '>')
                continue;
            if (i == 0 || s[i - 1] == '>') {
                FOR(j, n, i) {
                    if (s[j] == '>')
                        break;
                    v0[j] = small;
                    u[small] = true;
                    small++;
                }
            }
        }
        ll num = 1;
        for (ll i = n; i >= 0; --i) {
            if (v0[i] > 0)
                continue;
            while (u[num]) {
                num++;
            }
            v0[i] = num;
            u[num] = true;
        }
    }
    {
        vector<bool> u(n + 2, false);
        ll small = 1;
        REP(i, n) {
            if (s[i] == '>')
                continue;
            v1[i] = small;
            u[small] = true;
            small++;
        }
        ll num = 1;
        for (ll i = n; i >= 0; --i) {
            if (v1[i] > 0)
                continue;
            while (u[num]) {
                num++;
            }
            v1[i] = num;
            u[num] = true;
        }
    }

    REP(i, n + 1) {
        cout << v0[i];
        if (i < n)
            cout << " ";
    }
    cout << endl;
    REP(i, n + 1) {
        cout << v1[i];
        if (i < n)
            cout << " ";
    }
    cout << endl;
}

struct Data {
    ll m;
    string s;
};
Data D[10004];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> D[i].m >> D[i].s;
    }
    REP(i, N) {
        solve(D[i].m, D[i].s);
    }
    return 0;
}