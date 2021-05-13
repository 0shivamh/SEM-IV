import os
ipaddr = input ('Enter the IP address:')
stream =os.popen ('ping -c 4 {}'.format (ipaddr))
output =stream.read ()
if '0 received' in output:
    print ('IP unreachable')
else:
    print (output)