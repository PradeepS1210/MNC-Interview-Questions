/*
Example 1:
-----------
Input
3
3 1 1000
31 0 10
100 49 7

Output
No
No
No

Explanation
In the first case, there is no possible value of p.
In the second case, there is no possible value of p.
In the third case, there is no possible value of p.

Example 2:
-----------
Input
4
5 2 1
5 2 2
10 0 100
11 7 100

Output
No
Yes
Yes
Yes

Explanation
In the first example, the only possible way to pull the handle is with force 1. That is not enough to make the arrow point at sector 0, at least force 2 is required to do so.
In the second example, Vesper can pull the handle with the force 2 so the wheel will spin 2+1=3 sectors ahead and the arrow will point at sector 0.
In the third example, Vesper can pull the handle with the force 4 so the wheel will spin 4+3+2+1=10sectors and will point at sector 00 again.
In the fourth example, Vesper can pull the handle with the force 55 so the wheel will spin 5+4+3+2+1=15 sectors. That will make the wheel make one full turn plus 44 more sectors.
*/

#include <iostream>
#include <vector>
using namespace std;

bool canWin(int n, int x, int p) {
    auto sumNatural = [](int f) {
        return f * (f + 1) / 2;
    };

    for (int f = 1; f <= p; ++f) {
        int distance = sumNatural(f);
        int endingSector = (x + distance) % n;
        if (endingSector == 0) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;

    vector<string> results;
    for (int i = 0; i < t; ++i) {
        int n, x, p;
        cin >> n >> x >> p;

        if (canWin(n, x, p)) {
            results.push_back("Yes");
        } else {
            results.push_back("No");
        }
    }

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}
