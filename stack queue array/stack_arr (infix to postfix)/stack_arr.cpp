#include "stack_arr.h"

void createStack(Stack &S){
    S.Top = -1;
}
bool isEmpty(Stack S){
    return S.Top == -1;
}
bool isFull(Stack S){
    return S.Top == nMax;
}
void push(Stack &S, char X){
    if (isFull(S)){
        cout<<"Stack Full"<<endl;
    }else{
        S.Top++;
        S.info[S.Top] = X;
    }
}
void pop(Stack &S,char &X){
    if (!isEmpty(S)){
        X = S.info[S.Top];
        S.Top--;
    }
}
void printStack(Stack S){
    int i = 0;
    cout<<"Stack: ";
    while (i <= S.Top){
        cout<<S.info[i];
        i++;
    }
}
bool isOperator(char X){
    bool status;
    if ((X=='+')||(X=='-')||(X=='*')||(X=='/')||(X=='^')||(X=='(')||(X==')')){
        status = true;
    }else{
        status = false;
    }
    return (status);
}
int getPresedence(char X){
    int nilai;
    if ((X=='+')||(X=='-')){
        nilai = 1;
    }else if ((X=='*')||(X=='/')){
        nilai = 2;
    }else if (X=='^'){
        nilai = 3;
    }else if (X=='('){
        nilai = 4;
    }else {
        nilai = 0;
    }
    return (nilai);
}
