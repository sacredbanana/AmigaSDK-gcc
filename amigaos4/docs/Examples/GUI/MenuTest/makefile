#
# Makefile for Menutest
#

CPP	      = g++
CPP_FLAGS = -c
# Enable the following line for debugging:
# CPP_FLAGS = -gstabs -DDEBUG=4 -c
LD_FLAGS  = -lauto -athread=native
BIN	      = Menutest
VERSION	  = 53
# REVISION has to be set manually after a bumprev in $(BIN)_rev.rev
OBJS	  = $(BIN).o

all: $(BIN)_cd.h $(BIN)_rev.h $(BIN)

$(BIN):	$(OBJS)
	$(CPP) -o $@ $(OBJS) $(LD_FLAGS)

%.o: %.cpp $(BIN).h $(BIN)_cd.h $(BIN)_rev.h
	$(CPP) $(CPP_FLAGS) $<

%_rev.h:$(BIN)_rev.rev
	bumprev	$(VERSION) $(BIN)

%_cd.h:	%.cd
	CatComp $(BIN).cd cfile $(BIN)_cd.h
	
clean:
	-Delete $(OBJS) quiet
	-Delete $(BIN)_cd.h quiet
	-Delete $(BIN)_rev.~(rev) quiet
	-Delete $(BIN) quiet

