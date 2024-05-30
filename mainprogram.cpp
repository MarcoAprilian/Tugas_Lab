int main()
{   char pil;
    ulang:
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
            
            ulang1:
            cout<<endl;
            cout<<"Apakah anda ingin bermain lagi? (Y/N)"<<endl;
            cin>>pil;

            
            if (tolower(pil) == 'y')
                goto ulang;

            else if (tolower(pil) == 'n')
                {
                    cout<<"Terimakasih telah bermain";
                }
            else
                goto ulang1;


            return 0;

}
