package leetcode.leetcode_0007_easy_reverse_integer;

class Solution {
    public int reverse(int x) {
        int r = 0;
        while (x != 0){
            if (r > Integer.MAX_VALUE / 10 || (r == Integer.MAX_VALUE / 10 && x % 10 > Integer.MAX_VALUE % 10)) return 0;
            if (r < Integer.MIN_VALUE / 10 || (r == Integer.MIN_VALUE / 10 && x % 10 < Integer.MIN_VALUE % 10)) return 0;
            r = r * 10 + (x % 10);
            x = x / 10;
        }
        return r;
    }
}


public class v01 {
    public static void main(String[] argv){
        Solution sl = new Solution();
        System.out.println(sl.reverse(123)); // 321
        System.out.println(sl.reverse(-123)); // -321
    }
}

