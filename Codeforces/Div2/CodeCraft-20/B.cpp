#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<string, ll> psl;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve(string &S) {
    ll N = S.length();
    vector<psl> v;
    REP(i, N) {
        string s = "";
        FOR(j, N, i) {
            s.push_back(S[j]);
        }

        if (i % 2 == N % 2) {
            REP(j, i) {
                s.push_back(S[j]);
            }
        }
        else {
            for (ll j = i - 1; j >= 0; --j) {
                s.push_back(S[j]);
            }
        }
        v.push_back(psl(s, i + 1));
    }

    sort(v.begin(), v.end(), [](psl a, psl b) { return a.first == b.first ? a.second < b.second : a.first < b.first; });
    cout << v[0].first << endl;
    cout << v[0].second << endl;
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N;
        cin >> N;
        string S;
        cin >> S;
        solve(S);
    }
    return 0;
}