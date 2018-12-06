#ifndef SCANNER_H
#define SCANNER_H

template <class T>
class Scanner{
public:
	virtual void scan(T& product) = 0;
    virtual ~Scanner(){}
};

#endif