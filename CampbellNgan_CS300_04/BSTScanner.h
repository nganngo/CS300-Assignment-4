#include "Scanner.h"
#include "BST.h"
#include <iostream> 
#include <sstream> 
#include <fstream>
#include <string>

template <class T>
class BSTScanner: public Scanner<T>{
     BST<T> database;

public:
    BSTScanner(BST<T> _database):database(_database){
        fstream file("upc_corpus.txt");
        string line;
        string barcode;
        string item;
        while(getline(file, line)){
            stringstream ss(line);    
            getline(ss, barcode,','); //uses , as splitter instead of white space.
            getline(ss, item,',');
            T a(barcode, item);
            _database.insert(a);
        }
    }

	void scan(T& product){
        clock_t t;
        t = clock();
        T c = database.search(product);
        cout << c.getItem() << endl;
        t = clock() - t;
        cout << "BST time: " << t << " miliseconds" << endl;
        cout << "BST scan" << endl;
	}

	void setDatabase(BST<T> _database){
        database = _database;
	}

};
