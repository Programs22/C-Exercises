#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int Deck[][13]);
void deal(int Deck[][13], const char *Face[], const char *Suit[]);

int main(){
    const char *Suit[]={"Hearts", "Clubs", "Spades", "Diamonds"};
    const char *Face[]={"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int Deck[4][13]={0};
    srand(time(0));
    shuffle(Deck);
    deal(Deck,Face,Suit);
    return 0;
}

void shuffle(int Deck[][13]){
    int row, column, card;
    for(card=1;card<=52;card++){
        do{
            row=rand()%4;
            column=rand()%13;
        }while(Deck[row][column]!=0);
        Deck[row][column]=card;
    }
}

void deal(int Deck[][13], const char *Face[], const char *Suit[]){
    int row, column, card, counter=0, count_cards, count_pairs=0, i, j, colour=1;
    char *face[5], *suit[5]; // Arrays to hold the faces and suits of the cards dealt in the hand
    for(card=1;card<=5;card++){
        for(row=0;row<4;row++){
            for(column=0;column<13;column++){
                if(Deck[row][column]==card){
                    printf("%s of %s\n", Face[column], Suit[row]);
                    face[counter]=Face[column];
                    suit[counter]=Suit[row];
                    counter++; // counter is used to fill in the arrays face and suit
                }
            }
        }
    }
    for(i=0;i<5;i++){ // We use counters i and j here
        count_cards=1;
        for(j=i+1;j<5;j++){
            if(face[i]==face[j])
                count_cards++; // Counting the number of cards which are same in face in the hand
        }
        if(count_cards==2){
            printf("You have a pair in your hand\n");
            count_pairs++; // Counting the pairs in the hand
        }
        else if(count_cards==3)
            printf("You have a three of a kind in your hand\n");
        else if(count_cards==4)
            printf("You have a four of a kind in your hand\n");
    }
    if(count_pairs==2)
        printf("You have two pairs in your hand\n");
    for(i=1;i<5;i++){
        if(suit[0]==suit[i])
            colour++; // colour is used to count whether all five cards are of the same suit
    }
    if(colour==5)
        printf("You have a flush in your hand\n");
}
