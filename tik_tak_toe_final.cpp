#include <bits/stdc++.h>
using namespace std;

char board[3][3];
int size=3;
char player= 'X';

void starting_board(){
    cout<<' '<<' '<<0<<' '<<1<<' '<<2<<' '<<endl;
    for(int i=0;i<3;i++){
        cout<<i<<" ";
        for(int j=0;j<3;j++){
            cout<<" ";
            if(j<2){
                cout<<"|";
            }
        }
        cout<<endl;
        if(i<2){
            cout<<"  ------"<<endl;
        }
    }
}
void change_player(){
    
    if(player=='X'){
        player='O';
    }
    else if(player=='O'){
        player='X';
    }
}


bool winner(){
    for(int i=0;i<3;i++){
        if((board[i][0]==player && board[i][1]==player && board[i][2]==player) || 
           (board[0][i]==player && board[1][i]==player && board[2][i]==player)){
               return true;
           }
    }
    
    if((board[0][0]==player && board[1][1]==player && board[2][2]==player) ||
        (board[0][2]==player && board[1][1]==player && board[2][0]==player)){
            return true;
    }
    return false;
}
bool board_full(){
    int f=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]=='X' || board[i][j]=='O'){
                f=0;
            }
            else{
                return false;
            }
        }
    }
    
        return true;
    
    
    
}
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board(){
    cout<<' '<<' '<<0<<' '<<1<<' '<<2<<' '<<endl;
    for(int i=0;i<3;i++){
        cout<<i<<" ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            // if((board[i][j]!='X' || board[i][j]!='O')){
            //     cout<<" ";
            // }
            if (j < 2) cout << "|";
        }
        cout<<endl;
        if(i<2){
            cout<<"  ------"<<endl;
        }
    }
}
int main(){
    start_again:
    initializeBoard();
    starting_board();
    while(true){
        play_again:
        int r,c;
        cout<<player<<" play(enter row and column):";
        cin>>r>>c;
        if(board[r][c]!='X' && board[r][c]!='O'){
            board[r][c]=player;
            
            print_board();
        }
        else{
            cout<<"can't play on row "<<r<<" and colomn "<<c<<endl;
            goto play_again;
        }
        
        if(board_full()){
            cout<<"THE MATCH IS DRAW"<<endl;
            char c;
            cout<<"want to play again(y/n):";
            cin>>c;
            if(c=='y'){
                goto start_again;
            }
            return 0;
        }

        
        if(winner()){
            cout<<"PLAYER "<<player<<" WINS!"<<endl;
            char c;
            cout<<"want to play again(y/n):";
            cin>>c;
            if(c=='y'){
                goto start_again;
            }
            return 0;
        }
        
        change_player();
    }
    
    return 0;
}
