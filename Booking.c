#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<time.h>

struct Passanger
{
    char Fname[50];
    char Lname[50];
    int Number[10];
    char Address[150];
    int Date_of_departure;
    char destination[20];
    char class[20];
    int Number_of_seat;
    char Type_by_food[6];
    int Origin;
};

void main()
{
    struct Passanger Suyog;

    printf("Enter Your First Name : ");
    scanf("%s/n/n",&Suyog.Fname);

    printf("Enter Your Last Name : ");
    scanf("%s/n/n",&Suyog.Lname);

    printf("Enter Your Mobile Number : ");
    scanf("%s",&Suyog.Number);

    return 0;
}