package main

/*
#include "c_hello.h"
*/
import "C"
import "fmt"
import "unsafe"



//export GoFuncCallInCCode
func GoFuncCallInCCode(param *C.struct_COBJ) *C.struct_COBJ {

    fmt.Printf("param_name: %s param_num: %d param_sub_struct_name: %s param_sub_struct_num: %d\n", C.GoString(param.str), param.num, C.GoString(param.sub_struct.str), param.sub_struct.num);

    C.free(unsafe.Pointer(param.sub_struct));
    C.free(unsafe.Pointer(param));


    structPtr:= C.malloc(C.sizeof_struct_COBJ);
    var structElm *C.struct_COBJ;
    structElm = (*C.struct_COBJ) (unsafe.Pointer(structPtr));
    structElm.num = 1000;
    structElm.str = C.CString("result_from_go");

    subStructPtr:= C.malloc(C.sizeof_struct_SUB_COBJ);
    var subStructElm *C.struct_SUB_COBJ;
    subStructElm = (*C.struct_SUB_COBJ) (unsafe.Pointer(subStructPtr));
    subStructElm.num = 1001;
    subStructElm.str = C.CString("result_sub_struct_from_go");

    structElm.sub_struct = subStructElm;

    return structElm;
}


func main() {

}