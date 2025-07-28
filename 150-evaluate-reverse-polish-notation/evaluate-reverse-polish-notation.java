class Solution {
    public int convertToInt(String str)
    {
        int retVal = 0;
        boolean isNeagtive = false;
        for(char ch : str.toCharArray())
        {
            if(ch == '-')
            {
                isNeagtive = true;
                continue;
            }
            retVal *= 10;
            retVal += (ch - '0');
        }
        if(isNeagtive) retVal = -1 * retVal;
        return retVal;
    }
    public int evalRPN(String[] tokens) {
        Stack<Integer>stack = new Stack<>();
        for(String str : tokens)
        {
            if ("+-*/".contains(str))
            {
                int first = stack.peek();
                stack.pop();
                int second = stack.peek();
                stack.pop();
                switch(str)
                {
                    case "+" : 
                        stack.push(first + second);
                        break;
                    case "-" : 
                        stack.push(second - first);
                        break;
                    case "*" : 
                        stack.push(first * second);
                        break;
                    default : 
                        stack.push(second / first);
                        break;
                }
            }
            else {
                int val = convertToInt(str);
                stack.push(val);
            }
            System.out.println(stack.peek());
        }
        return stack.peek();
    }
}