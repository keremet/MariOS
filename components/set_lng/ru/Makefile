#
# This file and its contents are supplied under the terms of the
# Common Development and Distribution License ("CDDL"). You may
# only use this file in accordance with the terms of the CDDL.
#
# A full copy of the text of the CDDL should have accompanied this
# source. A copy of the CDDL is also available via the Internet at
# http://www.illumos.org/license/CDDL.
#

#
# Copyright 2017 Andrey Sokolov. All rights reserved.
#

include ../../../make-rules/shared-macros.mk

COMPONENT_NAME=		set_lng
COMPONENT_VERSION=	1.0
COMPONENT_SRC=		$(COMPONENT_NAME)-$(COMPONENT_VERSION)

include $(WS_TOP)/make-rules/prep.mk
include $(WS_TOP)/make-rules/configure.mk
include $(WS_TOP)/make-rules/ips.mk


build:

install:
	[ -d $(PROTO_DIR) ] || mkdir -p $(PROTO_DIR)
	mkdir -p $(PROTO_DIR)/usr/sbin 
	gcc -c -O3 -DLOCALE=\"ru_RU.UTF-8\" -fno-ident ../set_lng.c -o set_lng.o
	ld -s set_lng.o -lc -o $(PROTO_DIR)/usr/sbin/set_lng 
test:		$(NO_TESTS)

