#include <string>

int solution(string &S) {
    // Implement your solution here
    uint16_t patchesCount = 0;
    uint16_t roadSegment = S.length();

    for (auto i = 0; i < roadSegment; i++) {
        if (S[i] == 'X') {
            patchesCount++;
            i += 2;
        }
    }
    return patchesCount;
}
