#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct T {
    T *c[10] = {};
    void ins(string s) {
        T *n = this;
        for (char ch : s) {
            if (!n->c[ch - '0']) n->c[ch - '0'] = new T();
            n = n->c[ch - '0'];
        }
    }
    int pref(string s) {
        T *n = this;
        int len{0};
        for (char ch : s) {
            if (!n->c[ch - '0']) break;
            n = n->c[ch - '0'];
            ++len;
        }
        return len;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& a1, vector<int>& a2) {
        T t;
        for (int x : a1) t.ins(to_string(x));
        int mx{0};
        for (int x : a2) mx = max(mx, t.pref(to_string(x)));
        return mx;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {1, 10, 100};
    vector<int> arr2 = {1000};
    cout << "Longest Common Prefix Length: " << sol.longestCommonPrefix(arr1, arr2) << "\n"; // Output: 3
    return 0;
}
