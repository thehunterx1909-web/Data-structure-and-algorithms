#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
private:
    int dfs(TreeNode *root, int& res){
        if(root == nullptr) return 0;

        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        res = max(res, l + r);

        return max(l, r) + 1;
    }
};

int main(){
    
}