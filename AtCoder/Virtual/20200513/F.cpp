#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll C[30];
ll base = 9973;
ll mod[2] = {999999937, 1000000007};

pll getHash() {
    pll ret(0, 0);
    pll b(1, 1);
    REP(i, 27) {
        ret.first += C[i] * b.first % mod[0];
        ret.second += C[i] * b.second % mod[1];
        ret.first %= mod[0];
        ret.second %= mod[1];
        b.first = b.first * base % mod[0];
        b.second = b.second * base % mod[1];
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    memset(C, 0, sizeof(C));
    REP(i, K) {
        C[S[i] - 'a']++;
    }
    bool exist = false;
    map<pll, ll> m;
    m[getHash()] = 1;
    FOR(i, N, 1) {
        if (i + K - 1 >= N)
            break;
        C[S[i - 1] - 'a']--;
        C[S[i + K - 1] - 'a']++;
        pll h = getHash();
        if (m[h] == 0)
            m[h] = i + 1;
        else if (m[h] + K <= i + 1)
            exist = true;
    }

    if (exist)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}