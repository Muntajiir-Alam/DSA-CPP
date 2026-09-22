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

bool isSameTree(TreeNode* p, TreeNode* q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL || q == NULL)
        return false;
    if (p->val != q->val)
        return false;
    
    bool isLeft = isSameTree(p->left, q->left);
    bool isRight = isSameTree(p->right, q->right);
    return (isLeft && isRight);
}
int main()
{
    vector<int> nums = {1, 2, -1, -1, 3, -1, -1};
    TreeNode *p = buildTree(nums);
    idx = -1;
    TreeNode *q = buildTree(nums);
    cout << isSameTree(p, q) << endl;
}