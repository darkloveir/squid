# Makefile for SQUID Cache
#
# $Id: Makefile,v 1.1 1996/02/22 07:38:06 wessels Exp $
#

prefix=/usr/local/squid
exec_prefix=${prefix}

all: makefile doall

doall:
	@${MAKE} -f makefile all

squid: makefile dosquid

dosquid:
	@${MAKE} -f makefile squid

.DEFAULT:
	@if test \! -f makefile; then ${MAKE} makefile; fi
	@${MAKE} -f makefile $@

makefile: makefile.in Makefile
	@echo Running configure script to generate makefile
	@echo
	@sh configure --prefix=${prefix} --exec_prefix=${exec_prefix}
