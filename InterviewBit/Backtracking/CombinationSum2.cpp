void combinationSumHelper(vector<int> &A, int B, vector<int> smallAns, int sum, vector<vector<int>> &ans, int i){
    if(sum == B){
        ans.push_back(smallAns);
        int last = smallAns[smallAns.size()-1];
        smallAns.pop_back();
        sum -= last;
    }
    
    if(sum > B){
        int last = smallAns[smallAns.size()-1];
        smallAns.pop_back();
        sum -= last;
    }           

    if(A.size() == i){
        return;
    }
    
    combinationSumHelper(A, B, smallAns, sum, ans, i+1);
    smallAns.push_back(A[i]);
    sum += A[i];
    combinationSumHelper(A, B, smallAns, sum, ans, i+1);
}


vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    vector<vector<int>> ans;
    
    for(int i = 0; i<A.size(); i++){
        vector<int> smallAns;
        int sum = 0;
        smallAns.push_back(A[i]);
        sum += A[i];
        
        combinationSumHelper(A, B, smallAns, sum, ans, i+1);
    }

    for(int i = 0; i<ans.size(); i++){
        sort(ans[i].begin(), ans[i].end());
    }
    sort(ans.begin(), ans.end());
    vector<vector<int>>::iterator ip;
    ip = std::unique(ans.begin(), ans.end()); 
    ans.resize(std::distance(ans.begin(), ip)); 
    // vector<vector<int>>::iterator ip1;
    // ip1 = std::unique(ans.begin(), ans.end()); 
    // ans.resize(std::distance(ans.begin(), ip1));     
    return ans;
    
}

