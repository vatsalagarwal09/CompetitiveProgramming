inline bool isPalindrome( string A ){
    string rev = A;
    reverse( rev.begin(), rev.end() );
    return (rev == A);
}

void GeneratePartitions( vector<string> set, string A, vector<vector<string>> &result ){
    if( A.empty() ){
        result.push_back( set );
        return;
    }
    
    for( int l=1; l<=A.length(); ++l ){
        string first_part = A.substr( 0, l );
        string second_part = A.substr( l );
        
        if( isPalindrome( first_part ) ){
            vector<string> s = set;
            s.push_back( first_part );
            GeneratePartitions( s, second_part, result );
        }
    }
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string>> result;
    vector<string> empty_set;
    GeneratePartitions( empty_set, A, result );
    sort( result.begin(), result.end() );
    return result;
}


