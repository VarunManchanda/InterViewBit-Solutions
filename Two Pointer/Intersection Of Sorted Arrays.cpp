vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B)
{
    int p = 0;
    int q = 0;
    vector<int> ans;
    while(p<A.size() and q<B.size())
    {
        if(A[p]<B[q]) p+=1;
        else if(B[q]<A[p]) q+=1;
        else
        {
            ans.emplace_back(A[p]);
            p+=1; q+=1;
        }
        
    }
    return ans;
}
