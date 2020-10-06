void Solution::merge(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int m = A.size();
    int n = B.size();
    
    int i = 0;
    int j = 0;
    
    while(i < m && j < n){
        if(A[i] <= B[j]){
            C.push_back(A[i]);
            i++;
        } else {
            C.push_back(B[j]);
            j++;
        }
    }
    
    if(i==m){
        while(j<n){
            C.push_back(B[j]);
            j++;
        }
    }
    
    if(j==n){
        while(i<m){
            C.push_back(A[i]);
            i++;
        }
    }
    
    
    A = C;
}

