import asl

(drawer, file) = asl.FileRequest(title="Please Select a file", drawer="sys:", \
	filename="", pattern="#?")
asl.MessageBox("Info", "You selected\nDrawer: " + drawer + "\nFile: " + file, "Okay")
