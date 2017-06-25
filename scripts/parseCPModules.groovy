/*
Example use of collections and their methods to parse a file, 
 technically a CellProfiler Imaging Pipeline
 http://cellprofiler.org/ 
We identify and print the unique list of 'imaging modules' used in this file

author: IKM
   for: B2GMeetup-MAY-18-2017
*/
/* read a file from the git URL
 note you may need to adjust your groovy proxy setttings
 */
def modules=[] //and empty list to hold the imaging module names 
def u='https://raw.githubusercontent.com/imoutsatsos/BostonGroovyGrails_Meetup/master/testFiles/CP_pipeline_val.cpipe'
def lines=new URL(u).readLines()

def moduleLines= lines.findIndexValues{it.contains('module_num')}

moduleLines.each{
/*
cast to int because findIndexValues returns list of longs!
*/
//println lines[it].split(':')[0]
modules.add(lines[it as int].split(':')[0])
}


println 'Pipeline Imaging Modules'
println '-'*25
//print unique imaging modules in alphabeticalorder
modules.unique().sort().each{
println it
}
