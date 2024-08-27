#include<bits/stdc++.h>
using namespace std;

int generate_num(){
    int num=(rand()%(1-1000)+1);
    return num;
}
int main(){
    float number;
    number=generate_num();
    int guess;
    while(guess!=number){
        cout<<"Guess the number: ";
        int num;
        cin>>num;
        guess=num;
        if(guess>number){
            cout<<"You Guessed a Higher Number\nTry again!\n";
        }
        else if(guess<number){
            cout<<"You Guessed a Lower Number\nTry again!\n";
        }
    }
    cout<<"Congrats You gussed the correct number";
}