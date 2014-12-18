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
        CondOp(cond, COND_OP_SIGNAL, id);
        SemOp(id, 1);
    } else {
        SemOp(id, -1);
        PrintString("In the parent thread at them moment");
        while(array[0]!=10)
            CondOp(cond, COND_OP_WAIT, id);
        PrintInt(array[0]);
        SemOp(id, 1);
    }
}
