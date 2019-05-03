#include "queue_arr.h"

void createQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;
}

bool isEmpty(Queue Q){
    return ((Q.head== -1) && (Q.tail== -1));
}

bool isFull(Queue Q){
    bool status = false;
    if (Q.tail<Q.head){
        status = (Q.tail+1 == Q.head);
    }else if (Q.head==0){
        status = (Q.tail==nMax-1);
    }
    return (status);
}

void enQueue(Queue &Q, char x){
    if (Q.tail!=nMax-1){
        if (isEmpty(Q)){
            Q.tail++;
            Q.head++;
            Q.info[Q.tail] = x;
        }else{
            Q.tail++;
            Q.info[Q.tail] = x;
        }
    }else if (!isFull(Q)){
        Q.tail=0;
        Q.info[Q.tail] = x;
    }
}

char deQueue(Queue &Q){
    char X;
    if(Q.head<nMax-1){
        if (isEmpty(Q)){
            cout<<"Queue Kosong"<<endl;
        }else if (Q.head==Q.tail){
            X = Q.info[Q.head];
            Q.tail = -1;
            Q.head = -1;
        }else {
            X = Q.info[Q.head];
            Q.head++;
        }
    }else{
        if (Q.head==Q.tail){
            X = Q.info[Q.head];
            Q.tail = -1;
            Q.head = -1;
        }else{
            X = Q.info[Q.head];
            Q.head = -1;
        }
    }
}

void printQueue(Queue Q){
    int i = Q.head;

    if ((!isEmpty(Q))&&(Q.tail>=Q.head)){
        while (i<=Q.tail){
            cout<<Q.info[i]<<"-";
            i++;
        }
    }else if ((!isEmpty(Q))&&(Q.tail<Q.head)){
        while (i<=nMax-1){
            cout<<Q.info[i]<<"-";
            i++;
        }
        i=0;
        while (i<=Q.tail){
            cout<<Q.info[i]<<"-";
            i++;
        }
    }
}

