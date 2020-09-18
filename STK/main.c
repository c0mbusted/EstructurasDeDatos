#include <stdio.h>

#include "Stack.c"

int main(){
	Stack *s = createStack();
	
	printf("\nApilando\n");
	for(int k=0;k<=10;k++){
		push(s, createData(2*k));
		printf("Valor tope: %i\n", s->top->data->d);
	}
	
	printf("\nDesapilando\n");
	
	while(s->top != NULL){
		printf("Valor tope: %i\n", s->top->data->d);
		pop(s);
	}
	
	freeStack(s);
	
	return 0;
}