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
# Copyright 2016 Andrey Sokolov. All rights reserved.
#

include ../../make-rules/shared-macros.mk

COMPONENT_NAME=		crzvol
COMPONENT_VERSION=	2.0
COMPONENT_SRC=		$(COMPONENT_NAME)-$(COMPONENT_VERSION)

include $(WS_TOP)/make-rules/prep.mk
include $(WS_TOP)/make-rules/configure.mk
include $(WS_TOP)/make-rules/ips.mk


build:
	cd crttymon && make

install:
	[ -d $(PROTO_DIR) ] || mkdir -p $(PROTO_DIR)
	mkdir -p $(PROTO_DIR)/usr/bin && \
	cp files/* crttymon/crttymon $(PROTO_DIR)/usr/bin
test:		$(NO_TESTS)

