#ifndef GoFish_h
#define GoFish_h

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <conio.h>
#include <unordered_map>
#include <cctype>
#include <string>
#include "UI.h"

using namespace std;

vector <string> generate_deck_GoFish()
{
    vector <string> deck = {    "A","2","3","4","5","6","7","8","9","10","J","Q","K",
                                "A","2","3","4","5","6","7","8","9","10","J","Q","K",
                                "A","2","3","4","5","6","7","8","9","10","J","Q","K",
                                "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
    
    return deck;
}

vector <string> shuffle_card_GoFish(vector<string>deck)
{
    random_device rd;
    mt19937 g(rd()^ chrono::system_clock::now().time_since_epoch().count());
    shuffle(deck.begin(), deck.end(), g);

    return deck;
}

unordered_map <string,int> card_value = 
{
    {"A", 1},   {"2", 2},   {"3", 3},   {"4", 4},   {"5", 5},
    {"6", 6},   {"7", 7},   {"8", 8},   {"9", 9},   {"10", 10},
    {"J", 11},  {"Q", 12},  {"K", 13}
};

bool assign_value(const string &a, const string &b) 
{

    string rankA = a.substr(0, a.find(' '));
    string rankB = b.substr(0, b.find(' '));
    
    return card_value[rankA] < card_value[rankB];
}

vector <string> cekfour (vector <string> hand, int *poin )
{
    unordered_map <string, int> count;

    for (const auto card : (hand)) 
        {
            count[card]++;
        }

    for (const auto pasang : count)
        {
            if (pasang.second == 4) 
                {
                    auto removeIt = remove_if(hand.begin(), hand.end(), [&](const string& word) { return word == pasang.first; });
                    hand.erase(removeIt,hand.end());

                    cout << "Menyelesaikan 1 set kartu " << pasang.first << endl;
                    *poin += 1;
                }
        }
    return hand;
}

void printhand(vector <string> hand)
{
        for (int j = 0 ; j < hand.size() ; j++)
        {
            cout << hand[j] << " ";
        }
}

int handsize(vector <string> hand)
{
    int x  = hand.size();
    return x;
}

void interface_gf (vector <string> ownhand, vector <string> opohand, vector <string> dek, int poinlawan, int poinown)
{
    cout << " Kartu anda   = "; printhand(ownhand);
        cout << endl;
    cout << " Poin anda    = " << poinown << endl;
        cout << endl;
     cout << " Tangan lawan = " << opohand.size() << endl;
    cout << " Poin lawan   = " << poinlawan << endl;
    cout << "                                                              " << " Deck    = " << dek.size() << endl;
        garis();
    
}

auto GoFish() 
{
        system("CLS");

    ulang:    

    tampilanUtama_GoFish();

    vector <string> deck = generate_deck_GoFish();
    deck = shuffle_card_GoFish(deck);
    bool replay = false;
    string kartu;

    vector <string> plyhand;
    vector <string> opphand;

    for (int i = 0 ; i <= 6 ; i++)
        {
            plyhand.push_back(deck[0]);
            deck.erase(deck.begin());
            opphand.push_back(deck[0]);
            deck.erase(deck.begin());            
        }    

    int plypoint = 0;
    int *ptrplypoint;
    ptrplypoint = &plypoint;

    int oppoint = 0;
    int *ptroppoint;
    ptroppoint = &oppoint;


    
    while ((deck.size() != 0 ) || (plyhand.size() != 0) || (opphand.size() != 0))
        {

            //player turn
            atas:
            if (deck.size() == 0 ) 
                {
                        system("CLS");
                        UI_GoFish();

                    cout << "Deck Habis !!";
                    goto endgame;
                }
            if (plyhand.size() == 0)  
                {
                        system("CLS");
                        UI_GoFish();

                    cout << "Tangan Player Habis !!";
                    goto endgame;
                }    

                system("CLS");
                UI_GoFish();

            sort(plyhand.begin(), plyhand.end(), assign_value);
            interface_gf(plyhand, opphand, deck, *ptroppoint, *ptrplypoint);

            cout<<"Pilih kartu yang mau diminta: ";
            cin >> kartu;

            transform(kartu.begin(), kartu.end(), kartu.begin(), ::toupper);
            auto cekply = find(plyhand.begin(), plyhand.end(), (kartu));

            if (cekply == plyhand.end()) goto atas;

            auto cekopp = find(opphand.begin(), opphand.end(), (kartu));
            if (cekopp != opphand.end())
                { 
                    for (int j = 0 ; j < opphand.size() ; j++)
                        {
                            if (kartu == opphand[j]) 
                                {
                                    cout << "Anda mengambil kartu " << kartu << " dari tangan lawan" << endl;

                                    plyhand.push_back(kartu);
                                    auto removeIt =remove_if(opphand.begin(), opphand.end(), [&](const string& word) { return word == kartu; });
                                    opphand.erase(removeIt,opphand.end());

                                    plyhand = cekfour(plyhand, &plypoint);
                                        garis();

                                    system("pause");
                                    replay = true;
                                }
                        }
                } 
            else if (kartu == deck[0])
                {
                    cout << "GO FISH!!" << endl;
                    cout << "Anda mengambil kartu " << deck[0] << " dari deck" << endl;

                    plyhand.push_back(deck[0]);
                    deck.erase(deck.begin());

                    plyhand = cekfour(plyhand, &plypoint);
                        garis();
                    
                    system("pause");
                    replay = true;
                }
            else
                {   
                    cout << "GO FISH!!" << endl;
                    cout << "Anda mengambil kartu " << deck[0] << " dari deck" << endl;

                    plyhand.push_back(deck[0]);
                    deck.erase(deck.begin());

                    plyhand = cekfour(plyhand, &plypoint);
                        garis();
                    
                    system("pause");
                    goto nexturn;
                }
            
                
                system("CLS");
                UI_GoFish();
    
            interface_gf(plyhand, opphand, deck, *ptroppoint, *ptrplypoint);
        
            if (replay == true) goto atas;

            nexturn:
            if (deck.size() == 0 ) 
                {
                        system("CLS");
                        UI_GoFish();

                    cout << "Deck Habis !!";
                    goto endgame;
                }
            if (opphand.size() == 0)  
                {
                        system("CLS");
                        UI_GoFish();

                    cout << "Tangan Lawan Habis !!";
                    goto endgame;
                }    


                system("CLS");
                UI_GoFish();

            interface_gf(plyhand, opphand, deck, *ptroppoint, *ptrplypoint);


            //Opp turn
            int y = 0;
            bool replayopp = false;

            string oppchosen;
            string *ptroppchosen;
            ptroppchosen = &oppchosen;
    
            unordered_map <string, int> oppcard;

            for (const auto card : (opphand)) 
                {
                    oppcard[card]++;
                }

            for (const auto pair : oppcard)
                {
                    if (pair.second >= 3) oppchosen=pair.first;
                    else if (pair.second >= 2) oppchosen=pair.first;
                    else oppchosen=opphand[0];
                }

            cout << "Lawan memilih kartu: " << *ptroppchosen << endl;
            
            cekply = find(plyhand.begin(), plyhand.end(), (*ptroppchosen));
            if (cekply != plyhand.end())
                { 
                    for (int j = 0 ; j < plyhand.size() ; j++)
                        {
                            if (*ptroppchosen == plyhand[j]) 
                                {
                                    cout<< "Lawan mengambil kartu " << *ptroppchosen << " dari tangan anda" << endl;

                                    opphand.push_back(*ptroppchosen);
                                    auto removeIt =remove_if(plyhand.begin(), plyhand.end(), [&](const string& word) { return word == *ptroppchosen; });
                                    plyhand.erase(removeIt,plyhand.end());

                                    opphand = cekfour(opphand, &oppoint);
                                        garis();                        
                                        system("pause");

                                    replayopp = true;
                                }
                        }
                } 
            else if (*ptroppchosen == deck[0])
                {
                    cout << "GO FISH!!" << endl;
                    cout<< "Lawan mengambil kartu " << deck[0] << " dari deck" << endl;

                    opphand.push_back(deck[0]);
                    deck.erase(deck.begin());
                    
                    opphand = cekfour(opphand, &oppoint);
                        garis();
                        system("pause");

                    replayopp = true;
                }
            else
                {   
                    cout << "GO FISH!!" << endl;
                    cout<< "Lawan mengambil kartu dari deck" << endl;

                    opphand.push_back(deck[0]);
                    deck.erase(deck.begin());

                    opphand = cekfour(opphand, &oppoint);
                        garis();
                        system("pause");

                    goto atas;
                }
            
            
            opphand = cekfour(opphand, &oppoint);

            if (replayopp == true) goto nexturn;

        }
    
    //end
    endgame:

        cout << endl << endl;
    cout << "Poin anda    = " << *ptrplypoint << endl;
    cout << "Poin lawan   = " << *ptroppoint << endl;
        garis();

    if (*ptrplypoint > *ptroppoint) cout << "                                YOU WIN !!" << endl;
    else if (*ptrplypoint < *ptroppoint) cout << "                               YOU LOSE !!" << endl;
    else if (*ptrplypoint == *ptroppoint) cout << "                                   TIED !!" << endl;

        garis();
        system("pause");
        system("CLS");
        UI_GoFish();


    char lagi;

    cout << "                                Play Again ???? "    << endl;
    cout << "                            Yes(Y)            No(N)" << endl;

        garis();

    lagi = _getch(); 

    if (tolower(lagi) == 'y') goto ulang;
    else if (tolower(lagi) == 'n')
        {
            go2:

                system("pause");

            GameOver();
        } 
    else goto endgame;
}
#endif
