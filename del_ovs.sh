kill `cd /usr/local/var/run/openvswitch && cat ovsdb-server.pid ovs-vswitchd.pid`
rm -R /usr/local/etc/openvswitch
ovs-dpctl del-dp system@ovs-system
rmmod openvswitch
rmmod libcrc32c 
