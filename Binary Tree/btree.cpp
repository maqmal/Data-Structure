#include "btree.h"
void createTree(BTree &T){
    root(T) = NULL;
}
address allocation(infotype x){
    address N = new node;
    data(N)   = x;
    left(N)   = NULL;
    right(N)  = NULL;
    return N;
}
bool isLeaf(address root){
    return ((left(root) == NULL) && right(root) == NULL );
}
void insertBST(address &root, address n){
    if(root == NULL){
        root = n;
    }else{
        if(data(n) < data(root)){
            insertBST(left(root), n);
        }else if(data(n) > data(root)){
            insertBST(right(root), n);
        }
    }
}
void inOrder(address root){
    if(root != NULL){
        inOrder(left(root));
        cout << data(root)<<" - ";
        inOrder(right(root));
    }
}
address findNode(address root, infotype x){
    if (root == NULL || (data(root) == x)){
        return root;
    }else{
        if(x < data(root)){
            findNode(left(root), x);
        }else if(x > data(root)){
            findNode(right(root), x);
        }
    }
}
int countInternalNode(address root){
    if((right(root) != NULL) && (left(root) != NULL)){
        return 1+ countInternalNode(left(root)) + countInternalNode(right(root));
    }
}
void printLeaves(address root){
    if(root != NULL){
        printLeaves(left(root));
        if((left(root) == NULL) && (right(root) == NULL)){
            cout << data(root)<<" - ";
        }
        printLeaves(right(root));
    }
}
int countLeaves(address root){
    if(root == NULL){
        return 0;
    }

    if((right(root) == NULL) && (left(root) == NULL)){
        return 1;
    }else{
        return countLeaves(left(root))+countLeaves(right(root));
    }
}
