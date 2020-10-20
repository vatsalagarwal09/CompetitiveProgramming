#define MOD 10000003
int Solution::seats(string A) {
    auto n = A.length();
    
    // Median approach
    vector<int> pos;
    for (auto i = 0; i<n; ++i)
        if (A[i] == 'x')
            pos.emplace_back(i);
    
    auto psize = pos.size();
    
    if (psize == 0)
        return 0;
    int mid = psize/2;
    int median = psize & 1 ? pos[mid] : (pos[mid-1] + pos[mid])/2;
    int empty = A[median] == 'x' ? median - 1 : median;
    int hops = 0; 
    
    for (auto s = median-1; s>=0; --s)
        if (A[s] == 'x')
        {
            hops += empty - s;
            hops %= MOD;
            --empty;
        }
            
    empty = median + 1;
    for (auto e = median+1; e<n; ++e)
        if (A[e] == 'x')
        {
            hops += e - empty;
            hops %= MOD;
            ++empty;
        }
    
    return hops % MOD;
}

