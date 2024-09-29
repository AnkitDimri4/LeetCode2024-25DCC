#include <unordered_map>
#include <map>
#include <unordered_set>
using namespace std;

class AllOne {
    unordered_map<string, int> count;
    map<int, unordered_set<string>> freq;
public:
    AllOne() {}
    void inc(string key) {
        int cnt = count[key]++;
        if (cnt > 0) freq[cnt].erase(key);
        freq[cnt + 1].insert(key);
        if (freq[cnt].empty()) freq.erase(cnt);
    }
    void dec(string key) {
        int cnt = count[key]--;
        if (cnt > 0) freq[cnt].erase(key);
        if (cnt == 1) count.erase(key);
        else freq[cnt - 1].insert(key);
        if (freq[cnt].empty()) freq.erase(cnt);
    }
    string getMaxKey() {
        return freq.empty() ? "" : *(freq.rbegin()->second.begin());
    }
    string getMinKey() {
        return freq.empty() ? "" : *(freq.begin()->second.begin());
    }
};

int main() {
    AllOne allOne;
    allOne.inc("a");
    allOne.inc("b");
    allOne.inc("a");
    allOne.dec("b");
    string maxKey = allOne.getMaxKey();
    string minKey = allOne.getMinKey();
    return 0; // maxKey should be "a", minKey should be "a"
}
