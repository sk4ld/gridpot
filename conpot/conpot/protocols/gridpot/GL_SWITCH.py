# GridPot code
# switch object class for integrating with a GridLAB-D simulation instance
# Author: W. Owen Redwood

import logging
import urllib2
logger = logging.getLogger(__name__)

from GL_obj import GL_obj


# base object class for integrating with a GridLAB-D simulation instance
class GL_SWITCH(GL_obj):
    def init_params(self):
        # Here we define what we want to poll for this object. 
        # We dont necessarily want to have a setter for each one of these
        # Nor do we necessarily have to display each of these to the HMI
        self.params["status"] = ""
        self.params["phases"] = ""
        self.params["from"] = ""
        self.params["to"] = ""
        self.params["power_in"] = ""
        self.params["power_out"] = ""

    # OVERLOADED setter function
    def set_gl_object(self, var_name, new_value):
        if var_name == "status" and new_value == "CLOSED":
            new_value = "CLOSED2" # temporary hack
        gl_request = "http://"+ self.gridlabd_ip + ":"+self.gridlabd_port+"/"+self.obj_name+"/"+var_name+"="+str(new_value)
        data = self.send_request(gl_request)
        if data is None:
            print "[!] could not set "+self.obj_name+"/"+var_name+"="+str(new_value)
            return None
        else:
            return data

    # OVERLOADED http display for the conpot built in http hmi
    def http_display(self):
        ht_format = "<table border=0>\n"
        ht_format += "<tr>\n"
        ht_format += "  <td>"+ self.obj_name +"</td>\n"
        ht_format += "  <td></td>\n"
        ht_format += "</tr>\n"
        for x in ('status', 'phases', 'from', 'to', 'power_in', 'power_out'):            
            ht_format += "<tr>\n"        
            ht_format += "  <td>" + x + "</td>\n"
            ht_format += "  <td>" + self.params[x] + "</td>\n"
            ht_format += "<tr>\n"        
        return ht_format
