#include <iostream>
#include "ui.h"

using namespace std;

void uikece(MLLCustomerData &L, DLLProducts &P){
    int mainChoice;

    do {
        cout << "=============================";
        cout << "\nTOKO ONLINE TELU JEMPOL\n";
        cout << "=============================\n";
        cout << "1. Login\n";
        cout << "2. Sign Up\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            int loginChoice;
            cout << "\n--- LOGIN ---\n"; //i personally reccomend splitting the admin and user pages to be seperate to different ui functions so no one has to read this mess of spaghetti
            cout << "1. Admin\n";
            cout << "2. Pengguna\n";
            cout << "0. Back\n";
            cout << "Pilihan: ";
            cin >> loginChoice;

            if (loginChoice == 1) {
                string uname,pw;
                cout << "Username: ";
                cin >> uname;
                cout << "Password: ";
                cin >> pw;
                if(uname == "admin" && pw == "admin"){ //for the sake of ease just have the admin uname and pw as "admin"
                    int adminMenu; 
                    do {
                        cout << "\nADMIN PAGE\n"; //maybe split this admin page to like a uikeceadmin() function.
                        cout << "1. Melihat Produk\n";
                        cout << "2. Mengatur Produk\n";
                        cout << "3. Lihat Pengguna\n";
                        cout << "0. Logout\n";
                        cout << "Pilihan: ";
                        cin >> adminMenu;

                        if (adminMenu != 0)
                            cout << "[Admin feature placeholder]\n";
                    } while (adminMenu != 0);
                } else{
                    cout << "Username atau Password Salah.\n";
                }
            }

            else if (loginChoice == 2) {
                int userMenu;
                do {
                    cout << "\nUSER PAGE\n"; //same thing with the admin page part, split itto a uikeceuser() function. and also since there could be multiple users, thi
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

        else if (mainChoice == 2) { //signups are fine done in here cuz its short and simple
            cout << "\n--- SIGN UP ---\n";
            string uname,pw;
            cout << "Username: ";
            cin >> uname;
            cout << "Password: ";
            cin >> pw;
            addCustomer(L,uname,pw);
        }

    } while (mainChoice != 0);
}