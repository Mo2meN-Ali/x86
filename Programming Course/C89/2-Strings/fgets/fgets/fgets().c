// Source: C Primer Plus 6th Edition
// fgets().c -- using fgets() 
// Shows the difference between the null character and the null strings

#include <stdio.h>
#define STLEN 10
int main(void)
{
	char words[STLEN];
	int i;
	puts("Enter strings (empty line to quit):");
	while (fgets(words, STLEN, stdin) != NULL
						   && words[0] != '\n')
	{
		i = 0;
		while (words[i] != '\n' && words[i] != '\0')
				i++;
		if (words[i] == '\n')
			words[i] = '\0';
		else // must have words[i] == '\0'
			while (getchar() != '\n')
					continue;
		puts(words);
	}
	puts("done");

	return 0;
}