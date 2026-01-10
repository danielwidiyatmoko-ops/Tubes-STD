#include <iostream>
#include "ui.h"

using namespace std;

void uikece() {
    int mainChoice;

    do {
        cout << "=============================";
        cout << "\nTOKO ONLINE TELU JEMPOL\n";
        cout << "=============================";
        cout << "1. Login\n";
        cout << "2. Sign Up\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            int loginChoice;
            cout << "\n--- LOGIN ---\n";
            cout << "1. Admin\n";
            cout << "2. Pengguna\n";
            cout << "0. Back\n";
            cout << "Pilihan: ";
            cin >> loginChoice;

            if (loginChoice == 1) {
                int adminMenu;
                do {
                    cout << "\nADMIN PAGE\n";
                    cout << "1. Melihat Produk\n";
                    cout << "2. Mengatur Produk\n";
                    cout << "3. Lihat Pengguna\n";
                    cout << "0. Logout\n";
                    cout << "Pilihan: ";
                    cin >> adminMenu;

                    if (adminMenu != 0)
                        cout << "[Admin feature placeholder]\n";

                } while (adminMenu != 0);
            }

            else if (loginChoice == 2) {
                int userMenu;
                do {
                    cout << "\nUSER PAGE\n";
                    cout << "1. Lihat Produk\n";
                    cout << "2. Lihat Keranjang\n";
                    cout << "3. Beli\n";
                    cout << "0. Logout\n";
                    cout << "Pilihan: ";
                    cin >> userMenu;

                    if (userMenu != 0)
                        cout << "[User feature placeholder]\n";

                } while (userMenu != 0);
            }
        }

        else if (mainChoice == 2) {
            cout << "\n--- SIGN UP ---\n";
            cout << "[Sign up placeholder]\n";
        }

    } while (mainChoice != 0);
}