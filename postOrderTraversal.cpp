
// leetcode problem no # 145. Binary Tree Postorder Traversal 

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> v;
    vector<int> postorderTraversal(TreeNode* root) {
        if (root != NULL) {
            postorderTraversal(root->left);
            postorderTraversal(root->right);
            v.push_back(root->val);
        }
        return v;
    }
};

int main() {
    // Create a sample binary tree
    //         1
    //        / \
    //       2   3
    //      / \
    //     4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<int> result = solution.postorderTraversal(root);

    // Print the result
    cout << "Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}



