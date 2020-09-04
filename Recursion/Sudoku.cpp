#include<iostream>
using namespace std;
bool sudokuSolverHelper(int board[][9], int row, int column, int x, int y){
    if((x==row-1 && y==column-1 && board[x][y] != 0) || (x>=row-1 && y>=column-1)){
        return true;
    }
    
    int options[9];
    for(int i = 0; i<9; i++){
        options[i] = i+1;
    }
    
    if(board[x][y] == 0){
    for(int j = 0; j<column; j++){
        for(int k = 0; k<9; k++){
            if(board[x][j] == options[k]){
                options[k] = 0;
            }
        }
    }
    
    for(int i = 0; i<row; i++){
        for(int k = 0; k<9; k++){
            if(board[i][y] == options[k]){
                options[k] = 0;
            }
        }
    }
    
    int blockrow = x - x%3;
    int blockcol = y - y%3;
    
    for(int i = blockrow; i<blockrow+3; i++){
        for(int j = blockcol; j<blockcol+3; j++){
            for(int k = 0; k < 9; k++){
                if(board[i][j] == options[k]){
                    options[k] = 0;
                }
            }
        }
    }

    bool check = false;
    for(int i = 0; i<9; i++){
        if(options[i] != 0){
            check = true;
            break;
        } 
    }
        
    if(check == false){
        return false;
    }
    
    for(int k = 0; k<9; k++){
        if(options[k] != 0){
            board[x][y] = options[k];
            if(y!=8){
                if(sudokuSolverHelper(board, row, column, x, y+1) == true){
                    return true;
                } 
            } else {
                if(sudokuSolverHelper(board, row, column, x+1, 0) == true){
                    return true;
                }
                
            }
            
        }
    }
        board[x][y] = 0;
        return false;
        
        
    } else {
            if(y!=8){
                if(sudokuSolverHelper(board, row, column, x, y+1) == true){
                    return true;
                } 
            } else {
                if(sudokuSolverHelper(board, row, column, x+1, 0) == true){
                    return true;
                }
                
            }
        
        return false;
    }
    
}

bool sudokuSolver(int board[][9]){
    return sudokuSolverHelper(board, 9, 9, 0, 0);
}

int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}




