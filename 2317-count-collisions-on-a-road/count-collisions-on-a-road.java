class Solution {
    public int countCollisions(String directions) {
        int ans = 0;
        int leftMoving = 0;
        int rightMoving = 0;
        int stationary = 0;

        boolean leftDir = true;
        boolean rightDir = true;

        int size = directions.length();
        for(int i=0; i<size; i++) {
            if(directions.charAt(i) != 'L') break;
            leftMoving ++;
        }

        for(int i=size-1; i>=0; i--) {
            if(directions.charAt(i) != 'R') break;
            rightMoving ++;
        }

        for(int i=0; i<size; i++) {
            if(directions.charAt(i) == 'S') stationary ++;
        }

        return (size - leftMoving - rightMoving - stationary);
    }
}