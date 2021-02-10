#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 1e6 + 5;

struct Data {
    pll range;
    ll index;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<Data> A(N);
    REP(i, N) {
        cin >> A[i].range.first >> A[i].range.second;
        A[i].index = i;
    }
    sort(A.begin(), A.end(), [](Data a, Data b) { return a.range.first < b.range.first; });
    vector<ll> X(MAX, 0);
    ll idx = N - 1;
    for (ll i = MAX - 2; i >= 0; --i) {
        X[i] = X[i + 1];
        while (idx >= 0 && A[idx].range.first == i) {
            pll r = A[idx--].range;
            X[i] = std::max(X[i], X[r.second] + 1);
        }
    }

    cout << X[0] << endl;
    sort(A.begin(), A.end(), [](Data a, Data b) { return a.range.second < b.range.second; });
    priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q([](Data a, Data b) { return a.index > b.index; });
    vector<ll> ans;
    ll last = -1;
    idx = 0;
    ll cnt = X[0] - 1;
    REP(i, MAX) {
        if (X[i] < cnt || i == MAX - 1) {
            while (!q.empty() && q.top().range.first < last) {
                q.pop();
            }
            auto t = q.top();
            q.pop();
            ans.push_back(t.index);
            last = t.range.second;
            cnt--;
        }
        while (idx < N && A[idx].range.second <= i) {
            q.push(A[idx++]);
        }
    }

    REP(i, ans.size()) {
        cout << ans[i] + 1;
        if (i < ans.size() - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}