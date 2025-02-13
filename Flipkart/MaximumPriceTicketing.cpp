/*
Example 1:
------------
Input:
10 10
9 3 9 6 6 8 6 2 6 3
9 5 4 6 3 9 3 3 5 2

Output
9
3
3
6
2
9
-1
-1
-1
-1

Example 2:
------------
Input:
10 10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1

Output
1
1
1
1
1
1
1
1
1
1
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> assignTickets(vector<int>& ticketPrices, vector<int>& customerBudgets) {
    multiset<int> tickets(ticketPrices.begin(), ticketPrices.end());
    vector<int> results;

    for (int budget : customerBudgets) {
        auto it = tickets.upper_bound(budget);
        if (it == tickets.begin()) {
            results.push_back(-1);
        } else {
            --it;
            results.push_back(*it);
            tickets.erase(it);
        }
    }

    return results;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> ticketPrices(N);
    vector<int> customerBudgets(M);

    for (int i = 0; i < N; ++i) {
        cin >> ticketPrices[i];
    }

    for (int i = 0; i < M; ++i) {
        cin >> customerBudgets[i];
    }

    vector<int> results = assignTickets(ticketPrices, customerBudgets);

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
