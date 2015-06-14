// written by Mo'meN Ali
// 2011
// this code is an Airline station reserve program which works on 2 planes for 4 different flights
// each traveler should reserve then confirm his/her reservation in order for the system to save this reservation 
// each reservation has a secrutiy serial number which the user should use in order to cancel/delete his/her reservation
// the system provides all the flight information

#include "access.h"

int main(void)
{	
	seatsInfo plane[MAXSEATS]= {0};
	short readed_data= 0, flight_num= 0;
	char choice= '\0'; char alphaCh= '\0';
	__int8 i, no, rt= 0;
	
	for (i= 0, no= 1; i < MAXSEATS; i++, no++) 
		     plane[i].seat_Num= no;

	for (i= 0, alphaCh= 'A'; i < MAXSEATS; i++, alphaCh++) 
		     plane[i].seat_alpha= alphaCh;

		while ((flight_num= flights())) 
		{
			   if (flight_num == 102 || flight_num == 344 || 
				                        flight_num == 519 || flight_num == 444 || flight_num == 0)
									 break;
		}
		while ( (flight_num != 0) && (choice= menu(flight_num)) ) 
		{
			  if (choice == 'e') {  
				  system("cls");
				  read_data  (plane, flight_num);
				  show_number(plane);
				  puts("\nPress ENTER to continue...");
				  getchar();
				  system("cls");
			  }
			  else if (choice == 'l') { 
				  system("cls");
				  read_data  (plane, flight_num);
				  show_number(plane);
				  getchar();
				  puts("\nPress ENTER to continue...");
				  system("cls");
			  }
			  else if (choice == 'p') {
					   system("cls");
					   read_data     (plane, flight_num);
					   showAlpha_list(plane);
					   puts("\nPress ENTER to continue...");
					   getchar();
					   system("cls");
			  }
			  else if (choice == 'a') {
				      system("cls");
					  read_data            (plane, flight_num);
					  assignCustomersTOseat(plane);
					  puts("\nPress ENTER to continue...");
					  getchar();
					  system("cls");
			  }
			  else if (choice == 'c') {
				 system("cls");
				 read_data      (plane, flight_num);
				 conf_assignment(plane);
				 save_dataTOfile(plane, flight_num);
				 puts("\nPress ENTER to continue...");
				 getchar();
				 system("cls");
			  }
			  else if (choice == 'd') {
				     system("cls");
					 read_data         (plane, flight_num);
					 del_SeatAssignment(plane);
				     save_dataTOfile   (plane, flight_num);
					 puts("\nPress ENTER to continue...");
					 getchar();					 
					 system("cls");
			  }
			  else if (choice == 'q') {
					 putchar('\n');
					 while (1) {
					      flight_num= flights();
						  if ( (flight_num == 311) || (flight_num == 444) || (flight_num == 519) 
							                                                    || (flight_num == 102) || (flight_num == 0) )
																				break;
					 }
		    if (flight_num == 0)
				break;
			 }
		}
	system("pause");
	return 0;
}