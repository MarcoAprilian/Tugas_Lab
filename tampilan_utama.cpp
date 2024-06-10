#include <iostream>
using namespace std;

void UI_atas()
{
    cout << "===============================================================================" << endl;
    cout << "  * * *    *         * *     * * *   *     *        *    * *     * * *   *    *  "  << endl;
    cout << "  *     *  *       *     *  *        *   *          *  *     *  *        *   *   "  << endl;
    cout << "  * * *    *       * * * *  *        * *            *  * * * *  *        * *     "  << endl;
    cout << "  *     *  *       *     *  *        *   *     *    *  *     *  *        *   *   "  << endl;
    cout << "  * * *    * * *   *     *   * * *   *     *    * * *  *     *   * * *   *    *  "  << endl;
    cout << "===============================================================================" << endl;
}

int play()
{
    cout << "Play";

    return 0;
}

int instruksi()
{
        system("CLS");

    cout << "===============================================================================" << endl;
    cout << "                                  How to Play                                  " << endl;
    cout << "===============================================================================" << endl;
    cout << " Tujuan dari permainan ini adalah mencapai kemenangan melawan dealer (bot)     " << endl;
    cout << " dengan cara memiliki kartu di tangan player dengan jumlah paling mendekati    " << endl;
    cout << " angka 21 atau berjumlah 21.                                                   " << endl;
    cout << endl;
    cout << " Cara Main :                                                                   " << endl;
    cout << "  1. Player dan Dealer masing-masing mendapatkan dua buah kartu.               " << endl;
    cout << "  2. Player akan diberikan pilihan 'Hit' dan 'Stand'.                          " << endl;
    cout << "     a. Hit berarti meminta kartu tambahan dari dealer.                        " << endl;
    cout << "     b. Stand berarti tidak meminta kartu tambahan dan mempertahankan          " << endl;
    cout << "        nilai kartu saat ini.                                                  " << endl;
    cout << "  3. Player dikatakan menang (win) jika memiliki kartu dengan jumlah sama      " << endl;
    cout << "     dengan atau kurang dari 21 dan jumlah kartu lebih besar dari dealer.      " << endl;
    cout << "  4. Player dikatakan kalah (bust) jika memiliki kartu dengan jumlah lebih     " << endl;
    cout << "     dari 21 atau jumlah kartu lebih kecil dari dealer.                        " << endl;
    cout << "  5. Player dikatakan push (seri) jika memiliki kartu dengan jumlah sama       " << endl;
    cout << "     dengan jumlah kartu dealer.                                               " << endl;
    cout << "  6. Kartu Jack, Queen, dan King memiliki nilai berupa 10.                     " << endl;
    cout << "  7. Jika player memiliki kartu Ace dan kartu 10/Jack/Queen/King di tangan,    " << endl;
    cout << "     Player langsung dikatakan menang.                                         " << endl;
    cout << "===============================================================================" << endl;
    cout << endl;
    cout << " Press 1 to continue.... ";

    return 0;
}

int main()
{
    int pilihan;
    char space;

    ulang:

        system("CLS");

    UI_atas();

    cout << "              _____________________________________________" << endl;
    cout << "             |                                             |" << endl;
    cout << "             |                                       *     |" << endl;
    cout << "             |                                      ***    |" << endl;
    cout << "             |                                     *****   |" << endl;
    cout << "             |                                       *     |" << endl;
    cout << "             |                                      ***    |" << endl;
    cout << "             |                                             |" << endl;
    cout << "             |          * * * * *         * * *            |" << endl;
    cout << "             |        *           *     *     *            |" << endl;
    cout << "             |      *            *    *       *            |" << endl;
    cout << "             |       *          *             *            |" << endl;
    cout << "             |                *               *            |" << endl;
    cout << "             |              *                 *            |" << endl;
    cout << "             |            *                   *            |" << endl;
    cout << "             |          *                     *            |" << endl;
    cout << "             |        *                       *            |" << endl;
    cout << "             |       * * * * * * *     * * * * * * * *     |" << endl;
    cout << "             |                                             |" << endl;
    cout << "             |    *                                        |" << endl;
    cout << "             |   ***                                       |" << endl;
    cout << "             |  *****                                      |" << endl;
    cout << "             |    *                                        |" << endl;
    cout << "             |   ***                                       |" << endl;
    cout << "             |_____________________________________________|" << endl;
    cout << endl;
    cout << "===============================================================================" << endl;
    cout << " 1. Ready, Set, Play!!                                                         " << endl;
    cout << " 2. How to Play                                                                " << endl;
    cout << " 3. Exit                                                                       " << endl;
    cout << "===============================================================================" << endl;
    cout << " Pilihan Anda : ";
    cin >> pilihan;

    switch (pilihan)
    {
        case 1  : play();
                  break;

        case 2  : instruksi();
                  cin >> space;
                  if (space == '1') goto ulang;
                  break;

        default : break;
    }

    return 0;
    
}   