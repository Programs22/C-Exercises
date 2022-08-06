#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int Deck[][13]);
int deal(int Deck[][13], const char *Face[], const char *Suit[]);

int main(){
    const char *Suit[]={"Hearts", "Clubs", "Spades", "Diamonds"};
    const char *Face[]={"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int Deck[4][13]={0};
    int player1, player2, i, j; // i and j are counters for the for loops
    srand(time(0));
    shuffle(Deck);
    printf("Player 1, your hand has been dealt\n");
    player1=deal(Deck,Face,Suit);
    for(i=0;i<4;i++)
        for(j=0;j<13;j++)
            Deck[i][j]=0;
    shuffle(Deck);
    printf("Player 2, your hand has been dealt\n");
    player2=deal(Deck,Face,Suit);
    if(player1>player2)
        printf("Winner: Player 1\n");
    else if(player2>player1)
        printf("Winner: Player 2\n");
    else
        printf("Tie\n");
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

int deal(int Deck[][13], const char *Face[], const char *Suit[]){
    int row, column, card, counter=0, count_cards, count_pairs=0, i, j, colour=1, winner=-1; // winner is used to return the ranking of the winning hand of the player
    int rank[5]={0}; // An array to hold all the available hands the player has, value 1 if hand is present, value 0 if hand is not present
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
            rank[0]=1;
            count_pairs++; // Counting the pairs in the hand
        }
        else if(count_cards==3){
            printf("You have a three of a kind in your hand\n");
            rank[2]=1;
        }
        else if(count_cards==4){
            printf("You have a four of a kind in your hand\n");
            rank[4]=1;
        }
    }
    if(count_pairs==2){
        printf("You have two pairs in your hand\n");
        rank[1]=1;
    }
    for(i=1;i<5;i++){
        if(suit[0]==suit[i])
            colour++; // colour is used to count whether all five cards are of the same suit
    }
    if(colour==5){
        printf("You have a flush in your hand\n");
        rank[3]=1;
    }
    for(i=0;i<5;i++){
        if(rank[i]==1)
            winner=i;
    }
    return winner;
}
