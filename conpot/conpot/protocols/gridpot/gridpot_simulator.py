# GridPot code
# details go here
# Author: W. Owen Redwood

import logging
import urllib2
import gevent
import conpot.core as conpot_core

import xml.etree.ElementTree as ET
import io
import ConfigParser
from GL_obj import GL_obj
from GL_SWITCH import GL_SWITCH
from GL_TRANSFORMER import GL_TRANSFORMER
from GL_REGULATOR import GL_REGULATOR

logger = logging.getLogger(__name__)


# integrates with a GridLAB-D simulation instance
class GridPotSimulator(object):
    def __init__(self, *args):
        # both highres, lowres will be calculated on the fly
        print "OMFG\n\n\n\n"
        self.conpot_name = "conpot1"
        self.gridpotmodel_file = "model.gpm"
        self.gridlabd_ip = "localhost"
        self.gridlabd_port = "6267" # defaultport
        self.gridpotmodel = ""
        self.SCADA_objects = []
        # p1, p2, p3
        #self.voltage = [0, 0, 0]
        #self.current = [0, 0, 0]
        #self.power = [0, 0, 0]
        gevent.spawn(self.initialize)

    def get_http(self, key):
        print "[*] get_http("+str(key)+")\n\n"
        print "[*] self.SCADA_objects="+str(self.SCADA_objects)
        for x in self.SCADA_objects:
            if key == x.obj_name:
                return x.http_display()

    def parse_xml_for_value(self,response):
        # get the value field
        #print 'RESPONSE:'+response
        tree = ET.fromstring(response)
        for child in tree:
            #print "parsing: "+str(child.tag) + ":" + str(child.text)
            if child.tag == 'value':
                return str(child.text)
            
    def poll_gridlabd(self):
        while True:
            gevent.sleep(1)
            for x in self.SCADA_objects:
                print "[*]========================================="
                print "[*] " + x.obj_name + " properties:"
                print x.params
                for prop in x.params:
                    #print "[*] DEBUG: " + str(prop)
                    response = x.poll_gl_object(prop)
                    x.params[prop] = self.parse_xml_for_value(response)
                    print "[*] " + x.obj_name + "/"+str(prop)+" is " + str(x.params[prop])
                    
                    
    def setup_gl_objects(self):
        gpm_conf = ConfigParser.RawConfigParser()
        try:
            gpm_conf.readfp(io.BytesIO(self.gridpotmodel))
        except Exception:
            print "Error reading the grid pot model from GridLAB-D"
            raise
            exit(0)
        if gpm_conf.has_section(self.conpot_name):
            print "[*] Found gpm data for this conpot instance"
            
            for scada in gpm_conf.options(self.conpot_name):
                print "[*] type is: " + str(scada)
                if scada == "switch":
                    x = GL_SWITCH(self.gridlabd_ip, self.gridlabd_port, gpm_conf.get(self.conpot_name, scada))
                    self.SCADA_objects.append(x)
                elif scada == "transformer":
                    x = GL_TRANSFORMER(self.gridlabd_ip, self.gridlabd_port,  gpm_conf.get(self.conpot_name, scada))
                    self.SCADA_objects.append(x)
                elif scada == "regulator":
                    x = GL_REGULATOR(self.gridlabd_ip, self.gridlabd_port,  gpm_conf.get(self.conpot_name, scada))
                    self.SCADA_objects.append(x)
                #keep adding more as we go
        

    def initialize(self):
        # we need the databus initialized before we can probe values
        
        
        databus = conpot_core.get_databus()
        databus.initialized.wait()
        
        self.conpot_name = databus.get_value("conpot_name")
        self.gridpotmodel_file = databus.get_value("gridpotmodel_file")
        self.gridlabd_ip = databus.get_value("gridlabd_ip")
        self.gridlabd_port = databus.get_value("gridlabd_port")
        
        
        databus.set_value("gridpot_obj", self)#save the reference in the databus
        #databus.set_value('register_1', self._get_energy_in_lowres)
        
        request = 'http://' + self.gridlabd_ip + ':' + str(self.gridlabd_port) + '/output/' + self.gridpotmodel_file
        print request
        response = urllib2.urlopen(request)
        self.gridpotmodel = response.read()
        print self.gridpotmodel
        if self.gridpotmodel != None:
            self.setup_gl_objects()
        else:
            print "Could not get the .GPM model from GridLAB-D"
            exit(0)
        
        gevent.spawn(self.poll_gridlabd)
        # end iniitialize
