class Solution {
    public int countCollisions(String directions) {
        int ans = 0;
        int leftMoving = 0;
        int rightMoving = 0;
        int stationary = 0;

        int size = directions.length();
        int a = 0;
        int b = size-1;
        for(; a<size; a++) {
            if(directions.charAt(a) != 'L') break;
            if(directions.charAt(a) == 'S') stationary ++;
            leftMoving ++;
        }

        for(; b>=0; b--) {
            if(directions.charAt(b) != 'R') break;
            if(directions.charAt(b) == 'S') stationary ++;
            rightMoving ++;
        }

        for(; a<=b; a++, b--) {
            if(a == b) {
                if(directions.charAt(a) == 'S') stationary ++;
                break;
            }
            if(directions.charAt(a) == 'S') stationary ++;
            if(directions.charAt(b) == 'S') stationary ++;
        }

        return (size - leftMoving - rightMoving - stationary);
    }
}