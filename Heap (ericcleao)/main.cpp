#include <QDebug>
#include "heap.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc);
    Q_UNUSED(argv);

//    int array[] = {10,11,12,13,14,15,16,17,18};

    Heap<int> test/*(array,9,15)*/;

    test.insert(10);
    test.insert(11);
    test.insert(12);
    test.insert(13);
    test.insert(14);
    test.insert(15);
    test.insert(16);
    test.insert(17);
    test.insert(18);
    test.insert(19);
    test.insert(20);
    test.insert(21);

    test.buildMaxHeap();

    qDebug() << test.toString();

    return 0;
}
