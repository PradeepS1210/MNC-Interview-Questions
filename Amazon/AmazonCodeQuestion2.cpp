// Compiled successfully: 8/15 test cases passed

/***********************************************************************************
AWS provides many services for outlier detection. A prototype small service to detect an outlier in an array of integers is under development. 
 
Given an array of n integers, there are (n - 2) normal numbers and the sum of the (n - 2) numbers originally in this array. If a number is neither in the original numbers nor is it their sum, it is an outlier. Discover the potential outliers and return the greatest of them.
Note: It is guaranteed that the answer exists.  

Example
n = 6
arr = [4, 1, 3, 16, 2, 10] 
 
There are two potential outliers:
• Remove 16 - ar * r' = [4, 1, 3, 2, 10] The sum of [4, 1, 3, 2] is 10, so 16 is a potential outlier. (It is not an original number or their sum.) 
• Remove 4 - ar * r' = [1, 3, 16, 2, 10] The sum of [1, 3, 2, 10] is 16, so 4 is a potential outlier.

The outlier is the greater of the two potential outliers, so 16 is the outlier. 
 
Function Description
Complete the function getOutlierValue in the editor below.
getOutlierValue has the following parameter(s):
int arr[n]: value of (n-2) numbers, their sum, and outlier value 
 
Returns
int: the outlier value 
 
Constraints
• 3 <= n <= 10 ^ 5
• 1 <= arr[i] <= 10 ^ 9 

Input Format For Custom Testing
The first line contains an integer, n, the number of elements in arr.
Each line i of the n subsequent lines (where 0≤ i<n) contains an integer, arr[i].

Sample Case 0
Sample Input For Custom Testing
STDIN               FUNCTION
6           →       arr[] size n = 6 
4           →       arr = [4, 1, 2, 1, 10, 3] 
1
2
1
10
3 

Sample Output
1
Explanation
The original list is [1, 2, 3, 4] with a sum of 10. 
 
Sample Case 1
Sample Input For Custom Testing
STDIN                FUNCTION
4             →      arr[] size n = 4
2             →      arr [2, 2, 4, 2]
2
4
2
Sample Output
2
Explanation
The original list is [2, 2] with a sum of 4
************************************************************************************/

int getOutlierValue(std::vector<int> arr) {
    long totalSum = std::accumulate(arr.begin(), arr.end(), 0L);
    std::unordered_map<int, int> freq;
    
    for (int num : arr) {
        freq[num]++;
    }
    
    int outlier = INT_MIN;
    
    for (int num : arr) {
        long normalSum = totalSum - num;
        
        if (freq[normalSum] > 0 && (normalSum != num || freq[num] > 1)) {
            continue;
        }
        
        outlier = std::max(outlier, num);
    }
    
    return outlier;
}
