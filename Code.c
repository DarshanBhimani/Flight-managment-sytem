#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<time.h>

typedef struct Airplane
{
    char Name[50];
    int flight_id;
    int capacity;
    struct arrival{
        int hh;
        int mm;
    }arrive;
    struct departure{
        int hh;
        int mm;
    }depart;
    char Class[50];
}
flight;

int main();

void Up_date(int id,int hh,int mm,int data)
{
    flight fg;
    FILE * f1, * f2;
    if(data == 1)
    {
        f1 = fopen("data.txt","rb");
        f2 = fopen("temp.txt","wb");
    }
    else
    {
        f1 = fopen("data1.txt","rb");
        f2 = fopen("temp.txt","wb");       
    }
    while(fread(&fg,sizeof(flight),1,f1))
    {
        if(fg.flight_id == id && fg.arrive.hh == hh && fg.arrive.mm == mm)
        {
            printf("Enter the new cpacity : ");
            scanf("%d",&fg.capacity);
            printf("Enter the new class : ");
            scanf("%s",fg.Class);
        }
        fwrite(&fg,sizeof(flight),1,f2);
    }
    fclose(f1);
    fclose(f2);
    if(data == 1)
    {
        f1 = fopen("data.txt","wb");
        f2 = fopen("temp.txt","rb");
    }
    else
    {
        f1 = fopen("data1.txt","wb");
        f2 = fopen("temp.txt","rb");       
    }
    while(fread(&fg,sizeof(flight),1,f2))
    {
        fwrite(&fg,sizeof(flight),1,f1);
    }
    fclose(f1);
    fclose(f2);
    printf("Updated successfully ..");
    getch();
    main();
}

void Insert()
{
    FILE* fp, * fp1;
    int data;
    while(1)
    {
        int choice;
        printf("Enter the number 1 or 2 for insertion/updation in list 1 or list 2 : ");
        scanf("%d",&choice);
        if(choice == 1){
            fp = fopen("data.txt","ab");
            data = 1;
            break;
        }
        else if(choice == 2)
        {
            fp = fopen("data1.txt","ab");
            data = 2;
            break;            
        }
        else
        {
            printf("Please enter 1 or 2 only..");
        }
    }

    if(fp==NULL)
    {
        printf("Data cannot be saved.");
        return;
    }
    flight fl;
    flight f;

    printf("Enter the arrival time in HH MM format : ");
    scanf("%d",&fl.arrive.hh);
    scanf("%d",&fl.arrive.mm);

    while(1)
    {
        int id;
        printf("Enter the flight id(can be 1-100) : ");
        scanf("%d",&id);
        if(id>0 && id<101){
            fl.flight_id = id;
            printf("Checking the data..\n");
            break;
        }
        else
        {
            printf("PLease choose the number between 1 to 100 (inclusive)..");
        } 
    }

    fp1 = fopen("data.txt","rb");
    while(fread(&f,sizeof(flight),1,fp1))
    {
        if(f.flight_id == fl.flight_id && f.arrive.hh == fl.arrive.hh && f.arrive.mm == fl.arrive.mm)
        {
            fclose(fp);
            fclose(fp1);
            int ch;
            printf("Given flight is already in the list.. Enter 1 for updation or 2 for exit : ");
            scanf("%d",&ch);
            if(ch==1)
            {
                Up_date(f.flight_id,f.arrive.hh,f.arrive.mm,data);
            }
            else if(ch==2)
            {
                printf("Exiting ..");
            }
            else{
                printf("Please choose either 1 or 2 number..");
            }
        }
    }

    printf("Enter the flight name : ");
    fflush(stdin);
    gets(fl.Name);

    printf("Enter the capacity of flight : ");
    scanf("%d",&fl.capacity);

    printf("Enter the departure time in HH MM format : ");
    scanf("%d",&fl.depart.hh);
    scanf("%d",&fl.depart.mm);

    printf("Enter the class (VIP/VVIP/PUBLIC) : ");
    while(1){
        char ch[5];
        scanf("%s",ch);
        if(!strcmp(ch,"VIP") || !strcmp(ch,"VVIP") || !strcmp(ch,"PUBLIC"))
        {
            strcpy(fl.Class,ch);
            break;
        }
        else{
            printf("Enter correctly \n");
        }
    }
    if(fwrite(&fl,sizeof(flight),1,fp)){
        printf("Data inserted successfully ... Thankyou");
    }
    else{
        printf("Data not inserted. Please try agin.");
    }

    fclose(fp);
    fclose(fp1); 
}

void Display()
{
    flight fl;
    FILE *fp;
    while(1)
    {
        int choice;
        printf("Enter the number 1 or 2 for display of list 1 or list 2 : ");
        scanf("%d",&choice);
        if(choice == 1){
            fp = fopen("data.txt","rb");
            break;
        }
        else if(choice == 2)
        {
            fp = fopen("data1.txt","rb");
            break;            
        }
        else
        {
            printf("Please enter 1 or 2 only..");
        }
    }
    while(fread(&fl,sizeof(flight),1,fp))
    {
        printf("%-5d%-10s",fl.flight_id,fl.Name);
        printf("%3d:%d",fl.arrive.hh,fl.arrive.mm);
        printf("%3d:%d",fl.depart.hh,fl.depart.mm);
        printf("%7s%5d",fl.Class,fl.capacity);
        printf("\n");
    }
    fclose(fp);
}

