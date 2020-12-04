#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

template<typename T>
struct Matrix {
    Matrix(int r, int c, T id = 0)
            : mR(r), mC(c) {
        init(id);
    }

    void init(T id) {
        mMat.resize(mR, vector<T>(mC, id));
    }

    void print() {
        for (int r = 0; r < mR; ++r) {
            for (int c = 0; c < mC; ++c) {
                cout << mMat[r][c] << " ";
            }
            cout << endl;
        }
    }

    Matrix<T> operator+(const Matrix<T> &obj) {
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

    Matrix<T> operator-(const Matrix<T> &obj) {
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

    Matrix<T> operator-() {
        Matrix ret(this->mR, this->mC);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                ret.mMat[r][c] = -this->mMat[r][c];
            }
        }
        return ret;
    }

    Matrix<T> operator*(const Matrix<T> &obj) {
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

    Matrix<T> &operator=(const Matrix<T> &obj) {
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

    vector<T> &operator[](int r) {
        assert(r < mR);
        return mMat[r];
    }

    int mR;
    int mC;
    vector<vector<T>> mMat;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    long double P;
    ll K;
    cin >> P >> K;
    Matrix<long double> M(2, 2);
    M[0][0] = M[1][1] = 1.0 - P;
    M[0][1] = M[1][0] = P;

    Matrix<long double> T(2, 2);
    T[1][1] = T[0][0] = 1.0;
    while (K > 0) {
        if ((K & 1) == 1)
            T = M * T;
        M = M * M;
        K >>= 1LL;
    }
    // T.print();
    cout << OF64 << (T[0][1] + T[1][0]) * 0.5 << endl;
    return 0;
}
