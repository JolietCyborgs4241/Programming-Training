#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string player1Input[] {"rock", "paper", "scissors", "rock", "rock", "scissors", "scissors", "paper", "paper"};
string player2Input[] {"rock", "paper", "scissors", "paper", "scissors", "rock", "paper", "rock", "scissors"};


string rockPaperScissors(string player1, string player2) {
    if (player1 == player2) {
        return "tie";
    }
    
    if (player1 == "rock" && player2 == "scissors") {
        return "Player 1 Wins";
    } 
    
    if (player1 == "rock" && player2 == "paper") {
        return "Player 2 Wins";
    }
    
    if (player1 == "scissors" && player2 == "paper") {
        return "Player 1 Wins";
    } 
    
    if (player1 == "scissors" && player2 == "rock") {
        return "Player 2 Wins";
    }
    
    if (player1 == "paper" && player2 == "rock") {
        return "Player 1 Wins";
    } 
    
    if (player1 == "paper" && player2 == "scissors") {
        return "Player 2 Wins";
    }
}

int main() {
    for (int i = 0; i < sizeof(player1Input)/sizeof(player1Input[0]); i++) {
        cout << rockPaperScissors(player1Input[i], player2Input[i]) << endl;
    }
    
    return 0;
}