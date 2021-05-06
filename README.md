### How to use

1. go build -buildmode=c-shared -o go_hello.so go_hello.go
2. gcc -o c_go_c c_main.c ./go_hello.so
3. ./c_go_c
