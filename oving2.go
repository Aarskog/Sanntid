package main

import (
	. "fmt"

	"time"
)


var i int = 2
func one(c chan int) {

	for x := 0; x < 1000000; x++ {
		i:=<-c
		i++
		c <- i
	}


}
func two(c chan int) {

	for y := 0; y < 1000000; y++ {
		i:=<-c
		i--
		c <- i
	}

}

func main() {
	c := make(chan int,1)
	c<-i
	go one(c)
	go two(c)

	time.Sleep(100 * time.Millisecond)
	i := <-c
	Println(i)
}
