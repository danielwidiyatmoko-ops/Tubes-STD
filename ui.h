#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED
#include <iostream>
#include "mll.h"
using namespace std;
void uikece(MLLCustomerData &L, DLLProducts &P);
void uikeceuser(MLLCustomerNodePtr &C, DLLProducts &L);
void uikeceadmin(MLLCustomerData &C, DLLProducts &L);
#endif // UI_H_INCLUDED