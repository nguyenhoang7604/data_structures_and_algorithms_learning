#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int countPerfectPairs(const vector<int>& arr) {
    int n = arr.size();
    vector<int> absArr(n);
    
    for (int i = 0; i < n; i++) {
        absArr[i] = abs(arr[i]);
    }

    sort(absArr.begin(), absArr.end());
    
    long long count = 0;
    int j = 0;
    
    for (int i = 0; i < n; i++) {
        if (j < i + 1) {
            j = i + 1;
        }

        while (j < n && absArr[j] <= 2 * absArr[i]) {
            j++;
        }

        count += (j - i - 1);
    }
    
    return count;
}

int main() {
    vector<int> arr = {2, 5, -3};
    cout << "Number of perfect pairs: " << countPerfectPairs(arr) << endl;
    // Expected output: 2 (the pairs (2, -3) and (5, -3))
    return 0;
}
