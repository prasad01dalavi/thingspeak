import httplib, urllib
import sys

api_key = '49I73T91FC0WX3DU' # Declaring my API write key 

params = urllib.urlencode({'field1':50,'key':api_key})   
headers = {"Content-type": "application/x-www-form-urlencoded","Accept": "text/plain"}
conn = httplib.HTTPConnection("api.thingspeak.com:80")
conn.request("POST", "/update", params, headers)

response = conn.getresponse()
if response.status == 200:
    print 'Data has been uploaded!'
else:
    print 'Data upload Failed!', response.reason

