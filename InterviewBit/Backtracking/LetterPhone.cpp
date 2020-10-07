std::string mapping[] = {"0", "1", "abc", "def", 
                         "ghi", "jkl", "mno", "pqrs", 
                         "tuv", "wxyz"};

void makeCombinations(const std::string& A, const int pos, const std::string& current, 
                      std::vector<std::string>& result) {
    if (pos >= A.size()) return;
    const std::string& letters = mapping[A[pos] - '0'];
    
    //std::cout << letters << std::endl;
    
    for (const char ch: letters) {
        std::string next = current;
        next.push_back(ch);
        if (next.size() == A.size()) {
            result.push_back(next);
        } else {
            makeCombinations(A, pos+1, next, result);
        }
        
    }
}

std::vector<std::string> Solution::letterCombinations(std::string A) {
  
    std::vector<std::string> result;
    makeCombinations(A, 0, "", result);
    //std::cout << result.size() << std::endl;
    return result;
}

