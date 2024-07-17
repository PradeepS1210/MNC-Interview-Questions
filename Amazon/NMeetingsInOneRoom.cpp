/*
Example:
=========
Input:
Enter the number of meetings: 6
Enter the start times of the meetings: 1 3 0 5 8 5
Enter the end times of the meetings: 2 4 6 7 9 9

Output: The maximum number of meetings that can be held is: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
*/

#include <bits/stdc++.h>
using namespace std;

struct Meeting
{
    int start;
    int end;
};

bool comparator(Meeting m1, Meeting m2)
{
    return m1.end < m2.end;
}

class Solution
{
public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<Meeting> meetings(n);
        for (int i = 0; i < n; ++i)
        {
            meetings[i].start = start[i];
            meetings[i].end = end[i];
        }

        sort(meetings.begin(), meetings.end(), comparator);

        int count = 1;
        int last_end_time = meetings[0].end;

        for (int i = 1; i < n; ++i)
        {
            if (meetings[i].start > last_end_time)
            {
                ++count;
                last_end_time = meetings[i].end;
            }
        }

        return count;
    }
};

int main()
{
    int n;
    cout << "Enter the number of meetings: ";
    cin >> n;

    int start[n], end[n];
    cout << "Enter the start times of the meetings: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> start[i];
    }

    cout << "Enter the end times of the meetings: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> end[i];
    }

    Solution obj;
    int max_meetings = obj.maxMeetings(start, end, n);
    cout << "The maximum number of meetings that can be held is: " << max_meetings << endl;

    return 0;
}
