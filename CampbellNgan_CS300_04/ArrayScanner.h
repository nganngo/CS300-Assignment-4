#include "Scanner.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>

using namespace std;

template <class T>
class ArrayScanner: public Scanner<T>{
    T* database;
    int count = 0;
    long SIZE = 1045913;


public:
     ArrayScanner(T* _database):database(_database){
        fstream file("upc_corpus.txt");
        string line;
        string barcode;
        string item;
        T *myArray = new T[SIZE];
        while(getline(file, line)){
            stringstream ss(line);    
            getline(ss, barcode, ','); //uses , as splitter instead of white space 
            getline(ss, item, ',');
            T a(barcode, item);
            myArray[count] = a;
            count++;
        }
    }

	void scan(T& product){
        cout << "Scan Array..." << endl;
        T *myArray = new T[SIZE];
        clock_t t;
        t = clock();
        for(int i = 0; i < count; i++){
            if(myArray[i] == product){
                cout << myArray[i].getItem()<<endl;
                break;
            }
        }
        t = clock() - t;
        cout << "Array time: " << t << " miliseconds" << endl;
        delete []myArray;
	}

	void setDatabase(T* _database){
        database = _database;
	}

	~ArrayScanner(){
		delete database;
	}

};
