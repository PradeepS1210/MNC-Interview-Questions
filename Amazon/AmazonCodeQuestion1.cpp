/***************************************************************************************
Amazon Academy has launched a new course on Quantum Physics.  

The course has n chapters, each chapterhas memory[i] memory points, which a student gains or loses while reading that chapter. The course has a requirement: in order to study the ith chapter, the student must revisit all the previous chapters. A student gains memory[0] + memory[1] + ... + memory[i] memory points for reading the ith chapter. The total memory points is the sum of memory points gained while reading each chapter.  

Students can read the chapters in any order, and want to maximize their total memory points. Find the maximum total memory points a student can score ensuring that all the chapters are read. 

Example
memory = [3, 4, 5]
Considering all permutations of reading the chapters and their total memory points:
• [3, 4, 5] → Corresponding memory points will be [3, 7, 12], thus total memory points will be 3 + 7 + 12 = 21
• [3, 5, 4] → Corresponding memory points will be [3, 8, 12], thus total memory points will be 3 + 8 + 12 = 23
• [4, 3, 5] → Corresponding memory points will be [4, 7, 12], thus total memory points will be 4 + 7 + 12 = 23
• [4, 5, 3] → Corresponding memory points will be [4, 9, 12], thus total memory points will be 4 + 9 + 12 = 25
• [5, 3, 4] → Corresponding memory points will be [5, 8, 12], thus total memory points will be 5 + 8 + 12 = 25
• [5, 4, 3] → Corresponding memory points will be [5, 9, 12], thus total memory points will be 5 + 9 + 12 = 26

The maximum number of total memory points is 26. 
 
Function Description
Complete the function maximize TotalMemoryPoints in the editor below.
maximize TotalMemoryPoints has the following parameter: int memory[n]: the memory points associated with each chapter 
 
Returns
long_int: the maximum possible total memory points 


Constraints
• 1 ≤ n ≤ 10^5 
• -10^3 ≤ memory[i] ≤ 10^3 

Input Format For Custom Testing
Sample Case 0
Sample Input For Custom Testing
STDIN                FUNCTION
3           →        memory[] size,
n = 3
1           →        memory =[1,-2, 3]
-2
3

Sample Output
9
Explanation
The permutation with maximum total memory points is [3, 1, -2]. The corresponding memory points for each chapter are [3, 4, 2] resulting in the maximum sum of 3+4+2=9.

Sample Case 1
Sample Input For Custom Testing
STDIN                FUNCTION
4            →       memory[] size n = 4
2            →       memory = [2, 2, 2, 2]
2
2
2

Sample Output
20
Explanation
The total memory points will remain the same regardless of order. The corresponding memory points are [2, 4, 6, 8], resulting in the maximum total of 2 + 4+6+8=20.
****************************************************************************************/

long maximizeTotalMemoryPoints(vector<int> memory) {
    sort(memory.begin(), memory.end(), greater<int>());
    
    long totalMemoryPoints = 0;
    long cumulativeSum = 0;
    
    for (int points : memory) {
        cumulativeSum += points;
        totalMemoryPoints += cumulativeSum;
    }
    
    return totalMemoryPoints;
}
