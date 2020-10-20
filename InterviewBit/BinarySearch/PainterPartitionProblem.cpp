int check(long long int mid,vector<int> C) // Returns no. of workers required to do the job in "mid" time.
{
    int count=1;
    long long int sum=0;
    for(int i=0;i<C.size();i++)
    {
        if(sum+C[i]>mid)  
        {
            sum=C[i];
            count++;
            if(C[i]>mid)  // If the dimension of a board is more than mid then it is impossible for a worker to complete the job in mid time so we will return INT_MAX;
            {
                return INT_MAX;
            }
        }
        else
        {
            sum+=C[i];
        }
    }
    return count;  // return no. of workers needed.
}
int Solution::paint(int A, int B, vector<int> &C) {
    long long int low=LONG_MAX;   // If a painter paints the smallest board then it will take the least time.
    long long int high=0;  // If a single painter paints all the board then it will take the highest time.
    for(int i=0;i<C.size();i++)
    {
        low=min(low,(long long)C[i]);  
        high+=C[i]; 
    }
    long long int ans;
    long long int mid;
    while(low<=high)    /* Binary Search */ 
    {
        mid=low+(high-low)/2;
        if(check(mid,C)<=A)  // If "mid" is the amount of time we have then check() function will return number of workers we need to complete the job in "mid" time.
        {
            ans=mid; 
            high=mid-1;  // We will check if we can do the job in time less than "mid".
        }
        else
        {
            low=mid+1; // if it is not possible to do the job in given time. We will increase our range.
        }
    }
    return (ans*B)%10000003;
}



