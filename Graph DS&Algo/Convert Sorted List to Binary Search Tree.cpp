TreeNode* buildBST(vector<int> &arr, int s, int e)
{
    //base-case
    if(s==e) return NULL;
    int mid = (s+e)/2;
    TreeNode* root = new TreeNode(arr[mid]);
    root->left = buildBST(arr,s,mid);
    root->right = buildBST(arr,mid+1,e);
    return root;
}


TreeNode* Solution::sortedListToBST(ListNode* A)
{
    if(A==NULL) return NULL;
    vector<int> arr;
    ListNode* temp = A;
    while(temp!=NULL)
    {
        arr.emplace_back(temp->val);
        temp = temp->next;
    }
    return buildBST(arr,0,arr.size());
}
