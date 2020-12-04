#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<ll> v;
    v.push_back(-1);
    REP(i, N) {
        if (S[i] == 'L')
            v.push_back(i);
    }

    ll sum = 0;
    vector<vector<int>> u;
    while (true) {
        vector<int> t;

        for (ll i = v.size() - 1; i > 0; --i) {
            if (i - 1 == v[i])
                break;
            if (v[i] > v[i - 1] + 1) {
                t.push_back(v[i]);
                v[i]--;
            }
        }
        if (t.size() == 0)
            break;
        sort(t.begin(), t.end());
        u.push_back(t);
        sum += t.size();
    }

    if (u.size() > K || sum < K) {
        cout << -1 << endl;
        return 0;
    }

    ll index = 0;
    REP(i, K) {
        if (K - i == u.size() - index) {
            printf("%d", static_cast<int>(u[index].size()));
            REP(j, u[index].size()) {
                printf(" %d", u[index][j]);
            }
            printf("\n");
            index++;
            continue;
        }
        printf("1 %d\n", u[index][u[index].size() - 1]);
        u[index].pop_back();
        if (u[index].size() == 0)
            index++;
    }
    return 0;
}