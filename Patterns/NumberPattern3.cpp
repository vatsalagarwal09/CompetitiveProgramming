void printPattern(int n){

    int j = 0;
    int count = 0;
    int i = 0;
    for(i = 1; i<=n; i++){
        count = 0;
        for(j = n; j>= n-i+1; j--){
            cout << j << " ";
            count++;
            if(j-1 < n-i+1 && count < n){
                j++;
            }
            
        }
        
        int l = j+1;
        int temp_count = 0;        
        for(int k = 2; count<2*n-1; k++){
            if(temp_count < j){
                cout << l << " ";
                temp_count++;
            } else {
                cout << k << " ";
            }
            count++;
            
        }
        cout << endl;
    }
   
    
    for(i; i<=2*n-1; i++){
        int count_check  = 0;
        for(j = n; count_check<n; j--){
            if(j <= i-n){
                j = j+1;    
            } 
            cout << j << " ";
            count_check++;
        }
        
        int l = j+1;
        int count_check2 = 0;
        for(int k = 2; count_check<2*n-1; k++){
            if(count_check2 < i-n){
                cout << l << " ";
            } else {
                cout << k << " ";
            }
            count_check++;
            count_check2++;
        }
        cout << endl;
    }

}

