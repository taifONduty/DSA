#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void to_upper(char *str){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i] = str[i] - 32;
        }
    }
}

int main(){
    FILE *fptr;
    int count=0;
    char str[100];
    fptr = fopen("nawar.txt","r"); //File read mode e open korar function jeta file tar address return kore(pointer hishebe)

    if(fptr == NULL){ //file open na korle error msg diye program stop korbe
        printf("Could not open file\n");
        exit(1);
    }
    while(fscanf(fptr,"%s",str)!=EOF){ //file theke ekta ekta kore string scan kortese and loop ta EOF (End of File) porjonto cholbe
        to_upper(str); // Prottek ta string ke uppercase e convert korbe
        if(strcmp(str,"DHAKA") == 0){ // file theke scan kora string ar "DHAKA" string er sathe compare korbe
            count++;
        }
    }
    
    fclose(fptr);
    printf("Number of times Dhaka is mentioned in the file is %d\n",count);
    return 0;
}