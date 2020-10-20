int Solution::maxp3(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    int a = A[n-1] * A[n-2] * A[n-3];
    int b = A[0] * A[1] * A[n-1];
    return max(a,b);
}

