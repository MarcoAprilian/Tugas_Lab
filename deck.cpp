vector<int> generate_deck()
{
    int Ace = 1;
    int J = 11;
    int Q = 12;
    int K = 13;

    vector <int> deck = {  Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
              Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
              Ace,2,3,4,5,6,7,8,9,10,J,Q,K,
              Ace,2,3,4,5,6,7,8,9,10,J,Q,K };
    
    return deck;

}

vector<int> shuffle(vector<int>deck)
{
    random_device rd; //
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);

    return deck;
}

vector<int> print_deck(vector<int>deck)
{
    for (int i = 0; i < deck.size(); i++)
    {
      cout << deck[i] << " , ";
      if (i % 13 == 0) cout << endl;
    }
    return deck;
}


int main()
{   

    system("CLS");
    vector <int> deck = generate_deck();
    deck = shuffle(deck);
    print_deck(deck);

    return 0;
}
