#include "syscall.h"
#include "synchop.h"

#define SEMKEY 19
#define CONDKEY 17

int
main()
{
    int *array = (int *)ShmAllocate(10*sizeof(int));
    array[0]=1;
    int x = Fork();
    int id = SemGet(SEMKEY);
    int cond = CondGet(CONDKEY);
    if(x == 0) {
        SemOp(id, -1);
        PrintString("In the child thread at the moment\n");
        array[0]=10;
        SemOp(id, 1);
    } else {
        while(array[0]!=10); // busy-wait
        SemOp(id, -1);
        PrintString("In the parent thread at them moment");
        SemOp(id, 1);
    }
}
