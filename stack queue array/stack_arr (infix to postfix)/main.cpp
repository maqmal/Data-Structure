#include "stack_arr.h"

int main()
{
    char infix[nMax];
    char postfix[nMax];
    Stack S;
    createStack(S);
    cout<<"TUGAS PENDAHULUAN - MODUL 7"<<endl;
    cout<<"Notasi INFIX : ";
    cin>>infix;
    int index = -1;
    char X,A,B;
    for(int i = 0; i < strlen(infix); i++){
        cout<<i+1<<" Dibaca "<<infix[i]<<"\t";
        if (!isOperator(infix[i])){
            index++;
            postfix[index] = infix[i];
        }else{
            int idx = 0;
            bool ada = false;
            while (idx<=S.Top){
                if (S.info[idx] == '('){
                        ada = true;
                    }
                idx++;
            }
            if (infix[i] == ')'){
                while ((S.info[S.Top]) != '('){
                    pop(S,A);
                    index++;
                    postfix[index] = A;
                }
                pop(S,A);
            }else if ((isEmpty(S))||(S.info[S.Top]== '(')){
                push(S,infix[i]);
            }else if ((S.info[S.Top]!= '(') && (getPresedence(infix[i]))>getPresedence(S.info[S.Top])&& !ada ){
                push(S,infix[i]);
            }else if ((S.info[S.Top]!= '(') && (getPresedence(infix[i]))<= getPresedence(S.info[S.Top])&& !ada){
                pop(S,A);
                index++;
                postfix[index] = A;
                push(S,infix[i]);
            }else if (!ada){
                index++;
                postfix[index] = infix[i];
            }else{
                push(S,infix[i]);
            }
        }

        printStack(S);
        if (i==14){
            cout<<"   ";
        }
        cout<<"\tPostfix: ";
        for(int x = 0; x <=index; x++){
            cout<<postfix[x];
        }
        cout<<endl;

    }
        cout<<"   Dibaca   "<<"\t";
        while (S.Top>=0){
            pop(S,A);
            index++;
            postfix[index] = A;

        }
        pop(S,A);
        printStack(S);
        cout<<"    ";
        cout<<"\tPostfix: ";
        for(int x = 0; x <=index; x++){
            cout<<postfix[x];
        }
        cout<<endl;
    return 0;
}
