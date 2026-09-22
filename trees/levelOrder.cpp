#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};
static int idx = -1;

TreeNode *buildTree(vector<int> &preorder)
{
    idx++;
    if (preorder[idx] == -1)
        return NULL;

    TreeNode *root = new TreeNode(preorder[idx]);

    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void traverse(TreeNode *root, int level, vector<vector<int>> &ans)
{
    if (root == nullptr)
        return;

    // Create a new level if needed
    if (level == ans.size())
        ans.push_back({});

    // Add current node to its level
    ans[level].push_back(root->val);

    // Go to next level
    traverse(root->left, level + 1, ans);
    traverse(root->right, level + 1, ans);
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;

    traverse(root, 0, ans);

    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    TreeNode *root = buildTree(nums);
    vector<vector<int>> result = levelOrder(root);

    for (const auto &level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << "\n";
    }
}