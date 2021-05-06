#include <stdio.h>

#include "c_hello.h"
#include "go_hello.h"

int main(void)
{
    struct COBJ *param = (struct COBJ*)malloc(sizeof(struct COBJ));
    struct SUB_COBJ *param_sub_struct = (struct SUB_COBJ*)malloc(sizeof(struct SUB_COBJ));
    (*param).num = 10;
    (*param).str = "param_from_c";

    (*param_sub_struct).num = 11;
    (*param_sub_struct).str = "param_sub_struct_from_c";
    (*param).sub_struct = param_sub_struct;

    struct COBJ *cobj = GoFuncCallInCCode(param);
    printf("result_name: %s result_num: %lu result_sub_struct_name: %s result_sub_struct_num: %lu\n", cobj->str, cobj->num, cobj->sub_struct->str, cobj->sub_struct->num);

    free(cobj->sub_struct->str);
    free(cobj->sub_struct);
    free(cobj->str);
    free(cobj);
    return 0;
}