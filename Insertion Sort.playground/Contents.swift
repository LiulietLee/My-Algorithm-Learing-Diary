//: Playground - noun: a place where people can play

import Foundation

func sorting(var array: [Int]) -> [Int] {
    for i in 1 ..< array.count {
        var key = array[i]
        for var j = i - 1; j >= 0; j-- {
            if array[j] > key {
                array[j + 1] = array[j]
                array[j] = key
                key = array[j]
            } else {
                break
            }
        }
    }
    
    return array
}

let array = [5, 4, 1, 2, 6, 3, 233]

let sortedArray = sorting(array)

print(sortedArray)

/*

result: 
[1, 2, 3, 4, 5, 6, 233]

*/
