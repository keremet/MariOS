#
# This file and its contents are supplied under the terms of the
# Common Development and Distribution License ("CDDL"), version 1.0.
# You may only use this file in accordance with the terms of version
# 1.0 of the CDDL.
#
# A full copy of the text of the CDDL should have accompanied this
# source.  A copy of the CDDL is also available via the Internet at
# http://www.illumos.org/license/CDDL.
#


include ../../make-rules/shared-macros.mk

COMPONENT_NAME=		locale-chm
COMPONENT_FMRI=		locale/chm
COMPONENT_PROJECT_URL=	http://src.illumos.org/source/xref/illumos-gate/usr/src/data/locale/data/
COMPONENT_SUMMARY=	Mari  language support
IPS_COMPONENT_VERSION= 1

include $(WS_MAKE_RULES)/prep.mk
include $(WS_MAKE_RULES)/configure.mk
include $(WS_MAKE_RULES)/ips.mk


build:		

install:	
	localedef -v -f UTF-8.cm -u UTF-8 -w widths.txt -i ru_CHM.UTF-8.src ru_CHM.UTF-8	

test:		$(NO_TESTS)
