//Proof:- In order to minimize the difference abs(max-min) => abs(a-b) => a-b < INT_MAX only when a decrease and b increases, So we use
//three pointers point from last and calculate the difference now in order to minimize the value we start to decrease maximum value.
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int p = A.size()-1;
    int q = B.size()-1;
    int s = C.size()-1;
    int ans = 1e9;
    while(p>=0 and q>=0 and s>=0)
    {
        int cal = abs(max(A[p],max(B[q],C[s])) - min(A[p],min(B[q],C[s])));
        ans = min(ans,cal);
        if(max(A[p],max(B[q],C[s]))==A[p]) p-=1;
        else if(max(A[p],max(B[q],C[s]))==B[q]) q-=1;
        else s-=1;
    }
    return ans;
}
