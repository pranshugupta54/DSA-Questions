/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        // int count = 1
        vector<long long> sum;
        sum.push_back(root -> val);
        while(!q.empty()){
            long long tempsum =0;
            while(q.front() != NULL){
                if(q.front() -> left){
                    q.push(q.front()->left);
                    tempsum += q.front() -> left -> val;
                }
                if(q.front() -> right){
                    q.push(q.front()->right);
                    tempsum += q.front() -> right -> val;
                }
            q.pop();
            }
            q.pop();
            if (!q.empty()) {
                sum.push_back(tempsum);
                q.push(NULL);
            }
        }

// return -1;
        sort(sum.begin(), sum.end());
        if(sum.size() < k){
            return -1;
        }
        return sum[sum.size()-k];
    }
};