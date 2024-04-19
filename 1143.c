#include <stdio.h>
#include <string.h>

#define max(a, b) ((a) > (b)) ? (a) : (b)

int lcs(char * restrict text1 , char *restrict text2 , int i , int j, int mem[][1000]){
   
    if(text1[i]=='\0' || text2[j]=='\0'){
        return 0;
    }
    if(mem[i][j]!=-1){
        return mem[i][j];
    }

    if (text1[i] == text2[j]){
        mem[i][j] = 1 + lcs(text1,text2, i+1 , j+1,mem);
        return mem[i][j];
    }
    mem[i][j] = max(lcs(text1, text2 , i,j+1,mem), lcs(text1,text2, i+1 , j,mem));
    return mem[i][j];

}

int longestCommonSubsequence(char* restrict text1, char* restrict text2) {
    int mem[1000][1000];
    memset(mem, -1, sizeof(mem));
    return lcs(text1,text2,0,0,mem);
}
