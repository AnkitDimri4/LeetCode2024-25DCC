class Solution {
    public String nearestPalindromic(String s) {
        long num = Long.parseLong(s);
        long[] c = {
            (long) Math.pow(10, s.length() - 1) - 1,
            (long) Math.pow(10, s.length()) + 1
        };
        String p = s.substring(0, (s.length() + 1) / 2);
        int i = -1;
        while (i <= 1) {
            String pStr = Long.toString(Long.parseLong(p) + i);
            String rev = new StringBuilder(pStr).reverse().toString();
            if (s.length() % 2 == 0) {
                c = append(c, Long.parseLong(pStr + rev));
            } else {
                c = append(c, Long.parseLong(pStr + rev.substring(1)));
            }
            i++;
        }
        long res = -1;
        int idx = 0;
        while (idx < c.length) {
            long x = c[idx++];
            if (x != num && (res == -1 || Math.abs(x - num) < Math.abs(res - num) || 
                            (Math.abs(x - num) == Math.abs(res - num) && x < res))) {
                res = x;
            }
        }
        return Long.toString(res);
    }
    
    private long[] append(long[] arr, long value) {
        long[] newArr = new long[arr.length + 1];
        int j = 0;
        while (j < arr.length) {
            newArr[j] = arr[j];
            j++;
        }
        newArr[arr.length] = value;
        return newArr;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.nearestPalindromic("123"));  // Output: "121"
        System.out.println(sol.nearestPalindromic("1"));    // Output: "0"
    }
}
