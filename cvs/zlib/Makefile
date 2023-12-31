# Makefile for zlib
# Copyright (C) 1995-2005 Jean-loup Gailly.
# For conditions of distribution and use, see copyright notice in zlib.h

srcdir     = .
top_srcdir = ..


# To compile and test, type:
#    ./configure; make test
# The call of configure is optional if you don't have special requirements
# If you wish to build zlib as a shared library, use: ./configure -s

# To use the asm code, type:
#    cp contrib/asm?86/match.S ./match.S
#    make LOC=-DASMV OBJA=match.o

# To install /usr/local/lib/libz.* and /usr/local/include/zlib.h, type:
#    make install
# To install in $HOME instead of /usr/local, use:
#    make install prefix=$HOME

CC=gcc

CFLAGS=-Os -static
#CFLAGS=-O -DMAX_WBITS=14 -DMAX_MEM_LEVEL=7
#CFLAGS=-g -DDEBUG
#CFLAGS=-O3 -Wall -Wwrite-strings -Wpointer-arith -Wconversion \
#           -Wstrict-prototypes -Wmissing-prototypes

LDFLAGS=libz.a -Lno/lib
LDSHARED=$(CC)
CPP=$(CC) -E

LIBS=libz.a
SHAREDLIB=libz.so
SHAREDLIBV=libz.so.1.2.3
SHAREDLIBM=libz.so.1

# For CVS, separate AR and ARFLAGS.
AR=ar
RANLIB=ranlib
AMTAR=${SHELL} /home/micha/git/cvs/build-aux/missing --run tar
SHELL=/bin/sh
EXE=

prefix=/usr
exec_prefix = $(prefix)
libdir = ${exec_prefix}/lib
includedir = ${prefix}/include
mandir = ${prefix}/share/man
man3dir = ${mandir}/man3

OBJS = adler32.o compress.o crc32.o gzio.o uncompr.o deflate.o trees.o \
       zutil.o inflate.o infback.o inftrees.o inffast.o

OBJA =
# to use the asm code: make OBJA=match.o

TEST_OBJS = example.o minigzip.o

DISTFILES = README FAQ INDEX ChangeLog configure Makefile.* *.[ch] \
  make_vms.com algorithm.txt zlib.3 \
  amiga/[a-z0-9ABD-Z]* \
  as400/[a-z0-9ABD-Z]* \
  msdos/[a-z0-9ABD-Z]* \
  qnx/package.qpg \
  win32/[a-z0-9ABD-Z]* \
  contrib/RE*.contrib \
  contrib/ada/[a-z0-9]* \
  contrib/asm586/match.S contrib/asm586/README.586 \
  contrib/asm686/match.S contrib/asm686/README.686 \
  contrib/blast/[a-z0-9ABD-Z]* \
  contrib/delphi/[a-z0-9ABD-Z]* \
  contrib/infback9/[a-z0-9ABD-Z]* \
  contrib/inflate86/[a-z0-9ABD-Z]* \
  contrib/iostream/[a-z0-9ABD-Z]* \
  contrib/iostream2/[a-z0-9ABD-Z]* \
  contrib/iostream3/[a-z0-9ABD-Z]* \
  contrib/masm686/[a-z0-9ABD-Z]* \
  contrib/masmx64/[a-z0-9ABD-Z]* \
  contrib/masmx86/[a-z0-9ABD-Z]* \
  contrib/minizip/[a-z0-9ABD-Z]* contrib/minizip/Ch* \
  contrib/pascal/[a-z0-9ABD-Z]* \
  contrib/puff/[a-z0-9ABD-Z]* \
  contrib/testzlib/[a-z0-9ABD-Z]* \
  contrib/untgz/[a-z0-9ABD-Z]* \
  contrib/vstudio/readme.txt \
  contrib/vstudio/vc7/[a-z0-9ABD-Z]* \
  contrib/vstudio/vc8/[a-z0-9ABD-Z]* \
  old/[a-np-z0-9ABD-Z]* old/os2/[a-z0-9ABD-Z]* \
  examples/[a-z0-9ABD-Z]* \
  libz.dep libz.dsp libz.mak .cvsignore

