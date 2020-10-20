int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
            int sumGas = 0;
            int sumCost = 0;
            int start = 0;
            int tank = 0;
            for (int i = 0; i < A.size(); i++) {
                sumGas += A[i];
                sumCost += B[i];
                tank += A[i] - B[i];
                if (tank < 0) {
                    start = i + 1;
                    tank = 0;
                }
            }
            if (sumGas < sumCost) {
                return -1;
            } else {
                return start;
            }
}

