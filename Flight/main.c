#include <stdio.h>
#include "booking.h"
//#include "complain.h"
#include "about.h"
#include "manage.h"

void routes(){
     int flag;
    char Local_destination[][20] = {"Mumbai","delhi","hyderabad","chennai","bengaluru"};
    char Internation_destination[][20]={"london","paris","san-fransico","tokyo","berlin"};

    printf("******** Following are the local flights available ********\n\n");
    for(int i=0;i<5;i++){
        printf("\n\n\n");
        for(int k=0;k<5;k++){
            printf("Flight from %s to %s \n",Local_destination[i],Local_destination[k]);
        }
    }

    printf("******** Following are the international flights available ********\n\n");
    for(int o=0;o<5;o++){
      printf("\n\n\n");
      for(int p=0;p<5;p++){
        printf("Flight from %s to %s \n",Local_destination[o],Internation_destination[p]);
        }
    }

   printf("\n\n\n");


}


int main(){
    int opt;
    system("COLOR 4f");
    do
    {
		printf("\n\n\t\t\t\t ************************************************************************");
		printf("\n\t\t\t\t                   Welcome to SVNIT's airline system                   ");
		printf("\n\t\t\t\t   *******************************************************************");
        printf("\n\n\t\t\t\t   ************************* MENU ************************************");
		printf("\n\t\t\t\t Please enter your choice from below (1-13):");
        printf("\n\n\t\t\t\t 0. Booking");
		printf("\n\n\t\t\t\t 1. Routes");
		printf("\n\n\t\t\t\t 2. complain");
		printf("\n\n\t\t\t\t 3. About");
        printf("\n\n\t\t\t\t 4. Management");
		printf("\n\n\t\t\t\t 5. Exit");
        printf("\n\n\t\t\t\t ********************************************************************");
		printf("\n\n\t\t\t\t Feel free to contact on 7721827790");
		printf("\n\n\t\t\t\t Enter your choice : ");

        scanf("%d",&opt);
        system("cls");

        switch (opt)
        {
        case 0:
            booking();
            break;
        case 1:
            routes();
            break;
        case 2:
            //complain();
            break;
        case 3:
            about();
            break;
        case 4:
            manage();
            break;
        case 5:
            printf("Exiting... Thankyou..");
            break;
        default:
			printf("\n\n\t SORRY INVALID CHOICE!");
			printf("\n\n\t PLEASE CHOOSE FROM 1-13");
			printf("\n\n\t Do not forget to chose from 1-13");
        }
        getch();
    } while (opt!=5);
    
    return 0;

}