void Delete()
{
    flight fl;
    FILE *fp, *fp1;
    int id, found = 0;
    int choice;
    while(1)
    {
        printf("Enter the number 1 or 2 for deletion in list 1 or list 2 : ");
        scanf("%d",&choice);
        if(choice == 1){
            fp = fopen("data.txt","rb");
            fp1 = fopen("temp.txt","wb");
            break;
        }
        else if(choice == 2)
        {
            fp = fopen("data1.txt","rb");
            fp1 = fopen("temp.txt","wb"); 
            break;            
        }
        else
        {
            printf("Please enter 1 or 2 only..");
        }
    }
    if(fp==NULL || fp1==NULL)
    {
        printf("Data cannot be deleted at this moment. Please try again..");
        return;
    }
    printf("Enter the id of the flight to be deleted : ");
    scanf("%d",&id);
    while(fread(&fl,sizeof(flight),1,fp))
    {
        if(fl.flight_id==id){
            found = 1;
        }
        else{
            fwrite(&fl,sizeof(flight),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);
    if(found){
        if(choice == 1){
            fp = fopen("data.txt","wb");
            fp1 = fopen("temp.txt","rb");
        }
        else
        {
            fp = fopen("data1.txt","wb");
            fp1 = fopen("temp.txt","rb");       
        }

        while(fread(&fl,sizeof(flight),1,fp1))
        {
            fwrite(&fl,sizeof(flight),1,fp);
        }

        printf("Data has been successfully deleted..");
    }
    else
    {
        printf("The given id is not found..");
    }
    fclose(fp);
    fclose(fp1);
}

void getNumFlights()
{
    flight fl;
    FILE * fp;
    while(1)
    {
        int choice;
        printf("Enter the number 1 or 2 for display of list 1 or list 2 : ");
        scanf("%d",&choice);
        if(choice == 1){
            fp = fopen("data.txt","rb");
            break;
        }
        else if(choice == 2)
        {
            fp = fopen("data1.txt","rb");
            break;            
        }
        else
        {
            printf("Please enter 1 or 2 only..");
        }
    }
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(flight);
    printf("No. of flights available are : %d",n);
    fclose(fp);
}

int is_Empty()
{
    flight fl;
    FILE * fp;
    while(1)
    {
        int choice;
        printf("Enter the number 1 or 2 for display of list 1 or list 2 : ");
        scanf("%d",&choice);
        if(choice == 1){
            fp = fopen("data.txt","rb");
            break;
        }
        else if(choice == 2)
        {
            fp = fopen("data1.txt","rb");
            break;            
        }
        else
        {
            printf("Please enter 1 or 2 only..");
        }
    }
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(flight);
    fclose(fp);
    if(n==0){
        return 1;
    }
    return 0;
}

int isFull()
{
    flight fl;
    FILE * fp;
    while(1)
    {
        int choice;
        printf("Enter the number 1 or 2 for display of list 1 or list 2 : ");
        scanf("%d",&choice);
        if(choice == 1){
            fp = fopen("data.txt","rb");
            break;
        }
        else if(choice == 2)
        {
            fp = fopen("data1.txt","rb");
            break;            
        }
        else
        {
            printf("Please enter 1 or 2 only..");
        }
    }
    fseek(fp,0,SEEK_END);
    int n = ftell(fp)/sizeof(flight);
    fclose(fp);
    if(n==10){
        return 1;
    }
    return 0;
}

void updateFlightStatus()
{

}

void getLongestStay()
{

}

void listUnique()
{

}

void listUnion()
{

}

void listIntersection()
{

}

void listDifference()
{

}

void listSymmetricDifference()
{

}


int main()
{
    int opt,e=0,f=0;
    do
    {
		printf("\n\n\t\t\t ************************************************************************");
		printf("\n\t\t\t                   Welcome to Suyog's airline system                   ");
		printf("\n\t\t\t   *******************************************************************");
        printf("\n\n\t\t\t   ************************* MENU ************************************");
		printf("\n\t\t\t Please enter your choice from below (1-13):");
        printf("\n\n\t\t\t 0. Display the records");
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
        case 0:
            Display();
            break;
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
            e = is_Empty();
            if(e){
                printf("The list is empty..");
            }
            else{
                printf("The list is non empty..");
            }
            break;
        case 5:
            f = isFull();
            if(e){
                printf("The list is full..");
            }
            else{
                printf("The list is not full..");
            }
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
        default:
			printf("\n\n\t SORRY INVALID CHOICE!");
			printf("\n\n\t PLEASE CHOOSE FROM 1-13");
			printf("\n\n\t Do not forget to chose from 1-13");
        }
        getch();
    } while (opt!=13);
    
    return 0;
}
