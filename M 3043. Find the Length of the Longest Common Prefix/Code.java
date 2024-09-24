class TrieNode {
    TrieNode[] children = new TrieNode[10];
    void insert(String s) {
        TrieNode node = this;
        for (char ch : s.toCharArray()) {
            if (node.children[ch - '0'] == null) {
                node.children[ch - '0'] = new TrieNode();
            }
            node = node.children[ch - '0'];
        }
    }
    int prefix(String s) {
        TrieNode node = this;
        int length = 0;
        for (char ch : s.toCharArray()) {
            if (node.children[ch - '0'] == null) break;
            node = node.children[ch - '0'];
            length++;
        }
        return length;
    }
}
class Solution {
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        TrieNode trie = new TrieNode();
        for (int num : arr1) {
            trie.insert(String.valueOf(num));
        }
        int maxLength = 0;
        for (int num : arr2) {
            maxLength = Math.max(maxLength, trie.prefix(String.valueOf(num)));
        }
        return maxLength;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr1 = {1, 10, 100};
        int[] arr2 = {1000};
        System.out.println("Longest Common Prefix Length: " + sol.longestCommonPrefix(arr1, arr2)); // Output: 3
    }
}
