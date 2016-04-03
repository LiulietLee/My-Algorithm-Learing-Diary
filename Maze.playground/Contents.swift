//: Playground - noun: a place where people can play

import Foundation

let maze: [[Int]] = [
    [1, 1, 1, 1, 1, 1],
    [0, 0, 0, 1, 0, 1],
    [1, 0, 1, 0, 0, 1],
    [1, 0, 1, 1, 0, 1],
    [1, 0, 0, 0, 0, 0],
    [1, 1, 1, 1, 1, 1]]


func solveMaze(begin: (Int, Int), end: (Int, Int), from: Int) -> [(Int, Int)] {
    var returnPath = [begin]
    
    // succeed
    if begin == end {
        return [end]
    }
    
    // up
    if begin.0 > 0 && maze[begin.0 - 1][begin.1] == 0 && from != 3 {
        let path = solveMaze((begin.0 - 1, begin.1), end: end, from: 1)
        if path[0] != (0, 0) {
            returnPath += path
            return returnPath
        }
    }
    
    // right
    if begin.1 < maze[0].count && maze[begin.0][begin.1 + 1] == 0 && from != 4 {
        let path = solveMaze((begin.0, begin.1 + 1), end: end, from: 2)
        if path[0] != (0, 0) {
            returnPath += path
            return returnPath
        }
    }
    
    // down
    if begin.0 < maze.count && maze[begin.0 + 1][begin.1] == 0 && from != 1 {
        let path = solveMaze((begin.0 + 1, begin.1), end: end, from: 3)
        if path[0] != (0, 0) {
            returnPath += path
            return returnPath
        }
    }
    
    // left
    if begin.1 > 0 && maze[begin.0][begin.1 - 1] == 0  && from != 2 {
        let path = solveMaze((begin.0, begin.1 - 1), end: end, from: 4)
        if path[0] != (0, 0) {
            returnPath += path
            return returnPath
        }
    }
    
    // failed
    return [(0, 0)]
}

let result = solveMaze((1, 0), end: (4, 5), from: 2)
print(result)

/*
 
 print:
 
 [(1, 0), (1, 1), (2, 1), (3, 1), (4, 1), (4, 2), (4, 3), (4, 4), (4, 5)]
 
 */
