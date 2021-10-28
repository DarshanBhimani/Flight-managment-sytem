#include<stdio.h>

int main()
{
    int choice;

    while(1)
    {
        printf("\nChoose the category of your complain:\n");
        printf("\n1. Airport Handling\n");
        printf("\n2. Baggage Delivery\n");
        printf("\n3. Booking and Ticketing\n");
        printf("\n4. Other\n");
        printf("\n5. I don't have any complaint.\n");
        printf("\nEnter your choice from 1 to 5: ");
        
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: complaint();
                    break;
            case 2: complaint();
                    break;
            case 3: complaint();
                    break;
            case 4: complaint();
                    break;
            case 5: 
                    break;
            default: printf("\nPlease Enter a valid choice.\n");
        }
    }
}