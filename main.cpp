int main()
{   
       system("CLS");

            vector <int> deck = generate_deck();
            deck = shuffle(deck);
            print_deck(deck);
            vector <int> playerhand;
            vector <int> dealerhand;

            for (int i = 0 ; i<=1 ; i++)
                {
                    playerhand.push_back(deck[0]);
                    cout<<playerhand[i];
                    deck.erase(deck.begin());
                    cout<<endl;
                    dealerhand.push_back(deck[0]);
                    cout<<dealerhand[i];
                    deck.erase(deck.begin());
                    cout<<endl;
                }

            char pil;
            cout<<"Hit or no"<<endl;
            cin>>pil;

            if (pil == 'y')
                {
                    playerhand.push_back(deck[0]);
                    deck.erase(deck.begin());
                }

            int sumph = accumulate(playerhand.begin(),playerhand.end(),0);
            int sumdh = accumulate(dealerhand.begin(),dealerhand.end(),0);
            checkwin(sumph,sumdh);



            
            

            return 0;

}
