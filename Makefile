


ifndef INSTALLPREF
	export INSTALLPREF="/usr/local"
endif


ifndef _INCLUDED_
export _INCLUDED_=.


default: config cvs-patched


cvs-patched: 
	cd cvs && make


config: 
	cd cvs && ./configure --disable-client --disable-server --prefix=$(INSTALLPREF)


install: install-scripts install-cvs


install-scripts:
	cd scripts && $(MAKE) install 


install-cvs:
	cd cvs && ${MAKE) install
	

endif

help:
	@cat $(_INCLUDED_)/Readme.make

