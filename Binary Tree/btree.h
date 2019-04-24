#ifndef BTREE_H_INCLUDED
#define BTREE_H_INCLUDED
#define root(T) T.root
#define left(N) N->left
#define right(N) N->right
#define data(N) N->data
#define nil NULL

using namespace std;

typedef struct node *address;
typedef int infotype;
struct node{
    infotype data;
    address left;
    address right;
};
struct BTree{
    address root;
};

void createTree(BTree &T);
address allocation(infotype x);
bool isLeaf(address root);
void insertBST(address &root, address n);
void inOrder(address root);
address findNode(address root, infotype x);
int countInternalNode(address root);
void printLeaves(address root);
int countLeaves(address root);

#endif // BTREE_H_INCLUDED
