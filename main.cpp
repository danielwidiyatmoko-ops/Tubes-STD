#include <iostream>
#include "mll.h"
using namespace std;
/****************************************
 TOKO ONLINE TELU JEMPOL
 THINGS TO DO :
 ADD LOGIN SYSTEM FOR CUSTOMERS AND ADMIN
 ROLES :
 CUSTOMERS : BUYS STUFF AND ADD OR DELETE TO CART;
 ADMIN : MODIFIES PRODUCTS LISTS AND PERHAPS DELETE USERS;
 ALL USERS CAN LOGIN AND LOGOUT AND THEIR SHIT IS SAVED AS LONG AS THE PROGRAM IS RUNNING

 ADD SOME BASIC PRODUCTS SO THAT THERES SOMETHING TO DISPLAY (CURRENTLY DOING IT IN THE insertSimpleProducts)

 MAKE SURE YOU CAN APPEND DATA ON THE PRODUCTS AND SEEIF OUT OF STOCK OR NO.

 IMPLEMENT FUCK ALL MAN

 FOR ALL INTENTS AND PURPOSES, WE DONT REALLY NEED TO CARE ABT MEMORY LEAKS CUZ WHO GIVES A SHIET
****************************************/

void insertSimpleProducts(DLLProducts &L){
    infotypeProducts i;
    i.productID = 1;
    i.productName = "Aqoa Mineral Watre 670ml";
    i.stock = 150;
    i.price = 3500;
    DLLProductsNodePtr p = createProductNode(i);
    insertProductNode(L,p);
    i.productID = 2;
    i.productName = "Sira Rito Roti Tawar 10Pcs";
    i.stock = 50;
    i.price = 15000;
    p = createProductNode(i);
    insertProductNode(L,p);
    i.productID = 3;
    i.productName = "NiceKafe Latte 222ml";
    i.stock = 50;
    i.price = 11000;
    p = createProductNode(i);
    insertProductNode(L,p);

}
int main() {
    MLLCustomerData CustomerData;
    DLLProducts ProductsList;
    createEmptyMLL(CustomerData);
    createEmptyDLL(ProductsList);

    cout << "Hello, World!" << endl;
    return 0;
}