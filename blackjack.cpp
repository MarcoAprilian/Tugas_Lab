#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <conio.h>
using namespace std;

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

vector <int> shuffle(vector<int>deck)
{
    random_device rd;
    mt19937 g(rd()^ chrono::system_clock::now().time_since_epoch().count());
    shuffle(deck.begin(), deck.end(), g);

    return deck;
}

vector <int> print_deck(vector<int>deck)
{
    for (int i = 0; i < deck.size(); i++)
    {
      cout << deck[i] << " , ";
      if (i % 13 == 0) cout << endl;
    }
    return deck;
}


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


auto interfaceplayer(vector <int> ph)
    {               
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
    ulang:
    bool cd = false;
       system("CLS");

            vector <int> deck = generate_deck();
            deck = shuffle(deck);
            
            vector <int> playerhand;
            vector <int> dealerhand;

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
                    cd=true;
                    while (sumdh<17)
                    {
                        dealerhand.push_back(deck[0]);
                        deck.erase(deck.begin());
                        sumdh = accumulate(dealerhand.begin(),dealerhand.end(),0);
                    }
                    
                    interfaceplayer(playerhand);
                    interfacedealer(dealerhand, cd);
                    checkwin(sumph,sumdh);
                    system("pause");
                    goto gameover;
                }

            system("CLS");
            interfaceplayer(playerhand);
            interfacedealer(dealerhand, cd);

            

            sumph = accumulate(playerhand.begin(),playerhand.end(),0);
            sumdh = accumulate(dealerhand.begin(),dealerhand.end(),0);
            
            if (sumph < 21)
                {
                        goto hit;
                }
                
            checkwin(sumph,sumdh);
            system("pause");

            char lagi;
            gameover:
            cout<<"Main lagi???? (Y/N)";
            cin>>lagi;

            if (tolower(lagi) == 'y')
                {
                    goto ulang;
                }

            else
                {
                    cout<<"Terimakasih Sudah Bermain :)))";
                }


            return 0;

}
