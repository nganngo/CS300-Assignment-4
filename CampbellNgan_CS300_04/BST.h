/*Ngan Campbell
*CS300
*Assignment4
*/

#include <iostream>

using namespace std;

template<class T>
struct node{
    T data;
    node<T>* left;
    node<T>* right;
};

template<class T>
class BST{
    node<T>* root;
    public:
       BST();
       ~BST();
       void printInOrder();
       void printPreOrder();
       void printPostOrder();
       T search(T& item);
       void insert(T& item);
       void deleteNode(T& item);
       T findMax(T&);
       int nodeCount();
       int height();
    private:
       void insert(node<T>*&, T&);
       void printInOrder(node<T>*);
       void printPreOrder(node<T>*);
       void printPostOrder(node<T>*);
       T search(node<T>*, T&, string e);
       T findMax(node<T>*, T&);
       void deleteNode(node<T>*&, T&);
       void destroyBST(node<T>* p);
};

template <class T>
BST<T>::BST(){
    root = NULL;
}

template <class T>
void BST<T>::destroyBST(node<T>* p){
    if (p != NULL){
        destroyBST(p->left);
        destroyBST(p->right);
        delete p;
    }
}

template <class T>
BST<T>::~BST(){
    destroyBST(root);
}

template <class T>
void BST<T>::printInOrder(){
    printInOrder(root);
}

template <class T>
void BST<T>::printInOrder(node<T>* p){
    if(p != NULL){
       printInOrder(p -> left);
       cout << p -> data << endl;
       printInOrder(p -> right);
    }
}

template <class T>
void BST<T>::insert(T& item){
    insert(root, item);
}

template <class T>
void BST<T>::insert(node<T>* &p, T& item){
    if(p == NULL){
       p = new node<T>;
       p -> data = item;
       p -> left = p -> right = NULL;
    }else if(item < p -> data){
       insert(p -> left, item);
    }else if(item > p -> data){
       insert(p -> right, item);
    }
}

template <class T>
void BST<T>::printPreOrder(){
    printPreOrder(root);
}

template <class T>
void BST<T>::printPreOrder(node<T>* p){
    if(p != NULL){
       cout << p -> data  << endl;
       printPreOrder(p -> left);
       printPreOrder(p -> right);
    }
}

template <class T>
void BST<T>::printPostOrder(){
    printPostOrder(root);
}

template <class T>
void BST<T>::printPostOrder(node<T>* p){
    if(p != NULL){
       printPostOrder(p -> left);
       printPostOrder(p -> right);
       cout << p -> data << endl;
    }
}

template <class T>
T BST<T>::search(T& item){
    return search(root, item, "Item not found");
}
template <class T>
T BST<T>::search(node<T>* p, T& item, string e){
    if(p == NULL || p -> data == item)
       return p -> data;
    else if(item < p -> data)
       return search (p -> left, item, e);
    else if(item > p -> data)
       return search(p -> right, item, e);
    else
      return e;
}

template <class T>
T BST<T>::findMax(T& e){
    return findMax(root, e);
}

template <class T>
T BST<T>::findMax(node<T>* p, T& e){
    if(p == NULL)
       return e;
    else if(p -> right == NULL)
       return p -> data;
    else
       return findMax(p -> right, e);
}

template <class T>
void BST<T>::deleteNode(T& item){
    deleteNode(root, item);
}

template <class T>
void BST<T>::deleteNode(node<T>* &p, T& item){
    if(p == NULL){
       return;
    }else if(item < p -> data){
       deleteNode(p -> left, item);
    }else if(item > p -> data){
       deleteNdoe(p -> right, item);
    }else{
        if(p -> right != NULL && p -> left != NULL){
          int e = -1;
          T max = findMax(p -> left, item);
          p -> data = max;
          deleteNode(p -> left, max);
        }else{
            node<T>* q = p;
            if(p -> left != NULL)
               p = p -> left;
            else if(p -> right != NULL)
               p = p -> right;
            delete q;
        }
    }
}

