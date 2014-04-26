#ifndef HEAP_H
#define HEAP_H
#include "HeapADT.h"
#include <QDebug>
#include <stdlib.h>
#include <QString>

template <typename E>
class Heap// : public HeapADT
{
    E* content; // Pointer to the heap array
    int n; // Number of elements now in the heap
    int maxsize; // Maximum size of the heap
    void heapfy(int pos){
        E aux;

        if(pos < n/2 && pos >= 0){
            if(content[pos] < content[this->left(pos)+1] || content[pos] < content[this->righ(pos)+1]){
                if(content[this->left(pos)+1] > content[this->righ(pos)+1]){
                    aux = content[pos];
                    content[pos] = content[this->left(pos)+1];
                    content[this->left(pos)+1] = aux;
                    heapfy(this->left(pos)+1);
                } else{
                    aux = content[pos];
                    content[pos] = content[this->righ(pos)+1];
                    content[this->righ(pos)+1] = aux;
                    heapfy(this->righ(pos)+1);
                }
            }
        }
    }

public:
    // Constructor
    Heap(E* h = 0, int num = 0, int max = 0){
        this->maxsize = max;
        content = (E*)calloc(this->maxsize, sizeof(E));
        this->n = num;
        for(int cont = 0; cont < n; ++cont){
            content[cont] = h[cont];
        }

    }

    // Return current heap size
    int size() const{
        return n;
    }

    // True if pos is a leaf
    bool isLeaf(int pos) const{
        if(pos >= this->n/2 + 1){
            return true;
        } else{
            return false;
        }
    }

    // Return leftchild position
    int left(int pos) const{
        return 2*(pos);
    }

    // Return rightchild position
    int righ(int pos) const{
        return 2*pos+1;
    }

    // Return parent position
    int parent(int pos) const{
        return (pos)/2;
    }

    // Heapify contents of Heap
    void buildMaxHeap(){
        for(int cont = n/2 - 1; cont >= 0; --cont){
            heapfy(cont);
        }
    }

    // Insert "it" into the heap
    void insert(const E& it){
        if(n < maxsize){
            content[n] = it;
            ++n;
        } else{
            this->maxsize += 15;
            content = (E*)realloc(content, this->maxsize*sizeof(E));
            content[n] = it;
            ++n;
        }
    }

    E removefirst(){
        --n;
        qDebug() << "etst" << content[n];
        E aux = content[0];
        content[0] = content[n];
        content[n] = 0;
        buildMaxHeap();
        return aux;
    }

    E remove(int pos){
        --n;
        E aux = content[pos-1];
        content[pos-1] = content[n];
        content[n] = 0;
        buildMaxHeap();
        return aux;
    }

    QString toString(){
        int cont;
        QString print = "";
        for(cont = 0; cont < this->n - 1; ++cont){
            print += QString::number(this->content[cont]) + " ";
        }
        print += QString::number(this->content[cont]);
        return print;
    }
};

#endif // HEAP_H
