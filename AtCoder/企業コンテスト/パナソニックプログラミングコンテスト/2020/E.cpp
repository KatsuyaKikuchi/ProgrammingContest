#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[3];
bool AB[5005];
bool BC[5005];
bool AC[5005];

ll solve(const string &a, const string &b, const string &c) {
    memset(AB, 0, sizeof(AB));
    memset(AC, 0, sizeof(AC));
    memset(BC, 0, sizeof(BC));

    REP(i, 5000) {
        bool ok = true;
        REP(j, c.size()) {
            if (i + j >= a.size())
                break;
            if (a[i + j] == c[j])
                continue;
            if (a[i + j] == '?' || c[j] == '?')
                continue;
            ok = false;
            break;
        }
        AC[i] = ok;
    }
    REP(i, 5000) {
        bool ok = true;
        REP(j, b.size()) {
            if (i + j >= a.size())
                break;
            if (a[i + j] == b[j])
                continue;
            if (a[i + j] == '?' || b[j] == '?')
                continue;
            ok = false;
            break;
        }
        AB[i] = ok;
    }
    REP(i, 5000) {
        bool ok = true;
        REP(j, c.size()) {
            if (i + j >= b.size())
                break;
            if (b[i + j] == c[j])
                continue;
            if (b[i + j] == '?' || c[j] == '?')
                continue;
            ok = false;
            break;
        }
        BC[i] = ok;
    }

    ll min = a.size() + b.size() + c.size();
    REP(i, a.size() + 5) {
        REP(j, b.size() + a.size() + 5) {
            ll ci = i + j;
            if (AC[ci] && BC[j] && AB[i]) {
                min = std::min(min, std::max({(ll) a.size(), (ll) (i + b.size()), (ll) (ci + c.size())}));
            }
        }
    }
    return min;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    REP(i, 3) {
        cin >> S[i];
    }

    ll ans = INF;
    vector<ll> v = {0, 1, 2};
    do {
        ans = std::min(ans, solve(S[v[0]], S[v[1]], S[v[2]]));
    } while (next_permutation(v.begin(), v.end()));
    cout << ans << endl;
    return 0;
}