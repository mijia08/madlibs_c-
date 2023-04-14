#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <fstream>
 
using namespace std;
const int COLUMNSIZE = 51;
const int ROWSIZE = 112; // constant variables of row and column size based on size of haikus
 
void readHaiku(ifstream& input, char array[], char haikuArray[][COLUMNSIZE], int& i);
void userChoiceRequest(char userChoice);
void haikuPicker(int haikuAmount, int& num);
int findHaikuSpace(char array[]);
void replaceHaiku(char array[], char haikuArray[], char input[]);
void askChoice(char noun[], char adjective[], char gerund[]);
void printHaiku(char array[], char haikuA[][COLUMNSIZE], char baseArray[], int userChoice, char noun[], char adjective[], char gerund[]);
 
// making sure to call functions prior to main in order to use in main.
 
int main()
{
    int i;
    int request;
    int haikuAmount;
    ifstream input;
    char answer = 'y' && 'Y';
    char haikuArray[ROWSIZE][COLUMNSIZE];
    char baseArray[COLUMNSIZE];
    char adjective[COLUMNSIZE];
    char noun[COLUMNSIZE];
    char gerund[COLUMNSIZE];
    char finishHaiku[COLUMNSIZE];
    // defining functions i am using in main.
   
    readHaiku(input, baseArray, haikuArray, haikuAmount);
    input.close();
    cout << "Welcome to Mad Lib Haikus! " << endl;
    while(answer == 'y' || answer == 'Y'){
      askChoice(adjective, noun, gerund);
      haikuPicker(haikuAmount, request);
      printHaiku(baseArray, haikuArray, finishHaiku, request, noun, adjective, gerund);
      userChoiceRequest(answer);
      // while loop to only play game when the user selects yes
   }
}
    void readHaiku(ifstream& input, char array[], char haikuPlacer[][COLUMNSIZE], int& i){
    char c;
    string haikuFile = "haikus.dat";
    input.open(haikuFile.c_str());
    if(input.fail()){
       cout << "Haiku file non-existent. Please contact the administrator." << endl;
               cout << "Thank you for using Mad Lib Haikus!";
    }
    input.get(c);
            if(input.eof()){
               cout << "Haiku file is empty. Please contact the administrator."<< endl;
               cout << "Thank you for using Mad Lib Haikus!";
    }
    input.putback(c);
            i = 0;
    input.getline(array, COLUMNSIZE);
        while(!input.eof()){
                                    strcpy(haikuPlacer[i], array);
                                    i++;
                                    input.getline(array, COLUMNSIZE);
        }
        i = i/3;
    }
void userChoiceRequest(char userChoice){
    cout<<"Continue (Y/N)?"<<endl;
    cin >> userChoice;
    char temp = userChoice;
    userChoice = tolower(temp);
}
 
void haikuPicker(int haikuAmount, int& num){
    srand(time(0));
    num = ((rand() % haikuAmount)*3);
}
int findHaikuSpace(char array[]){
    for(int i = 0; array[i] != '\0'; i++){
        if(array[i] == '*')
        return(i);
}
    return(-1);
}
void replaceHaiku(char array[], char haikuArray[], char input[]){
    int i = findHaikuSpace(array);
    if(i != -1){
        strncpy(haikuArray, array, i);
        strcat(haikuArray, input);
        strcat(haikuArray, &array[i + 1]);
    }
}
void askChoice(char noun[], char adjective[], char gerund[]){
    char userGerund;
            cout <<"Enter a one syllable noun: "<<endl;
            cin >> noun;
            cout<<"Enter a two syllable adjective: "<<endl;
            cin >> adjective;
            cout <<"Enter a two syllable gerund (a verb ending in “ing” like “asking”): "<<endl;
            cin >> userGerund;
            gerund[0] = toupper(userGerund);
}         
void printHaiku(char array[], char haikuA[][COLUMNSIZE], char baseArray[], int userChoice, char noun[], char adjective[], char gerund[]){
    for(int i = 0; i < COLUMNSIZE; i++){
        baseArray[i] = '\0';
        array[i] = '\0';
    }
    strcpy(array, haikuA[userChoice]);
    replaceHaiku(array, baseArray, noun);
    cout << baseArray;
    cout << endl;
    for(int i = 0; i < COLUMNSIZE; i++){
        baseArray[i] = '\0';
        array[i] = '\0';
    }
    strcpy(array, haikuA[userChoice + 1]);
    replaceHaiku(array, baseArray, adjective);
    cout << baseArray;
    cout << endl;
    for(int i = 0; i < COLUMNSIZE; i++){
        baseArray[i] = '\0';
        array[i] = '\0';
    }
    strcpy(array, haikuA[userChoice + 2]);
    replaceHaiku(array, baseArray, gerund);
    cout << baseArray;
    cout << endl;
    for(int i = 0; i < COLUMNSIZE; i++){
        baseArray[i] = '\0';
        array[i] = '\0';
    }
}
