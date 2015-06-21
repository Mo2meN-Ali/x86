// Source: C Primer Plus 6th Edition
// Sums the elements of an array 
// Show how to pass arrays as arguments

#include <stdio.h>
#define SIZE 10

// Both Functions are summing the array elements and returning the result
int sum(int ar[], int n);
int sump(int *start, int *end);

int main(void)
{
    int marbles[SIZE] = { 20, 10, 5, 39, 4, 16, 19, 26, 31, 20 };
    long answer= 0;

    answer= sum(marbles, SIZE);
    printf("sum(): The total number of marbles is %ld.\n", answer);
    printf("The size of marbles is %u bytes from main().\n",
			sizeof (marbles));
	putchar('\n');
	answer= sump(marbles, &marbles[SIZE]);		
    printf("sump(): The total number of marbles is %ld\n", answer);

	system("pause");
    return 0;
}

// Summing an array elements using an array notation
int sum(int ar[], int n)     // how big an array?
{
    int i;
    int total = 0;

    for( i= 0; i < n; ++i)
        total+= ar[i];

    printf("The size of ar is %u bytes from sum().\n", sizeof (ar));

    return total;
}


// Summing an array elements using pointer notation 
int sump(int *start, int *end)
{
    int total= 0;

    while (start != end)
    {
        total+= *start;  /* add value to total              */
        start++;         /* advance pointer to next element */
    }

    return total;
}
