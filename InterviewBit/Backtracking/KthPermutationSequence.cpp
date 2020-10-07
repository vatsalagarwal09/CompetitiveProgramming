int fact(int n) {
    if(n>12)
        return INT_MAX;
    if(n==0)
        return 1;
    return n*fact(n-1);
}

string answer(int B, vector<int> &v) {
    int A=v.size();
    if(A==0)
        return "";
    int f=fact(A-1);
    int pos=B/f;
    B%=f;
    string c=to_string(v[pos]);
    v.erase(v.begin()+pos);
    return c+answer(B,v);
}

string Solution::getPermutation(int A, int B) {
    vector<int> v;
    for(int i=1;i<=A;i++)
        v.push_back(i);
    return answer(B-1,v);
}

