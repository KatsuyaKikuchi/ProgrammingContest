#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll B[100005];
ll C[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, A;
    cin >> N >> A;
    A--;
    string S;
    cin >> S;
    REP(i, N) {
        cin >> B[i];
        B[i]--;
    }
    memset(C, 0, sizeof(C));

    ll index = 1;
    ll move = 0;
    ll loop = 0;
    while (true) {
        if (C[A] > 0) {
            move = C[A] - 1;
            loop = index - C[A];
            break;
        }

        C[A] = index++;
        A = B[A];
    }

    cout << move << " " << loop << endl;



    return 0;
}