#include <cstring>
#include <iostream>

using namespace std;
const int nMax = 100;
struct Stack {
    char info[nMax];
    int Top;
};
void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, char X);
void pop(Stack &S,char &X);
void printStack(Stack S);

bool isOperator(char X);
int getPresedence(char X);





