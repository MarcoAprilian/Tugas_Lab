#ifndef UI_H
#define UI_H

#include <iostream>
#include <conio.h>
using namespace std;

void garis()
{
    cout << "==================================================================================" << endl;
}

void UI_Blackjack()
{
    garis();
    cout << "  * * *    *         * *     * * *   *     *        *    * *     * * *   *    *  "  << endl;
    cout << "  *     *  *       *     *  *        *   *          *  *     *  *        *   *   "  << endl;
    cout << "  * * *    *       * * * *  *        * *            *  * * * *  *        * *     "  << endl;
    cout << "  *     *  *       *     *  *        *   *     *    *  *     *  *        *   *   "  << endl;
    cout << "  * * *    * * *   *     *   * * *   *     *    * * *  *     *   * * *   *    *  "  << endl;
    garis();
}

void UI_GoFish()
{
    garis();   
    cout << "         * * *      * * *       * * * *  * * * * *    * * *    *       *         " << endl;
    cout << "       *       *  *       *     *            *      *       *  *       *         " << endl;
    cout << "       *          *       *     * * * *      *        *        *       *         " << endl;
    cout << "       *   * * *  *       *     *            *           *     * * * * *         " << endl;
    cout << "       *       *  *       *     *            *      *       *  *       *         " << endl;
    cout << "         * * *      * * *       *        * * * * *    * * *    *       *         " << endl;
    garis();        
}

void manual_Blackjack()
{
        system("CLS");

        garis();
    cout << "                                  How to Play                                  " << endl;
        garis();
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
        garis();
        cout << endl;
}

void manual_GoFish()
{
    system("CLS");

        garis();
    cout << "                                  How to Play                                  " << endl;
        garis();
}

auto tampilanUtama_Blackjack()
{
    char pilihan;

    ulang:

        system("CLS");

    UI_Blackjack();

    cout << "                _____________________________________________ " << endl;
    cout << "               |                                             |" << endl;
    cout << "               |                                       *     |" << endl;
    cout << "               |                                      ***    |" << endl;
    cout << "               |                                     *****   |" << endl;
    cout << "               |                                       *     |" << endl;
    cout << "               |                                      ***    |" << endl;
    cout << "               |                                             |" << endl;
    cout << "               |          * * * * *         * * *            |" << endl;
    cout << "               |        *           *     *     *            |" << endl;
    cout << "               |      *            *    *       *            |" << endl;
    cout << "               |       *          *             *            |" << endl;
    cout << "               |                *               *            |" << endl;
    cout << "               |              *                 *            |" << endl;
    cout << "               |            *                   *            |" << endl;
    cout << "               |          *                     *            |" << endl;
    cout << "               |        *                       *            |" << endl;
    cout << "               |       * * * * * * *     * * * * * * * *     |" << endl;
    cout << "               |                                             |" << endl;
    cout << "               |    *                                        |" << endl;
    cout << "               |   ***                                       |" << endl;
    cout << "               |  *****                                      |" << endl;
    cout << "               |    *                                        |" << endl;
    cout << "               |   ***                                       |" << endl;
    cout << "               |_____________________________________________|" << endl;
    cout << endl;
    cout << "        =============================================================  " << endl;
    cout << "      ||   1. Ready, Set, Play!!                                     ||" << endl;
    cout << "      ||   2. How to Play                                            ||" << endl;
    cout << "        =============================================================  " << endl;
    cout << "                                Pilihan Anda : ";
    pilihan = _getch();

    if (pilihan == '1') return 0;
    else if (pilihan == '2')
        {
            manual_Blackjack();

                system("pause");

            goto ulang;
        }
    else goto ulang;
}

