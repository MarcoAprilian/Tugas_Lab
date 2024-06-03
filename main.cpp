#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <conio.h>
#include "UI.h"

using namespace std;

class deck_struct {
    public :
    vector <int> generate_deck()
        {
            int Ace = 1;
            int J = 10;
            int Q = 10;
            int K = 10;

            vector <int> deck = {  Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
                    Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
                    Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
                    Ace,2,3,4,5,6,7,8,9,10,J,Q,K };
            
            return deck;

        }

    public :
    vector <int> shuffle_card(vector<int>deck)
        {
            random_device rd;
            mt19937 g(rd()^ chrono::system_clock::now().time_since_epoch().count());
            shuffle(deck.begin(), deck.end(), g);

            return deck;
        }

    public :
    vector <int> print_deck(vector<int>deck)
        {
            for (int i = 0; i < deck.size(); i++)
            {
            cout << deck[i] << " , ";
            if (i % 13 == 0) cout << endl;
            }
            return deck;
        }

};

void checkwin(int playerhand, int dealerhand)
{
    garis();
    if (playerhand == 21 && dealerhand == 21) {
        cout<<"     BLACKJACK PUSH"<<endl;
    } else
    if (playerhand == 21 && dealerhand != 21) {
        cout<<"     BLACKJACK WIN"<<endl;
    } else
    if (playerhand != 21 && dealerhand == 21) {
        cout<<"     DEALER BLACK JACK, YOU LOSE"<<endl;
    } else
    if (playerhand < 21 && playerhand > dealerhand) {
        cout<<"     YOU WIN"<<endl;
    } else
    if (playerhand > 21) {
        cout<<"     BUST LOST"<<endl;
    } else 
    if (dealerhand > 21) {
        cout<<"     DEALER BUST, YOU WIN"<<endl;
    }else
    if (playerhand == dealerhand) {
        cout<<"     PUSH"<<endl;
    } else
    if (playerhand < dealerhand) {
        cout<<"     YOU LOSE"<<endl;
    }    
}


auto interfaceplayer(vector <int> ph)
    {   
            UI_atas();   
        int total = 0;
        cout<<"Kartu anda       :";
        for (int i = 0 ; i< ph.size() ; i++)
            {   
                cout<<ph[i]<<" ";
                total += ph[i];
            }
        printf("   (total = %d)", total);
        cout<<endl;  
    }

auto interfacedealer(vector <int> dh, bool cond)
    {   
        if (cond == false) 
            {
                cout<<"Kartu dealer     :";
                for (int i = 0 ; i < (dh.size()-1) ; i++)
                    {   
                        cout<<dh[i]<<" ";
                    }
                cout<<endl;  
            }       

        else if (cond == true)    
            {
                cout<<"Kartu dealer     :";
                for (int i = 0 ; i < (dh.size()) ; i++)
                    {   
                        cout<<dh[i]<<" ";
                    }
                cout<<endl;  
            }
    }


int main()
{   
    tampilan_utama();

    deck_struct card;
    ulang:
    bool cd = false;
       system("CLS");

            vector <int> deck = card.generate_deck();
            vector <int> playerhand;
            vector <int> dealerhand;
            deck = card.shuffle_card(deck);
            
           

            for (int i = 0 ; i<=1 ; i++)
                {
                    playerhand.push_back(deck[0]);
                    deck.erase(deck.begin());
                    dealerhand.push_back(deck[0]);
                    deck.erase(deck.begin());            
                }

            char pil;

            hit:
            system("CLS");

            interfaceplayer(playerhand);
            interfacedealer(dealerhand,cd);
                garis();
            cout<<"Hit or Stand (H/S) "<<endl;
            cin>>pil;
            
            int sumph = accumulate(playerhand.begin(),playerhand.end(),0);
            int sumdh = accumulate(dealerhand.begin(),dealerhand.end(),0);

            if (tolower(pil) == 'h')
                {
                    playerhand.push_back(deck[0]);
                    deck.erase(deck.begin());                    
                }

            else if (tolower(pil) == 's')
                {   
                    system ("CLS");
                    cd=true;
                    while (sumdh<17)
                        {
                            dealerhand.push_back(deck[0]);
                            deck.erase(deck.begin());
                            sumdh = accumulate(dealerhand.begin(),dealerhand.end(),0);
                        }
                    
                    interfaceplayer(playerhand);
                    interfacedealer(dealerhand, cd);
                    cout<<endl;
                    checkwin(sumph,sumdh);
                    cout<<endl;
                    system("pause");
                    goto gameover;
                }

            system("CLS");
            interfaceplayer(playerhand);
            interfacedealer(dealerhand, cd);

            

            sumph = accumulate(playerhand.begin(),playerhand.end(),0);
            sumdh = accumulate(dealerhand.begin(),dealerhand.end(),0);
            
            if (sumph < 21)
                goto hit;

            cout<<endl;    
            checkwin(sumph,sumdh);
            cout<<endl;

            system("pause");

            uji:
            system("CLS");

            char lagi;
            gameover:
           
            UI_atas();
            cout<<"Main lagi???? (Y/N)"<<endl;
            cin>>lagi;

            if (tolower(lagi) == 'y')
                goto ulang;

            else if (tolower(lagi) == 'y')
                cout<<"Terimakasih Sudah Bermain :)))";

            else 
                goto uji;
                


            return 0;

}