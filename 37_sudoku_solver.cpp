// 填入数独
//  DFS 暴力回溯枚举。
// 数独要求每横行，每竖行，每九宫格内，1-9的数字不能重复，
// 每放下一个数字的时候，在这 3 个地方都需要判断一次。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // 若
        // pos, find := []position{}, false
        // for (i = 0; i < len(board); i++) {
        //     for (j = 0; j < len(board[0]); j++) {
        //         if board[i][j] == '.' {
        //             pos = append(pos, position{x: i, y: j});
        //         }
        //     } 
        // }
        // putSudoku(&board, pos, 0, &find);
    }

        // for (int i = 0; i < 9; ++i){
        //     for (int j = 0; j < 9; ++j) {
        //         if (board[i][j] == '.') {
        //             for (int k = 0; k < 9; ++k) {
        //                 board[i][j] = '1' + k;
        //                 if (isValid(board, i, j) && solveSudoku(board))
        //                     return true;
        //                 board[i][j] = '.';
        //             }
        //             return false;
        //         }
        //     }
        // }
        // return true;


    // 1.
    void putSudoku(vector<vector<char>>& board){

    }

    // 2.判断是否存在矛盾
    bool checkSudoku(vector<vector<char>>& board, int val){

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
                                
    g.solveSudoku(board);
    for(int i=0; i<9; ++i){
        for(int j=0; j<9; ++j){
            cout << board[i][j];
            if(j!=8) cout << ", ";
            else cout << ";" <<endl;
        }
    }
    
    return 0;
}
