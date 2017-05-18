/*
Assay plates have row and column identifiers
This script creates alphanumeric identifiers for a 1536 high density plate
You can adjust the rowIds/columnIds to create lists for other plates sizes
*/
rowIds='A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,AA,AB,AC,AD,AE,AF'
columnIds=(1..48)
plate=GroovyCollections.combinations(rowIds.split(','),columnIds.collect{String.format('%02d',it)})
assert plate.size()==1536

//Create alphanumeric WellID
wellid=plate.collect{it.join('')}
println "RowID,ColumnID,WellID"
plate.each{
println "${it[0]},${it[1]},${it.join('')}"
}
 
return

