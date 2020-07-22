package main

import (
   "fmt"
    "math"
)


//basic function def
func add(x, y int) int {
	return x + y
}


//function def: 
//    if all args are the same, 
//    only the last needs a type
//
//functions can return multiple values (string, string)
func swap(x, y string) (string, string) {
   return y, x
}

func main() {

   fmt.Println("Hello, World!")

   //calling function that returns multiple values.
	a, b := swap("hello", "world")
   fmt.Println(a, b)
   
   fmt.Println(add(3,4))
   //Capitalized variable names can be exported (used in other packages)
   //non-capitalized are like local variables to the package
   fmt.Println(math.Pi)
   
   //Uaing variable in printing requires Printf not Println
   //works like C printf
   fmt.Printf("Now you have %g problems.\n", math.Sqrt(7))


}