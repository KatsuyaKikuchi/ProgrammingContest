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
    string S;
    cin >> S;
    ll N = S.length();
    ll cmb = 0;
    ll num = 5;
    ll damage = 0;

    queue<tuple<ll, ll, ll>> dam;
    queue<pll> ret;
    ll stay = 0;
   // ll cnt = 0;
    REP(i, 2 * N) {
        if (!ret.empty() && ret.front().first <= i) {
            num += ret.front().second;
            ret.pop();
        }

        if (!dam.empty() && get<0>(dam.front()) <= i) {
            auto t = dam.front();
            dam.pop();
            pll p(get<0>(t) + 10, get<1>(t));
            ll c = get<2>(t);
            ret.push(p);
            cmb++;
            ll a = 10;
            if (p.second == 3)
                a = 50;
            damage += a + a * c / 10;
        }

        if (i % 2 == 1)
            continue;
        if (i < stay)
            continue;
        if (S[i / 2] == '-')
            continue;
        //cout << cnt << " " << cmb << endl;
        if (S[i / 2] == 'N') {
            if (num == 0)
                continue;
            num--;
            dam.push(make_tuple(i + 3, 1, cmb / 10));
            continue;
        }

        if (num < 3)
            continue;
        num -= 3;
        dam.push(make_tuple(i + 7, 3, cmb / 10));
        stay = i + 5;
    }

    while (!dam.empty()) {
        auto t = dam.front();
        dam.pop();
        pll p(get<0>(t) + 5, get<1>(t));
        ll c = get<2>(t);
        cmb++;
        ll a = 10;
        if (p.second == 3)
            a = 50;
        damage += a + a * c / 10;
    }

    cout << damage << endl;

    return 0;
}