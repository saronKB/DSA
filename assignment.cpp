#include <iostream>
#include <string>

using namespace std;
#define TAX_RATE_DIRECTIVE 0.1
int main()
{
    // welcome messeges
    cout << "hello,this platform will make your purchase fun";
    cout << "c++ is a compiled language";

    const float TAX_RATE_ = 0.1;
    // product details variables
    string productName;
    int category = 1;
    int intialInventoryQty{0};
    float pricePerUnit = 0.0;
    int itemSold = 0;
    // computed values
    int newInventoryQty;
    float totalSales;
    string inventoryStatus;
    auto totalSalesHelper = totalSales;
    decltype(intialInventoryQty) initialInventoryQtyHelper = 60;
    // user input
    cout << "Enter the product name (single word): ";
    cin >> productName;
    cout << "Enter the product category (1-5): ";
    cin >> category;
    cout << "Enter the initial inventory quantity: ";
    cin >> intialInventoryQty;
    cout << "Enter the product price per unit: ";
    cin >> pricePerUnit;
    cout << "Enter the number of items sold: ";
    cin >> itemSold;
    newInventoryQty = intialInventoryQty;
    newInventoryQty -= itemSold;
    totalSales = itemSold * pricePerUnit;
    inventoryStatus = (newInventoryQty < 10) ? "Low inventory" : "sufficient inventory";
    if ((category < 1) || (category > 5))
    {
        cout << "Invalid product category! Please enter a number between 1 and 5. " << endl;
    }
    else
    {
        switch (category)
        {
        case 1:
            cout << "category 1: Electronics" << endl;
            break;
        case 2:
            cout << "category 2: Groceries" << endl;
            break;
        case 3:
            cout << "category 3: clothing" << endl;
            break;
        case 4:
            cout << "category 4: Stationary" << endl;
            break;
        case 5:
            cout << "category 5: Miscallenous" << endl;
            break;
        }
    }
    cout << "\n Receipt details" << endl;
    for (int i = 1; (i <= itemSold); i++)
    {
        cout << "Item " << i << " price: $" << pricePerUnit << endl;
    }
    // summary
    cout << "\n summary of transactions: " << endl;
    cout << "product name:" << productName << endl;
    cout << "product category:" << category << endl;
    cout << "initial inventory: " << intialInventoryQty << endl;
    cout << "product price:$" << pricePerUnit << endl;
    cout << "items sold: " << itemSold << endl;
    cout << "new inventory: " << newInventoryQty << endl;
    cout << "total sales amount:$" << totalSales << endl;
    cout << "inventory status: " << inventoryStatus << endl;
    cout << "helper total sales:$" << totalSalesHelper << endl;
    cout << "helper inventory value: " << initialInventoryQtyHelper << endl;
    cout << "tax rate(from directive):" << TAX_RATE_DIRECTIVE << endl;
    cout << "tax rate: " << TAX_RATE_ << endl;
    return 0;
}