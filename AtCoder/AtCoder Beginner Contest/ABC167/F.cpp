#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[1000006];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> S[i];
    }

    bool e = false;
    REP(i, N) {
        if (S[i][S[i].length() - 1] == ')')
            e = true;
    }
    if (!e) {
        cout << "No" << endl;
        return 0;
    }

    vector<pll> v, t, u;
    REP(i, N) {
        ll d = 0;
        pll tmp(0, 0);
        REP(j, S[i].length()) {
            if (S[i][j] == '(')
                d++;
            else
                d--;
            tmp.first = std::min(tmp.first, d);
        }
        tmp.second = d;
        if (tmp.second >= 0)
            v.push_back(tmp);
        else if (S[i][S[i].length() - 1] == '(')
            u.push_back(tmp);
        else
            t.push_back(tmp);
    }
    sort(v.begin(), v.end(),
         [](pll a, pll b) { return a.first == b.first ? a.second > b.second : a.first > b.first; });

    {
        ll d = 0;
        REP(i, v.size()) {
            if (d + v[i].first < 0) {
                cout << "No" << endl;
                return 0;
            }
            d += v[i].second;
        }
        REP(i, u.size()) {
            if (d + u[i].first < 0) {
                cout << "No" << endl;
                return 0;
            }
            d += u[i].second;
        }
        REP(i, t.size()) {
            if (d + t[i].first < 0) {
                cout << "No" << endl;
                return 0;
            }
            d += t[i].second;
        }
        if (d != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}