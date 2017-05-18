/* Enable Groovy PROXY SETTINGS 
Edit and run this so that you setup a proxy for Groovy
A successsful test prints the html that is served from the http://biouno.org site

*/ 
System.getProperties().put("proxySet", "true");
System.getProperties().put("proxyHost", "yourProxyServer");
System.getProperties().put("proxyPort", "nnnn");

/*Now run a snall test*/
link='http://biouno.org'
url=new URL(link)
def result=[]

url.eachLine{
    println it
}
