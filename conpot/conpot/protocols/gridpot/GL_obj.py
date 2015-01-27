# GridPot code
# base object class for integrating with a GridLAB-D simulation instance
# Author: W. Owen Redwood

import logging
import urllib2
logger = logging.getLogger(__name__)

# base object class for integrating with a GridLAB-D simulation instance
class GL_obj:
    def __init__(self, ip, port, object_name):
        self.obj_name = object_name
        self.gridlabd_ip = ip
        self.gridlabd_port = port
        
        # Properties are stored as a dictionary, so we can use 
        # EXACTLY the same property names that gridlabd objects 
        # have.  
        self.params = {} 
        self.init_params()
        
    def http_display(self):
        return ""
    
    
    def init_params():
        return
    
    # basic wget function    
    def send_request(self, gl_request):
        #print "[*] wget "+gl_request
        response = urllib2.urlopen(gl_request)
        return response.read()

    # basic poller function
    def poll_gl_object(self, var_name):
        gl_request = "http://"+ self.gridlabd_ip + ":"+self.gridlabd_port+"/"+self.obj_name+"/"+var_name
        data = self.send_request(gl_request)
        if data is None:
            print "[!] could not get "+self.obj_name+"/"+var_name
            return None
        else:
            return data

    # basic setter function
    def set_gl_object(self, var_name, new_value):
        gl_request = "http://"+ self.gridlabd_ip + ":"+self.gridlabd_port+"/"+self.obj_name+"/"+var_name+"="+str(new_value)
        data = self.send_request(gl_request)
        if data is None:
            print "[!] could not set "+self.obj_name+"/"+var_name+"="+str(new_value)
            return None
        else:
            return data
