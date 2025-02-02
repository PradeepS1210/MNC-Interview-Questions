/*
Examples:
----------
Input: root[] = [1, 2, 3]
Output: [[1], [2, 3]]

Input: root[] = [10, 20, 30, 40, 50]
Output: [[10], [20, 30], [40, 50]]

Input: root[] = [1, 3, 2, N, N, N, 4, 6, 5]
Output: [[1], [3, 2], [4], [6, 5]]
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelSize; i++) {
                Node* currentNode = q.front();
                q.pop();
                currentLevel.push_back(currentNode->data);
                
                if (currentNode->left != nullptr) {
                    q.push(currentNode->left);
                }
                
                if (currentNode->right != nullptr) {
                    q.push(currentNode->right);
                }
            }
            result.push_back(currentLevel);
        }
        
        return result;
    }
};

Node* insertLevelOrder(vector<int>& arr, int i) {
    if (i >= arr.size() || arr[i] == -1) {
        return nullptr;
    }
    
    Node* root = new Node(arr[i]);
    root->left = insertLevelOrder(arr, 2 * i + 1);
    root->right = insertLevelOrder(arr, 2 * i + 2);
    
    return root;
}

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    
    vector<int> nodes(n);
    cout << "Enter node values (use -1 for null nodes): ";
    for (int i = 0; i < n; i++) {
        cin >> nodes[i];
    }
    
    Node* root = insertLevelOrder(nodes, 0);
    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);
    
    cout << "Level order traversal:" << endl;
    for (const auto& level : result) {
        for (int value : level) {
            cout << value << " ";
        }
        cout << endl;
    }
    
    return 0;
}
