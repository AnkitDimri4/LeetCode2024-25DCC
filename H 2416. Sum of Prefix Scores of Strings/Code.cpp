#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct T {
    T* c[26] = {};
    int cnt = 0;
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& w) {
        T* r = new T();  
        for (auto& s : w) 
            for (T* n = r; auto ch : s) 
                n = n->c[ch - 'a'] ? n->c[ch - 'a'] : n->c[ch - 'a'] = new T(), n->cnt++;
        vector<int> res;
        for (auto& s : w) {
            int sc = 0;
            for (T* n = r; auto ch : s) 
                sc += (n = n->c[ch - 'a'])->cnt;
            res.push_back(sc);
        }
        return res;
    }
};
int main() {
    Solution sol;
    vector<string> words = {"abc", "ab", "bc", "b"};
    vector<int> result = sol.sumPrefixScores(words);
    
    cout << "[";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    cout << "]" << "\n";  // Output: [5, 4, 3, 2]
    
    return 0;
}
