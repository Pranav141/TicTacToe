#include<bits/stdc++.h>
#include<iostream>
using namespace std;
char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,col;
char token='X';
void gameMoves(){
    int digit;
    if(token=='X'){
        cout<<"Player 1 turn, Please enter digit"<<endl;
        cin>>digit;
    }
    else{
        cout<<"Player 2 turn, Please enter digit"<<endl;
        cin>>digit;
    }
    if(digit==1){
        row=0;
        col=0;
    }
    else if(digit==2){
        row=0;
        col=1;
    }
    else if(digit==3){
        row=0;
        col=2;
    }
    else if(digit==4){
        row=1;
        col=0;
    }
    else if(digit==5){
        row=1;
        col=1;
    }
    else if(digit==6){
        row=1;
        col=2;
    }
    else if(digit==7){
        row=2;
        col=0;
    }
    else if(digit==8){
        row=2;
        col=1;
    }
    else if(digit==9){
        row=2;
        col=2;
    }
    else{
        cout<<"Invalid digit"<<endl;    
    }
    if(token=='X' && space[row][col]!='X' && space[row][col]!='O'){
        space[row][col]='X';
        token='O';
    }
    else if(token=='O' && space[row][col]!='X' && space[row][col]!='O'){
        space[row][col]='O';
        token='X';
    }
    else{
        cout<<"Invalid move"<<endl;
        gameMoves();
    }
}
bool checkWin(){
    for(int i=0;i<3;i++){
        if(space[i][0]==space[i][1] && space[i][1]==space[i][2]  || space[0][i]==space[1][i] && space[1][i]==space[2][i] ){
            return true;
        }

        if(space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0]){
            return true;
        }
    }
    return false;
}
void printBoard(){
    cout<<"   |   |   "<<endl;
    cout<<" "<<space[0][0]<<" | "<<space[0][1]<<" | "<<space[0][2]<<" "<<endl; // " " is used to create space between the numbers
    cout<<"___|___|___"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<" "<<space[1][0]<<" | "<<space[1][1]<<" | "<<space[1][2]<<" "<<endl; // " " is used to create space between the numbers

    cout<<"___|___|___"<<endl;
    cout<<"   |   |   "<<endl;
    cout<<" "<<space[2][0]<<" | "<<space[2][1]<<" | "<<space[2][2]<<" "<<endl; // " " is used to create space between the numbers

    cout<<"   |   |   "<<endl;
}
void gameStart(){
 
    string p1,p2;
    cout<<"Enter Player 1 name: "<<endl;
    cin>>p1;
    cout<<"Enter Player 2 name: "<<endl;
    cin>>p2;
    cout<<"Welcome "<<p1<<" and "<<p2<<" to the game of Tic Tac Toe"<<endl;
    cout<<p1<<" will play first"<<endl;
    cout<<p2<<" will play second"<<endl;
    for (int i = 0; i < 9; i++)
    {
        /* code */
        printBoard();
        gameMoves();
        if(checkWin()){
            printBoard();
            cout<<"Game Over"<<endl;
            if(i%2==0){
                cout<<p1<<" wins"<<endl;
            }
            else{
                cout<<p2<<" wins"<<endl;
            }
            return;
        }

    }
    
    cout<<"Game Over"<<endl;
    cout<<"Draw"<<endl;
    return;

}

int main(){
    gameStart();
    return 0;
}