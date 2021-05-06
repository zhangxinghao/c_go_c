#ifndef C_HELLO_H 
#define C_HELLO_H

#include <stdint.h>
#include <stdlib.h>

struct SUB_COBJ
{
    uint64_t num;
    char* str;
};


struct COBJ
{
    uint64_t num;
    char* str;
    struct SUB_COBJ * sub_struct;
};



#endif