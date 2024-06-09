#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <conio.h>
#include <unordered_map>
#include <cctype>
#include <string>
#include <stdio.h>

using namespace std;

vector <string> generate_deck()
    {
        vector <string> deck = {  "A","2","3","4","5","6","7","8","9","10","J","Q","K",
                "A","2","3","4","5","6","7","8","9","10","J","Q","K",
                "A","2","3","4","5","6","7","8","9","10","J","Q","K",
                "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
        
        return deck;

    }

unordered_map <string,int> card_value = {
    {"A", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5},
    {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}, {"10", 10},
    {"J", 11}, {"Q", 12}, {"K", 13}
};

bool assign_value(const string &a, const string &b) 
    {

        string rankA = a.substr(0, a.find(' '));
        string rankB = b.substr(0, b.find(' '));
        
        return card_value[rankA] < card_value[rankB];
    }

vector <string> shuffle_card(vector<string>deck)
    {
        random_device rd;
        mt19937 g(rd()^ chrono::system_clock::now().time_since_epoch().count());
        shuffle(deck.begin(), deck.end(), g);

        return deck;
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
                        auto removeIt =remove_if(hand.begin(), hand.end(), [&](const string& word) { return word == pasang.first; });
                        hand.erase(removeIt,hand.end());

                        cout<<"Menyelesaikan 1 set "<<pasang.first;
                        *poin += 1;
                    }

            }
        return hand;
    }

void printhand(vector <string> hand)
    {
           for (int j = 0 ; j < hand.size() ; j++)
            {
                cout<<hand[j]<<" ";
            }
    }

int handsize(vector <string> hand)
    {
        int x  = hand.size();
        return x;
    }

void interface_gf (vector <string> ownhand, vector <string> opohand, vector <string> dek, int poinlawan, int poinown)
    {
        cout<<endl;
        cout<<"Tangan lawan = " << opohand.size() << "          " << "Poin lawan = " << poinlawan;
        cout<<endl;
        cout<<endl;
        cout<<"Kartu anda   = "; printhand(ownhand);
        cout<<endl;
        cout<<"Poin anda    = " << poinown << endl;
        cout<<endl;
        cout<<"Deck         = " << dek.size();
        cout<<endl;
        
    }

int main() {
    system("CLS");
    vector <string> deck = generate_deck();
    deck = shuffle_card(deck);
    bool replay = false;

    vector <string> plyhand;
    vector <string> opphand;

    
    for (int i = 0 ; i<=6 ; i++)
        {
            plyhand.push_back(deck[0]);
            deck.erase(deck.begin());
            opphand.push_back(deck[0]);
            deck.erase(deck.begin());            
        }    

    string kartu;

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
        system("CLS");
        sort(plyhand.begin(), plyhand.end(), assign_value);
        
        interface_gf(plyhand, opphand, deck, *ptroppoint, *ptrplypoint);

        cout<<endl;
        cout<<"Pilih kartu yang mau diminta ";
        cin>>(kartu);
        transform(kartu.begin(), kartu.end(), kartu.begin(), ::toupper);
        auto cekply = find(plyhand.begin(), plyhand.end(), (kartu));
        if (cekply == plyhand.end())
            {
                goto atas;
            }


        auto cekopp = find(opphand.begin(), opphand.end(), (kartu));
        if (cekopp != opphand.end())
            { 
                int sz = opphand.size();
                
                for (int j = 0 ; j < sz ; j++)
                    {
                        
                        if (kartu == opphand[j]) 
                            {
                                plyhand.push_back(kartu);
                                auto removeIt =remove_if(opphand.begin(), opphand.end(), [&](const string& word) { return word == kartu; });
                                opphand.erase(removeIt,opphand.end());
                                cout << "Anda mengambil kartu " << kartu << " dari tangan lawan" << endl;
                                system("pause");
                                plyhand = cekfour(plyhand, &plypoint);
                                system("pause");
                                replay = true;

                            }
                    }
            } 
        else if (kartu == deck[0])
            {
                plyhand.push_back(deck[0]);
                deck.erase(deck.begin());
                cout << "Anda mengambil kartu " << kartu << " dari deck" << endl;
                system("pause");
                plyhand = cekfour(plyhand, &plypoint);
                system("pause");
                
                replay = true;
            }
        
        else
            {   
                plyhand.push_back(deck[0]);
                deck.erase(deck.begin());
                cout<<"GO FISH!!" << endl;
                system("pause");
                plyhand = cekfour(plyhand, &plypoint);
                system("pause");
                goto nexturn;
                
            }
        
        system("CLS");
 
        interface_gf(plyhand, opphand, deck, *ptroppoint, *ptrplypoint);
        cout<<endl;
        printhand(opphand);
        cout<<endl;
       
        if (replay == true)
            goto atas;

        nexturn:

        system("pause");
        system("CLS");

        interface_gf(plyhand, opphand, deck, *ptroppoint, *ptrplypoint);
        cout<<endl;
        printhand(opphand);
        cout<<endl;
    //opp turn

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
                    if (pair.second >= 3)
                    {
                        oppchosen=pair.first;
                    } 
                    else if (pair.second >= 2)
                    {
                        oppchosen=pair.first;
                    }
                    else
                    {
                        oppchosen=opphand[0];
                    }
                }

        cout<<endl;
        cout<<"Lawan memilih kartu "<<*ptroppchosen<<endl;
        cout<<endl;
        system("pause");
        
        cekply = find(plyhand.begin(), plyhand.end(), (*ptroppchosen));
                if (cekply != plyhand.end())
                    { 
                        int sz = plyhand.size();
                        
                        for (int j = 0 ; j < sz ; j++)
                            {
                                
                                if (*ptroppchosen == plyhand[j]) 
                                    {
                                        opphand.push_back(*ptroppchosen);
                                        auto removeIt =remove_if(plyhand.begin(), plyhand.end(), [&](const string& word) { return word == *ptroppchosen; });
                                        plyhand.erase(removeIt,plyhand.end());
                                        cout<< "Lawan mengambil kartu " << *ptroppchosen << " dari tangan anda" <<endl;
                                        opphand = cekfour(opphand, &oppoint);
                                        system("pause");
                                        replayopp = true;

                                    }
                            }
                    } 
                else if (*ptroppchosen == deck[0])
                    {
                        opphand.push_back(deck[0]);
                        deck.erase(deck.begin());
                        cout<< "Lawan mengambil kartu " << *ptroppchosen << " dari deck"<<endl;
                        system("pause");
                        opphand = cekfour(opphand, &oppoint);
                        system("pause");
                        replayopp = true;
                    }
                
                else
                    {   
                        opphand.push_back(deck[0]);
                        deck.erase(deck.begin());
                        cout<<"GO FISH!!" << endl;
                        system("pause");
                        opphand = cekfour(opphand, &oppoint);
                        system("pause");
                        goto atas;
                        
                    }
        
        opphand = cekfour(opphand, &oppoint);
        system("pause");

        for (int j = 0 ; j < opphand.size() ; j++)
            {
                cout<<opphand[j]<<" ";
            }
        cout<<endl;

        if (replayopp == true)
            goto nexturn;

    }

}
