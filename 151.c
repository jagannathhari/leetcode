#include <stdio.h>
#include <string.h>

#define swap(a, b)                                                             \
    ({                                                                         \
        __typeof__(a) temp = a;                                                    \
        a = b;                                                                 \
        b = temp;                                                              \
    })

void reverseString(char * restrict s, size_t n){
    for(int i=0;i<(n/2);i++){
        swap(s[i],s[n-i-1]);
    }
}

void removeExtraSpace(char *restrict s , int * restrict n){
    int write_head = 0;
    int total_space = 0;
    int i = 0;
    for(;s[i]!='\0';i++){
        if(s[i]!=' '){
            s[write_head++] = s[i];
            total_space = 0;
        }else{
            total_space++;
            if(total_space==1){
                s[write_head++] = s[i];
            }
        }
    }

    *n = write_head;
    s[write_head] = '\0';
}

char* reverseWords(char* restrict s) {
    int len;
    char *ans = s;
    removeExtraSpace(s,&len);
    reverseString(s,len);

    if(s[0]==' '){
        s++;
        len--;
    }
    if(s[len-1]==' ') s[len-1]='\0';
    int start= 0;
    for(int i=0;i<len+1;i++){
        if(s[i] == ' ' || s[i] == '\0'){
            reverseString(&s[start],i-start);
            start = i+1;
        }    
    }
    return s;
}
