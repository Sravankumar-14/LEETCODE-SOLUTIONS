class Solution {

    ArrayList<Integer> getVersionValues(String version) {
        String str = "";
        ArrayList<Integer> list = new ArrayList<>();
        for(int i=0; i<version.length(); i++) {
            int num = 0;
            while(i<version.length() && version.charAt(i) != '.') {
                char ch = version.charAt(i);
                int temp = ch - '0';
                num *= 10;
                num += temp;
                i++;
            }
            list.add(num);
        }
        return list;
    }

    public int compareVersion(String version1, String version2) {
        ArrayList<Integer> ver1 = getVersionValues(version1);
        ArrayList<Integer> ver2 = getVersionValues(version2);
        System.out.println(ver1);
        System.out.println(ver2);
        int i=0;
        for(; i<ver1.size() && i< ver2.size(); i++) {
            int num1 = ver1.get(i);
            int num2 = ver2.get(i);
            if(num1 < num2) return -1;
            if(num1 > num2) return 1;
        }
        for(; i<ver1.size(); i++) {
            if(ver1.get(i) != 0) return 1;
        }
        for(; i<ver2.size(); i++) {
            if(ver2.get(i) != 0) return -1;
        }
        return 0;
    }
}