#include <iostream>
using namespace std;

const int N = 10000005;
int spf[N];

void build() {
    for(int i = 1; i < N; i++) spf[i] = i;

    for(int i = 2; i * i < N; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j < N; j += i) {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

int countFactors(int n) {
    int cnt = 0;

    while(n > 1) {
        if(n >= N) {
            for(int i = 2; i * i <= n; i++) {
                if(n % i == 0) {
                    cnt++;
                    while(n % i == 0) n /= i;
                }
            }
            if(n > 1) cnt++;
            break;
        }

        int p = spf[n];
        cnt++;

        while(n % p == 0) {
            n /= p;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    build();

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        if(n == 1) {
            cout << 0 << '\n';
            continue;
        }

        int k = countFactors(n);

        long long ans = (1LL << k);

        cout << ans << '\n';
    }

    return 0;
}