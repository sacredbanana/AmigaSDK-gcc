#
# Makefile for CatComp example
#

cat = CatComp
CC = gcc

.PHONY: catalogs all clean

default: all

catalogs:
	$(cat) helloworld.cd CFILE helloworld_strings.h
	$(cat) helloworld.cd helloworld.ct CATALOG Catalogs/french/helloworld.catalog

all: catalogs
	$(CC) -o HelloWorld helloworld.c -lauto
	
clean:
	Delete HelloWorld Catalogs/french/helloworld.catalog helloworld_strings.h quiet

