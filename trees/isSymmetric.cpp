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

bool isMirror(TreeNode *left, TreeNode *right)
{
    if (left == nullptr && right == nullptr)
        return true;
    if (left == nullptr || right == nullptr)
        return false;
    if (left->val != right->val)
        return false;

    bool leftMirror = isMirror(left->left, right->right);
    bool rightMirror = isMirror(left->right, right->left);

    return leftMirror && rightMirror;
}

bool isSymmetric(TreeNode *root)
{
    if (root == nullptr)
        return true;
    return isMirror(root->left, root->right);
}
int main()
{
    vector<int> nums = {1, 2, 3, -1, -1, 4, -1, -1, 2, 4, -1, -1, 3, -1, -1};
    TreeNode *root = buildTree(nums);
    cout << isSymmetric(root) << endl;
}