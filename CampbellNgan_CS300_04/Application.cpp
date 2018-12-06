#include "BarCodeItem.h"
#include "BSTScanner.h"
#include "ArrayScanner.h"

void scan(Scanner<BarCodeItem>* scanner, BarCodeItem item) { //polymorphic function
	scanner->scan(item);
}

BarCodeItem getBarCode(){
    string upc;
    cout << "UPC Code: ";
    cin >> upc;
    BarCodeItem x(upc);
    return x;
}

int main(){
	BST<BarCodeItem> bst;
	//...
	Scanner<BarCodeItem>* scanner = new BSTScanner<BarCodeItem>(bst);
	BarCodeItem item;
    item = getBarCode();
	scan(scanner, item);

	BarCodeItem* array;
	//...
	scanner = new ArrayScanner<BarCodeItem>(array);
	scan(scanner, item);
	return 0;

}
