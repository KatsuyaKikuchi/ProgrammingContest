#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve() {
    ll N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    vector<ll> ans;
    ll index = 0;

    while (index < N) {
        char b = T[N - 1 - index];
        if (index % 2 == 0) {
            char a = S[index / 2];
            if (a == b)
                ans.push_back(1);
            ans.push_back(N - index);
        }
        else {
            char a = S[N - 1 - (index / 2)];
            if (a != b)
                ans.push_back(1);
            ans.push_back(N - index);
        }
        index++;
    }

#if false
    REP(i, ans.size()) {
        ll n = ans[i];
        string s = "";
        REP(j, N) {
            s.push_back(S[j]);
        }
        REP(j, n) {
            s[n - 1 - j] = (char) ((S[j] - '0' + 1) % 2) + '0';
        }
        REP(j, N) {
            S[j] = s[j];
        }
    }
    cout << S << endl;
    cout << T << endl;
#endif

    cout << ans.size();
    REP(i, ans.size()) {
        cout << " " << ans[i];
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}