    int y = 0;
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
                if (pair.second == 3)
                {
                    oppchosen=pair.first;
                } 
                else if (pair.second == 2)
                {
                    oppchosen=pair.first;
                }
                else
                {
                    oppchosen=opphand[0];
                }
            }
