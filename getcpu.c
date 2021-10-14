#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

struct getcpu_cache
{
        unsigned long blob[128/sizeof(long)];
};

int getcpu(unsigned *cpu,unsigned *node,struct getcpu_cache *tcache)
{

        return syscall(SYS_getcpu,cpu,node,tcache);
}

int main(void)
{
        unsigned cpu;
        unsigned node;

        if(getcpu(&cpu,&node,NULL)==-1)
        {
                printf("getcpu bad \n");
                return 1;
        }

        printf("cpu = %u node = %u\n",cpu,node);

        return 0;
}

