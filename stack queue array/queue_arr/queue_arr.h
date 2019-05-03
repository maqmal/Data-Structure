#include <iostream>
using namespace std;
const int nMax = 5;
struct Queue{
    int info[nMax];
    int head;
    int tail;
};
void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enQueue(Queue &Q, char X);
char deQueue(Queue &Q);
void printQueue(Queue Q);

