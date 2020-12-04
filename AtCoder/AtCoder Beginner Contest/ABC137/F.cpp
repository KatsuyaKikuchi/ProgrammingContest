#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[3005];

struct Matrix {
    Matrix(int r, int c, long long int id = 0)
            : mR(r), mC(c) {
        init(id);
    }

    void init(long long int id) {
        mMat.resize(mR, vector<long long int>(mC, id));
    }

    Matrix operator+(const Matrix &obj) {
        assert(this->mR == obj.mR);
        assert(this->mC == obj.mC);
        Matrix ret(this->mR, this->mC);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                ret.mMat[r][c] = this->mMat[r][c] + obj.mMat[r][c];
            }
        }
        return ret;
    }

    Matrix operator-(const Matrix &obj) {
        assert(this->mR == obj.mR);
        assert(this->mC == obj.mC);
        Matrix ret(this->mR, this->mC);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                ret.mMat[r][c] = this->mMat[r][c] - obj.mMat[r][c];
            }
        }
        return ret;
    }

    Matrix operator-() {
        Matrix ret(this->mR, this->mC);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                ret.mMat[r][c] = -this->mMat[r][c];
            }
        }
        return ret;
    }

    Matrix operator*(const Matrix &obj) {
        assert(this->mC == obj.mR);
        Matrix ret(this->mR, obj.mC);
        for (int r = 0; r < ret.mR; ++r) {
            for (int c = 0; c < ret.mC; ++c) {
                for (int i = 0; i < this->mC; ++i) {
                    ret.mMat[r][c] += this->mMat[r][i] * obj.mMat[i][c];
                }
            }
        }
        return ret;
    }

    Matrix &operator=(const Matrix &obj) {
        this->mR = obj.mR;
        this->mC = obj.mC;
        init(0);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                this->mMat[r][c] = obj.mMat[r][c];
            }
        }
        return *this;
    }

    vector<long long int> &operator[](int r) {
        assert(r < mR);
        return mMat[r];
    }

    int mR;
    int mC;
    vector<vector<long long int>> mMat;
};

ll modpow(ll n, ll p, ll mod) {
    ll ret = 1;
    ll m = n;
    while (p > 0) {
        if (p & 1)
            ret = (ret * m) % mod;
        p >>= 1;
        m = (m * m) % mod;
    }
    return ret;
}

ll Q[3005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll P;
    cin >> P;
    REP(i, P) {
        cin >> A[i];
    }

    Matrix mat(P, P + 1);
    REP(i, P) {
        REP(j, P) {
            mat[i][j] = modpow(i, j, P);
        }
        mat[i][P] = A[i];
    }

    REP(i, P) {
        Q[i] = modpow(i, P - 2, P);
    }

    REP(r, P) {
        ll p = mat[r][r];
        FOR(i, P + 1, r) {
            mat[r][i] = (mat[r][i] * Q[p]) % P;
        }
        FOR(c, P, r + 1) {
            ll q = mat[c][r];
            FOR(j, P + 1, r) {
                ll m = (mat[r][j] * q) % P;
                mat[c][j] = (P + mat[c][j] - m) % P;
            }
        }
    }

    for (ll i = P - 1; i >= 0; --i) {
        ll p = mat[i][i];
        for (ll j = i - 1; j >= 0; --j) {
            ll q = mat[j][i];
            REP(c, P + 1) {
                mat[j][c] = (P + mat[j][c] - (mat[i][c] * q) % P) % P;
            }
        }
    }

    REP(i, P) {
        cout << mat[i][P] << " ";
    }
    cout << endl;

    return 0;
}