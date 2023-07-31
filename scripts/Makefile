

ifndef _INCLUDED_
export _INCLUDED_=..
include ../Makefile
endif



install:
	install -D -t $(INSTALLPREF)/bin `cat install.make` 


makeinstall:
	cvsls . | sed -e '/Makefile/d;/install.make/d;/RF/d;/alias.sh/d' > install.make

