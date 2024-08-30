==============
 CgmRadio 2.1
==============


Purpose of the program
----------------------

CgmRadio is a simple program for listening to network radio stations streaming
with ShoutCast protocol and MPEG-Audio format (usually MP3, MPEG-1 Layer III).
Note that it cannot decode other stream formats like Ogg Vorbis, WMA or AAC+.


Starting
--------

Program is always launched from a shell (CLI) window. Usually it takes a path to
a playlist file, for example:

CgmRadio RAM:mystation.pls

Alternatively a direct URL to an audio stream may be given with STREAM keyword:

CgmRadio STREAM=server.myradio.com:23456/stream

Stream URL must be given *without* "http://" prefix.


Stopping
--------

Playback is stopped by pressing CTRL+C in the console. Alternatively CTRL-C
signal may be sent to the process with some external tool.



Integration with Odyssey Web Browser
------------------------------------

OWB may be configured to play a radio station when a link to *.pls file is
clicked. To do it follow these steps:

1. Copy CgmRadio to some directory on the system command path (for example
   "C:").
2. Enter OWB MIME settins.
3. Add a new mimetype "audio/x-scpls" with extension "pls".
4. Set "External Browser" action and "CgmRadio %l" as browser.
5. Save settings and restart OWB.

From now on OWB will automatically download a playlist file to a temporary
directory and launch CgmRadio. The program will open a shell output window.
It may be stopped with CTRL-C as usual, then window may be closed.

Notes:
1. Usually compatible playlist files are linked with WinAmp icon.
2. Most of such playlists link to MP3 streams. CgmRadio will refuse to play
   streams using other codecs.
3. Sometimes playlists use *.m3u format. It is not yet supported by CgmRadio.


Known bugs and limitations
--------------------------

There are many. Most of them will be fixed in the future.

1. For now only *.pls playlist format is supported. *.m3u will be supported
   in the future.

2. CgmRadio is currently unable to recover from some buffer stalls. There are
   two cases of buffer underrun. The first is when buffer stalls at 0%. In this
   case program can be quit with CTRL+C. The second one is worse and buffer
   stalls at 100%. When user presses CTRL+C nothing happens. This is not a
   crash. User has to start Task Manager tool, find process named
   "http.stream x", where 'x' is some number and send CTRL-C signal to it using
   right mouse button menu. I know, it sucks.

3. No display of metadata information sent inside ShoutCast stream.

4. No GUI yet. In the future the program will become a screenbar module with
   GUI for station selection.

5. Buffer is fixed at 64 kB.

6. No option for dumping stream to a file.


License
-------

The program is freeware. No warranties, no responsibility taken. Freely
redistributable.


Contact
-------

Bugreports, suggestions etc:

Grzegorz Kraszewski
e-mail: krashan@teleinfo.pb.edu.pl
irc: irc.freenode.net #morphos (English), #ppa (Polish), nick "krashan"
Also present on Facebook and Google+
