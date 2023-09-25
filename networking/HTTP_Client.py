import http.client

con = http.client.HTTPConnection("localhost:8000")
con.request("GET", "/")

resp = con.getresponse()

print("Status: {} and reason: {}".format(resp.status, resp.reason))
while resp != '200':
    con = http.client.HTTPConnection("localhost:8000")

    con.request("GET", "/HTTP_Client.py")

    resp = con.getresponse()

    print("Status: {} and reason: {}".format(resp.status, resp.reason))

con.close()