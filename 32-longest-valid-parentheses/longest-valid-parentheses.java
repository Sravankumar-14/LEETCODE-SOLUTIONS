class Solution {
    public int longestValidParentheses(String s) {
        char [] ch = s.toCharArray();
        Stack<int[]> stack = new Stack<>();
        for(int i=0; i<ch.length; i++) {
            char bracket = ch[i];
            int [] temp = new int [2];
            temp[0] = (int) bracket;
            temp[1] = i;
            if(stack.empty()) {
                stack.push(temp);
            } else {
                int[] top = stack.peek();
                if(top[0] == (int) '(' && bracket == ')') {
                    stack.pop();
                } else {
                    stack.push(temp);
                }
            }
        }
        
        int range = ch.length;
        if(stack.empty()) return range;
        int maxValue = 0;
        while(!stack.empty()) {
            int [] top = stack.peek();
            int index = top[1];
            int subArr = range - index - 1;
            range = index;
            maxValue = Math.max(maxValue, subArr);
            stack.pop();
        }
        maxValue = Math.max(maxValue, range);
        return maxValue;

    }
}