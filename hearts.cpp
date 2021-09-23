/*Hana Shaikh
  Hearts!
*/

#include <iostream>
#include <vector>
#include <random>

using namespace std;
const string RED = "❤️";
const string BLUE = "💙";
const string GREEN="💚";
const string YELLOW="💛";
const string PURPLE="💜";
const string ONE="1️⃣";
const string TWO="2️⃣";
const string THREE="3️⃣";
const string FOUR="4️⃣";
const string FIVE="5️⃣";

const vector<string> HEARTS = {RED, BLUE, GREEN, YELLOW, PURPLE};


//prints out the welcome screen and rules
void welcomeScreen(){
  cout<<"Rules of Hearts!:\n";
  cout<<"THe computer has selected hearts of three colors and placed them in 3 positions. Your task is to guess which color hearts are used AND what position they have been placed. \n";
  cout<<"You have 10 tries.\n";
  cout<<"While there are 5 possible colors, only 3 are used. \n";
  cout<<"There is only 1 heart of each color. \n";
}




//swaps the values in a vector 
//called by later functions
void swap(vector<int>&key, int index1, int index2){
  int value;
  value = key[index1]; 
  key[index1] = key[index2];
  key[index2] = value;
}



//randomizes the list
//calls swap
void buildList(vector<int>&key){
  int index;
  int length = key.size();

  for(int i = 0; i < length; i++){
    index = rand() % length;
    swap(key, i, index);
  }
}



//displays the correct solution
void solution(vector<int> key){
  cout<<"Correct Solution\n";
  cout<<"---- ---- ----\n";
  cout<<HEARTS[key[0]]<<"   | "<<HEARTS[key[1]]<<"   | "<<HEARTS[key[2]]<<endl;
  cout<<"---- ---- ----\n";
}



//checks if the guesses are valid guess
bool validGuess(int index1, int index2, int index3){
  bool valid = false;
  if(index1 < 6 && index2 < 6 && index3 < 6){
    if(index1 != index2 && index2 != index3 && index1 != index3){
      valid = true;
    }
  }

  return valid;
}




//checks the guesses and outputs results of the code
bool checkGuess(vector<int> key, int index1, int index2, int index3, int &attempt){
  bool end = false;
  vector<int> guess = {index1, index2, index3};

  attempt--;

  int colors = 0;
  for(int i = 0; i<3; i++){
    for(int j = 0; j<3; j++){
      if(key[i] == guess[j]){
        colors++;
      }
    }
  }

  int position;
  for(int i = 0; i<3; i++){
    if(key[i] == guess[i]){
      position++;
    }
  }

  if(colors == 3 && position == 3){
    solution(key);
    end = true;
  }
  else{
  cout<<"--------------------"<<endl;
  cout<<"Colors correct: "<<colors<<endl;
  cout<<"Positions correct: "<<position<<endl;
  cout<<"Attempts left: "<<attempt<<endl;
  cout<<"--------------------"<<endl;
  }

  return end;
}



//controls the user inputting guess
//calls guessCheck
bool guess(vector<int> key, int &attempt){
  int color1;
  int color2;
  int color3;

  bool validG;
  do{
    cout<<"Enter your guesses: \n";
    cout<<ONE<<"  "<<TWO<<"  "<<THREE<<"  "<<FOUR<<"  "<<FIVE<<"  "<<endl;
    cout<<RED<<"  "<<BLUE<<"  "<<GREEN<<"  "<<YELLOW<<"  "<<PURPLE<<endl;
    cout<<"Place 1: ";
    cin>>color1;
    cout<<"Place 2: ";
    cin>>color2;
    cout<<"Place 3: ";
    cin>>color3;
    //ERROR OCCURS HERE "SEGMENTATION FAULT"


    validG = validGuess(color1, color2, color3);

  }while(validG == false);


  bool complete = checkGuess(key, color1-1, color2-1, color3-1, attempt);

  //if false continue guessing, true end
  return complete;
}


//controls the game running
int main() {
  //randomizes the program between runs
  srand(time(0));

  //welcome + rules
  welcomeScreen();

  //vector which will hold the randomly made sequence
  vector<int> key = {0, 1, 2, 3, 4};
  
  //variables made
  //number of attempts
  int attempt = 10;
  //game completion
  bool complete = false;

  //randomizes the sequence
  buildList(key);

  //controls the game
  while(complete == false){
    complete = guess(key, attempt);
  }

}