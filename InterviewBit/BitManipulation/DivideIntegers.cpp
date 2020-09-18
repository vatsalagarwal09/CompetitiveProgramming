int Solution::divide(int A, int B) {
    if(A==0){
        return 0;
    }
    
    if(B==1){
        return A;
    }
    
    if(B==-1){
       if(A == INT_MIN){
            return INT_MAX;
        }        
        return -1*A;
    }
    
    bool check = false;
    if((A<0 && B<0) || (A>0 && B>0)){
        check = false;
    } else {
        check = true;
    }
    
    if(B<0){
        B *=-1;
    }

    int count = 0;
    int i = 0; 
    while(i<A){
        i += B;
        count++;
        if(i<A &&i > INT_MAX-B){
            count++;
            break;
        }        
    }
    
    if(check == true){
        if(count == INT_MAX){
            return INT_MIN;
        }
        return -1*(count-1);
    } else {
        return count-1;    
    }
    
}

