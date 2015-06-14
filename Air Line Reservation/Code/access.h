// written by Mo'meN Ali
// 2011

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#define CHARS 30
#define MAXSEATS 12
 
typedef struct struct0 {
	unsigned int assigment_ID;
	short seat_Num;
	char fName[CHARS];
	char lName[CHARS];
	char seat_alpha;
	__int8 confirmation;
} seatsInfo;

void eat_line(void);
char menu(short);
short flights(void);
void show_number(seatsInfo *); 
void show_list(seatsInfo *); 
void showAlpha_list(seatsInfo *); 
void assignCustomersTOseat(seatsInfo *);
__int8 conf_assignment(seatsInfo *);
__int8 del_SeatAssignment(seatsInfo *);
void read_data(seatsInfo *, short);
void save_dataTOfile(seatsInfo *, short);

