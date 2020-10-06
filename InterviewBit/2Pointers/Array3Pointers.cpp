int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {

    int ans = INT_MAX;
    int i = 0; 
    int j = 0; 
    int k = 0;
    int m = A.size();
    int n = B.size();
    int o = C.size();
    
    while(i<m && j<n && k<o){
        int a = A[i];
        int b = B[j];
        int c = C[k];
        int smallAns = max(a, max(b,c)) - min(a, min(b,c));
        ans = min(smallAns, ans);
        if(A[i] <= B[j] && A[i] <= C[k]){
            i++;
        } else if (B[j] <= C[k] && B[j] <= A[i]){
            j++;
        } else {
            k++;
        }
    }
    
    return ans;
}

