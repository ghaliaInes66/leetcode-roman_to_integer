#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool isCorrect(char *s){
	int i=0;
    while(s[i]!='\0'){
        if(s[i]!='I' && s[i]!='V' && s[i]!='X' && s[i]!='L' && s[i]!='C' && s[i]!='D' && s[i]!='M'){
            return false;
        }
        i++;
    }
    return true;
}

 char* input(){
    static char s[15];
do{
    printf("enter the roman number it has a maximum of 15 characters and the characters is I V X L C D M :");
    scanf("%s",s);}
while(! isCorrect(s));
    return s;
}

int integer(char c){
    int n;
    switch(c){
        case 'I':n=1;break;
        case 'V':n=5;break;
        case 'X':n=10;break;
        case 'L':n=50;break;
        case 'C':n=100;break;
        case 'D':n=500;break;
        case 'M':n=1000;break;
    }
    return n;
}

int romanToInt(char * s){
int nbr=0,i=0;
while(s[i]!='\0'){
    if((s[i]=='I'&&(s[i+1]=='V'||s[i+1]=='X'))||(s[i]=='X'&&(s[i+1]=='L'||s[i+1]=='C'))||(s[i]=='C'&&(s[i+1]=='D'||s[i+1]=='M'))){
     nbr=nbr-integer(s[i]);
    }
    else{
        nbr=nbr+integer(s[i]);
    }
    i++;
}
return nbr;
}

void output(int output){
    printf("%i",output);
}

int main(){
	int nbr=romanToInt(input());
	output(nbr);
}
