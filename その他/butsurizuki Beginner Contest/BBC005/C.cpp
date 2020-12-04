#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;


string create(ll n) {
    string ret = "";
    while (n > 0) {
        ret.push_back(('a' + (n - 1) % 26));
        n /= 26;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<string> S(N);
    REP(i, N) {
        cin >> S[i];
    }

    REP(_, K) {
        ll index = 1;
        while (true) {
            string t = create(index++);

            bool exist = false;
            REP(i, S.size()) {
                if (t == S[i]) {
                    exist = true;
                    break;
                }
            }

            if (exist)
                continue;

            S.push_back(t);
            cout << t << endl;
            break;
        }
    }
    return 0;
}