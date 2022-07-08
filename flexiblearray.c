//Effective C Book
#include <stdio.h>
#include <stdlib.h>

//declare a struct with an array of integers
//where the size is not given
typedef struct{
      size_t num;
      int data[];
} widget;

//define a function that creates an allocated
//memory space for the struct and the 
//data[], now allocted by array_size
void *func(size_t array_size)
{
    //allocates room for 1 struct,
    //and an array of integers, same void setup()
    //data[array_size]
    widget *p = (widget *)malloc(sizeof(widget)) + sizeof(int) * array_size;
    
    //if allocation fails, return NULL
    if(p == NULL){
        return NULL;
    }

    p->num = array_size;
    for(size_t i = 0; i < p->num; ++i){
        p->data[i] = 17;
    }
}

int main(void)
{
    func(50);
}