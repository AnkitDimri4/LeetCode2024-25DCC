---
# Lemonade Change

# Intuition
To determine if we can provide the correct change to every customer at a lemonade stand, we need to track the number of `$`5 and `$`10 bills we have as we process each customer’s payment. The challenge is to make sure we always have enough `$`5 and `$`10 bills to give the correct change for a `$`10 or `$`20 bill, respectively.

# Approach
We iterate through each customer's payment, increasing our count of `$`5 bills if they pay with a `$`5 bill. For a `$`10 bill, we check if we have a `$`5 bill for change, if not, return false. With a `$`20 bill, we first try to give one `$`10 bill and one `$`5 bill as change. If that's not possible, we then attempt to give three `$`5 bills. If neither option is available, return false. This confirms we can provide the correct change to every customer if we finish processing without issues.

# Complexity
- **Time Complexity** $$O(n)$$, where $$n$$ is the length of the bills array. We only need a single pass through the array.
- **Space Complexity** $$O(1)$$, as we only use a fixed amount of extra space for tracking the counts of `$`5 and `$`10 bills.

# Code
```cpp []
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five{0}, ten{0}, i{0};
        while (i < bills.size()) {
            if (bills[i] == 5) five++;
            else if (bills[i] == 10) { if (!five--) return false; ten++; }
            else if (ten && five--) ten--;
            else if (five >= 3) five -= 3; 
            else return false;
            i++;
        }
        return true;
    }
};
```

```java []
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int five = 0, ten = 0, i = 0;
        while (i < bills.length) {
            if (bills[i] == 5) five++;
            else if (bills[i] == 10) { if (five-- <= 0) return false; ten++; }
            else if (ten > 0 && five-- > 0) ten--;
            else if (five >= 3) five -= 3; 
            else return false;
            i++;
        }
        return true;
    }
}
```
```python []
class Solution:
    def lemonadeChange(self, bills):
        five, ten, i = 0, 0, 0
        while i < len(bills):
            if bills[i] == 5:
                five += 1
            elif bills[i] == 10:
                if five <= 0:
                    return False
                five -= 1
                ten += 1
            elif ten > 0 and five > 0:
                ten -= 1
                five -= 1
            elif five >= 3:
                five -= 3
            else:
                return False
            i += 1
        return True

```

- **[C++ | Efficient Solution for "Lemonade Change" | 55ms Beats 97.21% | Python | Java](https://leetcode.com/problems/lemonade-change/solutions/5637601/c-efficient-solution-for-lemonade-change-55ms-beats-9721-python-java)**

---