/*Ngan Campbell
*CS300
*Assignment4
*/

#include <string>
#include <iostream>

using namespace std;

class BarCodeItem{
    string BarCode;
    string item;
    public:
        BarCodeItem();
        BarCodeItem(string a, string b);
        BarCodeItem(string a);
        string getBarCode();
        string getItem();
        void setBarCode(string a);
        friend bool operator>(BarCodeItem &item1, BarCodeItem &item2);
        friend bool operator<(BarCodeItem &item1, BarCodeItem &item2);
        friend bool operator==(BarCodeItem &item1, BarCodeItem &item2);
};

BarCodeItem::BarCodeItem(){
    BarCode = "";
    item = "";
}

BarCodeItem::BarCodeItem(string a, string b){
    BarCode = a;
    item = b;
}

BarCodeItem::BarCodeItem(string a){
    BarCode = a;
}

string BarCodeItem::getBarCode(){
    return BarCode;
}

string BarCodeItem::getItem(){
    return item;
}

bool operator>(BarCodeItem& item1, BarCodeItem &item2){
    return item1.getBarCode() > item2.getBarCode();
}

bool operator<(BarCodeItem &item1, BarCodeItem &item2){
    return item1.getBarCode() < item2.getBarCode();
}

void BarCodeItem::setBarCode(string a){
   BarCode = a;
}

ostream& operator<<(ostream& os, BarCodeItem b){
    os << b.getBarCode()<< " " << b.getItem() << endl;
    return os;
}

bool operator==(BarCodeItem &item1, BarCodeItem &item2){
    return item1.getBarCode() == item2.getBarCode();
}

