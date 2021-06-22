#include <stdio.h>
#include <stdlib.h>

typedef char stack_element_t;
typedef struct stack_node_s { 
	stack_element_t element; 
	struct stack_node_s *restp;
} stack_node_t;

typedef struct { 
	stack_node_t *topp;
} stack_t;


 
void push(stack_t *sp, stack_element_t c); 
stack_element_t pop(stack_t *sp);

int main(void){
	stack_t s = {NULL};
	push(&s, '2'); push(&s, '+');
	push(&s, 'C');push(&s, '/');

	printf("\nEmptying stack: \n");
	while (s.topp != NULL) {
		printf("%c\n", pop(&s)); return (0);
	} 
}
void push(stack_t *sp,stack_element_t c) {
	stack_node_t *newp; 
	newp = (stack_node_t *)malloc(sizeof (stack_node_t)); newp->element = c;
	newp->restp = sp->topp;
	sp->topp = newp; 
}


stack_element_t pop(stack_t *sp) /* input/output - stack */ {
	stack_node_t *to_freep; 
	stack_element_t ans;
	to_freep = sp->topp;
	ans = to_freep->element; 
	sp->topp = to_freep->restp; 
	free(to_freep);
	return (ans); 
}