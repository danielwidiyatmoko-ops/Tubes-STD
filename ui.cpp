#include <iostream>
#include "ui.h"

using namespace std;

void uikece(MLLCustomerData &L, DLLProducts &P){
    int mainChoice;
    string uname,pw;
    do {
        cout << "=============================";
        cout << "\nTOKO ONLINE TELU JEMPOL\n";
        cout << "=============================\n";
        cout << "1. Login\n";
        cout << "2. Sign Up\n";
        cout << "0. Keluar\n";
        cout << "=============================\n";
        cout << "Pilihan: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            int loginChoice;
            cout << "\n--- LOGIN ---\n"; //i personally reccomend splitting the admin and user pages to be seperate to different ui functions so no one has to read this mess of spaghetti
            cout << "1. Admin\n";
            cout << "2. Pengguna\n";
            cout << "0. Back\n";
            cout << "-------------\n";
            cout << "Pilihan: ";
            cin >> loginChoice;

            if (loginChoice == 1) {
                cout << "\n--- LOGIN ADMIN ---\n";
                cout << "Username: ";
                cin >> uname;
                cout << "Password: ";
                cin >> pw;
                cout << "-------------------\n";
                if(uname == "admin" && pw == "admin"){ //for the sake of ease just have the admin uname and pw as "admin"
                    uikeceadmin(L,P);
                } else{
                    cout << "Username atau Password Salah.\n";
                }
            } else if (loginChoice == 2) {
                cout << "\n--- LOGIN USERS ---\n";
                cout << "Username: ";
                cin >> uname;
                cout << "Password: ";
                cin >> pw;
                cout << "-------------------\n";
                MLLCustomerNodePtr user = loginCustomer(L,uname,pw);
                if(user != nullptr){
                    uikeceuser(user,P);
                }
            }
        } else if (mainChoice == 2) { //signups are fine done in here cuz its short and simple
            cout << "\n--- SIGN UP ---\n";
            cout << "Username: ";
            cin >> uname;
            cout << "Password: ";
            cin >> pw;
            cout << "---------------\n";
            addCustomer(L,uname,pw);
        }

    } while (mainChoice != 0);
}
void uikeceuser(MLLCustomerNodePtr &C, DLLProducts &L){
    int userMenu;
    do {
        cout << "\n=============================\n";
        cout << "USER PAGE\n"; //same thing with the admin page part, split itto a uikeceuser() function. and also since there could be multiple users, thi
        cout << "=============================\n";
        cout << "1. Lihat Produk\n";
        cout << "2. Lihat Keranjang\n";
        cout << "3. Beli\n";
        cout << "0. Logout\n";
        cout << "Pilihan: ";
        cin >> userMenu;

        switch(userMenu){
            case 1:
                printProducts(L);
                //actions that you can do when you see products here (buy the item as much as n or go back)
                cout << "--- Aksi ---\n";
                cout << "1. Beli Barang\n";
                cout << "0. Back\n";
                break;
            case 2:
                printShoppingCart(C);
                //action that you can do with shopping cart (add, decrease, etc)
                break;
            case 3:
                purchaseCartItems(C);
                //this just buys everything in the cart. the fucntion is already implemented.
                break;
            case 0:
                cout << "Logout Successful\n";
                break;
            default:
                cout <<"Pilihat Tidak ada. Mohon coba lagi.\n";
                break;
        }

    } while (userMenu != 0);
}
void uikeceadmin(MLLCustomerData &C, DLLProducts &L){
    int adminMenu; 
    do {
        cout << "\n=============================\n";
        cout << "ADMIN PAGE\n"; //maybe split this admin page to like a uikeceadmin() function.
        cout << "=============================\n";
        cout << "1. Melihat Produk\n";
        cout << "2. Mengatur Produk\n";
        cout << "3. Lihat Pengguna\n";
        cout << "0. Logout\n";
        cout << "Pilihan: ";
        cin >> adminMenu;

        switch(adminMenu){
            case 1:
                printProducts(L);
                //i guess only viewing cuz you already have mengatur produk
                break;
            case 2:
                printProducts(L);
                //actions to manage products (add, edit, delete)
                break;
            case 3:
                printCustomers(C);
                //action to do with customers (edit name, pw, maybe delete)
                break;
            case 0:
                cout << "Logout Successful\n";
                break;
            default:
                cout <<"Pilihat Tidak ada. Mohon coba lagi.\n";
                break;
        }
    } while (adminMenu != 0);
}