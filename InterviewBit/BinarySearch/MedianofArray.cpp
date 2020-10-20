double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

     if(A.size()>B.size())
     return findMedianSortedArrays(B,A);
     int x = A.size();
     int y = B.size();
     int l =0,h=x;
     while(l<=h)
     {
         int partitionX = l+(h-l)/2;
         int partitionY = (x+y+1)/2-partitionX;
         int maxLeftX = (partitionX==0)?INT_MIN:A[partitionX-1];
         int maxLeftY = (partitionY==0)?INT_MIN:B[partitionY-1];
         int minRightX = (partitionX==x)?INT_MAX:A[partitionX];
         int minRightY = (partitionY==y)?INT_MAX:B[partitionY];
         if(maxLeftX<=minRightY && maxLeftY<=minRightX)
         {
             if((x+y)%2==0)
                 return (double)(max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2;
             else
              return (double)(max(maxLeftX,maxLeftY));
             
         }
         else if(maxLeftX>minRightY)
         h = partitionX-1;
         else
         l = partitionX+1;
         
         
     }
        
}

