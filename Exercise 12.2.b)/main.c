#include <stdio.h>
#include <string.h>

typedef struct Symbol{
    int digit;
    char Characters[3];
}Symbol;

void Conversion(FILE *file, int phone[7]);

int main(){
    FILE *file;
    Symbol Blank={-1,""};
    int i;
    int phone[7];
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
        printf("Enter the phone you want to convert\n");
        for(i=0;i<7;i++)
            scanf("%d", &phone[i]);
        Conversion(file,phone);
    }
    return 0;
}

void Conversion(FILE *file, int phone[7]){
    int i, j, k, m, n, o, p; // Counters
    int counter=0;
    char result[7];
    Symbol Digit1={-1,""}, Digit2={-1,""}, Digit3={-1,""}, Digit4={-1,""}, Digit5={-1,""}, Digit6={-1,""}, Digit7={-1,""};
    fseek(file,(phone[0])*sizeof(Symbol),SEEK_SET);
    fread(&Digit1,sizeof(Symbol),1,file);
    for(i=0;i<strlen(Digit1.Characters);i++){
        result[counter]=Digit1.Characters[i];
        counter++;
        fseek(file,(phone[1])*sizeof(Symbol),SEEK_SET);
        fread(&Digit2,sizeof(Symbol),1,file);
        for(j=0;j<strlen(Digit2.Characters);j++){
            result[counter]=Digit2.Characters[j];
            counter++;
            fseek(file,(phone[2])*sizeof(Symbol),SEEK_SET);
            fread(&Digit3,sizeof(Symbol),1,file);
            for(k=0;k<strlen(Digit3.Characters);k++){
                result[counter]=Digit3.Characters[k];
                counter++;
                fseek(file,(phone[3])*sizeof(Symbol),SEEK_SET);
                fread(&Digit4,sizeof(Symbol),1,file);
                for(m=0;m<strlen(Digit4.Characters);m++){
                    result[counter]=Digit4.Characters[m];
                    counter++;
                    fseek(file,(phone[4])*sizeof(Symbol),SEEK_SET);
                    fread(&Digit5,sizeof(Symbol),1,file);
                    for(n=0;n<strlen(Digit5.Characters);n++){
                        result[counter]=Digit5.Characters[n];
                        counter++;
                        fseek(file,(phone[5])*sizeof(Symbol),SEEK_SET);
                        fread(&Digit6,sizeof(Symbol),1,file);
                        for(o=0;o<strlen(Digit6.Characters);o++){
                            result[counter]=Digit6.Characters[o];
                            counter++;
                            fseek(file,(phone[6])*sizeof(Symbol),SEEK_SET);
                            fread(&Digit7,sizeof(Symbol),1,file);
                            for(p=0;p<strlen(Digit7.Characters);p++){
                                result[counter]=Digit7.Characters[p];
                                counter++;
                                printf("%s\n",result);
                                counter=6;
                            }
                            counter=5;
                        }
                        counter=4;
                    }
                    counter=3;
                }
                counter=2;
            }
            counter=1;
        }
        counter=0;
    }
}
