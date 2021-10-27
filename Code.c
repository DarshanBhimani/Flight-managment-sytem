#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include "ManageHeader.h"

struct Airplane
{
    char Name[50];
    int flight_id;
    int capacity;
    time_t arrival;
    time_t departure;
    char Class[50];
}
*flights;

int main()
{
    int opt;
    do
    {
		printf("\n\n\t\t\t ************************************************************************");
		printf("\n\t\t\t                   Welcome to Suyog's airline system                   ");
		printf("\n\t\t\t   *******************************************************************");
        printf("\n\n\t\t\t   ************************* MENU ************************************");
		printf("\n\t\t\t Please enter your choice from below (1-13):");
		printf("\n\n\t\t\t 1. Insert a record");
		printf("\n\n\t\t\t 2. Delete a record");
		printf("\n\n\t\t\t 3. Get the number of flights");
        printf("\n\n\t\t\t 4. Check whether list is empty");
        printf("\n\n\t\t\t 5. Check whether list is full");
        printf("\n\n\t\t\t 6. Update flight status");
        printf("\n\n\t\t\t 7. Get the longest stay in all flights");
        printf("\n\n\t\t\t 8. Remove duplicates(Make list unique)");
        printf("\n\n\t\t\t 9. Make union list");
        printf("\n\n\t\t\t 10. Make intersection list");
        printf("\n\n\t\t\t 11. Get difference between lists");
        printf("\n\n\t\t\t 12. Get Symmetric difference between lists");
		printf("\n\n\t\t\t 13. EXIT");
        printf("\n\n\t\t\t ********************************************************************");
		printf("\n\n\t\t\t Feel free to contact on 7721827790");
		printf("\n\n\t\t\t Enter your choice : ");

        scanf("%d",&opt);
        system("cls");

        switch (opt)
        {
        case 1:
            Insert();
            break;
        case 2:
            Delete();
            break;
        case 3:
            getNumFlights();
            break;
        case 4:
            is_Empty();
            break;
        case 5:
            isFull();
            break;
        case 6:
            updateFlightStatus();
            break;
        case 7:
            getLongestStay();
            break;
        case 8:
            listUnique();
            break;
        case 9:
            listUnion();
            break;
        case 10:
            listIntersection();
            break;
        case 11:
            listDifference();
            break;
        case 12:
            listSymmetricDifference();
            break;
        case 13:
            savefile();
            break;
        default:
			printf("\n\n\t SORRY INVALID CHOICE!");
			printf("\n\n\t PLEASE CHOOSE FROM 1-13");
			printf("\n\n\t Do not forget to chose from 1-13");
        }
        getch();
    } while (opt!=13);
    
    return 0;
}
