// written by Mo'meN Ali
// 2011

#include "access.h"
static const size_t size= sizeof(struct struct0);

void  eat_line(void)
{
	char Ch = '\0';
	while ((Ch = getchar()) != '\n');
}
short flights(void)
{
	short fleet_choice= 0;

	system("cls");
	printf(
		   " Welcome into Colossus Airlines,\n"
		   " We've 4 flights daily\n"
		   " Flight 102, 311, 444 & 519\n"
		   " choose any of them or (0) to quit\n"
		   "\nEnter Your choice\n"
		  );

	while (scanf("%hd", &fleet_choice) != 1) { 
		   eat_line();
		   puts("Please respond with a number");
	}
	eat_line();
	while (1) {
	      if (fleet_choice == 102)
			  break;
     else if (fleet_choice == 444)
		      break;
	 else if (fleet_choice == 519)
		      break;
	 else if (fleet_choice == 311)
		      break;
	 else if (fleet_choice == 0)
		      break;                 
	 else {
	     puts("Please respond with the appropiate flight");
	     scanf("%hd", &fleet_choice);
	     eat_line();
	 }
	}
	return fleet_choice;
}
char  menu(short flight_choice)
{
	char choice= '\0';

	switch (flight_choice) {
	case 102:
		printf("\n\t   Flight 102\n");
		break;
	case 444:
		printf("\n\t   Flight 444\n");
		break;
	case 519:
		printf("\n\t   Flight 519\n");
		break;
	case 311:
		printf("\n\t   Flight 311\n");
		break;
	}
    printf("\nHi, to choose a function, enter its letter label\n"
		   "  a) Show number of empty seats. (e)\n"
		   "  b) Show list of empty seats. (l)\n" 
		   "  c) Show alphabetical list of seats. (p)\n"
		   "  d) Assign a customer to a seat assignment. (a)\n"
		   "  e) Confirm a seat assignment. (c)\n"
		   "  f) Delete a seat assignment. (d)\n" 
		   "  g) Goto the flights menu again. (q)\n"
	      );

 choice= getchar();
 eat_line();
 while (choice < 'a' || choice > 'z') {
	 puts("Please respond with a character");
	 choice= getchar();
	 eat_line();
 }
 
 while (1) {
    	 if (choice == 'q')
     		 break;
    else if (choice == 'e')
	         break;
    else if (choice == 'l')
	         break;
    else if (choice == 'a')
	         break;
    else if (choice == 'p')
	         break;
    else if (choice == 'd')
	         break;
	else if (choice == 'c')
		    break;
    else {
          puts("Please respond with one of the appropiate letters (f-g-h-i-d-q)");
		  choice= getchar();
	      eat_line();
	}
 }
  return choice;
}
void assignCustomersTOseat(seatsInfo *ptrTOseat)
{
	FILE *fPtr;
	short rsve_no= 0;
    __int8 i, j;
	srand((unsigned int)time(0));
   
	puts ("Please, Enter the number of the reservations you want to make");
	scanf("%hd", &rsve_no);
	eat_line();

	for (j=i= 0; j < MAXSEATS; i++, ptrTOseat++)
		if (ptrTOseat->fName[0] == '\0' && j++ < rsve_no)  {
	         puts("Enter your first name"); 
		     gets(ptrTOseat->fName);	
		     puts("Enter your last name");
		     gets(ptrTOseat->lName);
			 ptrTOseat->assigment_ID= rand()%10000 + 1;
			 printf("Your seat is %hd chair alpha is %c and assigment confirmation ID= %hd\n", 
				                   ptrTOseat->seat_Num, ptrTOseat->seat_alpha, ptrTOseat->assigment_ID);
			 puts("\nPleae use the confirmation ID to confirm your seat\n if you want before closing the program\n");
		}	
}
__int8 conf_assignment(seatsInfo *ptrTOseat)
{
	int ass_ID= 0;
	__int8 i;

	puts("Enter the ID of the assignment you want to confirm");
	while ( (scanf("%d", &ass_ID) != 1) )
		    puts("confirmation ID is a number consists of 4 numbers");
	eat_line();

	for (i= 0; (i < MAXSEATS); i++, ptrTOseat++) 
		if ( (ass_ID == (ptrTOseat->assigment_ID)) ) {
			ptrTOseat->confirmation= 1;
			printf(" %s %s reservation confirmed.", ptrTOseat->fName, ptrTOseat->lName);
			return 1;
		}
	puts("This ID is unvalid");
	return 0;
}
__int8  del_SeatAssignment(seatsInfo *ptrTOseat)
{
	FILE *fPtr;
	char seat_alpha= '\0', fName[CHARS]= {0};
	__int8 i, flag= 0;

	for (i= 0; (i < MAXSEATS); i++, ptrTOseat++) 
		if (ptrTOseat->fName[0] != '\0') {
		    flag= 1;
			break;
		}
	if (flag == 0) {
		puts("This Flight has no reservations at all");
		return 0;
	}
	flag= 0;
	puts("Please Enter your reservation alpha");
	scanf("%c", &seat_alpha);
	eat_line();

	if (islower(seat_alpha)) 
		seat_alpha-= 32;
 			   
	for (i= 0; i < MAXSEATS; i++, ptrTOseat++) {
		if (ptrTOseat->seat_alpha == seat_alpha && ptrTOseat->fName[0] != '\0') {
		   ptrTOseat->fName[0]= '\0';
		   flag= 1;
		   break;
		}
	}
	if (flag == 0)
		puts("There's no such reservation on this flight");

    return 1;
}
void  show_number(seatsInfo *ptrTOseat)
{
	__int8 i, empSeats_no;

	for (empSeats_no=i= 0; i < MAXSEATS; i++, ptrTOseat++) 
		 if (ptrTOseat->fName[0] == '\0') 
		      ++empSeats_no;
		 
   if (empSeats_no > 1)
	   printf("There are %hd empty seats\n", empSeats_no);
   
   else if (empSeats_no == 1)
	   puts("There's only 1 seat left");
   
   else if (empSeats_no == 11)
       puts("All seats are empty");
   
   else if (empSeats_no == 0)
	   puts("There's no empty seats in this flight");
}
void  show_list(seatsInfo *ptrTOseat)
{
	__int8 i,empSeats, flag;

	for (i=empSeats=flag= 0; i < MAXSEATS; i++, ptrTOseat++)
		if (ptrTOseat->fName[0] == '\0') {
			printf("seat %c is empty\n", ptrTOseat->seat_alpha);
		    ++empSeats; flag= 1;
		}
    if (flag == 0)
		puts("There's no empty seats for this flight");
} 
void  showAlpha_list(seatsInfo *ptrTOseat)
{
	__int8 i, flag= 0;

	for (i= 0; i < MAXSEATS; i++, ptrTOseat++)
		if (ptrTOseat->fName[0] != '\0') {
			if (ptrTOseat->confirmation == 1)
	            printf("Seat %c is reserved for %s %s (CONFIRMED)\n", 
			                  ptrTOseat->seat_alpha, ptrTOseat->fName, ptrTOseat->lName);
			else if (ptrTOseat->confirmation == 0)
				     printf("Seat %c is reserved for %s %s (UNCONFIRMED)\n", 
			                      ptrTOseat->seat_alpha, ptrTOseat->fName, ptrTOseat->lName);
		    flag= 1;
		}

	if (flag == 0)
		puts("There's no reservations on this flight");
	if (i == 0)
		puts("There's no reserved seats");
}
void  read_data(seatsInfo *ptrTOseat, short flight_choice)
{
	FILE *fPtr;
	char ch= '\0';
	__int8 i;
	short readed_data= 0;
    
	if (flight_choice == 102) {
		if ( (fPtr= fopen("flight102.txt", "ab")) == NULL ) {
			perror("");
			exit(EXIT_FAILURE);
		}
		rewind(fPtr);
		for(i= 0; (i < MAXSEATS) && (ptrTOseat->fName[0] == '\0'); i++, ptrTOseat++)
			fread(ptrTOseat, size, 1, fPtr);
		fclose(fPtr);
	}
	else if (flight_choice == 444) {
		    if ( (fPtr= fopen("flight444.txt", "ab")) == NULL ) {
			    perror("");
			    exit(EXIT_FAILURE);
			}
			rewind(fPtr);
			for (i= 0; (i < MAXSEATS) && (ptrTOseat->fName[0] == '\0'); i++, ptrTOseat++)
				 fread(ptrTOseat, size, 1, fPtr); 
			fclose(fPtr);
	}
	else if (flight_choice == 519) {
		    if ( (fPtr= fopen("flight519.txt", "ab")) == NULL ) {
			    perror("");
			    exit(EXIT_FAILURE);
			}
			rewind(fPtr);
			for (i= 0; (i < MAXSEATS) && (ptrTOseat->fName[0] == '\0'); i++, ptrTOseat++)
				  fread(ptrTOseat, size, 1, fPtr);
			fclose(fPtr);
	}
	else if (flight_choice == 311) {
		    if ( (fPtr= fopen("flight311.txt", "ab")) == NULL ) {
			    perror("");
			    exit(EXIT_FAILURE);
			}
			rewind(fPtr);
			for (i= 0; (i < MAXSEATS) && (ptrTOseat->fName[0] == '\0'); i++, ptrTOseat++)
				  fread(ptrTOseat, size, 1, fPtr);
			fclose(fPtr);
	}
}
void  save_dataTOfile(seatsInfo *ptrTOseat, short flight_choice)
{
	FILE *fPtr;
	size_t counter= 0;
	__int8 i, j;	

	if (flight_choice == 102) {
		if ( (fPtr= fopen("flight102.txt", "wb")) == NULL ) {
			perror("");
			exit(EXIT_FAILURE);
		}
		for (i= 0; (i < MAXSEATS); i++, ptrTOseat++)
			if (ptrTOseat->fName[0] != '\0' && ptrTOseat->confirmation)
			    fwrite(ptrTOseat, size, 1, fPtr);
		fclose(fPtr);
	}
	else if (flight_choice == 444) {
		    if ( (fPtr= fopen("flight444.txt", "wb")) == NULL ) {
			    perror("");
			    exit(EXIT_FAILURE);
			}
	        for (i= 0; (i < MAXSEATS); i++, ptrTOseat++)
				if (ptrTOseat->fName[0] != '\0' && ptrTOseat->confirmation)
			        fwrite(ptrTOseat, size, 1, fPtr);
			fclose(fPtr);
	}
	else if (flight_choice == 519) {
		    if ( (fPtr= fopen("flight519.txt", "wb")) == NULL ) {
			    perror("");
			    exit(EXIT_FAILURE);
			}
			for (i= 0; (i < MAXSEATS); i++, ptrTOseat++)
				if (ptrTOseat->fName[0] != '\0' && ptrTOseat->confirmation)
			        fwrite(ptrTOseat, size, 1, fPtr);
			fclose(fPtr);
	}
	else if (flight_choice == 311) {
		    if ( (fPtr= fopen("flight311.txt", "wb")) == NULL ) {
			    perror("");
			    exit(EXIT_FAILURE);
			}
			for (i= 0; (i < MAXSEATS); i++, ptrTOseat++)
				if (ptrTOseat->fName[0] != '\0' && ptrTOseat->confirmation)
			        fwrite(ptrTOseat, size, 1, fPtr);
			fclose(fPtr);
	}
}
