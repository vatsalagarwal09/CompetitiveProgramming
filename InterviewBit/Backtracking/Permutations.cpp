void find(vector<int> A, vector<int> b, vector<int> c, int i, int n){
    if(i==n){
        int k;
        cout<<"[";
        for(k=0;k<n;k++){
            cout<<c[k]<<" ";
        }
        cout<<"] ";
        return;
    }
    for(int j=0;j<n;j++){
        if(b[j]>0){
            c[i]=A[j];
            b[j]--;
            find(A,b,c,i+1,n);
            b[j]++;
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    int n=A.size();
    vector<vector<int>> p;
    sort(A.begin(),A.end());
    vector<int> b(n,1);
    vector<int> c(n);
    find(A,b,c,0,n);
    
    return p;
}
