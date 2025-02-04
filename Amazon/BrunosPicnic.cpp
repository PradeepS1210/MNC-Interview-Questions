#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }

        int nan = 0;
        int uppu = n + 1;

        while (nan < uppu - 1) {
            int k = (nan + uppu) / 2;
            int c = 0;
            for (int i = 0; i < n; i++) {
                if (c < k && a[i] >= k - c - 1 && b[i] >= c) {
                    c += 1;
                }
            }

            if (c >= k) {
                nan = k;
            } else {
                uppu = k;
            }
        }

        cout << nan << endl;
    }

    return 0;
}
