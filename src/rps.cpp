#include <iostream>
#include <vector>
#include <stdlib.h>
#include <set>
using namespace std;

int main(){

  int player_score;
  int pc_score;
  vector<char> temp;
  char temp1;

  int pc_option;
  char user_input;

  player_score = 0;
  pc_score = 0;

  cout << "Rock paper scissors \n Enter r for Rock, p for Paper, and s for Scissors \n";
  
  while(true){
    cout << " \n Game is starting... Choose your option! \n";
    cout << " Enter q to quit \n";
    cout << "-----------------------------------------------\n";
    
    cin >> user_input;
    if(user_input == 'q'){
      break;
    }

    if(user_input == 'r') cout << "\nYou picked rock!" << endl;
    else if(user_input == 'p') cout << "\nYou picked paper!" << endl;
    else if(user_input == 's') cout << "\nYou picked scissors!" << endl;
    else{
      cout << "Enter a valid option \n";
      continue;
    }

    // calculate pc option

    pc_option = rand() % 10 + 1;
    
    for(int i = 0; i < 10; i++){
      temp1 = 'a' + rand()%3;
      if(temp1 == 'a') temp.push_back('r');
      else if(temp1 == 'b') temp.push_back('p');
      else if(temp1 == 'c') temp.push_back('s');
    }

    if(temp[pc_option] == 'r') cout << "Your opponent picked rock!\n";
    else if(temp[pc_option] == 'p') cout << "Your opponent picked paper!\n";
    else if(temp[pc_option] == 's') cout << "Your opponent picked scissors!\n";


    if((temp[pc_option] == 'p')&&(user_input == 's')){
      cout << "You win! \n";
      player_score++;
    }
    else if ((temp[pc_option] == 's')&&(user_input == 'r')){
      cout << "You win! \n";
      player_score++;
    }

    else if ((temp[pc_option] == 'r')&&(user_input == 'p')){
      cout << "You win! \n";
      player_score++;
    }

    else if ((temp[pc_option] == 's')&&(user_input == 'p')){
      cout << "You lose! \n";
      pc_score++;
    }

    else if ((temp[pc_option] == 'r')&&(user_input == 's')){
      cout << "You lose! \n";
      pc_score++;
    }

    else if ((temp[pc_option] == 'p')&&(user_input == 'r')){
      cout << "You lose! \n";
      pc_score++;
    }

    else if ((temp[pc_option] == 'p')&&(user_input == 'p')){
      cout << "It's a draw! \n";
    }

    else if ((temp[pc_option] == 's')&&(user_input == 's')){
      cout << "It's a draw! \n";
    }

    else if ((temp[pc_option] == 'p')&&(user_input == 'p')){
      cout << "It's a draw! \n";
    }

    cout << "Current score: " << player_score << " | " << pc_score << endl;
    temp.clear();

  }
    

  return 0;
}