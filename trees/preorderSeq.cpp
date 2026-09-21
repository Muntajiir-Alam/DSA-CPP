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

// ────────────────── Traversals ───────────────────────

void preorder(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(TreeNode *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main()
{
    vector<int> nums = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    TreeNode *root = buildTree(nums);
    cout << "Tree built from preorder sequence!" << endl;
    // preorder(root);
    // inorder(root);
    postorder(root);
}