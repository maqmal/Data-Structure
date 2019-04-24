#include <iostream>
#include "btree.cpp"
using namespace std;
int main()
{
    BTree T;
    createTree(T);
    address X;
    X = allocation(8);
    insertBST(root(T),X);
    X = allocation(3);
    insertBST(root(T),X);
    X = allocation(1);
    insertBST(root(T),X);
    X = allocation(10);
    insertBST(root(T),X);
    X = allocation(6);
    insertBST(root(T),X);
    X = allocation(4);
    insertBST(root(T),X);
    X = allocation(7);
    insertBST(root(T),X);
    X = allocation(14);
    insertBST(root(T),X);
    X = allocation(13);
    insertBST(root(T),X);
    cout<<"InOrder = ";
    inOrder(root(T));
    cout<<endl;
    cout<<"Jumlah Internal Node = ";
    cout<<countInternalNode(root(T))<<endl;
    cout<<"Leaves = ";
    printLeaves(root(T));
    cout<<endl;
    cout<<"Jumlah Leaves = ";
    int jml = 0;
    jml = countLeaves(root(T));
    cout<<jml<<endl;
    return 0;
}
