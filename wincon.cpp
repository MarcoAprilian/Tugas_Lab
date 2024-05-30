#include <iostream>
using namespace std;

void checkwin(int playerhand, int dealerhand){

    if (playerhand == 21 && dealerhand == 21) {
        cout<<"Blackjack push"<<endl;
    } else
    if (playerhand == 21 && dealerhand != 21) {
        cout<<"Blackjack win"<<endl;
    } else
    if (playerhand != 21 && dealerhand == 21) {
        cout<<"Dealer Blackjack, lose"<<endl;
    } else
    if (playerhand < 21 && playerhand > dealerhand) {
        cout<<" Wins"<<endl;
    } else
    if (playerhand > 21) {
        cout<<" Bust, lost"<<endl;
    } else 
    if (dealerhand > 21) {
        cout<<" Dealer Bust, Win"<<endl;
    }else
    if (playerhand == dealerhand) {
        cout<<" Push"<<endl;
    } else
    if (playerhand < dealerhand) {
        cout<<" Lose"<<endl;
    }    
}


int main() {
    int a,b;
    cout<<"Input player hand: ";
    cin>>a;
    cout<<endl<<"Inpu dealer hand: ";
    cin>>b;
    checkwin(a,b);
}