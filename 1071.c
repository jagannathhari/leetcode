#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* gcdOfStrings(char* str1, char* str2) {
    size_t len_str1 = strlen(str1) ;
    size_t len_str2 = strlen(str2) ;
    char *ans = malloc(len_str1+1);
    ans[0] = '\0';
    if ( len_str1 > len_str2 ){
        char *temp = str1;
        str1 = str2;
        str2 = str1;
    }
    
}
