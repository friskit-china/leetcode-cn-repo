package leetcode.leetcode_0104_easy_maximum_depth_of_binary_tree;

public class v01 {
    static
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    static
    class Solution {
        public int maxDepth(TreeNode root) {
            if (root == null){
                return 0;
            }
            return Integer.max(maxDepth(root.left), maxDepth(root.right)) + 1;
        }
    }

    public static void main(String[] argv){
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);
        System.out.println(new Solution().maxDepth(root));
    }
    
}