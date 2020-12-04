#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

map<ll, ll> Map;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);

    A[0] = 1;
    A[1] = 2;
    Map[3]++;
    pll m(3, 1);
    FOR(i, N, 2) {
        if (M == 0) {
            A[i] = Map.rbegin()->first + 1;
        }
        else if (M >= m.second) {
            A[i] = m.first;
            M -= m.second;
        }
        else {
            bool exist = false;
            pll max(0, 0);
            for (auto p: Map) {
                if (p.first <= A[i - 1])
                    continue;
                if (p.second <= M) {
                    exist = true;
                    if (max.second < p.second) {
                        max = p;
                    }
                }
            }

            if (!exist) {
                A[i] = Map.rbegin()->first + 1;
            }
            else {
                A[i] = max.first;
                M -= max.second;
            }
        }

        REP(j, i) {
            Map[A[i] + A[j]]++;
            if (Map[A[i] + A[j]] >= m.second) {
                m = pll(A[i] + A[j], Map[A[i] + A[j]]);
            }
        }
    }

    if (M > 0) {
        cout << -1 << endl;
        return 0;
    }
    REP(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}