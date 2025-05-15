class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer>stack = new Stack<>();

        boolean destroyed = false;
        for(int ast : asteroids)
        {
            while(!stack.isEmpty() && stack.peek() > 0 && ast < 0)
            {
                if(stack.peek() > -ast)
                {
                    destroyed = true;
                    break;
                }
                else if(stack.peek() < -ast)
                {
                    stack.pop();
                }
                else
                {
                    stack.pop();
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed)
            {
                stack.push(ast);
            }
            destroyed = false;
        }

        int [] ans = new int[stack.size()];
        for(int i=stack.size()-1; i>=0; i--)
        {
            ans[i] = stack.peek();
            stack.pop();
        }
        return ans;
    }
}