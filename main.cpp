#include "mll.h"
#include "ui.h"
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
int TOTALCUSTOMERS= 4; //global variable to keep track of total customers for ID assignment
int TOTALPRODUCTS =4; //global variable to keep track of total products for ID assignment
 //may not be the best practice but whatever for this simple project it's fine

int main() {
    MLLCustomerData CustomerData;
    DLLProducts ProductsList;
    createEmptyMLL(CustomerData);
    createEmptyDLL(ProductsList);
    insertSimpleProducts(ProductsList);
    /*printProducts(ProductsList);
    DLLProductsNodePtr p = findProductByID(ProductsList, 2);
    editProductInfo(p,3,"",0,16500);
    printProducts(ProductsList);
    p = findProductByID(ProductsList, 3);
    editProductInfo(p,4,"teto_dapoteto",-25,12500);
    printProducts(ProductsList); this was for testing if the shit works. just in case*/ 
    uikece(CustomerData, ProductsList);
    printCustomers(CustomerData);
    printProducts(ProductsList);
    cout << "Terima Kasih, Sampai Jumpa!" << endl;
    return 0;
}