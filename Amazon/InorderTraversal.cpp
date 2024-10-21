// Problem Description: https://www.naukri.com/code360/problems/inorder-traversal_16634186

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
/*
    Time Complexity: O( N )
    Space Complexity: O( N )
*/

void inOrderHelper(TreeNode *node, vector<int> &answer)
{
    if (node == NULL)
    {
        return;
    }

    inOrderHelper(node->left, answer);

    answer.push_back(node->data);

    inOrderHelper(node->right, answer);
}

vector<int> getInOrderTraversal(TreeNode *root)
{
    vector<int> answer;

    inOrderHelper(root, answer);

    return answer;
}
