/*Ngan Campbell
*CS300
*Assignment4
*/

#include "BarCodeItem.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>

using namespace std;

int main(){
    ifstream file("upc_corpus.txt");
    string line;
    string barcode;
    string item;
    int count = 0;
    long SIZE = 1045913;
    BarCodeItem *myArray = new BarCodeItem[SIZE];
    while(getline(file, line)){
        stringstream ss(line);    
        getline(ss, barcode, ','); //uses , as splitter instead of white space 
        getline(ss, item, ',');
        BarCodeItem a(barcode, item);
        myArray[count] = a;
        count++;
    }
    string upc;
    cout << "UPC Code: ";
    cin >> upc;
    BarCodeItem x(upc);
    clock_t t;
    t = clock();
    for(int i = 0; i < count; i++){
        if(myArray[i] == x){
            cout << myArray[i].getItem()<<endl;
            break;
        }
    }
    t = clock() - t;
    cout << "Array time: " << t << " miliseconds" << endl;
    delete []myArray;
    return 0;
}
