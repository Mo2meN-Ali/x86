// written by Mo'meN Ali
// 2011

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char get_char(void);
void eat_line(void);
void itob(short, short);
void gates(char **, short, short);
int main(void)
{
	short inputs_no= 0, prob= 1, storage= 0;
    __int8 i, j;

	puts("Enter Number of inputs");
	scanf("%hd", &inputs_no);
	eat_line();
	for (i= inputs_no; i > 0; prob<<= 1, i--);
	itob(inputs_no, prob);
	putchar('\n');
	system("pause");
	return 0;
}
void eat_line(void)
{
	char Ch= '\0';

	while ( (Ch= getchar()) != '\n' );
}
char get_char(void)
{
	char Ch= '\0';

	Ch= getchar();
	if (isupper(Ch))
		Ch-= 32;
	if (Ch < 'a' || Ch > 'z') {
		puts("Please respond with a character");
		Ch= getchar();
	}
	return Ch;
}
void itob(short inputs_no, short prob)
{
	short storage;
	char **Arr_b;
        int i, j;

	if ( (Arr_b= (char **)malloc(prob*sizeof(char *))) == NULL ) {
		 puts("Allocation Failed");
		 exit(EXIT_FAILURE);
	}
	for (i= 0; i < prob; i++) 
		if ( (Arr_b[i]= (char *)malloc(inputs_no*sizeof(char))) == NULL ) {
		     puts("Allocation Failed");
		     exit(EXIT_FAILURE);
		 }
	for (i= 0; i < prob ; ++i) {
		storage= i;
		for(j= inputs_no-1; j >= 0; --j, storage>>= 1)
			*(*(Arr_b+i)+j)= (storage & 0x01);
	}
	puts("\t  Truth Table\n");
	for (i= 0; i < prob; ++i) {
		for (j= 0; j < inputs_no; ++j)
			printf("\t%4hd", *(*(Arr_b+i)+j));
	    putchar('\n');
	}
	gates(Arr_b, inputs_no, prob);
}
void gates(char **Arr_b, short input_no, short prob)
{
	short AND, OR, XOR, NAND, NOR;
	char Ch= '\0';
	__int8 i, j, k;
	
	puts("Enter (a) for AND gate, (o) for OR gate, (x) for XOR gate, (r) & (d) for NAND gate or (q) to quit");

	Ch= getchar();
	while (Ch != 'q') {
		eat_line();
           if (Ch == 'a') {
	           puts("\n\n\tAND\n");
	           for (AND= '\0', i= 0; i < prob; ++i)
		       for (j= 0, AND= *(*(Arr_b+i)+j); j < input_no; ++j, AND *= *(*(Arr_b+i)+j)) {
			        if ((j+1) % input_no == 0)
			             printf("\t%d\n", AND);
			   }
		   }
			else if (Ch == 'o') {
	                 puts("\n\n\tOR\n");
	                 for (OR= '\0', i= 0; i < prob; ++i)
		                  for (j= 0, OR= *(*(Arr_b+i)+j); j < input_no; ++j, OR += *(*(Arr_b+i)+j), OR= !!OR) {
			                   if ((j+1) % input_no == 0) 
				               printf("\t%d\n", OR);
						  }
			}
			else if (Ch == 'r') {
	                 puts("\n\n\tNOR\n");
	                 for (NOR= '\0', i= 0; i < prob; ++i)
		                  for (j= 0, NOR= *(*(Arr_b+i)+j); j < input_no; ++j, NOR += *(*(Arr_b+i)+j), NOR= !!NOR) {
			                   if ((j+1) % input_no == 0) 
				               printf("\t%d\n", !NOR);
						  }
			}
			else if (Ch == 'x') {
				puts("\n\n\tXOR\n");
	                 for (XOR= 0, i= 0; i < prob; ++i) {
						 for (j= 0; j < input_no; ++j, XOR= XOR + *(*(Arr_b+i)+j)); 
						 if (i == 0 || i == prob-1)
							 puts("\t1");
						else
							 puts("\t0");   
					 }
			}
			else if (Ch == 'd') {
				  puts("\n\n\tNAND\n");
	           for (NAND= '\0', i= 0; i < prob; ++i)
		       for (j= 0, NAND= *(*(Arr_b+i)+j); j < input_no; ++j, NAND *= *(*(Arr_b+i)+j)) {
			        if ((j+1) % input_no == 0)
			             printf("\t%d\n", !NAND);
			   }
			}
			puts("\nEnter (a) for AND gate, (o) for OR gate, (x) for XOR gate, (r) & (d) for NAND gate or (q) to quit");
			Ch= get_char();
			
	}
	free(Arr_b);
}
