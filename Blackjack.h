#ifndef Blackjack_h
#define Blackjack_h

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <conio.h>
#include "UI.h"

using namespace std;

class deck_struct 
{
    public :
    vector <int> generate_deck_Blackjack()
        {
            int Ace = 1;
            int J = 10;
            int Q = 10;
            int K = 10;

            vector <int> deck = {   Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
                                    Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
                                    Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
                                    Ace,2,3,4,5,6,7,8,9,10,J,Q,K };
            
            return deck;
        }

    public :
    vector <int> shuffle_card_Blackjack(vector<int>deck)
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


void checkwin(int playerhand, int dealerhand, int *ptruang, int bet)
{
        garis();

    if (playerhand == 21 && dealerhand == 21) {
        cout << "   BLACKJACK PUSH" << endl;
    } else
    if (playerhand == 21 && dealerhand != 21) {
        cout << "   BLACKJACK WIN" << endl;
            *ptruang += bet;
    } else
    if (playerhand != 21 && dealerhand == 21) {
        cout << "   DEALER BLACK JACK, YOU LOSE" << endl;
            *ptruang -= bet;
    } else
    if (playerhand < 21 && playerhand > dealerhand) {
        cout << "   YOU WIN" << endl;
            *ptruang += bet;
    } else
    if (playerhand > 21) {
        cout << "   BUST LOST" << endl;
            *ptruang -= bet;
    } else 
    if (dealerhand > 21) {
        cout <<"    DEALER BUST, YOU WIN" << endl;
            *ptruang += bet;
    }else
    if (playerhand == dealerhand) {
        cout << "   PUSH" << endl;
    } else
    if (playerhand < dealerhand) {
        cout << "   YOU LOSE" << endl;
            *ptruang -= bet;
    }
}


auto interfaceplayer(vector <int> ph)
{   
        UI_Blackjack();  

    int total = 0;
    cout << "Kartu anda       :";
    for (int i = 0 ; i< ph.size() ; i++)
        {   
            cout<<ph[i]<<" ";
            total += ph[i];
        }
    cout << "(Total = " << total << ")";

        cout << endl;  
}


auto interfacedealer(vector <int> dh, bool cond)
{   
    if (cond == false) 
        {
            cout << "Kartu dealer     :";
            for (int i = 0 ; i < (dh.size()-1) ; i++)
                {   
                    cout<<dh[i]<<" ";
                }

            cout << endl;  
        }       

    else if (cond == true)    
        {
            cout << "Kartu dealer     :";
            for (int i = 0 ; i < (dh.size()) ; i++)
                {   
                    cout<<dh[i]<<" ";
                }

            cout << endl;  
        }
}


void Blackjack()
{   
    ulang:
    
    tampilanUtama_Blackjack();

    int uang = 100;
    int *ptruang = &uang;
    int bet;

    deck_struct card;

    bool cd = false;

        system("CLS");

    vector <int> deck = card.generate_deck_Blackjack();
    deck = card.shuffle_card_Blackjack(deck);
    vector <int> playerhand;
    vector <int> dealerhand;
    
    bet = *ptruang + 1;
    while (bet > *ptruang)
        {
                UI_Blackjack();    

            cout << "Your Point = " << *ptruang << endl;
            cout << "Pasang Taruhan: ";
            cin >> bet;     
        }

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

    cout << "Hit or Stand (H/S) " << endl;
    pil= _getch(); 
    
    int sumph = accumulate(playerhand.begin(),playerhand.end(),0);
    int sumdh = accumulate(dealerhand.begin(),dealerhand.end(),0);

    if (tolower(pil) == 'h')
        {
            playerhand.push_back(deck[0]);
            deck.erase(deck.begin());

        } else if (tolower(pil) == 's')
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
                checkwin(sumph, sumdh, ptruang, bet); 

                if (*ptruang <= 0) goto gameover;

                    garis();

                cout << endl << "Your Point = " << *ptruang << endl;

                    cout << endl;
                    system("pause");

                goto gameover;
            }

        system("CLS");

    interfaceplayer(playerhand);
    interfacedealer(dealerhand, cd);

    sumph = accumulate(playerhand.begin(),playerhand.end(),0);
    sumdh = accumulate(dealerhand.begin(),dealerhand.end(),0);
    
    if (sumph < 21) goto hit;

    checkwin(sumph, sumdh, ptruang, bet);
    if (*ptruang <= 0) goto gameover;
        
        garis();
        
    cout << endl << "Your Credit= " << *ptruang << endl;
    cout << endl;
    
        system("pause");

    gameover:

    cout << "   BANGKRUT SUDAH" << endl;
    garis();

        system("pause");
        system("CLS");
        UI_Blackjack();

    char lagi;

    cout << "                                Play Again ???? "    << endl;
    cout << "                            Yes(Y)            No(N)" << endl;

        garis();

    lagi = _getch(); 

    if (tolower(lagi) == 'y') goto ulang;
    else if (tolower(lagi) == 'n')
        {
                system("pause");

            GameOver();
        } 
    else goto gameover;
}
#endif