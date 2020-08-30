#include <stddef.h>
#include "ll_cycle.h"

int ll_has_cycle(node *head) {
    node *hair, *turtle;
    hair = head;
    turtle = head;
    while (1){
	if(hair == NULL || hair -> next == NULL){
		return 0;
	}
	hair = hair -> next -> next;
	turtle = turtle -> next;
	if (turtle == hair){
		return 1;
	}
    }
    return 0;
}
