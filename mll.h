#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

using namespace std;
// primitive data structure for the Multi-Level Linked List (can be turned to a graph if you want so thats cool)
typedef struct MLLCustomerNode *MLLCustomerNodePtr; //pointer to MLL Customer Node which are users
typedef struct MLLShoppingCartNode *MLLShoppingCartNodePtr; //pointer to MLL Shopping Cart Node which are products added to shopping cart
typedef struct SLLProductsNode *SLLProductsNodePtr; //pointer to SLL Products Node which are products
/************************
 Diagram of MLL structure using SLL Variant of MLL:

  MLL
   |
 first -> [ PNode ] -> [ PNode ] -> NULL
              |            |-> [ CNode ] -> NULL
              v
            [ CNode ] -> [ CNode ] -> NULL
 ***********************/
struct MLLCustomerNode {
    infotypeCustomer info;                      
    MLLShoppingCartNodePtr childHead;       
    MLLCustomerNodePtr next;            
};
 struct MLLShoppingCartNode { //child node of the Customer Node; contains products added to shopping cart
    infotypeShoppingCart data;                     
    MLLShoppingCartNodePtr next;            
};
struct SLLProductsNode { //single linked list for products
    infotypeProducts data;
    SLLProductsNodePtr next;
};
struct infotypeCustomer { //infotype for customer/user
    int id;
    string name;
    string password;
};

struct infotypeShoppingCart { //infotype for product in shopping cart
    SLLProductsNodePtr product; //pointer to the product in the SLL
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
struct SLLProducts {
    SLLProductsNodePtr first; // Pointer to the head of the products list
};

#endif // MLL_H_INCLUDED