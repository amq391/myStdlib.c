#include <stddef.h>
#include "mem.h"

int testMemcpy() {
    // Copying a string over to another buffer
    char src[] = "This is the string to be copied";
    char dest[50];
    memcpy(dest,src,strlen(src) +1);
    if (strcmp(dest, src) != 0) {
        return -1;
    }

    // Copying data over to another array
    int src2[4] = {34, 47, -555, 55};
    int dest2[10];
    memcpy(dest2,src2,sizeof(src2));
    for (int i = 0; i < 4; i++) {
        if (dest2[i] != src2[i]) return -1;
    }

    return 1;
}

int testMemset() {
    // Setting array to 1s 
    int src[4] = {34, 47, -555, 55};
    memset(src,1,4);
    for (int i = 0; i < 4; i++) {
        if (src[i] != 1) return -1;
    }

    // Setting array to -1s 
    int src2[4] = {34, 47, -555, 55};
    memset(src2,-1,4);
    for (int i = 0; i < 4; i++) {
        if (src2[i] != -1) return -1;
    }
    return 1;
}

int testMemcmp() {
    // Testing different arrays 
    int l1[4] = {34, 47, -555, 55};
    int l2[4] = {24, 85, -40, 38};
    if (memcmp(l1,l2,4) != 1) return -1;
    

    // Testing identical arrays
    int l3[4] = {34, 47, -555, 55};
    int l4[4] = {34, 47, -555, 55};
    if (memcmp(l1,l2,4) != 0) return -1;

    return 1;
}

int testStrcat() {
    return 1;
}

int testStrncat() {
    return 1;
}

int testStrcmp() {
    return 1;
}

int testStrncmp() {
    return 1;
}

int testStrcpy() {
    return 1;
}

int testStrncpy() {
    return 1;
}

int testPrintf() {
    return 1;
}

void reqTests() {
    char *cat = "cat";
    char *dogGoesWoof = "dog\0goes\0woof";
    char str[100];
    memset(str,0,100);
    strcat(str,cat);

    printf("%s\n",str);   //"cat"

    strcpy(str,dogGoesWoof);

    printf("%s\n",str);   //"dog"

    //strcpy(str+1,str);    // overlapping strings to strcpy -> unpredictable behavior

    // copies data that is beyond null terminator in cat string
    // Uncomment to see output but program may crash
    // memcpy(str,cat,22);    
}

int main() {
    printf("***\n**Running Tests**\n***\n");
    printf("Testing memcpy: %d\n\n", testMemcpy());
    printf("Testing memset: %d\n\n", testMemset());
    printf("Testing memcmp: %d\n\n", testMemcmp());
    printf("Testing strcat: %d\n\n", testStrcat());
    printf("Testing strncat: %d\n\n", testStrncat());
    printf("Testing strcmp: %d\n\n", testStrcmp());
    printf("Testing strncmp: %d\n\n", testStrncmp());
    printf("Testing strcpy: %d\n\n", testStrcpy());
    printf("Testing strncpy: %d\n\n", testStrncpy());
    printf("Testing printf: %d\n\n", testPrintf());

    printf("***\n**Running Required Tests**\n***\n");
    reqTests();
    
    return 0;
}