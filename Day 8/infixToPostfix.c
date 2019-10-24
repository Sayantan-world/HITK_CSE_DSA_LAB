#include <stdio.h>
typedef struct stack {
        char stk[50];
        int top;
}stack;
stack push(stack optr_stk,char c){
        optr_stk.top++;
        optr_stk.stk[optr_stk.top]=c;
        return optr_stk;
}
char pop(stack *optr_stk){
        int temp=optr_stk->top--;
        return optr_stk->stk[temp];
}
int precedence(char c){
        switch(c) {
        case '^': return 4;
        case '*': return 3;
        case '/': return 3;
        case '+': return 2;
        case '-': return 2;
        case '(': return 1;
        case ')': return 1;
        default: return 0;
        }
}
int braces(char infix[]){
        int lb=0,rb=0,i=0;
        while(infix[i]!='\0') {
                if(infix[i]=='(')
                        lb++;
                else if(infix[i]==')')
                        rb++;
                i++;
        }
        if(lb==rb)
                return 0;
        else{
                printf("The number of braces is not match!\nTry Again!\n");
                return 1;
        }
}
int main(){
        char infix[50],postfix[50],ch;
        stack optr_stk;
        optr_stk.top=-1;
        int i=0,j=0;
        do {
                printf("Enter the infix notation: ");
                scanf(" %s",infix);
        } while(braces(infix));
        while(infix[i]!='\0') {
                if(precedence(infix[i])==0)
                        postfix[j++]=infix[i++];
                else if(infix[i]=='(')
                        optr_stk=push(optr_stk,infix[i++]);
                else if(infix[i]==')') {
                        ch=pop(&optr_stk);
                        while(ch!='(') {
                                postfix[j++]=ch;
                                ch=pop(&optr_stk);
                        }
                        i++; 3
                }
                else{
                        if(precedence(infix[i])>precedence(optr_stk.stk[optr_stk.top]))
                                optr_stk=push(optr_stk,infix[i++]);
                        else{
                                while(precedence(infix[i])<=precedence(optr_stk.stk[optr_stk.top])) {
                                        ch=pop(&optr_stk);
                                        postfix[j++]=ch;
                                }
                                optr_stk=push(optr_stk,infix[i++]);
                        }
                }
        }
        while(optr_stk.top!=-1) {
                ch=pop(&optr_stk);
                postfix[j++]=ch;
        }
        postfix[j]='\0';
        printf("The postfix notation is: %s\n",postfix);
        return 0;
}
