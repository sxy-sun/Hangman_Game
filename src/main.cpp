#include <iostream>
#include <unistd.h>
#include <string>

bool game_over;
std::string answer;
std::string current_guess="";
int answer_length;
int num_attempt = 7;
int height = 16;
int width = 27;

void PrintMessage();
void GetInput();
void CheckAnswer();

int main(){
    std::cout << "Please input the answer word: ";
    std::cin >> answer;
    answer_length = answer.length();
    std::cout << "Game will start in 3 seconds..." << std::endl;
    sleep(3);
    system("clear");
    std::cout << "Game Start!" << std::endl;
    game_over = false;
    while (!game_over){
        PrintMessage();
        GetInput();
        CheckAnswer();
    }
    return 0;
}

void CheckAnswer(){
    if (current_guess == answer){
        game_over = true;   
    }
}

void GetInput(){
    std::string current_letter;
    std::cout << "Please input one letter: ";
    std::cin >> current_letter;
    current_guess += current_letter;
    num_attempt -= 1;
    //system("clear");
}

void PrintMessage(){
    std::string guess_buffer = current_guess;
    int underscore_len = answer_length-current_guess.length();
    for (int i = 0; i < width-9; i++){
        if (current_guess.length() == 0){   // when no guess, print "Guess: ____"
            if (i < answer_length){
                guess_buffer += "_";
            } else {
                guess_buffer += " ";
            }
        } else {                            // when exist guess, print "Guess: xx___"
            if (i >= current_guess.length() && i < current_guess.length()+ underscore_len){
                guess_buffer += "_";
            } else if (i >= current_guess.length()+ underscore_len){
                guess_buffer += " ";
            }
        }
    }
    for (int i = 0; i < height; i++){
        if (i == 0 || i == 2 || i == 15){
            std::cout << "+=========================+" << std::endl;
        } else if(i == 1){
            std::cout << "|      Hangman Game       |" << std::endl;
        } else if(i == 4 || i == 11){
            std::cout << "|      +-----------       |" << std::endl;
        } else if(i == 3 || i == 12){
            std::cout << "|                         |" << std::endl;          
        } else if(i == 14){
            std::cout << "|Attempts: " << num_attempt << "              |" << std::endl; 
        } else if (i == 13){
            std::cout << "|Guess: " << guess_buffer << "|" << std::endl;
        } else{
            std::cout << "|      |                  |" << std::endl;             
        }
    }
}

/*
+=========================+0    width = 27
|      Hangman Game       |1    height = 15
+=========================|2
|                         |3
|      +-----------       |4
|      |     |            |5
|      |     |            |6
|      |     O            |7
|      |    /|\           |8
|      |    / \           |9
|      |                  |10
|      +-----------       |11
|                         |12
|Guess: _______________   |13
|Attempts: 7              |14
+=========================+15

*/