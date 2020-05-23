/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A)
{
    if(A==NULL) return {{}};
    vector<vector<int> > globalAns;
    vector<int> a;
    a.emplace_back(A->val);
    globalAns.emplace_back(a);
    queue<TreeNode*> q1, q2;
    vector<int> arr;
    q1.push(A);
    while(!q1.empty() || !q2.empty())
    {
        while(!q1.empty())
        {
            auto node = q1.front(); q1.pop();
            if(node->left!=NULL) 
            {
                q2.push(node->left);
                arr.emplace_back(node->left->val);
            }
            if(node->right!=NULL)
            {
                q2.push(node->right);
                arr.emplace_back(node->right->val);
            }
        }
        if(arr.size()!=0)
        {
            globalAns.emplace_back(arr);
            arr.clear();
        }
        while(!q2.empty())
        {
            auto node = q2.front(); q2.pop();
            if(node->left!=NULL) 
            {
                q1.push(node->left);
                arr.emplace_back(node->left->val);
            }
            if(node->right!=NULL)
            {
                q1.push(node->right);
                arr.emplace_back(node->right->val);
            }
        }
        if(arr.size()!=0)
        {
            globalAns.emplace_back(arr);
            arr.clear();
        }
    }
    return globalAns;
}
