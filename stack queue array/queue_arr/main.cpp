#include "queue_arr.h"
int main()
{
    Queue Q;
    createQueue(Q);
    int del;
    if (isEmpty(Q)){
        cout<<"Queue kosong"<<endl;
    }else{
        cout<<"Queue tidak kosong"<<endl;
    }
    if (isFull(Q)){
        cout<<"Queue penuh"<<endl;
    }else{
        cout<<"Queue tidak penuh"<<endl;
    }
    enQueue(Q,7);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\t\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    enQueue(Q,9);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\t\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    del = deQueue(Q);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\t\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    enQueue(Q,0);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\t\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    del = deQueue(Q);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\t\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    del = deQueue(Q);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"    ";
    cout<<"\t\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    enQueue(Q,4);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\t\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    enQueue(Q,8);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\t\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    enQueue(Q,1);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\t\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    enQueue(Q,3);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    enQueue(Q,7);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    enQueue(Q,2);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    enQueue(Q,10);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    del = deQueue(Q);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    del = deQueue(Q);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\t\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    enQueue(Q,10);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    del = deQueue(Q);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\t\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    enQueue(Q,5);
    cout<<"Queue = ";
    printQueue(Q);
    cout<<"\tHead = "<<Q.head<<" Tail = "<<Q.tail<<endl;
    if (isFull(Q)){
        cout<<"Queue Penuh";
    }else{
        cout<<"Queue Tidak Penuh";
    }
    return 0;
}
