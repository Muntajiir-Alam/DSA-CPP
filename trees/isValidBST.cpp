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

bool isValidBSTHelper(TreeNode *root, long long minVal, long long maxVal)
{
    if (root == NULL)
        return true;
    if (root->val <= minVal || root->val >= maxVal)
        return false;
    return isValidBSTHelper(root->left, minVal, root->val) &&
           isValidBSTHelper(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode *root)
{
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}
int main()
{
    vector<int> nums = {2, 1, -1, -1, 3, -1, -1};
    TreeNode *root = buildTree(nums);
    cout << isValidBST(root) << endl;
}