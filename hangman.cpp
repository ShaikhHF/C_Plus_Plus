/*Hana Shaikh
  Hangman
*/


#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

const vector<string> ANSWERS = {"UNDER THE WEATHER", "BURST YOUR BUBBLE", "SNOW LEOPARD"};

const vector<string> CATEGORIES = {"phrase", "phrase", "animal"};

const int NUM_ANSWERS = 3;

//generates the hidden string
string hideAnswer(string answer){
  string hidden;
  hidden.resize(answer.length());
  for(int i = 0; i < answer.length(); i++){
    if(answer.at(i) != ' '){
      hidden.at(i) = '_';
    }
    else{
      hidden.at(i) = ' ';
    }
  }

  return hidden;
}


//uncovers characters based on guess
bool vannaWhite(char guess, string answer, string &hidden){
  bool uncover = false;

  for(int i = 0; i < answer.length(); i++){
    if(guess == answer.at(i)){
      hidden.at(i) = answer.at(i);
      uncover = true;
    }
  }

  return uncover;
}


//shows hidden with spaces
void showHidden(string hidden){
  for(int i = 0; i < hidden.length(); i++){
    cout<<hidden.at(i)<<" ";
  }
  cout<<endl;
}


//inputs guess
char makeGuess(){
  char guess;
  cout<<"Letter: ";
  cin>>guess;

  guess = toupper(guess);
  return guess;
}


//randomizes the word
int setAnswerandCategory(){
  int index = rand() % NUM_ANSWERS;
  return index;
}


bool previouslyGuessed(char guess, string guesses){
  bool valid = true;

  for(int i = 0; i < guesses.length(); i++){
    if(guess == guesses.at(i)){
      valid = false;
      cout<<"Already guessed that one!\n";
    }
  }

  return valid;
}




//controls the game loop
int main() {
  srand(time(0));

  //variables
  int index = setAnswerandCategory();
  //original phrase and catagory
  string answer = ANSWERS[index];
  string catagory = CATEGORIES[index];

  //generates the hidden string
  string hidden = hideAnswer(answer);
  
  //user gues
  char guess;

  //holds if guess was correct
  bool uncover;

  //wheter game is complete
  bool done = false;

  //mistakes remaining
  int attempts = 5;

  //holds whether the guess hasn't be done before
  bool valid;

  string guesses = " ";

  //while loop controls the game
  while(done != true && attempts > 0){
    cout<<"Mistakes remaining: "<<attempts<<endl;

    showHidden(hidden);
    cout<<catagory<<endl;



    do{
      guess = makeGuess();
      
      valid = previouslyGuessed(guess, guesses);
      
    }while(valid != true);

    guesses.resize(guesses.length()+1);
    guesses.at(guesses.length()-1) = guess;


    uncover = vannaWhite(guess, answer, hidden);

    if(uncover == false){
      cout<<"Letter "<<guess<<" not found!\n";
      attempts --;
    }

    if(hidden == answer){
      cout<<"Good Job";
      done = true;
      cout<<endl;
      showHidden(hidden);
    }

    cout<<endl;
  }

  return 0;
}