# for CVS's distdir & Makefile targets
subdir = zlib

# For CVS, just build libz.a
all: libz.a

# To reenable make test
all-original: example$(EXE) minigzip$(EXE)

check test: all-original
	@LD_LIBRARY_PATH=.:$(LD_LIBRARY_PATH) ; export LD_LIBRARY_PATH; \
	echo hello world | ./minigzip | ./minigzip -d || \
	  echo '		*** minigzip test FAILED ***' ; \
	if ./example; then \
	  echo '		*** zlib test OK ***'; \
	else \
	  echo '		*** zlib test FAILED ***'; \
	fi

# For CVS, use an explict rc after $(AR).
libz.a: $(OBJS) $(OBJA)
	$(AR) rc $@ $(OBJS) $(OBJA)
	-@ ($(RANLIB) $@ || true) >/dev/null 2>&1

match.o: match.S
	$(CPP) match.S > _match.s
	$(CC) -c _match.s
	mv _match.o match.o
	rm -f _match.s

$(SHAREDLIBV): $(OBJS)
	$(LDSHARED) -o $@ $(OBJS)
	rm -f $(SHAREDLIB) $(SHAREDLIBM)
	ln -s $@ $(SHAREDLIB)
	ln -s $@ $(SHAREDLIBM)

example$(EXE): example.o $(LIBS)
	$(CC) $(CFLAGS) -o $@ example.o $(LDFLAGS)

minigzip$(EXE): minigzip.o $(LIBS)
	$(CC) $(CFLAGS) -o $@ minigzip.o $(LDFLAGS)

# For CVS, make install dependant on all and remove the uninstall target.
install: all
uninstall:
.PHONY: install uninstall

# Remove targets for CVS
dvi info pdf ps:
.PHONY: dvi info pdf ps
installcheck:
.PHONY: installcheck

#install: $(LIBS)
#	-@if [ ! -d $(exec_prefix) ]; then mkdir -p $(exec_prefix); fi
#	-@if [ ! -d $(includedir)  ]; then mkdir -p $(includedir); fi
#	-@if [ ! -d $(libdir)      ]; then mkdir -p $(libdir); fi
#	-@if [ ! -d $(man3dir)     ]; then mkdir -p $(man3dir); fi
#	cp zlib.h zconf.h $(includedir)
#	chmod 644 $(includedir)/zlib.h $(includedir)/zconf.h
#	cp $(LIBS) $(libdir)
#	cd $(libdir); chmod 755 $(LIBS)
#	-@(cd $(libdir); $(RANLIB) libz.a || true) >/dev/null 2>&1
#	cd $(libdir); if test -f $(SHAREDLIBV); then \
#	  rm -f $(SHAREDLIB) $(SHAREDLIBM); \
#	  ln -s $(SHAREDLIBV) $(SHAREDLIB); \
#	  ln -s $(SHAREDLIBV) $(SHAREDLIBM); \
#	  (ldconfig || true)  >/dev/null 2>&1; \
#	fi
#	cp zlib.3 $(man3dir)
#	chmod 644 $(man3dir)/zlib.3
# The ranlib in install is needed on NeXTSTEP which checks file times
# ldconfig is for Linux

#uninstall:
#	cd $(includedir); \
#	cd $(libdir); rm -f libz.a; \
#	if test -f $(SHAREDLIBV); then \
#	  rm -f $(SHAREDLIBV) $(SHAREDLIB) $(SHAREDLIBM); \
#	fi
#	cd $(man3dir); rm -f zlib.3

installdirs:
.PHONY: installdirs

