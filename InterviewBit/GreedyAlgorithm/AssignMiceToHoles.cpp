int Solution::mice(vector<int> &A, vector<int> &B) {
    int n=A.size();
    int t = 0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i=0;i<n;i++){
        t=max(t,abs(A[i]-B[i]));
    }
    return t;
}
