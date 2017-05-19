/*
Example of building json from a collection
author: IKM
   for: B2GMeetup-MAY-18-2017
*/
//the collection is a complex map
def ds=[SERIAL_ID:[2..6], TYPE:['DynamicReferenceParameter'], CLASS:['org.biouno.unochoice.DynamicReferenceParameter']]
//output collection as json
def json= new groovy.json.JsonBuilder(ds)
     println(json.toPrettyString())
