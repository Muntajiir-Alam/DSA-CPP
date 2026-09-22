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

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
        return root;
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}
int main()
{
    vector<int> nums = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    TreeNode *root = buildTree(nums);
    invertTree(root);
    cout << root->left->val << endl;
}