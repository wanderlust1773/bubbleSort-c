#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // write함수 오류떠서 추가해주었습니다.

#define NSTRINGS 16
#define MAXLENGTH 1024

void bubbleSort(char **, int);
void outputLine(char *);
char *inputLine(void);


int main(int argc, char**argv) {
    int n,nStrings;
    char *p, *q, *line;
    char *strptrs[NSTRINGS];
    char *strings[NSTRINGS][MAXLENGTH];
    
    line = (char *)malloc(sizeof(char));
    
    for (nStrings = 0; nStrings < NSTRINGS; nStrings++){
        
        if ((line = inputLine()) == NULL){
            break;
        }
        
        for(p = line, q = strings[nStrings]; *p != '\0'; p++, q++)
            *q = *p;
        *q = '\0';
        
        strptrs[nStrings] = strings[nStrings];
    }
    
    bubbleSort(strptrs, nStrings);
    
    for (n=0; n < nStrings; n++)
        outputLine(strptrs[n]);

    exit(0);
}


void bubbleSort(char **strings, int nStrings)
{
    int i,j;
    char *tmp;
    int notdone;
    
    j = nStrings;
    notdone = 1;
    
    while(notdone) {
        notdone = 0;
        j-=1;
        
        for (i = 0; i < j; i++){
            if(strlen(strings[i]) > strlen(strings[i+1])) {
                tmp = strings[i+1];
                strings[i+1] = strings[i];
                strings[i] = tmp;
                notdone = 1;
            }
        }
    }
}

char *inputLine(void) {
    char *input;
    
    input = (char *)malloc(sizeof(char));
    if (gets(input))
        return input;
    else
        return NULL;
}


void outputLine(char *str){
    write(1,str,strlen(str));
    write(1,"\n",1);
    
}

