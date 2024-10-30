#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    bool flag = true;
    int n = s.length();

    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << n << endl;
    } else {
        cout << static_cast<int>(s[0]) << endl;
    }

    return 0;
}
