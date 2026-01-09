#include <iostream>
#include "mll.h"
//CREATING/INITIALIZING THE LISTS
void createEmptyMLL(MLLCustomerData &L) {
    L.first = nullptr;
}
void createEmptyDLL(DLLProducts &L) {
    L.first = nullptr;
    L.last = nullptr;
}
//CREATING NODES FOR THE LISTS
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
//INSERTING NODES INTO THE LISTS
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
//DELETING NODES FROM THE LISTS
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
//PRINTING THE LISTS
void printCustomers(MLLCustomerData L){ //prints out customer info for admins
    MLLCustomerNodePtr p = L.first;
    printf("%-4s \t| %s\n","ID","Name");
    while(p != nullptr){
        printf("%-4d \t| %s\n",p->info.id, p->info.name);
        p = p->next;
    }
}
void printShoppingCart(MLLCustomerNode L){ //prints out things in shopping cart for customers
    MLLShoppingCartNodePtr p = L.firstChild;
    printf("%-4s \t| %30s | %-4s | %-7s\n","ID","Product Name","Qty","Price");
    while(p != nullptr){
        printf("%-4d \t| %30s | %-4d | Rp%7d\n",p->data.product->data.productID, p->data.product->data.productName, p->data.quantity, p->data.product->data.price); //i am so sorry for this mess thisis what happens when you connect a linked list to another linked list ;-;
        p = p->next;
    }
}
void printProducts(DLLProducts L){
    DLLProductsNodePtr p = L.first;
    printf("%-4s \t| %30s | %-4s | %-7s\n","ID","Product Name","Stock","Price");
    while(p != nullptr){
        printf("%-4d \t| %30s | %-4d | Rp%7d\n",p->data.productID, p->data.productName,p->data.stock,p->data.price);
        p = p->next;
    }
}
//FINDING NODES IN THE LISTS
MLLCustomerNodePtr findCustomerByID(MLLCustomerData L, int customerID) {
    MLLCustomerNodePtr p = L.first;
    while (p != nullptr) {
        if (p->info.id == customerID) {
            return p; // Customer found
        }
        p = p->next;
    }
    return nullptr; // Customer not found
}
MLLShoppingCartNodePtr findCartItemByProductID(MLLCustomerNodePtr parent, int productID) {
    MLLShoppingCartNodePtr c = parent->firstChild;
    while (c != nullptr) {
        if (c->data.product->data.productID == productID) {
            return c; // Product found in shopping cart
        }
        c = c->next;
    }
    return nullptr; // Product not found in shopping cart
}
DLLProductsNodePtr findProductByID(DLLProducts L, int productID) {
    DLLProductsNodePtr p = L.first;
    while (p != nullptr) {
        if (p->data.productID == productID) {
            return p; // Product found
        }
        p = p->next;
    }
    return nullptr; // Product not found
}
//EDIT NODES IN THE LISTS
void editCustomerInfo(MLLCustomerNodePtr customer,int code, string newName, string newPassword) { // int code is used for basically if they want to change name or password or both
    switch (code) {
        case 1:
            customer->info.name = newName;
            break;
        case 2:
            customer->info.password = newPassword;
            break;
        case 3:
            customer->info.name = newName;
            customer->info.password = newPassword;
            break;
        default:
            break;
    }
};
void editCartItemQuantity(MLLShoppingCartNodePtr cartItem, int newQuantitytoAdd) { //newQuantitytoAdd is the amount to add or remove to the existing quantity
    if (cartItem->data.quantity + newQuantitytoAdd > 0) {
        cartItem->data.quantity += newQuantitytoAdd;
    } else{
        cout << "Jumlah harus lebih besar dari nol." << endl;
    }
}
void editProductInfo(DLLProductsNodePtr product, int code, string newName, int newStock, int newPrice) {
    switch (code) {
        case 1:
            product->data.productName = newName;
            break;
        case 2:
            if(product->data.stock + newStock >= 0){
                product->data.stock += newStock;
            } else {
                cout << "Stok tidak boleh negatif." << endl;
            }
        case 3:
            product->data.price = newPrice;
            break;
        case 4:
            product->data.productName = newName;
            if(product->data.stock + newStock >= 0){
                product->data.stock += newStock;
            } else {
                cout << "Stok tidak boleh negatif." << endl;
            }
            product->data.price = newPrice;
            break;
        default:
            break;
    }
};
