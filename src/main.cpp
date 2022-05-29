#include <iostream>
#include <unistd.h>
#include <string>

bool game_over;
std::string answer;
std::string current_guess="";
std::string guess_buffer="";
int answer_length;
int num_attempt = 7;
int height = 16;
int width = 27;
std::string line5, line6, line7, line8, line9 = "";

void PrintMessage();
void GetInput();
void CheckAnswer(char);
void UpdateGuessBuffer();
void InitializeGuessBuffer();
void UpdateHangman();


int main(){
    std::cout << "Please input the answer word: (q to quit) ";
    std::cin >> answer;
    if (answer == "q"){
        return 0;
    }
    answer_length = answer.length();
    std::cout << "Game will start in 3..." << std::endl;
    sleep(1);
    std::cout << "Game will start in 2..." << std::endl;
    sleep(1);
    std::cout << "Game will start in 1..." << std::endl;
    sleep(1);
    system("clear");

    game_over = false;

    while (!game_over){
        if (num_attempt == 0){
            system("clear");
            PrintMessage();
            std::cout << "You run out of guesses!" << std::endl;
            std::cout << "Want to know the answer? (T/F) ";
            char show_answer;
            std::cin >> show_answer;
            if (show_answer == 'T'){
            std::cout << "The answer is: " << answer << std::endl;
            }
            return 0;
        }
        system("clear");
        if (guess_buffer == ""){
            InitializeGuessBuffer(); 
        }
           
        PrintMessage();
        GetInput();
        UpdateGuessBuffer();  
    }

    return 0;
}

void CheckAnswer(char letter){
    /* If has full answer, set gane_over to true
       If no full answer yet:
            If current letter is wrong, attempt decrement
            If current letter is right, append to current_guess*/
    char answer_letter = answer[current_guess.length()];
    if (answer_letter == letter) {
        current_guess += letter;
    } else{
        num_attempt -= 1;
    }
    if (current_guess == answer){
        system("clear");
        UpdateGuessBuffer(); 
        PrintMessage();
        std::cout << "You got it!" << std::endl;
        game_over = true;   
    } 
}

void GetInput(){
    /* get current input letter; attempt number decrement */ 
    char current_letter;
    std::cout << "Please input one letter: ";
    std::cin >> current_letter;
    CheckAnswer(current_letter);
}

void InitializeGuessBuffer(){  
    for (int i = 0; i < width-9; i++){
        if (i < answer_length){
            guess_buffer += "_";
        } else {
            guess_buffer += " ";
        }
    } 
}

void UpdateGuessBuffer(){
    std::string rear = guess_buffer.substr(current_guess.length());
    guess_buffer = current_guess + rear;
}

void UpdateHangman(){
    if (num_attempt == 7){
        line5 = line6 = line7 = line8 = line9 = "|      |                  |";
    } else{
        if (num_attempt == 6){
            line5 = line6 = "|      |     |            |";
        } 
        if (num_attempt == 5){
            line7 = "|      |     O            |";
        } 
        if (num_attempt == 4){
            line8 = "|      |     |            |";
        } 
        if (num_attempt == 3){
            line8 = "|      |    /|            |";
        } 
        if (num_attempt == 2){
            line8 = "|      |    /|\\           |";
        } 
        if (num_attempt == 1){
            line9 = "|      |    /             |";
        } 
        if (num_attempt == 0){
            line9 = "|      |    / \\           |";
        }       
    }
}

void PrintMessage(){
    UpdateHangman();
    for (int i = 0; i < height; i++){
        if (i == 0 || i == 2 || i == 15){
            std::cout << "+=========================+" << std::endl;
        } else if(i == 1){
            std::cout << "|      Hangman Game       |" << std::endl;
        } else if(i == 4 || i == 11){
            std::cout << "|      +-----------       |" << std::endl;
        } else if(i == 3 || i == 12){
            std::cout << "|                         |" << std::endl;          
        } else if(i == 5){
            std::cout << line5 << std::endl; 
        } else if(i == 6){
            std::cout << line6 << std::endl; 
        } else if(i == 7){
            std::cout << line7 << std::endl; 
        } else if(i == 8){
            std::cout << line8 << std::endl; 
        } else if(i == 9){
            std::cout << line9 << std::endl; 
        } else if (i == 13){
            std::cout << "|Guess: " << guess_buffer << "|" << std::endl;
        } else if(i == 14){
            std::cout << "|Attempts: " << num_attempt << "              |" << std::endl; 
        } else {
            std::cout << "|      |                  |" << std::endl;
        }
    }
}

/*
+=========================+0    width = 27
|      Hangman Game       |1    height = 16
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