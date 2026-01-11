#include "mll.h"
using namespace std;
//CREATING/INITIALIZING THE LISTS
void createEmptyMLL(MLLCustomerData &L) { //initialize MLL (Customer Data and their Shopping Carts)
    L.first = nullptr;
}
void createEmptyDLL(DLLProducts &L) { //initialize DLL (Products List)
    L.first = nullptr;
    L.last = nullptr;
}
//CREATING NODES FOR THE LISTS
MLLCustomerNodePtr createCustomerNode(infotypeCustomer info) { //creates a new customer node, returns address of the new node
    MLLCustomerNodePtr p = new MLLCustomerNode;
    p->info = info;
    p->firstChild = nullptr;
    p->next = nullptr;
    return p;
}
MLLShoppingCartNodePtr createCartNode(infotypeShoppingCart data) { //creates a new shopping cart node, returns address of the new node
    MLLShoppingCartNodePtr c = new MLLShoppingCartNode;
    c->data = data;
    c->next = nullptr;
    return c;
}
DLLProductsNodePtr createProductNode(infotypeProducts data) { //creates a new product node, returns address of the new node
    DLLProductsNodePtr p = new DLLProductsNode;
    p->data = data;
    p->prev = nullptr;
    p->next = nullptr;
    return p;
}
//INSERTING NODES INTO THE LISTS
void insertCustomerNode(MLLCustomerData &L, MLLCustomerNodePtr p) { //Inserts customer node into MLL via insert first
    //insert first implementation
    p->next = L.first;
    L.first = p;
}
void insertShoppingCartNode(MLLCustomerNodePtr parent, MLLShoppingCartNodePtr c) { //Inserts shopping cart node into the customer's shopping cart via insert first
    c->next = parent->firstChild;
    parent->firstChild = c;
}
void insertProductNode(DLLProducts &L, DLLProductsNodePtr p) {//inserts product node into DLL via insert last
    //insert last implementation
    if (L.first == nullptr) {
        L.first = p;
        L.last = p;
    } else {
        L.last->next = p;
        p->prev = L.last;
        L.last = p;
    }
}
//DELETING NODES FROM THE LISTS
MLLCustomerNodePtr deleteCustomerNode(MLLCustomerData &L, int customerID) { //deletes customer node from MLL by customer ID, returns the deleted node before deallocation
    MLLCustomerNodePtr p = L.first;
    MLLCustomerNodePtr prev = nullptr;
    while (p != nullptr && p->info.id != customerID) {
        prev = p;
        p = p->next;
    }
    if (p == nullptr) {
        return nullptr; // Customer not found
    } else if (prev == nullptr) {
        L.first = p->next; // Deleting the first node
    } else {
        prev->next = p->next; // Bypass the node to be deleted
    }
    p->next = nullptr; // Isolate the node
    return p;
}
MLLShoppingCartNodePtr deleteShoppingCartNode(MLLCustomerNodePtr parent, int productID) { //deletes shopping cart node from a customer's shopping cart by product ID, returns the deleted node before deallocation
    MLLShoppingCartNodePtr c = parent->firstChild;
    MLLShoppingCartNodePtr prev = nullptr;
    while (c != nullptr && c->data.product->data.productID != productID) {
        prev = c;
        c = c->next;
    }
    if (c == nullptr) {
        return nullptr; // Product not found in shopping cart
    } else if (prev == nullptr) {
        parent->firstChild = c->next; // Deleting the first child node
    } else {
        prev->next = c->next; // Bypass the node to be deleted
    }
    c->next = nullptr; // Isolate the node
    return c;
}
DLLProductsNodePtr deleteProductNode(DLLProducts &L, int productID) {//deletes product node from DLL by product ID, returns the deleted node before deallocation
    DLLProductsNodePtr p = L.first;
    DLLProductsNodePtr prev = nullptr;
    while (p != nullptr && p->data.productID != productID) {
        prev = p;
        p = p->next;
    }
    if (p == nullptr) {
        return nullptr; // Product not found
    } else if (prev == nullptr) {
        L.first = p->next; // Deleting the first node
        if (L.first != nullptr) {
            L.first->prev = nullptr;
        } else {
            L.last = nullptr; // List is now empty
        }
    } else {
        prev->next = p->next; // Bypass the node to be deleted
        if(p->next != nullptr) {
            p->next->prev = prev;
        } else {
            L.last = prev; // Deleted the last node
        }
    }
    p->next = nullptr; // Isolate the node
    //because some shopping carts may still reference this product node, we will have to delete it later
    //keep that it note

    return p;
}
//PRINTING THE LISTS
void printCustomers(MLLCustomerData L){ //prints out customer info; for admins
    MLLCustomerNodePtr p = L.first;
    printf("%-4s \t| %s\n","ID","Name");
    while(p != nullptr){
        printf("%-4d \t| %s\n",p->info.id, p->info.name.c_str());
        p = p->next;
    }
}
int printShoppingCart(MLLCustomerNodePtr L){ //prints out things in shopping cart; for customers; also counts total price and returns it
    MLLShoppingCartNodePtr p = L->firstChild;
    int totalPrice = 0;
    printf("%-4s \t| %30s | %-6s | %-7s\n","ID","Product Name","Qty","Total Price");
    while(p != nullptr){
        printf("%-4d \t| %30s | %-6d | Rp%7d\n",p->data.product->data.productID, p->data.product->data.productName.c_str(), p->data.quantity, p->data.product->data.price * p->data.quantity); //i am so sorry for this mess thisis what happens when you connect a linked list to another linked list ;-;
        totalPrice += p->data.product->data.price * p->data.quantity;
        p = p->next;
    }
    return totalPrice;
}
void printProducts(DLLProducts L){ //prints out products in the products list; for admins and customers
    DLLProductsNodePtr p = L.first;
    printf("%-4s | %30s | %-6s | %-7s\n","ID","Product Name","Stock","Price");
    while(p != nullptr){
        printf("%-4d | %30s | %-6d | Rp%-7d\n",p->data.productID, p->data.productName.c_str(),p->data.stock,p->data.price);
        p = p->next;
    }
}
//FINDING NODES IN THE LISTS
MLLCustomerNodePtr findCustomerByID(MLLCustomerData L, int customerID) {//finds customer node in MLL by customer ID, returns the node pointer if found, nullptr if not found
    MLLCustomerNodePtr p = L.first;
    while (p != nullptr) {
        if (p->info.id == customerID) {
            return p; // Customer found
        }
        p = p->next;
    }
    return nullptr; // Customer not found
}
MLLCustomerNodePtr findCustomerByName(MLLCustomerData L, string name) {//finds customer node in MLL by customer ID, returns the node pointer if found, nullptr if not found
    MLLCustomerNodePtr p = L.first;
    while (p != nullptr) {
        if (p->info.name == name) {
            return p; // Customer found
        }
        p = p->next;
    }
    return nullptr; // Customer not found
}

