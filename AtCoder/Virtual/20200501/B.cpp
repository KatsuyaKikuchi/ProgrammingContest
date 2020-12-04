#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[10];

double dist(vector<ll> v) {
    double ret = 0;
    REP(i, v.size() - 1) {

        ret += sqrt(pow(A[v[i]].first - A[v[i + 1]].first, 2) + pow(A[v[i]].second - A[v[i + 1]].second, 2));
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    vector<ll> v;
    REP(i, N) {
        v.push_back(i);
    }

    double sum = 0;
    ll num = 0;
    do {
        sum += dist(v);
        num++;
    } while (next_permutation(v.begin(), v.end()));

    cout << OF64 << sum / num << endl;
    return 0;
}