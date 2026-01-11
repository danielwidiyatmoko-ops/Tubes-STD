#include "mll.h"
using namespace std;

//EDIT NODES IN THE LISTS
void editCustomerInfo(MLLCustomerNodePtr customer,int code, string newName, string newPassword) { // edits information of customer; code 1 = name, 2 = password, 3 = both
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
void editCartItemQuantity(MLLShoppingCartNodePtr cartItem, int newQuantitytoAdd) { //edits quantity of product in shopping cart by adding newQuantitytoAdd (can be negative to reduce quantity)
    if (cartItem->data.quantity + newQuantitytoAdd > 0) {
        cartItem->data.quantity += newQuantitytoAdd;
    } else{
        cout << "Jumlah harus lebih besar dari nol." << endl;
    }
}
void editProductInfo(DLLProductsNodePtr product, int code, string newName, int newStock, int newPrice) { //edits information of product; code 1 = name, 2 = stock, 3 = price, 4 = all
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
            if(product->data.stock + newStock >= 0){
                product->data.productName = newName;
                product->data.stock += newStock;
                product->data.price = newPrice;
            } else {
                cout << "Stok tidak boleh negatif." << endl;
            }
            
            break;
        default:
            break;
    }
}
//PROPER APPLICATION OF FUNCTIONS WITH CHECKS
void addProducts(DLLProducts &L, string nama, int stock, int price){ //adds product to products list after checking if product ID already exists
    infotypeProducts data;
    data.productName = nama;
    data.stock = stock;
    data.price = price;
    if(findProductByName(L, data.productName) == nullptr){
        data.productID = TOTALPRODUCTS++;
        DLLProductsNodePtr p = createProductNode(data);
        insertProductNode(L, p); //what other stupid edge case am i missing?
        cout << "Tambahan Produk Berhasil\n";
    }else{
        cout << "Produk dengan nama tersebut sudah ada." << endl; 
    }
}
void addCustomer(MLLCustomerData &L, string nama, string password){//adds customer to customer data
    infotypeCustomer info;
    info.name = nama;
    info.password = password;
    if(findCustomerByName(L,nama) ==nullptr){
        info.id = TOTALCUSTOMERS++;
        MLLCustomerNodePtr p = createCustomerNode(info);
        insertCustomerNode(L, p);
        cout << "Signup Berhasil\n";
    }else{
        cout << "User dengan nama tersebut sudah ada." << endl; 
    }
}
void addProductToCart(MLLCustomerNodePtr &customer, DLLProductsNodePtr product, int quantity){//adds product to customer's shopping cart after checking if product is already in cart
    MLLShoppingCartNodePtr existingItem = findCartItemByProductID(customer, product->data.productID);
    if(existingItem != nullptr){
        editCartItemQuantity(existingItem, quantity); //add quantity if already in cart
        cout << "Editan Berhasil\n";
    } else {
        if(product->data.stock >= quantity){
            infotypeShoppingCart cartItemData;
            cartItemData.product = product;
            cartItemData.quantity = quantity;
            MLLShoppingCartNodePtr c = createCartNode(cartItemData);
            insertShoppingCartNode(customer, c);
        } else if (quantity <= 0){
            cout << "Jumlah harus lebih besar dari nol." << endl;

        }else {
            cout << "Stok tidak mencukupi untuk produk " << product->data.productName << endl; //redundant check but whatever
        }
    }
}
MLLCustomerNodePtr loginCustomer(MLLCustomerData L, string name, string password){ //simple login function for customers; returns pointer to customer node if login successful, nullptr if failed
    MLLCustomerNodePtr p = L.first;
    while (p != nullptr) {
        if (p->info.name == name && p->info.password == password) {
            cout << "Login berhasil. Selamat datang, " << p->info.name << "!" << endl;
            return p; //login returns customer node pointer so it can be used directly during session
        }
        p = p->next;
    }
    cout << "Login gagal. Nama atau kata sandi salah." << endl;
    return nullptr;
}

//logout is kinda unnecessary since we are not maintaining sessions or anything; automatically handled in main program flow when user decides to logout
void purchaseCartItems(MLLCustomerNodePtr &customer){ //processes purchase of all items in customer's shopping cart, stock availability is confirmed during adding to cart since this is a simple project
    int total = printShoppingCart(customer);
    cout << "Total Biaya: Rp" << total << endl;
    cout << "Apakah anda ingin Confirm? Y/N" << endl;
    char choice;
    cin >> choice;
    if(choice == 'Y' || choice == 'y'){
        MLLShoppingCartNodePtr p = customer->firstChild;
        while(p != nullptr){
            //reduce stock from products list
            DLLProductsNodePtr product = p->data.product;
            product->data.stock -= p->data.quantity;
            p = p->next;
        }
        //clear shopping cart
        customer->firstChild = nullptr; //yes i know this causes memory leaks but who cares for this simple project especially at this scale
        cout << "Pembelian berhasil! Terima kasih telah berbelanja." << endl;
    } else {
        cout << "Pembelian dibatalkan." << endl;
    }
}
void insertSimpleProducts(DLLProducts &L){ //inserting some simple products at startup
    infotypeProducts i;
    i.productID = 1;
    i.productName = "Aqoa_Mineral_Watre_670ml";
    i.stock = 150;
    i.price = 3500;
    DLLProductsNodePtr p = createProductNode(i);
    insertProductNode(L,p);
    i.productID = 2;
    i.productName = "Sira_Rito_Roti_Tawar_10Pcs";
    i.stock = 50;
    i.price = 15000;
    p = createProductNode(i);
    insertProductNode(L,p);
    i.productID = 3;
    i.productName = "NiceKafe_Latte_222ml";
    i.stock = 50;
    i.price = 11000;
    p = createProductNode(i);
    insertProductNode(L,p);

}
//WHAT ELSE DO WE NEED?