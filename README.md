# Dependencies
Install these dependencies before buiding and installing gridlabd and conpot

* autconf/automake/libtool
* subversion
* python-dev
* mysql-server   (library and dev files)
* python-mysqldb
* xerces-c       (library and dev files)
* libcurl(ssl|gnutls)

more gridlabd info: http://gridlab-d.sourceforge.net/wiki/index.php/Linux/Unix

# Install 

First, install mysqld

Set up conpot with:

conpot/sudo make clean (if rebuilding)

conpot/sudo python setup.py install

Set up gridlabd with:

autoreconf -isf

make

sudo make install

Set up libiec61850:

make

make INSTALL_PREFIX=/usr/local install

# Demo commands

We'll do a demo with the IEEE_13_Node_Test_Feeder.glm

for GridLAB-D 

cd gridlabd/3.1/models

gridlabd -D run_realtime=1 --server --debug --verbose IEEE_13_Node_Test_Feeder.glm 

For conpot:

sudo conpot -t gridpot

start configured IEDs

# Useful Developer Links

To expand the GridLAB-D objects we can interact with from conpot, one should see:
http://gridlab-d.sourceforge.net/wiki/index.php/Power_Flow_User_Guide

