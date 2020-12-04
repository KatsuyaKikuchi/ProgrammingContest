#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll S[100005];
ll T[3];
char C[3] = {'A', 'B', 'C'};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N >> T[0] >> T[1] >> T[2];
    REP(i, N) {
        string t;
        cin >> t;
        if (t == "AB")
            S[i] = pll(0, 1);
        if (t == "BC")
            S[i] = pll(1, 2);
        if (t == "AC")
            S[i] = pll(0, 2);
    }

    REP(i, 3) {
        T[i] = std::min(T[i], 2LL);
    }

    stack<tuple<ll, ll, ll, ll>> s;
    vector<ll> v(N, -1);
    ll index = 0;
    while (index < N) {
        ll n = S[index].first, m = S[index].second;
        if (T[n] == T[m]) {
            if (T[n] == 0) {
                if (s.empty()) {
                    cout << "No" << endl;
                    return 0;
                }
                auto t = s.top();
                s.pop();
                index = get<0>(t);
                T[0] = get<1>(t);
                T[1] = get<2>(t);
                T[2] = get<3>(t);
                swap(T[S[index].first], T[S[index].second]);
                v[index] = S[index].second;
            }
            else {
                v[index] = n;
                T[n]++;
                T[m]--;
                s.push(make_tuple(index, T[0], T[1], T[2]));
            }
        }
        else {
            if (T[n] > T[m]) {
                T[n]--;
                T[m]++;
                v[index] = m;
            }
            else if (T[n] < T[m]) {
                T[n]++;
                T[m]--;
                v[index] = n;
            }
        }
        index++;
    }

    cout << "Yes" << endl;
    REP(i, N) {
        cout << C[v[i]] << endl;
    }

    return 0;
}