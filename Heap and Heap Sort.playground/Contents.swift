//: Playground - noun: a place where people can play

import Foundation

func createHeap(var array: [Int]) -> [Int] {
    let lengthOfArray = array.count
    
    for var n = 2; n <= lengthOfArray; n++ {
        var child = n - 1
        var parent = Int(n / 2) - 1
        
        if array[child] > array[parent] {
            var temp = array[child]
            array[child] = array[parent]
            array[parent] = temp
            
            for var i = n - 1; i > 1; i-- {
                child = i - 1
                parent = Int(i / 2) - 1
                
                if array[child] > array[parent] {
                    temp = array[child]
                    array[child] = array[parent]
                    array[parent] = temp
                }
            }
        }
    }
    
    return array
}

func sortHeap(var array: [Int]) -> [Int] {
    var sortedArray = [Int]()
    
    while array.count >= 1 {
        sortedArray += [array[0]]
        array.removeFirst()
        array = createHeap(array)
    }
    
    return sortedArray
}

let array = [1, 6, 2, 5, 4, 3, 0, 12, 13, 14, 10, 9, 7, 8]

var heap = createHeap(array)
print("Heap = " + "\(heap)")

heap = sortHeap(heap)
print("Sorted Heap = " + "\(heap)")
