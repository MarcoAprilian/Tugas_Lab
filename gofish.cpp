#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <conio.h>
#include <unordered_map>
#include "UI.h"
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

bool assign_value(const string &a, const string &b) {

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
    
int main() {
    vector <string> deck = generate_deck();
    deck = shuffle_card(deck);
    

    vector <string> plyhand;
    vector <string> opphand;

    
    for (int i = 0 ; i<=6 ; i++)
        {
            plyhand.push_back(deck[0]);
            deck.erase(deck.begin());
            opphand.push_back(deck[0]);
            deck.erase(deck.begin());            
        }
    
   
    sort(plyhand.begin(), plyhand.end(), assign_value);
    
     for (int j = 0 ; j <= 6 ; j++)
        {
            cout<<plyhand[j]<<" ";
        }
    cout<<endl;

     for (int j = 0 ; j <= 6 ; j++)
        {
            cout<< opphand[j]<<" ";
        }
    cout<<endl;
    
    string kartu;

    atas:
    cout<<"Pilih kartu yang mau diminta "<<endl;
    cin>>(kartu);

    transform(kartu.begin(), kartu.end(), kartu.begin(), ::toupper);

    auto cek = find(plyhand.begin(), plyhand.end(), (kartu));

    if (cek == plyhand.end())
        {
            goto atas;
        }
    


    
        for (int j = 0 ; j <= plyhand.size() ; j++)
        {
            
            if (kartu == opphand[j]) {
                plyhand.push_back(kartu);
                opphand[j].erase();
            }

            else
                {
                    continue;
                }
        }

    for (int j = 0 ; j <= plyhand.size() ; j++)
        {
            cout<<plyhand[j]<<" ";
        }

    cout<<endl;
    
     for (int j = 0 ; j <= opphand.size() ; j++)
        {
            cout << opphand[j]<<" ";
        }
    cout<<endl;
    









    


    
}
