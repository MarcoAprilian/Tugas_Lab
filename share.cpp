auto share(vector <int> deck){
    vector <int> pile;
    pile.push_back(deck[0]);
    return pile;
}


int main()
{   

    system("CLS");
    vector <int> deck = generate_deck();
    deck = shuffle(deck);
    print_deck(deck);
    vector <int> tangan = share(deck);
    deck.erase(deck.begin());
    cout<<endl;
    cout<<deck[3];
    cout<<endl;
    cout<<"..."<<tangan[0]<<endl;
    print_deck(deck);
    return 0;
}
