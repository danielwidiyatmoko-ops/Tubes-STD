#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

using namespace std;
// primitive data structure for the Multi-Level Linked List (can be turned to a graph if you want so thats cool)
typedef struct MLLCustomerNode *MLLCustomerNodePtr; //pointer to MLL Customer Node which are users
typedef struct MLLShoppingCartNode *MLLShoppingCartNodePtr; //pointer to MLL Shopping Cart Node which are products added to shopping cart
typedef struct DLLProductsNode *DLLProductsNodePtr; //pointer to DLL Products Node which are products
/************************
 Diagram of MLL structure using SLL Variant of MLL:
 connected to an DLL of products available in the store

  MLL
   |
 first -> [ PNode ] -> [ PNode ] -> NULL
              |            |-> [ CNode ] -> NULL
              v                     |
            [ CNode ] -> [ CNode ] -> NULL
                |           |       |
SLL             |           |--------
   |            v           v
    first -> [ PNode ] <> [ PNode ] -> last

 ***********************/
int TOTALCUSTOMERS = 0; //global variable to keep track of total customers for ID assignment
int TOTALPRODUCTS = 0; //global variable to keep track of total products for ID assignment
//may not be the best practice but whatever for this simple project it's fine
//STRUCTS FOR THE LISTS
struct MLLCustomerNode {
    infotypeCustomer info;                      
    MLLShoppingCartNodePtr firstChild;       
    MLLCustomerNodePtr next;            
};
 struct MLLShoppingCartNode { //child node of the Customer Node; contains products added to shopping cart
    infotypeShoppingCart data;                     
    MLLShoppingCartNodePtr next;            
};
struct DLLProductsNode { //double linked list for products
    infotypeProducts data;
    DLLProductsNodePtr next;
    DLLProductsNodePtr prev;
};
struct infotypeCustomer { //infotype for customer/user
    int id;
    string name;
    string password;
};

struct infotypeShoppingCart { //infotype for product in shopping cart
    DLLProductsNodePtr product; //pointer to the product in the DLL
    int quantity;
};
struct infotypeProducts{
    int productID;
    string productName;
    int stock;
    int price;
};
struct MLLCustomerData {
    MLLCustomerNodePtr first;      // Pointer to the head of the parent node list
};
struct DLLProducts {
    DLLProductsNodePtr first; // Pointer to the head of the products list
    DLLProductsNodePtr last;  // Pointer to the tail of the products list
};
//FUNCTION PROTOTYPES
void createEmptyMLL(MLLCustomerData &L);
void createEmptyDLL(DLLProducts &L);
MLLCustomerNodePtr createCustomerNode(infotypeCustomer info);
MLLShoppingCartNodePtr createCartNode(infotypeShoppingCart data);
DLLProductsNodePtr createProductNode(infotypeProducts data);
void insertCustomerNode(MLLCustomerData &L, MLLCustomerNodePtr p);
void insertShoppingCartNode(MLLCustomerNodePtr parent, MLLShoppingCartNodePtr c);
void insertProductNode(DLLProducts &L, DLLProductsNodePtr p);
MLLShoppingCartNodePtr deleteShoppingCartNode(MLLCustomerNodePtr parent, int productID);
DLLProductsNodePtr deleteProductNode(DLLProducts &L, int productID);
void printCustomers(MLLCustomerData L);
int printShoppingCart(MLLCustomerNodePtr L);
void printProducts(DLLProducts L);
MLLCustomerNodePtr findCustomerByID(MLLCustomerData L, int customerID);
MLLShoppingCartNodePtr findCartItemByProductID(MLLCustomerNodePtr parent, int productID);
MLLShoppingCartNodePtr findCartItemByProductName(MLLCustomerNodePtr parent, string productName);
DLLProductsNodePtr findProductByID(DLLProducts L, int productID);
DLLProductsNodePtr findProductByName(DLLProducts L, string productName);
void editCustomerInfo(MLLCustomerNodePtr customer,int code, string newName, string newPassword);
void editCartItemQuantity(MLLShoppingCartNodePtr cartItem, int newQuantitytoAdd);
void editProductInfo(DLLProductsNodePtr product, int code, string newName, int newStock, int newPrice);
#endif // MLL_H_INCLUDED