auto tampilanUtama_GoFish()
{
    char pilihan;

    ulang:

        system("CLS");

    cout << "                      *****                                                                           *****                         " << endl;
    cout << "                      ***** ~~~~~~~~~ ~~~~~~~~~~~ ~~~~~~~~~~~~~  ~~~~~~~~~~~~~~~ ~~~~ ~~~~~~~~~~~~~~~ *****                         " << endl;
    cout << "                  *****                                                                                   *****                     " << endl;
    cout << "              *****                        _____________________________________________                      *****                 " << endl;
    cout << "          ****                            |                                             |                          ****             " << endl;  
    cout << "          ****                            |                                       *     |                          ****             " << endl;
    cout << "       ****                               |                                      ***    |        ><(((('>             ****          " << endl;
    cout << "       ****                               |                                     *****   |                             ****          " << endl;
    cout << "    ****                                  |                                       *     |                                ****       " << endl;
    cout << "  ****                                    |                                      ***    |                                  ****     " << endl;
    cout << "  ****                                    |                                             |                                  ****     " << endl;
    cout << " ***                      ()              |             * * * * * * * * * *             |                                    ***    " << endl;
    cout << " ***                                      |             *                *              |                                    ***    " << endl;
    cout << " ***                ()                    |                             *               |                                    ***    " << endl;
    cout << " **                                       |                            *                |                         ()          **    " << endl;
    cout << " ***                   ()                 |                           *                 |                                    ***    " << endl;
    cout << " ***                                      |                          *                  |                        ()          ***    " << endl;
    cout << " ***            ><(((('>                  |                         *                   |                                    ***    " << endl;
    cout << " **                     ><(((('>          |                        *                    |           ><(((('>                  **    " << endl;
    cout << " ***       ><(((('>                       |                       *                     |                                    ***    " << endl;
    cout << " ***                                      |   *                  *                      |                                    ***    " << endl;
    cout << " ***                                      |  ***                                        |                                    ***    " << endl;
    cout << " **                                   =======****  ======         =======  =========    =======   ||     ||                   **    " << endl;
    cout << " ***                                ||    |   *  ||  ><((||*'>   ||           ||      |||         ||     ||                  ***    " << endl;
    cout << " ***                                ||    ===||* ||      ||      ||======     ||      |||         ||=====||                  ***    " << endl;
    cout << " ***                                ||    |__||__||______||______||___________||><((*'>|======    ||=====||                  ***    " << endl;
    cout << "  ****                              ||      //   ||      ||      ||           ||              ||  ||     ||                ****     " << endl;
    cout << "  ****                                ======       ======        ||        =========  ========    ||     ||                ****     " << endl;
    cout << "     ****                             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                ****        " << endl;
    cout << "         ****             ~~~~~~~~~~~/  ......               .....           ....             .....     |~~~~~~~~~~ ****            " << endl;
    cout << "         **** ~~~~~~~~~~~/                      .....                            .....                              ****            " << endl;
    cout << "           *****                     .......                           .....                        .....        *****              " << endl;
    cout << "               *******    ......                     .....        .....               .....                *******                  " << endl;
    cout << "                     ***************************************************************************************                        " << endl;
    
      cout << endl;

    cout << "                                    =============================================================   " << endl;
    cout << "                                   ||   1. Ready, Set, Play!!                                     ||" << endl;
    cout << "                                   ||   2. How to Play                                            ||" << endl;
    cout << "                                    =============================================================   " << endl;
    cout << "                                                              Pilihan Anda : ";
    pilihan = _getch();

    if (pilihan == '1') return 0;
    else if (pilihan == '2')
        {
            manual_GoFish();

                system("pause");

            goto ulang;
        }
    else goto ulang;
}

void GameOver()
{
        system("CLS");
        
    cout << "  =====================================================================================   " << endl;
    cout << "||   *       *  * * *  *     *  * * *      * * *    * * *   *       *  * * *   * * *   || " << endl;
    cout << "||   * *   * *    *    * *   *    *       *        *     *  * *   * *  *      *        || " << endl;
    cout << "||   *   *   *    *    *  *  *    *       *   * *  * * * *  *   *   *  * * *    * *    || " << endl;
    cout << "||   *       *    *    *   * *    *       *     *  *     *  *       *  *            *  || " << endl;
    cout << "||   *       *  * * *  *     *  * * *      * * *   *     *  *       *  * * *   * * *   || " << endl;
    cout << "  =====================================================================================   " << endl;
    cout << "||                                                                                     || " << endl;
    cout << "||                                                                                     || " << endl;
    cout << "||    * * *    * * *   *       *  * * *      * * *   *       *  * * *   * * *          || " << endl;
    cout << "||   *        *     *  * *   * *  *         *     *   *     *   *      *     *         || " << endl;
    cout << "||   *   * *  * * * *  *   *   *  * * *     *     *    *   *    * * *  * * *           || " << endl;
    cout << "||   *     *  *     *  *       *  *         *     *     * *     *      *    *          || " << endl;
    cout << "||    * * *   *     *  *       *  * * *      * * *       *      * * *  *     *         || " << endl;
    cout << "||                                                                                     || " << endl;
    cout << "||                                                                                     || " << endl;
    cout << "||                                                                      credits = (0)  || " << endl;
    cout << "  =====================================================================================   " << endl;    
    system("pause");
}
#endif