#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <conio.h>
#include <unordered_map>
#include <cctype>
#include <string>

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

vector <string> print_deck(vector<string>deck)
    {
        for (int i = 0; i < deck.size(); i++)
        {
        cout << deck[i] << " , ";
        if (i % 13 == 0) cout << endl;
        }
        return deck;
    }


vector <string> cekfour (vector <string> hand )
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
                    }

            }
        return hand;
    }

int main() {
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

//player turn
    atas:
    sort(plyhand.begin(), plyhand.end(), assign_value);
    
     for (int j = 0 ; j < plyhand.size() ; j++)
        {
            cout<<plyhand[j]<<" ";
        }
    cout<<endl;
    for (int j = 0 ; j < opphand.size() ; j++)
        {
            cout<<opphand[j]<<" ";
        }
    cout<<endl;
    cout<<"Pilih kartu yang mau diminta "<<endl;
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
            int j = 0;
            for (j = 0 ; j < sz ; j++)
                {
                    
                    if (kartu == opphand[j]) 
                        {
                            plyhand.push_back(kartu);
                            auto removeIt =remove_if(opphand.begin(), opphand.end(), [&](const string& word) { return word == kartu; });
                            opphand.erase(removeIt,opphand.end());

                            replay = true;

                        }
                }
        } 
    else
        {
            plyhand.push_back(deck[0]);
            deck.erase(deck.begin());
            cout<<"GO FISH!!" << endl;
            goto nexturn;
            
        }
    
    plyhand = cekfour(plyhand);
  

    cout<<"size opp : " << opphand.size()<<endl;

     if (replay == true)
        goto atas;
    nexturn:
    


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

    cout<<"Lawan memilih kartu "<<*ptroppchosen<<endl;

            int pz = plyhand.size();
            for (int k = 0 ; k < pz ; k++)
                {
                    
                    if (oppchosen == plyhand[k]) 
                        {
                            plyhand.push_back(oppchosen);
                            auto removeIt =remove_if(plyhand.begin(), plyhand.end(), [&](const string& word) { return word == oppchosen; });
                            plyhand.erase(removeIt,plyhand.end());

                            replayopp = true;

                        }
                    else
                        {
                            opphand.push_back(deck[0]);
                            deck.erase(deck.begin());
                            cout<<"GO FISH!!" << endl;
                            goto atas;
                            
                        }
                }
        
    
    opphand = cekfour(opphand);
    for (int j = 0 ; j < opphand.size() ; j++)
        {
            cout<<opphand[j]<<" ";
        }
    cout<<endl;

     if (replayopp == true)
        goto nexturn;

}
