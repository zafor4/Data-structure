#include<stdio.h>
#include<stdlib.h>

struct Stack{
  int size;
  int top ;
  char* array;
};

int Empty(struct Stack* ptr){
if(ptr->top == -1)
    return 1 ;

return 0 ;
}

int Full(struct Stack* ptr){
if(ptr->top == ptr->size-1)
    return 1 ;

return 0 ;
}

void push(struct Stack* ptr,char value){
if(Full(ptr))
    printf("Stack overflow\n");
else{
    ptr->top++ ;
    ptr->array[ptr->top] = value;
    }
}

char pop(struct Stack* ptr){
if(Empty(ptr)){
    printf("Stack is underflow\n");
    return -1 ;
}
else{
    int value = ptr->array[ptr->top];
    ptr->top-- ;
    return value ;
    }
}

int parenthesisMatch(char* exp){
  struct Stack* sp ;
  sp->size = 100 ;
  sp->top = -1 ;
  sp->array = (char*)malloc(sp->size*sizeof(char));
  for (int i = 0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='('){
            push(sp ,'(');
        }
        else if(exp[i]==')'){
            if(Empty(sp)){
                return 0;
            }
            pop(sp);
        }
    }

    if(Empty(sp))
        return 1;
    else
        return 0;
}


int main()
{
    char * exp = "8)*(9)";
    // Check if stack is empty
    if(parenthesisMatch(exp)){
        printf("The parenthesis is matching");
    }
    else{
        printf("The parenthesis is not matching");
    }
return 0;
}