MLLShoppingCartNodePtr findCartItemByProductID(MLLCustomerNodePtr parent, int productID) {//finds shopping cart node in a customer's shopping cart by product ID, returns the node pointer if found, nullptr if not found
    MLLShoppingCartNodePtr c = parent->firstChild;
    while (c != nullptr) {
        if (c->data.product->data.productID == productID) {
            return c; // Product found in shopping cart
        }
        c = c->next;
    }
    return nullptr; // Product not found in shopping cart
}
MLLShoppingCartNodePtr findCartItemByProductName(MLLCustomerNodePtr parent, string productName) {//finds shopping cart node in a customer's shopping cart by product name, returns the node pointer if found, nullptr if not found
    MLLShoppingCartNodePtr c = parent->firstChild;
    while (c != nullptr) {
        if (c->data.product->data.productName == productName) {
            return c; // Product found in shopping cart
        }
        c = c->next;
    }
    return nullptr; // Product not found in shopping cart
}
DLLProductsNodePtr findProductByID(DLLProducts L, int productID) {//finds product node in DLL by product ID, returns the node pointer if found, nullptr if not found
    DLLProductsNodePtr p = L.first;
    while (p != nullptr) {
        if (p->data.productID == productID) {
            return p; // Product found
        }
        p = p->next;
    }
    return nullptr; // Product not found
}
DLLProductsNodePtr findProductByName(DLLProducts L, string productName) {//finds product node in DLL by product name, returns the node pointer if found, nullptr if not found
    DLLProductsNodePtr p = L.first;
    while (p != nullptr) {
        if (p->data.productName == productName) {
            return p; // Product found
        }
        p = p->next;
    }
    return nullptr; // Product not found
}
