//Effective C book
#include <stdio.h>
#include <stdlib.h>

typedef int object_t;

int do_something(char* filename1, char* filename2)
{
    FILE *file1, *file2;
    object_t *obj;
    int ret_val = 0;

    file1 = fopen( filename1, "a");
    if(file1 == NULL){
        ret_val = -1;
        goto FAIL_FILE1;
    }

    file2 = fopen(filename2, "a");
    if(file2 == NULL){
        printf("File %s failed to open.\n");
        ret_val = -1;
        goto FAIL_FILE2;
    }
    else
    {
        printf("File %s open success.\n", filename2);
    }

    obj = malloc(sizeof(object_t));
    if(obj == NULL){
        ret_val = -1;
    }


    //DO STUFF

    //Close only what we opened
    //If we fail on opening OBJ, then
    //we succeeded in opening file 1 and file2, etc.
    FAIL_OBJ:
        fclose(file2);
    FAIL_FILE2:
        fclose(file1);
    FAIL_FILE1:
        return ret_val;

}

int main(void)
{
    char* file1 = "/home/tardis1/filetest.txt";
    char* file2 = "/home/tardis1/filetest.txt";

    do_something(file1, file2);
    return 0;
}