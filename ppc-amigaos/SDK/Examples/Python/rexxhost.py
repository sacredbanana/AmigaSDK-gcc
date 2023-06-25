# An ARexx host example written in Python
# This example will open a port "LOGGER" and accept messages with two
# supported commands:
#
# LOG <text string> -> write a time stamped log string to a console window
# QUIT			  -> Quit the logger program

import arexx
import time

# Make the ARexx port
port = arexx.Port("LOGGER")

if port == None:
	print "can't allocate port " + port.name
	quit()

running = 1

print "[" + time.ctime(time.time()) + "] Logging started, port name " + port.name

while running:
	# Wait for a message to arrive
	port.wait(10000000)
	
	# Get the message
	msg = port.getmsg()
	
	# Now examine the content
	if msg == None:
		print "message timeout; retrying"
	elif msg.msg[:3] == "LOG":
		print "[" + time.ctime(time.time()) + "] " + msg.msg[4:]
		msg.reply()
	elif msg.msg[:4] == "QUIT":
		print "[" + time.ctime(time.time()) + "] logging terminated. Close the window to get rid of it."
		msg.reply()
		running = 0
	else:
		msg.error(20)

port.close()
