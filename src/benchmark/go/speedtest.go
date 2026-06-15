package main

import (
    "fmt"
    "time"
)

func main() {
    const N int64 = 100000000

    start := time.Now()

    var s int64 = 0

    for i := int64(0); i < N; i++ {
        s += i
    }

    fmt.Println(s)
    fmt.Println("time =", time.Since(start))
}