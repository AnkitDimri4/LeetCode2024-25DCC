// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    static bool isNonDec(int* nums, int n) {
        int prev=INT_MIN;
        for (int i{0}; i<n; i++) {
            while (i<n && nums[i]==INT_MAX) i++;
            if (i==n) break;
            if (nums[i]<prev) return 0;
            prev=nums[i];
        }
        return 1;
    }
    static int minimumPairRemoval(vector<int>& _nums) {
        const int n=_nums.size();
        int* nums=_nums.data();
        int op{0};
        while (!isNonDec(nums, n)) {
            int minPair=INT_MAX, s{-1}, t{-1};
            for (int i{0}; i<n-1; i++) {
                if (nums[i]==INT_MAX) continue;
                int j{i+1};
                while (j<n && nums[j]==INT_MAX) j++;
                if (j<n && nums[j]!=INT_MAX) {
                    int pairSum=nums[i]+nums[j];
                    if (pairSum<minPair) {
                        minPair=pairSum;
                        s=i;
                        t=j;
                    }
                }
            }
            if (s!=-1 && t!=-1) {
                nums[s]+=nums[t];
                nums[t]=INT_MAX;
                op++;
            } 
            else 
                break; 
        }
        return op;
    }
};


int main() {
    vector<vector<int>> testCases = {
        {5, 2, 3, 1},
        {1, 2, 2},
        {4, 1, 5, 2, 3}
    };

    for (auto &nums : testCases) {
        int result = Solution::minimumPairRemoval(nums);
        cout << "Minimum pair removals for [";
        for (size_t i = 0; i < nums.size(); i++) {
            if (i > 0) cout << ", ";
            cout << nums[i];
        }
        cout << "] = " << result << endl;
    }

    return 0;
}
