#include <iostream>
#include "mll.h"

void createEmptyMLL(MLLCustomerData &L) {
    L.first = nullptr;
}
void createEmptyDLL(DLLProducts &L) {
    L.first = nullptr;
    L.last = nullptr;
}
MLLCustomerNodePtr createCustomerNode(infotypeCustomer info) {
    MLLCustomerNodePtr p = new MLLCustomerNode;
    p->info = info;
    p->firstChild = nullptr;
    p->next = nullptr;
    return p;
}
MLLShoppingCartNodePtr createCartNode(infotypeShoppingCart data) {
    MLLShoppingCartNodePtr c = new MLLShoppingCartNode;
    c->data = data;
    c->next = nullptr;
    return c;
}
DLLProductsNodePtr createProductNode(infotypeProducts data) { 
    DLLProductsNodePtr p = new DLLProductsNode;
    p->data = data;
    p->next = nullptr;
    return p;
}
//THIS MUCH ADDED TO THE MLL.H FILE. PLS MOVE ONCE ADDED
void insertCustomerNode(MLLCustomerData &L, MLLCustomerNodePtr p) {
    //insert first implementation
    p->next = L.first;
    L.first = p;
}
void insertShoppingCartNode(MLLCustomerNodePtr parent, MLLShoppingCartNodePtr c) {
    c->next = parent->firstChild;
    parent->firstChild = c;
}
void insertProductNode(DLLProducts &L, DLLProductsNodePtr p) {
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
MLLCustomerNodePtr deleteCustomerNode(MLLCustomerData &L, int customerID) {
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
MLLShoppingCartNodePtr deleteShoppingCartNode(MLLCustomerNodePtr parent, int productID) {
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
DLLProductsNodePtr deleteProductNode(DLLProducts &L, int productID) {
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
    } else {
        prev->next = p->next; // Bypass the node to be deleted
    }
    p->next = nullptr; // Isolate the node
    //because some shopping carts may still reference this product node, we will have to delete it later
    //keep that it note

    return p;
}
void printCustomers(MLLCustomerData L){ //prints out customer info for admins
    MLLCustomerNodePtr p = L.first;
    while(p != nullptr){
        printf("%-4d \t| %s\n",p->info.id, p->info.name);
        p = p->next;
    }
}
void printShoppingCart(MLLCustomerNode L){ //prints out things in shopping cart for customers
    MLLShoppingCartNodePtr p = L.firstChild;
    while(p != nullptr){
        printf("%-4d \t| %30s | %-4d \n",p->data.product->data.productID, p->data.product->data.productName,p->data.quantity);
        p = p->next;
    }
}
void printProducts(DLLProducts L){
    DLLProductsNodePtr p = L.first;
    while(p != nullptr){
        printf("%-4d \t| %30s | %-4d \n",p->data.productID, p->data.productName,p->data.stock,p->data.price);
        p = p->next;
    }
}