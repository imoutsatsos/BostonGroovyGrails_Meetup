?/*Example of building json from a collection
author: IKM
   for: B2GMeetup-MAY-18-2017
*/
def ds=[SERIAL_ID:[2..6], TYPE:['DynamicReferenceParameter'], CLASS:['org.biouno.unochoice.DynamicReferenceParameter']]
def json= new groovy.json.JsonBuilder(ds)
     println(json.toPrettyString())

?