#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll K, N;
string A[100];
string S[100];

//! i番目が何文字の文字列か
vector<vector<ll>> v;

void dfs(vector<ll> t) {
    if (t.size() == K) {
        v.push_back(t);
        return;
    }

    REP(i, 3) {
        t.push_back(i + 1);
        dfs(t);
        t.pop_back();
    }
    return;
}

bool check(vector<ll> t) {
    vector<string> s(K);
    REP(i, N) {
        ll index = 0;
        REP(j, A[i].size()) {
            ll n = A[i][j] - '1';
            string m = "";
            REP(k, t[n]) {
                if (S[i].size() <= index)
                    break;
                m.push_back(S[i][index++]);
            }
            s[n] = m;
        }
    }

    REP(i, N) {
        string m = "";
        REP(j, A[i].size()) {
            m += s[A[i][j] - '1'];
        }
        if (m != S[i])
            return false;
    }

    REP(i, K) {
        cout << s[i] << endl;
    }
    return true;
}

int main() {
    cin >> K >> N;
    REP(i, N) {
        cin >> A[i] >> S[i];
    }

    vector<ll> t;
    dfs(t);

    REP(i, v.size()) {
        if (check(v[i])) {
            break;
        }
    }

    return 0;
}