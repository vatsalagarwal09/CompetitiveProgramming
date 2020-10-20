int expo(int x,int n,int d)
{
    long long int res = 1;
    long long int y = x;
    while(n>0)
    {
        if(n&1)
            res = (res*y)%d;
            
        y = ((y)%d*(y)%d)%d;
        n = n>>1;
    }
    if(res<0)
        res += d;
    return (int)res%d;
}
int Solution::pow(int x, int n, int d) 
{
    return expo(x,n,d);
}

