//: Playground - noun: a place where people can play

import Foundation

func comparison(array: [Int], input: Int) -> String {
    let length = array.count
    let middle = Int(length / 2)
    
    if array[middle] < input {
        let newArray = Array(array[middle..<length])
        
        if newArray.count <= 1 && array[0] < input {
            return "\(array[middle]) < input(\(input))"
        }
        
        return "\(array[middle]) < " + comparison(newArray, input: input)
    
    } else {
        let newArray = Array(array[0..<middle])
        
        if newArray.count <= 1 && input <= newArray[0] {
            return "input(\(input)) <= \(array[middle])"
        }
        
        return comparison(newArray, input: input) + " <= \(array[middle])"
    }
}

let array = [1, 3, 5, 7, 9, 11, 13, 14, 20, 233, 2333]

let result = comparison(array, input: 10)

print(result)

/*

print:

5 < 7 < 9 < input(10) <= 11

*/
