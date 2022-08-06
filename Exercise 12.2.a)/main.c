#include <stdio.h>
#include <string.h>

typedef struct Symbol{
    int digit;
    char Characters[3];
}Symbol;

void Conversion(FILE *file, char string[7]);

int main(){
    FILE *file;
    Symbol Blank={-1,""};
    int i;
    char string[7];
    if((file=fopen("Conversion.dat","wb"))==NULL)
        printf("Error in opening the file\n");
    else{
        for(i=0;i<10;i++)
            fwrite(&Blank,sizeof(Symbol),1,file);
    }
    if((file=fopen("Conversion.dat","rb+"))==NULL)
        printf("Error in opening the file\n");
    else{
        printf("Enter a digit, enter -1 to stop\n");
        scanf("%d", &Blank.digit);
        while(Blank.digit!=-1){
            printf("Enter the characters associated with the digit\n");
            fscanf(stdin," %s", Blank.Characters);
            fseek(file,Blank.digit*sizeof(Symbol),SEEK_SET);
            fwrite(&Blank,sizeof(Symbol),1,file);
            printf("Enter a digit, enter -1 to stop\n");
            scanf("%d", &Blank.digit);
        }
        printf("Enter the string you want to convert\n");
        scanf(" %s", &string);
        Conversion(file,string);
    }
    return 0;
}

void Conversion(FILE *file, char string[7]){
    int i, j, k; // Counters
    Symbol Blank={-1,""};
    for(j=0;j<7;j++){
        for(i=0;i<10;i++){
            fseek(file,i*sizeof(Symbol),SEEK_SET);
            fread(&Blank,sizeof(Symbol),1,file);
            if(Blank.digit!=1){
                for(k=0;k<strlen(Blank.Characters);k++){
                    if(string[j]==Blank.Characters[k])
                        printf("%d", Blank.digit);
                }
            }
        }
    }
}


