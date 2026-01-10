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

 brrrrrr
****************************************/


int main() {
    MLLCustomerData CustomerData;
    DLLProducts ProductsList;
    createEmptyMLL(CustomerData);
    createEmptyDLL(ProductsList);
    insertSimpleProducts(ProductsList);
    printProducts(ProductsList);
    DLLProductsNodePtr p = findProductByID(ProductsList, 2);
    editProductInfo(p,3,"",0,16500);
    printProducts(ProductsList);
    p = findProductByID(ProductsList, 3);
    editProductInfo(p,4,"teto_dapoteto",-25,12500);
    printProducts(ProductsList);

    cout << "Terima Kasih, Sampai Jumpa!" << endl;
    return 0;
}