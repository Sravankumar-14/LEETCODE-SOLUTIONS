class Pair{
    int position;
    int speed;

    Pair(int position, int speed) {
        this.position = position;
        this.speed = speed;
    }
}

class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        Pair[] array = new Pair[position.length];
        for(int i=0; i<position.length; i++) {
            array[i] = new Pair(position[i], speed[i]);
        }

        Arrays.sort(array, (a,b)-> a.position - b.position);
        Stack<Double> stack = new Stack<>();
        for (int i = array.length - 1; i >= 0; i--) {
            double time = (double)(target - array[i].position) / array[i].speed;
            if (stack.isEmpty() || time > stack.peek()) {
                stack.push(time);
            }
        }

        return stack.size();
    }
}