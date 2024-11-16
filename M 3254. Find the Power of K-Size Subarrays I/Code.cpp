#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size(), count = 1;
        vector<int> res(n - k + 1, -1); // Result array to store valid subsequences
        // Check for consecutive sequences starting from the first element
        for (int i = 1; i < k; i++) 
            count = (nums[i] == nums[i - 1] + 1) ? count + 1 : 1;
        if (count == k) res[0] = nums[k - 1]; // First valid subsequence
        // Process the rest of the array starting from index k
        for (int i = k; i < n; i++) {
            count = (nums[i] == nums[i - 1] + 1) ? count + 1 : 1;
            if (count >= k) res[i - k + 1] = nums[i]; // Store valid subsequences
        }
        return res; // Return the result array with subsequences
    }
};

// auto io_opt = [] { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

int main() {
    Solution sol;
    
    // Example input 1
    vector<int> arr1 = {1, 2, 3, 10, 4, 2, 3, 5};
    int k1 = 3;
    
    vector<int> result1 = sol.resultsArray(arr1, k1);
    cout << "Result for example 1: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Example input 2
    vector<int> arr2 = {5, 4, 3, 2, 1};
    int k2 = 4;
    
    vector<int> result2 = sol.resultsArray(arr2, k2);
    cout << "Result for example 2: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    // Example input 3
    vector<int> arr3 = {1, 2, 3};
    int k3 = 0;
    
    vector<int> result3 = sol.resultsArray(arr3, k3);
    cout << "Result for example 3: ";
    for (int num : result3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
