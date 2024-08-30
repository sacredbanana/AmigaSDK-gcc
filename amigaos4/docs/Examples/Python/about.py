import amiga
import asl
import platform

pf = platform.platform()
node = platform.node()

str = "AmigaOS Python\n" \
 + "\nPlatform: " + pf + "\n" \
 + "Hostname: " + node + "\n" \
 + "CPU: " + amiga.getcpu() + "\n" \
 + "Machine: " + amiga.getmachine() + "\n"

asl.MessageBox("Amiga Python 2.5.6", str, "Great")

