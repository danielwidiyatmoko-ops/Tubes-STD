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
                } else{
                    cout <<"Username atau password salah.\n";
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
    int userMenu, action, total, productID, qty;
    DLLProductsNodePtr prod;
    MLLShoppingCartNodePtr cartitem;
    do {
        cout << "\n=============================\n";
        cout << "USER PAGE\n"; //same thing with the admin page part, split itto a uikeceuser() function. and also since there could be multiple users, thi
        cout << "=============================\n";
        cout << "1. Lihat Produk\n";
        cout << "2. Lihat Keranjang\n";
        cout << "3. Beli\n";
        cout << "0. Logout\n";
        cout << "=============================\n";
        cout << "Pilihan: ";
        cin >> userMenu;
        switch(userMenu){
        case 1:
            printProducts(L);
            //actions that you can do when you see products here (buy the item as much as n or go back)
            cout << "\n--- Produk ---\n";
            cout << "1. Tambah ke Keranjang\n";
            cout << "0. Back\n";
            cout << "--------------\n";
            cout << "Pilihan: ";
            cin >> action;

            if (action == 1) {
                cout << "--------------\n";
                cout << "Masukkan ID Produk: ";
                cin >> productID;
                cout << "Jumlah: ";
                cin >> qty;
                cout << "--------------\n";

                prod = findProductByID(L, productID);
                if (prod != nullptr) {
                    addProductToCart(C, prod, qty);
                } else {
                    cout << "Produk tidak ditemukan.\n";
                }
            }
            break;
        case 2:
            //action that you can do with shopping cart (add, decrease, etc)
            total = printShoppingCart(C);
            cout << "Total sementara: Rp" << total << endl;
            cout << "\n--- Keranjang ---\n";
            cout << "1. Ubah Jumlah\n";
            cout << "2. Hapus Item\n";
            cout << "0. Back\n";
            cout << "-----------------\n";
            cout << "Pilihan: ";
            cin >> action;
            switch(action){
                case 1:
                    cout << "-----------------\n";
                    cout << "Masukkan ID Produk: ";
                    cin >> productID;
                    cout << "Jumlah: ";
                    cin >> qty;
                    cout << "-----------------\n";
                    cartitem = findCartItemByProductID(C, productID);
                    if(cartitem != nullptr){
                        editCartItemQuantity(cartitem,qty);
                    }
                    break;
                case 2:
                    cout << "-----------------\n";
                    cout << "Masukkan ID Produk: ";
                    cin >> productID;
                    cout << "-----------------\n";
                    if(deleteShoppingCartNode(C, productID) != nullptr){
                        cout << "Item berhasil dihapus dari keranjang.\n";
                    } else {
                        cout << "Item tidak ditemukan di keranjang.\n";
                    }
                    break;
                default:
                    //do nothing i guess just go back
                    break;
            }
            break;
        case 3:
            //this just buys everything in the cart. the fucntion is already implemented.
            purchaseCartItems(C);
            break;
        case 0:
            cout << "Logout Successful\n";
            cout << "-----------------\n";
            break;
        default:
            cout <<"Pilihan Tidak ada. Mohon coba lagi.\n";
            break;
        }

    } while (userMenu != 0);
}
void uikeceadmin(MLLCustomerData &C, DLLProducts &L){
    int adminMenu, action; 
    do {
        cout << "\n=============================\n";
        cout << "ADMIN PAGE\n"; //maybe split this admin page to like a uikeceadmin() function.
        cout << "=============================\n";
        cout << "1. Melihat Produk\n";
        cout << "2. Mengatur Produk\n";
        cout << "3. Lihat Pengguna\n";
        cout << "0. Logout\n";
        cout << "=============================\n";
        cout << "Pilihan: ";
        cin >> adminMenu;

        switch(adminMenu){
            case 1:
                printProducts(L);
                //i guess only viewing cuz you already have mengatur produk
                break;
            case 2:
                printProducts(L);
                
                cout << "\n--- Aksi Produk ---\n";
                cout << "1. Tambah Produk\n";
                cout << "2. Edit Produk\n";
                cout << "3. Hapus Produk\n";
                cout << "0. Back\n";
                cout << "-------------------\n";
                cout << "Pilihan: ";
                cin >> action;

                if (action == 1) {
                    string nama;
                    int stock, price;
                    cout << "-------------------\n";
                    cout << "Nama Produk: ";
                    cin.ignore();
                    getline(cin, nama);
                    cout << "Stock: ";
                    cin >> stock;
                    cout << "Harga: ";
                    cin >> price;
                    cout << "-------------------\n";
                    addProducts(L, nama, stock, price);
                    cout << "Produk berhasil ditambahkan.\n";
                } else if (action == 2){
                    int prodID;
                    cout << "ID Produk: ";
                    cin >> prodID;
                    DLLProductsNodePtr prod;
                    prod = findProductByID(L,prodID);
                    if(prod != nullptr){
                    cout << "\n--- Aksi Produk ---\n";
                    cout << "1. Ubah Nama\n";
                    cout << "2. Tambah Jumlah Stok\n";
                    cout << "3. Ubah Harga\n";
                    cout << "4. Semuanya\n";
                    cout << "0. Back\n";
                    cout << "-------------------\n";
                    cout << "Pilihan: ";
                    cin >> action;
                    cout << "-------------------\n";
                    string newname;
                    int newstock,newprice;
                    switch(action){
                        case 1:
                            cout << "Nama Baru: ";    
                            cin >> newname;
                            break;
                        case 2:
                            cout << "Jumlah Stok Tambahan: ";
                            cin >> newstock;
                            break;
                        case 3:
                            cout << "Harga Baru: ";
                            cin >> newprice;
                            break;
                        case 4:
                            cout << "Nama Baru: ";    
                            cin >> newname;
                            cout << "Jumlah Stok Tambahan: ";
                            cin >> newstock;
                            cout << "Harga Baru: ";
                            cin >> newprice;
                            break;
                        default:
                            break;
                    }
                    cout << "-------------------\n";
                    editProductInfo(prod,action,newname,newstock,newprice);
                    }
                } else if (action == 3){
                    int prodID;
                    cout << "ID Produk: ";
                    cin >> prodID;
                    if(deleteProductNode(L, prodID) != nullptr){
                        cout << "Produk berhasil dihapus.\n";
                    } else {
                        cout << "Produk tidak ditemukan.\n";
                    }
                }
                break;
            case 3:
                printCustomers(C);
                break;
            case 0:
                cout << "Logout Successful\n";
                cout << "-----------------\n";
                break;
            default:
                cout <<"Pilihan Tidak ada. Mohon coba lagi.\n\n";
                break;
        }
    } while (adminMenu != 0);
}