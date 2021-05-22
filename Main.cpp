#include <iostream> 
#include "Test.h"
#include "Kitchenware.h"
#include "Kitchenware.cpp"
#include "BinTree.h"
#include "BinTree.cpp"
#include <ctime>

using namespace std;

//void GetTypeName(Kitchenware*);

void GetTypeName(Kitchenware* obj)
{
    cout << typeid(*obj).name() << endl;
}

void PrintBeautifulDiamond();

Kitchenware* CreateInstance();
void DeleteInstance();
void PrintTree();

PTree treeWares = nullptr;

int main() {
    /*Kitchenware* obj1 = new ElectricStove(10, "Yellow", 100);
    Kitchenware* obj2 = new SlowCooker(5, "Green", 90, 500, false);
    Kitchenware* obj3 = new Stove(3, "Black");
    Kitchenware* obj4 = new SlowCooker(15, "Green", 90, 500, true);
    Kitchenware* obj5 = new Pot(25, 100);
    Kitchenware* obj6 = new ElectricStove(100, "Pink", 115);
    Kitchenware* obj7 = new SlowCooker(1, "Gray", 100, 250, false);
    Kitchenware* obj8 = new Pot(13, 200);
    Kitchenware* obj9 = new ElectricStove(8, "Orange", 220);

    Insert(treeWares, obj6);
    Insert(treeWares, obj1);
    Insert(treeWares, obj2);
    Insert(treeWares, obj5);    
    Insert(treeWares, obj7);
    Insert(treeWares, obj3);
    Insert(treeWares, obj4);    
    Insert(treeWares, obj8);
    Insert(treeWares, obj9);*/

    PrintHello();

    cout << "Multiple Inheritance\n";
    cout << "Created by Artyom PMI3\n";
    system("pause");
    system("cls");

    cout << "Hello!\nThis is simple application demonstrates some features of multiple inheritance\n";
    PrintBeautifulDiamond();
    cout << "\nYou can create instance of each element of struct above\n";
    cout << "Instance that you will create will be live in binary tree\n";
    system("pause");
    system("cls");
    int isEnd = false;
    
    while (!isEnd)
    {
        cout << "0. Show diamond\n";
        cout << "1. Create Instance\n";
        cout << "2. Delete Instance (by number)\n";
        cout << "3. Print only elements\n";
        cout << "4. Print tree\n";
        cout << "5. Clear console\n";
        cout << "6. Close application\n";
        int command;
        cin >> command;
        switch (command)
        {
        case 0:
            PrintBeautifulDiamond();
            break;
        case 1:
        {
            Kitchenware* newWare = CreateInstance();
            if (newWare != nullptr)
                Insert(treeWares, newWare);
            break;
        }
        case 2:
            DeleteInstance();
            break;
        case 3:
            PrintTree(treeWares);
            break;
        case 4:
            PrintTree();
            break;
        case 5:
            system("cls");
            break;
        case 6:
            isEnd = true;
            break;
        default:
            break;
        }
        cout << endl;
    }
    cout << "Good Bye!\n";
    DeleteTree(treeWares);
    return 0;
}

void PrintBeautifulDiamond()
{
    cout << "         +-------------+"; cout << endl;
    cout << "         | kitchenware |"; cout << endl;
    cout << "         |  int number |"; cout << endl;
    cout << "         +-------------+"; cout << endl;
    cout << "        /              \\"; cout << endl;
    cout << "       /                \\"; cout << endl;
    cout << "+-------------+          \\  "; cout << endl;
    cout << "|   Stove     |           \\"; cout << endl;
    cout << "|string color |            \\"; cout << endl;
    cout << "+-------------+             \\"; cout << endl;
    cout << "      |         \\          +-------------+"; cout << endl;
    cout << "      |           +------+  |   pot       |"; cout << endl;
    cout << "      |           |Gas   |  | int volume  |"; cout << endl;
    cout << "+--------------+  |Stove |  +-------------+"; cout << endl;
    cout << "|Electric Stove|  |int   |         /"; cout << endl;
    cout << "| int power    |  |gas   |        /"; cout << endl;
    cout << "+--------------+  |spend |       /"; cout << endl;
    cout << "              \\   +------+      /"; cout << endl;
    cout << "               \\               /"; cout << endl;
    cout << "                +-------------+"; cout << endl;
    cout << "                | slow cooker |"; cout << endl;
    cout << "                | bool _isPS  |"; cout << endl;
    cout << "                +-------------+"; cout << endl;
}

