//: Playground - noun: a place where people can play

import Foundation

let DOCUMENTS = ["location",
    
    "Hello this is Liuliet.Lee~",
    
    "Let Google help apps determine location. This means sending anonymous location data to Google, even when no apps are running.",
    
    "Let Apple help apps determine location. This means sending anonymous location data to Apple, even when no apps are running.",
    
    "Rediscover the places you’ve been and the routes you’ve traveled in your timeline. Only you can see your timeline.",
    
    "Find location. Singapore ... Full address, city or postcode. Go. Home > Find Locations. Copyright © 2016 Apple Inc. All rights reserved. Terms of Use"]

func searchEngine(searchString: String) -> [String] {
    let documents = [searchString] + DOCUMENTS
    
    var dics = [[String: Int]]()
    var numberOfWordsOfSearchString = 0
    var times = 0
    
    for _ in documents {
        let newDic = [String: Int]()
        dics.append(newDic)
    }
    
    for document in documents {
        var singleWord = ""
        var returnValue = [String]()
        
        for char in document.unicodeScalars {
            let letters = NSCharacterSet.letterCharacterSet()
            if letters.longCharacterIsMember(char.value) {
                singleWord += String(char)
            } else {
                returnValue += [singleWord]
                
                for (var i = 0; i < documents.count; i++) {
                    if let _ = dics[i][singleWord] {
                        if i == times {
                            dics[i][singleWord]! += 1
                        }
                    } else {
                        if singleWord != "" {
                            if i == times {
                                if document == documents[0] {
                                    numberOfWordsOfSearchString++
                                }
                                dics[i][singleWord] = 1
                            } else {
                                dics[i][singleWord] = 0
                            }
                        }
                    }
                }

                singleWord = ""
            }
        }
        
        if singleWord != "" {
            returnValue += [singleWord]
            
            for (var i = 0; i < documents.count; i++) {
                if let _ = dics[i][singleWord] {
                    if i == times {
                        dics[i][singleWord]! += 1
                    }
                } else {
                    if singleWord != "" {
                        if i == times {
                            if document == documents[0] {
                                numberOfWordsOfSearchString++
                            }
                            dics[i][singleWord] = 1
                        } else {
                            dics[i][singleWord] = 0
                        }
                    }
                }
            }
            
            singleWord = ""
        }
        
        times++
    }
    
    var valuesOfEachDocument = [[Int]]()
    
    for dic in dics {
        var values = [Int]()
        for value in dic {
            values += [value.1]
        }
        valuesOfEachDocument += [values]
    }
    
    var numerator = [Int]()
    var denominator = [Double]()
    var denominatorOfSearchString = 0.0
    
    for value in valuesOfEachDocument[0] {
        denominatorOfSearchString += pow(Double(value), 2)
    }
    denominatorOfSearchString = sqrt(denominatorOfSearchString)

    for var i = 1; i < valuesOfEachDocument.count; i++ {
        var value = 0
        for var j = 0; j < valuesOfEachDocument[0].count; j++ {
            value += valuesOfEachDocument[0][j] * valuesOfEachDocument[i][j]
        }
        numerator += [value]
        
        var val = 0.0
        for value in valuesOfEachDocument[i] {
            val += pow(Double(value), 2)
        }
        denominator += [sqrt(val) * denominatorOfSearchString]
    }
    
    var coses = [Double]()
    
    for var i = 0; i < numerator.count; i++ {
        var value = Double(numerator[i])
        if value < Double(numberOfWordsOfSearchString) {
            value /= 2
        }
        coses += [value / denominator[i]]
    }
    
    struct Doc {
        var content: String
        var cos: Double
    }
    
    var Documents = [Doc]()
    
    for var i = 1; i < documents.count; i++ {
        Documents += [Doc(content: documents[i], cos: coses[i - 1])]
    }
    
    Documents.sortInPlace({$0.cos > $1.cos})
    
    var returnDocs = [String]()
    
    for doc in Documents {
        returnDocs += [doc.content]
    }
    
    return returnDocs
}

let searchStr = "Google location"

let searchResults = searchEngine(searchStr)

for result in searchResults {
    print(result + "\n")
}

/*

searchResults:

Let Google help apps determine location. This means sending anonymous location data to Google, even when no apps are running.

location

Let Apple help apps determine location. This means sending anonymous location data to Apple, even when no apps are running.

Find location. Singapore ... Full address, city or postcode. Go. Home > Find Locations. Copyright © 2016 Apple Inc. All rights reserved. Terms of Use

Hello this is Liuliet.Lee~

Rediscover the places you’ve been and the routes you’ve traveled in your timeline. Only you can see your timeline.

*/
