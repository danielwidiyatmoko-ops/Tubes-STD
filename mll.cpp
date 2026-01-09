#include <iostream>
#include "mll.h"

void createEmptyMLL(MLLCustomerData &L) {
    L.first = nullptr;
}
void createEmptySLL(SLLProducts &L) {
    L.first = nullptr;
}
MLLCustomerNodePtr createParentNode(infotypeCustomer info) {
    MLLCustomerNodePtr p = new MLLCustomerNode;
    p->info = info;
    p->childHead = nullptr;
    p->next = nullptr;
    return p;
}
MLLShoppingCartNodePtr createChildNode(infotypeShoppingCart data) {
    MLLShoppingCartNodePtr c = new MLLShoppingCartNode;
    c->data = data;
    c->next = nullptr;
    return c;
}
SLLProductsNodePtr createProductNode(infotypeProducts data) {
    SLLProductsNodePtr p = new SLLProductsNode;
    p->data = data;
    p->next = nullptr;
    return p;
}
void insertCustomerNode(MLLCustomerData &L, MLLCustomerNodePtr p) {
    //insert first implementation
    p->next = L.first;
    L.first = p;
}
void insertShoppingCartNode(MLLCustomerNodePtr parent, MLLShoppingCartNodePtr c) {
    c->next = parent->childHead;
    parent->childHead = c;
}
void insertProductNode(SLLProducts &L, SLLProductsNodePtr p) {
    p->next = L.first;
    L.first = p;
}
