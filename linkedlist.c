#include <stdio.h>
#include <stdlib.h>
 
struct node {
  int x;
  struct node *next;
};
 
int main()
{
    /* This won't change, or we would lose the list in memory */
    struct node *root;       
    /* This will point to each node as it traverses the list */
    struct node *conductor;  
 
    root = malloc( sizeof(struct node) );  /* Tell root to point to something, a blank node */
    root->next = 0;                        /* Always tell a new node to point to a new blank node */
    root->x = 12;

    /* How to traverse through a LL */
    conductor = root; 
    if ( conductor != 0 ) {
        while ( conductor->next != 0)
        {
            conductor = conductor->next;
        }
    }
    /* Creates a node at the end of the list */
    conductor->next = malloc( sizeof(struct node) );  
 
    conductor = conductor->next; 


    if ( conductor == 0 )
    {
        printf( "Out of memory" );
        return 0;
    }

    /* initialize the new memory */
    conductor->next = 0;         
    conductor->x = 42;


/* Traverse through an LL and print output */
conductor = root;
if ( conductor != 0 ) { /* Makes sure there is a place to start */
    while ( conductor->next != 0 ) {
        printf( "%d\n", conductor->x );
        conductor = conductor->next;
    }
    printf( "%d\n", conductor->x );
}

/* Better way to traverse through list and print output */
conductor = root;
while ( conductor != NULL ) {
    printf( "%d\n", conductor->x );
    conductor = conductor->next;
}
 
    return 0;
}
