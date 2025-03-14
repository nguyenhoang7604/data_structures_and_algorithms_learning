// you can use includes, for example:
#include <algorithm>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, int X, int Y) {
    // Implement your solution here

    if (A.empty()) return 0;

    std::sort(A.begin(), A.end(), std::greater<int>());

    uint64_t suffixSum = 0;
    uint16_t suffixIndex = A.size() - 1;
    uint64_t ans = X * A.size();
    uint64_t prefixSum = 0;

    for (uint16_t i = 0; i < A.size(); i++) {
        prefixSum += A[i];

        while (suffixIndex > i && suffixSum + A[suffixIndex] <= prefixSum) {
            suffixSum += A[suffixIndex];
            suffixIndex--;
        }

        uint64_t cost = (Y * (i + 1)) + (X * std::max(0, suffixIndex - i));
        ans = std::min(ans, cost);
    }

    return ans;
}
