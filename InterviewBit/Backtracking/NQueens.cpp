void solveNQueensHelper(int A, vector<bool> check, vector<vector<string>> &ans, int current, vector<string> smallAns){
    if(current == A){
        ans.push_back(smallAns);
        return;
    } 
    
    for(int i = 0; i<A; i++){
        if(check[i] == true){
            continue;
        }
        
        int k = current-1;
        int m = i-1;
        bool smallCheck = false;
        while(m>=0 && k>=0){
            if(smallAns[k][m] == 'Q'){
                smallCheck = true;
            }
            k--;
            m--;
        }
        
        if(smallCheck == true){
            continue;
        }
        
        k = current-1;
        m = i+1;
        while(m<A && k>=0){
            if(smallAns[k][m] == 'Q'){
                smallCheck = true;
            }
            k--;
            m++;            
        }
        
        if(smallCheck == true){
            continue;
        }        
        
        check[i] = true;
        int j = 0;
        string newRow;
        while(j<i){
            newRow += '.';
            j++;
        }
        
        newRow += 'Q';
        j++;
        
        while(j<A){
          newRow += '.';
          j++;
        }
        vector<string> currentAns = smallAns;
        currentAns.push_back(newRow);
        solveNQueensHelper(A, check, ans, current+1, currentAns);
        check[i] = false;
    }    
    
    return;
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<bool> check;
    for(int i = 0; i<A; i++){
        check.push_back(false);
    }
    
    vector<vector<string>> ans;
    vector<string> smallAns;
    int current = 0;
    solveNQueensHelper(A, check, ans, current, smallAns);
    
    return ans;
}