Kitchenware* CreateInstance()
{
    cout << "Please select the class which instance you want to create\n";
    cout << "1. Stove\n";
    cout << "2. Electric Stove\n";
    cout << "3. Pot\n";
    cout << "4. Slow cooker\n";
    cout << "5. Gas stove\n";    
    int number, power, volume, gasspend;
    string color, isPC;
    bool _isPC = false;
    Kitchenware* newWare = nullptr;

    int command;
    cin >> command;
    cout << "Please, input number of the ware or input -1 to close the dialog\n";
    cin >> number;    
    while (Find(treeWares, number) != nullptr)
    {
        if (number == -1) return nullptr;
        cout << "Kitchenware with the number already exists\nPlease input another number or -1 to close the dialog\n";
        cin >> number;
    }
        
    switch (command)
    {
    //Stove
    case 1:        
        cout << "You choose Stove\nInstance of the class has a color\n";
        cout << "Please, choose color of the ware\n";
        cin >> color;
        newWare = new Stove(number, color);        
        break;
    //Electric Stove
    case 2:
        cout << "You choose Electric Stove\nInstance of the class has a color and power\n";
        cout << "Please, choose a color of the ware\n";
        cin >> color;
        cout << "Please, input a power of the ware\n";
        cin >> power;
        newWare = new ElectricStove(number, color, power);
        break;
    //Pot
    case 3:
        cout << "You choose Pot\nInstance of the class has a volume\n";
        cout << "Please, input a volume of the ware\n";
        cin >> volume;
        newWare = new Pot(number, volume);
        break;
    //Slow cooker
    case 4:
        cout << "You choose Electric Stove\nInstance of the class has a color, power, volume\n";
        cout << "Please, choose a color of the ware\n";
        cin >> color;
        cout << "Please, input a power of the ware\n";
        cin >> power;
        cout << "Please, input a volume of the ware\n";
        cin >> volume;
        cout << "Is it preasure cooker?(T/F)";
        cin >> isPC;
        if (isPC == "T" || isPC == "t")
            _isPC = true;
        newWare = new SlowCooker(number, color, power, volume, _isPC);
        break;
    case 5:
        cout << "You choose Gas Stove\nInstance of the class has a color and gas spend\n";
        cout << "Please, choose a color of the ware\n";
        cin >> color;
        cout << "Please, input a gas spend of the ware\n";
        cin >> gasspend;
        newWare = new GasStove(number, color, gasspend);
        break;
    default:
        break;
    }
    return newWare;
}

void DeleteInstance()
{
    int number;
    cout << "Please, input number of the ware you want delete\nOr input -1 to close the dialog\n";
    cin >> number; 
    while (Find(treeWares, number) == nullptr)
    {
        if (number == -1) return;
        cout << "Kitchenware with the number isn't exists\nPlease input another number or -1 to close the dialog\n";
        cin >> number;
    }
    Delete(treeWares, number);
}

void PrintTree()
{
    cout << "Select algorithm of tree traversal\n";
    cout << "1. NLR (Pre-order)\n";
    cout << "2. LNR (In-order\n";
    cout << "3. LRN (Post-order)\n";
    int command;
    cin >> command;
    switch (command)
    {
    case 1:
        NLR(treeWares);
        break;
    case 2:
        LNR(treeWares);
        break;
    case 3:
        LRN(treeWares);
        break;
    default:
        break;
    }
}
