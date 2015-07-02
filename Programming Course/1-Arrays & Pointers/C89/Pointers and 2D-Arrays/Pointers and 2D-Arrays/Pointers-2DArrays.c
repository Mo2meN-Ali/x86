// Pointers and 2D Arrays operations
// Source: C Primer Plus 6th Edition

#include <stdio.h>

int main(void)
{
    int zippo[4][2] = { {2,4}, {6,8}, {1,3}, {5, 7} };
	int (*pz)[2];		// Pointer-to-Multidimensional Array
    
	// Array Notation
	printf("\t\tArray Notation\n\n");
    printf("   zippo = %p,    zippo + 1 = %p\n",
               			zippo, zippo + 1);
    printf("zippo[0] = %p, zippo[0] + 1 = %p\n",
            				zippo[0], zippo[0] + 1);
    printf("  *zippo = %p,   *zippo + 1 = %p\n",
              			*zippo, *zippo + 1);
    printf("zippo[0][0] = %d\n", zippo[0][0]);
    printf("  *zippo[0] = %d\n", *zippo[0]);
    printf("    **zippo = %d\n", **zippo);
    printf("      zippo[2][1] = %d\n", zippo[2][1]);
    printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo+2) + 1));

	// Pointer Notation
	pz = zippo;	
	printf("\n\t\tPointer Notation\n\n");
	printf("   pz = %p,    pz + 1 = %p\n",
               			       pz, pz + 1);
    printf("pz[0] = %p, pz[0] + 1 = %p\n",
            			 pz[0], pz[0] + 1);
    printf("  *pz = %p,   *pz + 1 = %p\n",
             				 *pz, *pz + 1);
    printf("pz[0][0] = %d\n", pz[0][0]);
    printf("  *pz[0] = %d\n", *pz[0]);
    printf("    **pz = %d\n", **pz);
    printf("      pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz+2) + 1) = %d\n", *(*(pz+2) + 1));

	system("pause");
    return 0;
}
