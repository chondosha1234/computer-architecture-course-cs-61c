#include <stdio.h>

// Linked list,   takes a generic type from the enum 
// the union is a shared memory space, only one will be used based on enum choice
// pointer to another GenericLink struct for next element in linked list
typedef struct{
    enum {
	    typChar,
	    typUInt16,
	    typUInt32
    } genType;

    union {
	    char c;
	    uint16_t u16;
	    uint32_t u32;
    } value;
    
    GenericLink *next;

} GenericLink;

// sizeof (GenericLink) would be the largest size in union ?


// takes in a char and returns pointer to link containing char
GenericLink* store_char(char c){
    GenericLink *letter = (GenericLink*) malloc(sizeof(GenericLink));
    letter->genType = typChar;
    letter->value = c;
    return letter;
}

//takes in a string and returns pointer to the "head" of the GenericLinkedList
// holding that string
GenericLink* store_string(char* s){
    int i;
    GenericLink* first, final;
    first = store_char(s[0]);
    final = first;
    for (i = 1; s[i] != '\0'; i++){
    	GenericLink* letter = store_char(s[i]);
        first->next = letter;
        first = letter;
    }
    return final;
}



