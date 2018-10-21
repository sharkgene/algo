//algo.go
package main

//#cgo LDFLAGS:
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//char* echo(char* s);
import "C"
import "unsafe"
import "fmt"
import "time"
import (
	_ "net/http/pprof"
	"net/http"
	"log"
)

func main() {
	go func() {
		log.Println(http.ListenAndServe("0.0.0.0:6060", nil))
	}()

	for i := 0; i < 1000000000; i++ {
		allocateAndDeallocate()
	}
}

func allocateAndDeallocate() {
	cs := C.CString("Hello from stdio\n")
	defer C.free(unsafe.Pointer(cs))
	var echoOut *C.char = C.echo(cs)
	fmt.Println(C.GoString(echoOut))
	time.Sleep(100000000)
	//defer C.free(unsafe.Pointer(echoOut)) // no crash here
}