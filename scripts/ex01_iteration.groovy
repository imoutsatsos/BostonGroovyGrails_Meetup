/*
Iteration examples with each and eachWithIndex
*/

//list iteration
[1, 2, 3].each {println "Item: $it"  } // `it` is an implicit parameter corresponding to the current element
['a', 'b', 'c'].eachWithIndex { it, i ->println "$i: $it" }// `it` is the current element, while `i` is the index 

// map iteration
[a:'Hello',b:'and', c:'welcome',d:'to B2GMeetup!'].eachWithIndex { it, i ->println "$i: $it.key" }

//range iteration
(1..<3).each {println "Range Item: $it"  }
(1..3).eachWithIndex {it,ind->println "Range Item ($ind): $it"}???????????