# distdir added for CVS.
top_builddir = ..
PACKAGE = cvs
VERSION = 1.12.13
distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
distdir:
	@d=$(srcdir); \
	for file in `cd $$d; echo $(DISTFILES)`; do \
	  if test -d $(distdir)/`dirname $$file`; then \
	    :; \
	  else \
	    mkdir $(distdir)/`dirname $$file`; \
	  fi; \
	  if test -d $$d/$$file; then \
	    cp -pR $$d/$$file $(distdir) \
	    || exit 1; \
	  else \
	    test -f $(distdir)/$$file \
	    || cp -p $$d/$$file $(distdir)/$$file \
	    || exit 1; \
	  fi; \
	done
.PHONY: distdir

mostlyclean: clean
clean:
	rm -f *.o *~ example$(EXE) minigzip$(EXE) \
	   libz.a libz.so* foo.gz so_locations \
	   _match.s maketree contrib/infback9/*.o \
	   tags
.PHONY: mostlyclean clean

realclean: distclean
maintainer-clean: distclean
distclean: clean
	rm -f Makefile .DS_Store

zip:
	mv Makefile Makefile~; cp -p Makefile.in Makefile
	rm -f test.c ztest*.c contrib/minizip/test.zip
	v=`sed -n -e 's/\.//g' -e '/VERSION "/s/.*"\(.*\)".*/\1/p' < zlib.h`;\
	zip -ul9 zlib$$v $(DISTFILES)
	mv Makefile~ Makefile

dist:
	mv Makefile Makefile~; cp -p Makefile.in Makefile
	rm -f test.c ztest*.c contrib/minizip/test.zip
	d=zlib-`sed -n '/VERSION "/s/.*"\(.*\)".*/\1/p' < zlib.h`;\
	rm -f $$d.tar.gz; \
	if test ! -d ../$$d; then rm -f ../$$d; ln -s `pwd` ../$$d; fi; \
	files=""; \
	for f in $(DISTFILES); do files="$$files $$d/$$f"; done; \
	cd ..; \
	GZIP=-9 $(AMTAR) chofz $$d/$$d.tar.gz $$files; \
	if test ! -d $$d; then rm -f $$d; fi
	mv Makefile~ Makefile

.PHONY: tags
tags: TAGS

TAGS:
	tags=; \
	here=`pwd`; \
	list=`(echo *.[ch] && cd $(srcdir) && echo *.[ch]) |sort |uniq`; \
	unique=`for i in $$list; do \
	    if test -f "$$i"; then echo $$i; else echo $(srcdir)/$$i; fi; \
	  done | \
	  $(AWK) '    { files[$$0] = 1; } \
	       END { for (i in files) print i; }'`; \
	test -z "$(ETAGS_ARGS)$$unique$(LISP)$$tags" \
	  || etags $(ETAGS_ARGS) $$tags $$unique $(LISP)

# Makefile target added for CVS.
Makefile: $(srcdir)/Makefile.in  $(top_builddir)/config.status
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/$@ CONFIG_HEADERS= $(SHELL) ./config.status

depend:
	makedepend -- $(CFLAGS) -- *.[ch]

# DO NOT DELETE THIS LINE -- make depend depends on it.

adler32.o: zlib.h zconf.h
compress.o: zlib.h zconf.h
crc32.o: crc32.h zlib.h zconf.h
deflate.o: deflate.h zutil.h zlib.h zconf.h
example.o: zlib.h zconf.h
gzio.o: zutil.h zlib.h zconf.h
inffast.o: zutil.h zlib.h zconf.h inftrees.h inflate.h inffast.h
inflate.o: zutil.h zlib.h zconf.h inftrees.h inflate.h inffast.h
infback.o: zutil.h zlib.h zconf.h inftrees.h inflate.h inffast.h
inftrees.o: zutil.h zlib.h zconf.h inftrees.h
minigzip.o: zlib.h zconf.h
trees.o: deflate.h zutil.h zlib.h zconf.h trees.h
uncompr.o: zlib.h zconf.h
zutil.o: zutil.h zlib.h zconf.h
