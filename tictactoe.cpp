#include <iostream>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
bool checkWinner(char *spaces, char player);
bool horizontal(char *spaces, char player);
bool vertical(char *spaces, char player);
bool diagonal(char *spaces, char player);
bool checkTie(char *spaces);
bool gameOver(char *spaces, char player1, char player2);
void playerTurn(char *spaces, char player);
bool playAgain();
void clearBoard(char *spaces);
void tutorial();


int main(){

    tutorial();

    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player1 = 'O';
    char player2 = 'X';
    bool running = true; 

    drawBoard(spaces);
    
    while(running){
        
        playerTurn(spaces, player1);
        if(gameOver(spaces, player1, player2)){
            running = playAgain();
            if(running){
                clearBoard(spaces);
                drawBoard(spaces);
            }
            if(!running){
                break;
            }
            
        }
        playerTurn(spaces, player2);
        if(gameOver(spaces, player1, player2)){
            running = playAgain();
            if(running){
                clearBoard(spaces);
                drawBoard(spaces);
            }
            if(!running){
                break;
            }
        }
    }
    return 0;
}

void drawBoard(char *spaces){
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}

void playerMove(char *spaces, char player){
    int num;
    while(true){
        std::cout << "enter space number 1-9 \n";
        std::cin >> num;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "please enter a number 1-9 \n";
            continue;
        }
        std::cin.ignore(1000, '\n');
        if(num < 1 || num > 9){
            std::cout << "please enter a number 1-9 \n";
            continue;
        }
        num--;
        if(spaces[num] == ' '){
            spaces[num] = player;
            break;
        }
        else if(spaces[num] != ' '){
            std::cout << "space is already taken \n";
            continue;
        }    
    }
}

bool horizontal(char *spaces, char player){
    for(int num = 0; num < 7; num += 3){
        if(spaces[num] == player && spaces[num] == spaces[num + 1] && spaces[num + 1] == spaces[num + 2]){
            std::cout << player << " wins \n";
            return true;
        }
    }
    return false;
}

bool vertical(char *spaces, char player){
    for(int num = 0; num < 3; num++){
        if(spaces[num] == player && spaces[num] == spaces[num + 3] && spaces[num + 3] == spaces[num + 6]){
            std::cout <<  player << " wins \n";
            return true;
        }
    }
    return false;
}

bool diagonal(char *spaces, char player){
    if(spaces[0] == player && spaces[0] == spaces[4] && spaces[4] == spaces[8]){
        std::cout << player << " wins \n";
        return true;
    }
    else if(spaces[2] == player && spaces[2] == spaces[4] && spaces[4] == spaces[6]){
        std::cout << player << " wins \n";
        return true;
    }
    return false;
}

bool checkWinner(char *spaces, char player){

    bool h = horizontal(spaces, player);
    bool v = vertical(spaces, player);
    bool d = diagonal(spaces, player);

    if(h == true || v == true || d == true){
    return true;
    }
    return false;

}

bool checkTie(char *spaces){
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    std::cout << "Tie game \n";
    return true;
}

bool gameOver(char *spaces, char player1, char player2){
    bool w1 = checkWinner(spaces, player1);
    bool w2 = checkWinner(spaces, player2);
    bool t = checkTie(spaces);
    if(w1 == true || w2 == true || t == true){
        return true;
    }
    return false;
}

void playerTurn(char *spaces, char player){
    std::cout << player << "'s turn \n";
    playerMove(spaces, player);
    drawBoard(spaces);
}

bool playAgain(){
    std::cout << "Play again? Enter (Y) for yes or anything else to end \n";
        char again;
        std::cin >> again;
        again = toupper(again);
        if(again == 'Y'){
            return true;
        }
        else{
            return false;
        }
}

void clearBoard(char *spaces){
    std::fill(spaces, spaces + 9, ' ');
}

void tutorial(){
    char numBoard[9] = {'1','2','3','4','5','6','7','8','9'};
    char tutorial;
    bool yes;
    std::cout << "Would you like to see the tutorial? \n";
    std::cout << "Enter (Y) for yes, enter anything else to continue to the game \n";
    std::cin >> tutorial;
    tutorial = toupper(tutorial);
    if(tutorial == 'Y'){
            yes = true;
        }
        else{
            yes = false;
        }
    while(yes == true){
        std::cout << "The board spaces are numbered as follows: \n";
        drawBoard(numBoard);

        std::cout << "When it is your turn, you will enter the space number on the board you want to take. \n\n";

        std::cout << "Are you ready to play? Enter (Y) for yes, anything else to see the tutorial again \n";
        char play;
        std::cin >> play;
        play = toupper(play);
        if(play == 'Y'){
            break;
        }
        else{
            continue;
        }
    }


}
