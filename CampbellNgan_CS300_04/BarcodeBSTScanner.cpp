/*Ngan Campbell
*CS300
*Assignment4
*/

#include "BST.h"
#include <iostream> 
#include <sstream> 
#include <fstream>
#include <string>
#include "BarCodeItem.h"

using namespace std; 

int main(){
    ifstream file("upc_corpus.txt");
    string line;
    string barcode;
    string item;
    BST <BarCodeItem> b;
    while(getline(file, line)){
        stringstream ss(line);    
        getline(ss, barcode,','); //uses , as splitter instead of white space 
        getline(ss, item,',');
        BarCodeItem a(barcode, item);
        b.insert(a);
    }
    string upc;
    cout << "UPC Code: ";
    cin >> upc;
    BarCodeItem x(upc);
    clock_t t;
    t = clock();
    BarCodeItem c = b.search(x);
    cout << c.getItem() << endl;
    t = clock() - t;
    cout << "BST time: " << t << " miliseconds" << endl;
    return 0; 
}
