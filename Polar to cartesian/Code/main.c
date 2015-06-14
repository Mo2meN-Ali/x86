// written by Mo'meN Ali
// 2011

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 4*atan(1)

typedef struct {
    double mag;
	short angle;
} polar_form;

typedef struct {
    double mag;
	double x_angle;
	double y_angle;
} rect_form;

const polar_form *polar_p;
rect_form *rect_p;

void convert_co(void);
int main(void)
{
    polar_form polar_ex;
	rect_form  rect_ex;
	char Ch= '\0';

    polar_p= &polar_ex;
    rect_p= &rect_ex;
	      
	puts("Enter the polar co-ordinates magnitude\n");
	while ( Ch != 'q') 
	{
	       while ( (scanf("%lf", &(polar_p->mag)) != 1) || (polar_p->mag == 0) ) 
		   {
		   printf("%g\n", polar_p->mag);
		          puts("Please enter the magnitude and make sure it's != 0");
		          scanf("%lf", &(polar_p->mag));
				  getchar();
	       }
		   getchar();
		   puts("Now the angle");
           while (scanf("%hd", &(polar_p->angle)) != 1) 
		   {
		          puts("Please Enter the angle");
		          scanf("%hd", &(polar_p->angle));
				  getchar();
	       }
		   convert_co();
		   if (polar_p->angle != 0)
	           printf( "Cartesian Co. in radians is (%g,%g)\n", 
	                                    rect_p->mag * cos(rect_p->x_angle) , rect_p->mag * sin(rect_p->y_angle)  );
           getchar();
		   puts("Enter the polar co-ordinates Magnitude or (q) to quit\n");
           Ch=getchar();
	}							
	system("pause");
	return 0;
}

void convert_co(void)
{ 
	 rect_p->mag= polar_p->mag;
	 rect_p->x_angle= polar_p->angle;
   	 rect_p->y_angle= polar_p->angle;
}
