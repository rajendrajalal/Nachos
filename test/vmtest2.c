#include "syscall.h"
#define BASE_SIZE (3*256)
#define SIZE1 BASE_SIZE
#define SIZE2 (2*BASE_SIZE)
#define SIZE3 (4*BASE_SIZE)
#define SIZE4 (8*BASE_SIZE)

int array1[SIZE1], array2[SIZE2], array3[SIZE3], array4[SIZE4];

int
main()
{
    int i, sum=0;
    
    for (i=0; i<2*SIZE1/3; i++) sum += array1[i];
    for (i=0; i<SIZE1/3; i++) sum += array1[i];
    for (i=2*SIZE1/3; i<SIZE1; i++) sum += array1[i];
    for (i=SIZE1/3; i<2*SIZE1/3; i++) sum += array1[i];

    for (i=0; i<2*SIZE2/3; i++) sum += array2[i];
    for (i=0; i<SIZE2/3; i++) sum += array2[i];
    for (i=2*SIZE2/3; i<SIZE2; i++) sum += array2[i];
    for (i=SIZE2/3; i<2*SIZE2/3; i++) sum += array2[i];

    for (i=0; i<2*SIZE3/3; i++) sum += array3[i];
    for (i=0; i<SIZE3/3; i++) sum += array3[i];
    for (i=2*SIZE3/3; i<SIZE3; i++) sum += array3[i];
    for (i=SIZE3/3; i<2*SIZE3/3; i++) sum += array3[i];

    for (i=0; i<2*SIZE4/3; i++) sum += array4[i];
    for (i=0; i<SIZE4/3; i++) sum += array4[i];
    for (i=2*SIZE4/3; i<SIZE4; i++) sum += array4[i];
    for (i=SIZE4/3; i<2*SIZE4/3; i++) sum += array4[i];

    PrintString("Total sum: ");
    PrintInt(sum);
    PrintChar('\n');
    return 0;
}
