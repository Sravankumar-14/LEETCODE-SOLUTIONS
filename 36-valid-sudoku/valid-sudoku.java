class Solution {
    public boolean isValidSudoku(char[][] board) {
        //check row wise
        for(int i=0; i<9; i++) {
            Set<Character> set = new HashSet<>();
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') continue;
                if(set.contains(board[i][j])) return false;
                set.add(board[i][j]);
            }
        }

        //check col wise
        for(int i=0; i<9; i++) {
            Set<Character> set = new HashSet<>();
            for(int j=0; j<9; j++) {
                if(board[j][i] == '.') continue;
                if(set.contains(board[j][i])) return false;
                set.add(board[j][i]);
            }
        }

        //check box wise
        for(int i=0; i<9; i+=3) {
            for(int j=0; j<9; j+=3) {
                Set<Character> set = new HashSet<>();
                for(int a=i; a<i+3; a++) {
                    for(int b=j; b<j+3; b++) {
                        if(board[a][b] == '.') continue;
                        if(set.contains(board[a][b])) return false;
                        set.add(board[a][b]);
                    }
                }
            }
        }

        return true;
    }
}