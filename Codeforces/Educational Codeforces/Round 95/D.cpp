#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, Q;
    cin >> N >> Q;
    REP(i, N) {
        cin >> P[i];
    }

    sort(P, P + N);
    std::set<ll> s;
    std::multiset<ll> dist;
    REP(i, N) {
        s.insert(P[i]);
        if (i > 0)
            dist.insert(P[i] - P[i - 1]);
    }

    if (s.size() <= 1)
        cout << 0 << endl;
    else {
        ll len = P[N - 1] - P[0];
        ll p = *dist.rbegin();
        cout << len - p << endl;
    }

    REP(i, Q) {
        ll t, x;
        cin >> t >> x;
        if (t == 0) {
            auto it = s.find(x);
            ll left = -1;
            if (it != s.begin()) {
                it--;
                left = *it;
                it++;
            }
            it++;
            ll right = -1;
            if (it != s.end()) {
                right = *it;
            }
            it--;

            if (left >= 0 && right >= 0) {
                ll len = right - left;
                dist.insert(len);
            }
            ll p = *it;
            if (left >= 0) {
                auto it2 = dist.find(p - left);
                dist.erase(it2);
            }
            if (right >= 0) {
                auto it2 = dist.find(right - p);
                dist.erase(it2);
            }
            s.erase(it);
        }
        else {
            auto it = s.upper_bound(x);
            ll right = -1;
            if (it != s.end()) {
                right = *it;
            }
            ll left = -1;
            if (it != s.begin()) {
                it--;
                left = *it;
                it++;
            }
            if (left >= 0 && right >= 0) {
                ll len = right - left;
                auto it2 = dist.find(len);
                dist.erase(it2);
            }

            ll p = x;
            if (left >= 0) {
                dist.insert(p - left);
            }
            if (right >= 0) {
                dist.insert(right - p);
            }
            s.insert(x);
        }

        if (s.size() <= 1) {
            cout << 0 << endl;
        }
        else {
            ll len = *s.rbegin() - *s.begin();
            ll p = *dist.rbegin();
            cout << len - p << endl;
        }
    }

    return 0;
}