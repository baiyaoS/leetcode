// 检查给出的数独九宫格是否有明显的错误
// 横、竖、九格之内均不可有重复数字

// 行、列、九宫格可以一起

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row(9, vector<bool>(9));
        vector<vector<bool>> col(9, vector<bool>(9));
        vector<vector<bool>> nine(9, vector<bool>(9));
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if( board[i][j]!='.' ){
                    int num = board[i][j]-'0';
                    if ( row[i][num] || col[j][num] || nine[i/3*3+j/3][num] ){
                        return false; // 若有重复，返回false (=0);
                    }
                    else {
                        row[i][num]=true;
                        col[j][num]=true;
                        nine[i/3*3+j/3][num]=true;
                    }
                }
            }
        }
        return true;
    }
};


int main(){
    Solution g;
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};

    bool ret = g.isValidSudoku(board);
    cout << (ret==0 ? "false" : "true") << endl;
    return 0;
}
