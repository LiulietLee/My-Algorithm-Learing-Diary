//: Playground - noun: a place where people can play

import Foundation

func insertionSort(var array: [Int]) -> [Int] {
    for i in 1 ..< array.count {
        var key = array[i]
        for var j = i - 1; j >= 0; j -= 1 {
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

func mergeSort(array: [Int]) -> [Int] {
    let middle = Int(array.count / 2)
    var leftArray = Array(array[0..<middle])
    var rightArray = Array(array[middle..<array.count])
    
    leftArray = insertionSort(leftArray)
    rightArray = insertionSort(rightArray)
    
    var leftPoint = 0
    var rightPoint = 0
    var returnArray = [Int]()
    
    while true {
        if leftPoint == leftArray.count || rightPoint == rightArray.count {
            break
        }
        
        if leftArray[leftPoint] < rightArray[rightPoint] {
            returnArray += [leftArray[leftPoint]]
            leftPoint += 1
        } else {
            returnArray += [rightArray[rightPoint]]
            rightPoint += 1
        }
    }
    
    if leftPoint != leftArray.count {
        returnArray += leftArray[leftPoint..<leftArray.count]
    }
    if rightPoint != rightArray.count {
        returnArray += rightArray[rightPoint..<rightArray.count]
    }
    
    return returnArray
}

let array = [450, 12, 5, 4, 1, 2, 6, 3, 7, 233, 2333]

let sortedArray = mergeSort(array)

print(sortedArray)

/*

result:

[1, 2, 3, 4, 5, 6, 7, 12, 233, 450, 2333]

*/
