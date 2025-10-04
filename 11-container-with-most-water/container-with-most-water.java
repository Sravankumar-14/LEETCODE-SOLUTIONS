class Solution {
    public int maxArea(int[] height) {
        int a = 0;
        int b = height.length-1;
        int vol = 0;
        int maxVolume = 0;
        while(a < b) {
            vol = Math.min(height[a], height[b]) * (b - a);
            maxVolume = Math.max(vol, maxVolume);
            if(height[a] < height[b]) a++;
            else b--;
        }
        return maxVolume;
    }
}