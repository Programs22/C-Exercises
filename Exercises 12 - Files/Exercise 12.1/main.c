#include <stdio.h>

typedef struct hardware{
    int code;
    char Name[30];
    int stock;
    float price;
}Hardware;

void ListRecords(FILE *file);
void updateRecord(FILE *file);
void newRecord(FILE *file);
void deleteRecord(FILE *file);
void ListSpecificRecord(FILE *file);
void Sale(FILE *file);

int main(){
    FILE *file;
    int choice, i;
    Hardware Record={0,"",0,0.0};
    if((file=fopen("Hardware.dat","wb"))==NULL)
        printf("The file couldn't open\n");
    else{
        for(i=1;i<=100;i++)
            fwrite(&Record,sizeof(Hardware),1,file);
    }
    if((file=fopen("Hardware.dat","rb+"))==NULL)
        printf("The file couldn't be opened\n");
    else{
        printf("Enter the code of the product, enter 0 to stop\n");
        scanf("%d", &Record.code);
        while(Record.code!=0){
            printf("Enter the name of the product, how much of it is in stock, and it's price\n");
            fscanf(stdin,"%s%d%f",Record.Name,&Record.stock,&Record.price);
            fseek(file,(Record.code-1)*sizeof(Hardware),SEEK_SET);
            fwrite(&Record,sizeof(Hardware),1,file);
            printf("Enter the code of the product, enter 0 to stop\n");
            scanf("%d", &Record.code);
        }
        printf("Enter a choice from the menu\n");
        printf("0 - List all records\n");
        printf("1 - Update record\n");
        printf("2 - Enter new record\n");
        printf("3 - Delete record\n");
        printf("4 - List a specific record\n");
        printf("5 - Start a sale of a record\n");
        printf("6 - End of program\n");
        scanf("%d", &choice);
        while(choice>=0&&choice<6){
            rewind(file);
            switch(choice){
                case 0: ListRecords(file); break;
                case 1: updateRecord(file); break;
                case 2: newRecord(file); break;
                case 3: deleteRecord(file); break;
                case 4: ListSpecificRecord(file); break;
                case 5: Sale(file); break;
            }
            printf("Enter a choice from the menu\n");
            printf("0 - List all records\n");
            printf("1 - Update record\n");
            printf("2 - Enter new record\n");
            printf("3 - Delete record\n");
            printf("4 - List a specific record\n");
            printf("5 - Start a sale of a record\n");
            printf("6 - End of program\n");
            scanf("%d", &choice);
        }
        fclose(file);
    }
    return 0;
}

void ListRecords(FILE *file){
    Hardware Record={0,"",0,0.0};
    while(!feof(file)){
        fread(&Record,sizeof(Hardware),1,file);
        if(Record.code!=0)
            printf("%d %s %d %.2f\n", Record.code, Record.Name, Record.stock, Record.price);
    }
}

void updateRecord(FILE *file){
    int code;
    Hardware Record={0,"",0,0.0};
    printf("Enter the code of the product you want to update\n");
    scanf("%d", &code);
    fseek(file,(code-1)*sizeof(Hardware),SEEK_SET);
    fread(&Record,sizeof(Hardware),1,file);
    if(Record.code==0)
        printf("This product doesn't exist\n");
    else{
        printf("Enter the updated name, stock value and price of the product\n");
        scanf(" %s%d%f", Record.Name, &Record.stock, &Record.price);
        fseek(file,(Record.code-1)*sizeof(Hardware),SEEK_SET);
        fwrite(&Record,sizeof(Hardware),1,file);
    }
}

void newRecord(FILE *file){
    Hardware Record={0,"",0,0.0};
    int code;
    printf("Enter the code of the product you want to create\n");
    scanf("%d", &code);
    fseek(file,(code-1)*sizeof(Hardware),SEEK_SET);
    fread(&Record,sizeof(Hardware),1,file);
    if(Record.code!=0)
        printf("Record already exists\n");
    else{
        Record.code=code;
        printf("Enter the name of the product, it's stock value and price\n");
        scanf(" %s%d%f", Record.Name, &Record.stock, &Record.price);
        fseek(file,(Record.code-1)*sizeof(Hardware),SEEK_SET);
        fwrite(&Record,sizeof(Hardware),1,file);
    }
}

void deleteRecord(FILE *file){
    Hardware Record;
    Hardware Blank={0,"",0,0.0};
    int code;
    printf("Enter the code of the product you want to delete\n");
    scanf("%d", &code);
    fseek(file,(code-1)*sizeof(Hardware),SEEK_SET);
    fread(&Record,sizeof(Hardware),1,file);
    if(Record.code==0)
        printf("The product doesn't exist\n");
    else{
        fseek(file,(code-1)*sizeof(Hardware),SEEK_SET);
        fwrite(&Blank,sizeof(Hardware),1,file);
    }
}

void ListSpecificRecord(FILE *file){
    Hardware Record={0,"",0,0.0};
    int code;
    printf("Enter the code of the product you want to check\n");
    scanf("%d", &code);
    fseek(file,(code-1)*sizeof(Hardware),SEEK_SET);
    fread(&Record,sizeof(Hardware),1,file);
    if(Record.code==0)
        printf("No information about this product\n");
    else
        printf("%d %s %d %.2f\n", Record.code, Record.Name, Record.stock, Record.price);
}

void Sale(FILE *file){
    Hardware Record={0,"",0,0.0};
    int code, amount;
    printf("Enter the code of the product you want to buy\n");
    scanf("%d", &code);
    fseek(file,(code-1)*sizeof(Hardware),SEEK_SET);
    fread(&Record,sizeof(Hardware),1,file);
    if(Record.code==0)
        printf("The product doesn't exist\n");
    else{
        printf("Enter the amount you want to buy\n");
        scanf("%d", &amount);
        if(amount<=Record.stock){
            Record.stock-=amount;
            printf("The price will be %.3f\n", amount*Record.price);
            fseek(file,(Record.code-1)*sizeof(Hardware),SEEK_SET);
            fwrite(&Record,sizeof(Hardware),1,file);
        }
        else
            printf("We don't have enough in stock of this product\n");
    }
}