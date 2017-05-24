/* Enable Groovy PROXY SETTINGS if required
Edit and run this so that you setup a proxy for Groovy
A successsful test prints the html that is served from the http://biouno.org site
Configure and uncomment lines below to enable proxy

System.getProperties().put("proxySet", "true");
System.getProperties().put("proxyHost", "yourProxyServer");
System.getProperties().put("proxyPort", "nnnn");
*/

/*
Now run a small test. 
If it succeeds you have set your proxy correctly
*/
link='http://biouno.org'
url=new URL(link)
url.eachLine{
    println it
}
