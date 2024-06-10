#include <iostream>
#include <conio.h>
#include "UI.h"
#include "Blackjack.h"
#include "GoFish.h"

using namespace std;

int main() 
{
    int pilihan;
    int arr[2] = {1,2};

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
    cin >> pilihan;

    if (pilihan == arr[0]) Blackjack();
    else if (pilihan == arr[1]) GoFish();
    else goto ulang;
}
