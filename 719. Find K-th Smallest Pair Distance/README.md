---
# Find K-th Smallest Pair Distance

## Intuition
To find the k-th smallest pair distance in an array, we need to consider the possible distances between any two numbers in the array and efficiently search for the k-th smallest distance. Since the array is not sorted, sorting it initially allows us to perform a binary search over the possible distance values. By leveraging a counting approach within this binary search, we can efficiently narrow down the exact k-th smallest distance.

## Approach
Start by sorting the array to facilitate efficient distance calculation between pairs. Use binary search to find the k-th smallest pair distance, where the search space ranges from 0 to the maximum possible distance in the array. For each mid-point in the binary search, count the number of pairs with a distance less than or equal to this value by iterating through the array. Adjust the binary search boundaries based on whether the count is less than or greater than k. When the search converges, the lower boundary will give the k-th smallest distance.

## Complexity
- **Time Complexity**: $$O(n \log d + n \log n)$$ where $$n$$ is the length of the array and $$d$$ is the difference between the maximum and minimum element. The $$O(n \log n)$$ is due to sorting, and the binary search over possible distances takes $$O(n \log d)$$.
- **Space Complexity**: $$O(1)$$, as we only use a constant amount of extra space.

## Code
```cpp
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), low{0}, high = nums[n-1] - nums[0];
        while (low < high) {
            int mid = (low + high) >> 1, count{0}, j{0}, i{0};
            while (i < n) {
                while (j < n && nums[j] - nums[i] <= mid) ++j;
                count += j - i - 1;
                ++i;
            }
            if (count < k) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};
```

- **[C++ | Efficient Binary Search Solution for "Find K-th Smallest Pair Distance" | 0ms Beats 100%](https://leetcode.com/problems/find-k-th-smallest-pair-distance/solutions/5633294/c-efficient-binary-search-solution-for-find-k-th-smallest-pair-distance-0ms-beats-100)**
---