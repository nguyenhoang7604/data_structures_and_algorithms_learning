#include <vector>
#include <algorithm>
#include <numeric>

// Function to get the maximum reward points
int getMaximumRewardPoints(int k, const std::vector<int>& reward_1, const std::vector<int>& reward_2) {
    int n = reward_1.size();

    // Base total if intern2 does all tasks
    int totalReward = std::accumulate(reward_2.begin(), reward_2.end(), 0);
    
    // Compute the benefit (difference) for each task if done by intern1 instead of intern2
    std::vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        diff[i] = reward_1[i] - reward_2[i];
    }
    
    // Sort the differences in descending order so that the largest gains come first
    std::sort(diff.begin(), diff.end(), std::greater<int>());
    
    // Add the top k differences (even if some are negative, since we must pick exactly k tasks)
    for (int i = 0; i < k; i++) {
        totalReward += diff[i];
    }
    
    return totalReward;
}

// Function to get the maximum reward points
int getMaximumRewardPoints(int k, const std::vector<int>& reward_1, const std::vector<int>& reward_2) {
    int n = reward_1.size();
    int totalRewards = 0;
    
    std::vector<std::pair<int, int>> diff(n);
    for (auto i = 0; i < n; ++i) {
        int sub = reward_1[i] - reward_2[i];\
        diff[i] = std::pair<int,int>(sub, i);
    }

    std::sort(diff.begin(), diff.end(), [](std::pair<int,int> a, std::pair<int, int> b) {return a.first > b.first;} );

    for (auto i = 0; i < n; ++i) {
        if (i < k) {
            totalRewards += reward_1[diff[i].second];
        } else {
            totalRewards += reward_2[diff[i].second];
        }
    }

    return totalRewards;
}

// Example usage
#include <iostream>
int main() {
    std::vector<int> reward_1 = {5, 4, 3, 2, 1};
    std::vector<int> reward_2 = {1, 2, 3, 4, 5};
    int k = 3;
    
    int maxReward = getMaximumRewardPoints(k, reward_1, reward_2);
    std::cout << "Maximum combined reward points: " << maxReward << std::endl;
    // Expected output: 21
    return 0;
}
