#
#  Makefile for the Squid Object Cache server
#
#  $Id: Makefile.am,v 1.1.2.2 2009/08/16 21:55:43 hno Exp $
#
#  Uncomment and customize the following to suit your needs:
#


libexec_PROGRAMS = mswin_check_ad_group

mswin_check_ad_group_SOURCES = mswin_check_ad_group.c mswin_check_ad_group.h

INCLUDES = -I$(top_srcdir)/include -I$(top_srcdir)/src

#
# Currently activeds and adsiid libraries are not available on MinGW or Cygwin,
# so the following library list is just a placeholder for future MinGW/Cygwin releases.
# This helper can be compiled only using Microsoft Visual Studio.
#
LDADD   = -L$(top_builddir)/lib -lmiscutil -lnetapi32 -ladvapi32 -lole32 -loleaut32 \
          -lntdll -lactiveds -ladsiid $(XTRA_LIBS)

EXTRA_DIST = readme.txt
