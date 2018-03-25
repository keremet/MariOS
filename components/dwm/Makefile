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
# Copyright 2018 Andrey Sokolov. All rights reserved.
#

include ../../make-rules/shared-macros.mk

COMPONENT_NAME=		dwm
COMPONENT_VERSION=	6.1
COMPONENT_SRC=		$(COMPONENT_NAME)-$(COMPONENT_VERSION)

include $(WS_TOP)/make-rules/prep.mk
include $(WS_TOP)/make-rules/configure.mk
include $(WS_TOP)/make-rules/ips.mk


build:
	cd dwm_core && make
	cd runner && make
	cd dwm_calendar && make

install:
	[ -d $(PROTO_DIR) ] || mkdir -p $(PROTO_DIR)
	mkdir -p $(PROTO_DIR)/usr/bin && \
	cp dwm_core/dwm runner/runner dwm_calendar/dwm_calendar $(PROTO_DIR)/usr/bin
test:		$(NO_TESTS)

