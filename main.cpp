#include <iostream>
#include <conio.h>
#include "UI.h"
#include "blackjack.h"

using namespace std;

int main() 
{
    char pilihan;

    ulang:

        system("CLS");

    cout << "  =====================================================================================   " << endl;
    cout << "||   *       *  * * *  *     *  * * *      * * *    * * *   *       *  * * *   * * *   || " << endl;
    cout << "||   * *   * *    *    * *   *    *       *        *     *  * *   * *  *      *        || " << endl;
    cout << "||   *   *   *    *    *  *  *    *       *   * *  * * * *  *   *   *  * * *    * *    || " << endl;
    cout << "||   *       *    *    *   * *    *       *     *  *     *  *       *  *            *  || " << endl;
    cout << "||   *       *  * * *  *     *  * * *      * * *   *     *  *       *  * * *   * * *   || " << endl;
    cout << "  =====================================================================================   " << endl;
    cout << "||                                                                                     || " << endl;
    cout << "||   1. Blackjack                                                                      || " << endl;
    cout << "||   2. Go Fish                                                                        || " << endl;
    cout << "||   3. Coming soon...                                                                 || " << endl;
    cout << "||                                                                                     || " << endl;
    cout << "||                                                                                     || " << endl;
    cout << "||                                                                      credits = (1)  || " << endl;
    cout << "  =====================================================================================   " << endl;    
    cout << "                                   Pilihan Anda : ";
    pilihan = _getch();

    if (pilihan == '1') Blackjack();
    else if (pilihan == '2') tampilanUtama_GoFish();
    else goto ulang;
}