// 检查给出的数独九宫格是否有明显的错误
// 横、竖、九格之内均不可有重复数字

// 我首先想到的方法——对于每个横、竖、九宫格，分别扫描一遍
// 行和列可以一起扫，九宫格分开

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> row={};
        set<char> col={};
        set<char> nine={};

        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if( board[i][j]!='.' ){
                    if ( col.find(board[i][j])!=col.end() ) return false; // 若行有重复，返回false (=0);
                    else col.insert(board[i][j]);
                }
                if( board[j][i]!='.' ){
                    if ( row.find(board[j][i])!=row.end() ) return false; // 若列有重复，返回false (=0);
                    else row.insert(board[j][i]);
                }
            }
            col = {};
            row = {};
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int ii = i * 3; ii < i*3+3; ii++) {
                    for (int jj = j * 3; jj < j*3+3; jj++) {
                        if( board[ii][jj]!='.' ){
                            if ( nine.find(board[ii][jj])!=nine.end() ) return false; // 若有重复，返回false (=0);
                            else nine.insert(board[ii][jj]);
                        }
                    }
                }
                nine = {};
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


// 遍历set
            // auto word=col.cbegin();
            // while (word != col.cend()){
            //     cout << *word << ',';
            //     ++word;
            // }
            // cout << endl;

            // auto word=row.cbegin();
            // while (word != row.cend()){
            //     cout << *word << ',';
            //     ++word;
            // }
            // cout << endl;

                // auto word=nine.cbegin();
                // while (word != nine.cend()){
                //     cout << *word << ',';
                //     ++word;
                // }
                // cout << endl;
