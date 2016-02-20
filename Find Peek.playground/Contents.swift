
//      
//      There is a 2-D array of numbers.
//      And there is only one Peek in this array.
//
//      What is Peek: This array looks like this:
//
//      a, b, c
//      d, e, f
//      g, h, i
//      
//      e is the Peek. 
//      And e >= b && e >= d && e >= h && e >=f
//

import Foundation

func findPeekForRow(array: [Int]) -> Int {
    let length = array.count
    let middle: Int = length / 2
    
    if middle + 1 < length && array[middle] < array[middle + 1] {
        let nextArray = Array(array[middle..<length])
        let num = findPeekForRow(nextArray)
        return num + middle
        
    } else if middle - 1 >= 0 && array[middle] < array[middle - 1] {
        let nextArray = Array(array[0..<middle])
        return findPeekForRow(nextArray)

    } else {
        return middle
    }
}

func findPeek(array: [[Int]]) -> Int {
    let numberOfColumn = array.count
    let middle = numberOfColumn / 2
    let middleColumn = array[middle]
    let peekNumber = findPeekForRow(middleColumn)
    
    if middle - 1 >= 0 && array[middle][peekNumber] < array[middle - 1][peekNumber] {
        let nextArray = Array(array[0..<middle])
        return findPeek(nextArray)
        
    } else if middle + 1 < numberOfColumn && array[middle][peekNumber] < array[middle + 1][peekNumber] {
        let nextArray = Array(array[middle..<numberOfColumn])
        return findPeek(nextArray)
        
    } else {
        return array[middle][peekNumber]
    }
}

var array = [[1, 3, 4, 4, 3, 2, 1, 0],
             [0, 2, 3, 4, 3, 2, 1, 0],
             [1, 3, 4, 5, 6, 2, 1, 0],
             [0, 2, 3, 4, 6, 2, 1, 0],
             [1, 3, 3, 5, 7, 2, 1, 0],
             [0, 2, 4, 5, 8, 2, 1, 0],
             [1, 3, 3, 4, 3, 2, 1, 0]]

let peek = findPeek(array)
