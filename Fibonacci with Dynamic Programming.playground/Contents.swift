//: Playground - noun: a place where people can play

import Foundation

func fibonacci(k: Int) -> Int64 {
    if k <= 2 {
        return 1
    }
    
    if let fib = fibDic[k] {
        return fib
    }
    
    let fib = fibonacci(k - 1) + fibonacci(k - 2)
    fibDic[k] = fib
    return fib
}

var fibDic = [Int: Int64]()

print(fibonacci(92))