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

#
# Copyright 2017 Izi Chapa.  All rights reserved.
#

include ../../make-rules/shared-macros.mk

COMPONENT_NAME=		jansson
COMPONENT_VERSION=	2.10
COMPONENT_FMRI=		jansson
COMPONENT_PROJECT_URL=	http://www.digip.org/jansson
COMPONENT_SRC=		$(COMPONENT_NAME)-$(COMPONENT_VERSION)
COMPONENT_ARCHIVE=	$(COMPONENT_SRC).tar.gz
COMPONENT_ARCHIVE_HASH=	\
    sha256:78215ad1e277b42681404c1d66870097a50eb084be9d771b1d15576575cf6447
COMPONENT_ARCHIVE_URL=	http://www.digip.org/jansson/releases/$(COMPONENT_ARCHIVE)
COMPONENT_LICENSE=	MIT
COMPONENT_LICENSE_FILE=	$(COMPONENT_NAME).license

COMPONENT_SUMMARY=	Jansson is a C library for encoding, decoding and manipulating JSON data

include $(WS_MAKE_RULES)/prep.mk
include $(WS_MAKE_RULES)/configure.mk
include $(WS_MAKE_RULES)/ips.mk


CONFIGURE_OPTIONS+=	--prefix=/usr

build:		$(BUILD_32)

install:	$(INSTALL_32)

test:		$(NO_TESTS)

BUILD_PKG_DEPENDENCIES =	$(BUILD_TOOLS)

include $(WS_MAKE_RULES)/depend.mk

