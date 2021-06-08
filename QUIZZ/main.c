#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define max 10
char *stkQ[max][256];
int stkAns[max];
int top = -1;

void pushAns(int a)
{
    top = top + 1;
    stkAns[top] = a;
}
void main()
{
    printf("*****WELCOME*****\n");
    printf("QUIZ GAME USING STACK AS DATA STRUCTURE\n");
    printf("================================================================");

    int points = 0, i, ans;
    char name;

    char stkQ[max][256] = {
        "Final Question ==>\nWhich African country is very famous for chocolate? \n1)Nigeria \t2)Ethiopia \t3)DR Congo \t4)Ghana",
        "9th Question ==>\nThe first World Environment Day was held in which year?\n1)1974\t2)1964\t3)1850\t4)1900",
        "8th Question ==>\nWhere is the 'Raffles Hotel' in the world?\n1)India\t2)Dubai\t3)USA\t4)Russia",
        "7th Question ==>\nWhich animal is known as the 'Ship of the Desert'?\n1)Dog\t2)Camel\t3)Cow\t4)Mouse",
        "6th Question ==>\nWho invented the Computer?\n1)Charles Babbage \t2)Edison\t3)Ross Geller\t4)Dennis Richard",
        "5th Question ==>\nWho successfully built and flew the world’s first Aeroplane?\n1)Wright Brothers\t2)Newton\t3)Tim Burnerss\t4)Grahm Bell",
        "4th Question ==>\nWho invented the Printing Press? \n1)Newton \t2)Johannes Gutenberg \t3)Darwin \t4)Farady",
        "3rd Question ==>\nWho invented the Telephone? \n1)Marie \t2)Curie \t3)Alexander Graham Bell \t4)Galileo Galilei",
        "2nd Question ==>\nWho invented the Light Bulb? \n1)Nikola Tesla \t2)Pythagoras \t3)Ada Lovelace \t4)Thomas Alva Edison",
        "1st Question ==>\nWorld’s first artificial Satellite was?\n1)Microsat \t2)GSAT-17 \t3)PSLV \t4)Sputnik I."

    };

    pushAns(4); //push 10 ans.
    pushAns(1); //push 9 ans.
    pushAns(2); //push 8 ans.
    pushAns(2); //push 7 ans.
    pushAns(1); //push 6 ans.
    pushAns(1); //push 5 ans.
    pushAns(2); //push 4 ans.
    pushAns(3); //push 3 ans.
    pushAns(4); //push 2 ans.
    pushAns(4); //push 1 ans.

    printf("\nWelcome to Quiz.\n");
    printf("\nEnter your name : \n");
    name = scanf("%s", &name);

    for (i = 9; i >= 0; i--)
    {
        printf("\n\nThis question is for 10 points\n");
        printf("%s\n", stkQ[i]);
        printf("\nEnter your answer : \n");
        scanf("%d", &ans);

        if (ans == stkAns[i])
        {
            points = points + 10;
            printf("\nCongrats!!!\n You earn %d points\n", points);
        }

        else
        {
            points = points - 5;
            printf("\nSorry, the correct answer is %d. \n", stkAns[i]);
            printf("\nYour score now is %d points\n", points);
            //break;
        }
    }

    printf("\nYour score is %d points!!!\n", points);
}