#include <stdio.h>
#include "conio2.h"
#include <stdlib.h>
#include <string.h>
#include "rlyres.h"
int main()
{

    int choice,ticket_no,result;
    Passenger *ptr;
    add_trains();
    char* pmob_no,*ptrain_no;
    int  *pticket_no;
    char* train_no;
    while(1)
    {

        choice = enterchoice();
        if(choice == 9)
        {
            textcolor(LIGHTBLUE);
            printf("\nVisit Again Thankyou!!\n");
            textcolor(WHITE);
            exit(0);
        }
        switch(choice)
        {
        case 1:
            clrscr();
            view_trains();
            getch();
            clrscr();
            break;
        case 2:
            ptr=get_passenger_details();
            clrscr();
            if(ptr!=NULL)
            {
                ticket_no = book_ticket(*ptr);
                if(ticket_no==-1)
                {
                    textcolor(LIGHTRED);
                    printf("BOOKING FAILED!");
                }
                else
                {
                    textcolor(LIGHTGREEN);
                    printf("TICKET SUCCESFULLY BOOKED\nYour ticket number is %d!",ticket_no);
                }
                textcolor(WHITE);
                printf("\nPress any key to go back to the main screen");
                getch();
                clrscr();
            }
            break;
        case 3:
            clrscr();
            ticket_no = accept_ticket_no();
            if(ticket_no!=0)
            {
                view_ticket(ticket_no);
            }
            textcolor(WHITE);
            printf("\nPress any key to go to the main screen!");
            getch();
            clrscr();
            break;
        case 4:
            clrscr();
            pmob_no=accept_mob_no();
            if(pmob_no!=NULL)
            {
                pticket_no=get_ticket_no(pmob_no);
                view_all_tickets(pmob_no,pticket_no);
            }
            clrscr();
            break;
        case 5:
            clrscr();
            view_all_bookings();
            printf("\npress any key to return to the main screen");
            getch();
            clrscr();

            break;
        case 6:
            clrscr();
            ptrain_no=accept_train_no();
            if(ptrain_no!=NULL)
            {
                view_booking(ptrain_no);
            }
            getch();
            clrscr();
            break;
        case 7:
            clrscr();
            ticket_no = accept_ticket_no();
            if(ticket_no!=0)
            {
                result = cancel_ticket(ticket_no);
                if(result==0)
                {
                    textcolor(LIGHTRED);
                    printf("Sorry, No tickets Booked against ticket number %d",ticket_no);

                }
                else if(result==1)
                {
                    textcolor(LIGHTGREEN);
                    printf("Ticket number %d Succesfully canceled",ticket_no);
                }
                else if(result==2)
                {
                    textcolor(LIGHTRED);

                    printf("Sorry, Error in cancellation Try Again");
                }
                textcolor(WHITE);
                printf("\n\nPress any key to go back to the main screen");
            }

            getch();
            clrscr();
            break;
        case 8:
            clrscr();
            train_no=accept_train_no();
            if(train_no!=NULL)
            {
                result=cancel_train(train_no);
            }
            if(result==0)
            {
                textcolor(LIGHTRED);
                printf("Sorry! No Train is there against train no %s",train_no);
            }
            else if(result==1)
            {
                textcolor(LIGHTGREEN);
                printf("Train No %s Successfully Cancelled",ticket_no);
            }
            else if(result==2)
            {
                textcolor(LIGHTRED);
                printf("There is something Error While Removing and Renaming of File! PLEASE TRY AGAIN!");
            }
            textcolor(WHITE);
            printf("\nPress any key to go to the main screen");
            getch();
            clrscr();
            break;

            break;
        default:
            textcolor(LIGHTRED);
            printf("\nWrong Input! Try again!!");
            getch();
            clrscr();
        }
    }

    return 0;
}
