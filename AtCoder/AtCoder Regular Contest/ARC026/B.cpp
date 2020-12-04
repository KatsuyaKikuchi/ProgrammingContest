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
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;

    ll n = 2;
    ll sum = 1;
    while (n * n <= N) {
        if (N % n == 0) {
            sum += n;
            if (N / n != n)
                sum += N / n;
        }
        n++;
    }
    if (sum < N || N == 1)
        cout << "Deficient" << endl;
    else if (sum > N)
        cout << "Abundant" << endl;
    else
        cout << "Perfect" << endl;

    return 0;
}