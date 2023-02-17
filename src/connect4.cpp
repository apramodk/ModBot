#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <time.h>

using namespace std;

struct game_t{
  game_t(){
    for(int i=0; i<6; i++) for(int x=0; x<7; x++) board[i][x] = '~';
  }
  void printBoard();
  int firstSpaceOnColumn(int c);
  void compMoveEasy();
  void compMoveHard();
  bool isGameOver();

  void placePieceTop(int c, char piece);

  char board[6][7];
  int playOrder;
  char com;
  char ply;
};

int main(int argc, char* argv[]){
  srand(time(NULL));
  game_t connect4;

  cout << "Would you like to be Red or Yellow? (R/Y)\n";
  cin >> connect4.ply;

  while(connect4.ply != 'R' && connect4.ply != 'Y'){
    cout << "Error: Red or Yellow? (R/Y)\n";
    cin >> connect4.ply;
  }

  if(connect4.ply == 'R'){
    connect4.com = 'Y';
  }else{
    connect4.com = 'R';
  }

  cout << "Would you like to be Player 1/2?\n";
  cin >> connect4.playOrder;

  while(connect4.playOrder != 1 && connect4.playOrder != 2){
    cout << "Error: PLayer 1/2\n";
    cin >> connect4.playOrder;
  }



  printf("You are Player %d\n", connect4.playOrder);
  while(!(connect4.isGameOver())){
    if(connect4.playOrder == 2){
      connect4.compMoveEasy();
      if(connect4.isGameOver()){
        connect4.printBoard();
        printf("YOU LOSE\n");
        break;
      }
    }else{
      connect4.placePieceTop(pChoice, connect4.ply);
      if(connect4.isGameOver()){
        connect4.printBoard();
        printf("YOU WIN\n");
        break;
      }
    }
    connect4.printBoard(); int pChoice;
    cout << "Enter Column of Desired Placement: (0-6)\n";
    cin >> pChoice;
    while(connect4.firstSpaceOnColumn(pChoice) == -1){
      cout << "Invalid of Full: (0-6)\n";
      cin >> pChoice;
    }
    if(connect4.playOrder == 2){
      connect4.placePieceTop(pChoice, connect4.ply);
      if(connect4.isGameOver()){
        connect4.printBoard();
        printf("YOU WIN\n");
        break;
      }
    }else{
      connect4.compMoveEasy();
      if(connect4.isGameOver()){
        connect4.printBoard();
        printf("YOU LOSE\n");
        break;
      }
    }
  }

  return 0;
}






//CLASS FUNCTIONS
void game_t::printBoard(){
  for(int i=0; i<6; i++){
    for(int x=0; x<7; x++){
      printf("%c ", board[i][x]);
    }
    printf("\n");
  }
}

int game_t::firstSpaceOnColumn(int c){
  if(c > 6 || c < 0) return -1;
  for(int i=6; i >= 0; i--){
    if(board[i][c] == '~') return i;
  }
  return -1;
}

void game_t::placePieceTop(int c, char piece){
  int spot = firstSpaceOnColumn(c);
  if(spot == -1) return;
  board[spot][c] = piece;
}

bool game_t::isGameOver(){
  //VERTICALS
  for(int i=0; i<7; i++){
    for(int x=0; x<3; x++){
      if((board[x+0][i] == board[x+1][i]) &&
         (board[x+1][i] == board[x+2][i]) &&
         (board[x+2][i] == board[x+3][i]) &&
         (board[x+3][i] != '~')) return true;
    }
  }
  //HORIZONTAL
  for(int i=0; i<6; i++){
    for(int x=0; x<4; x++){
      if((board[i][x+0] == board[i][x+1]) &&
         (board[i][x+1] == board[i][x+2]) &&
         (board[i][x+2] == board[i][x+3]) &&
         (board[i][x+3] != '~')) return true;
    }
  }
  //DIAGNOLS TL <-> BR
  for(int i=0; i<4; i++){
    for(int x=0; x<3; x++){
      if((board[x+0][i+0] == board[x+1][i+1]) &&
         (board[x+1][i+1] == board[x+2][i+2]) &&
         (board[x+2][i+2] == board[x+3][i+3]) &&
         (board[x+3][i+3] != '~')) return true;
    }
  }
  //DIAGNOLS TR <-> BL
  for(int i=6; i>=3; i--){
    for(int x=0; x<3; x++){
      if((board[x+0][i-0] == board[x+1][i-1]) &&
         (board[x+1][i-1] == board[x+2][i-2]) &&
         (board[x+2][i-2] == board[x+3][i-3]) &&
         (board[x+3][i-3] != '~')) return true;
    }
  }
  return false;
}

void game_t::compMoveEasy(){
  while(true){
    int pick = rand()%7;
    if(firstSpaceOnColumn(pick) != -1){
      placePieceTop(pick, com);
      break;
    }
  }
}

void game_t::compMoveHard(){

}