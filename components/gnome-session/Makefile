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
# Copyright 2015 Alexander Pyhalov
#

include ../../make-rules/shared-macros.mk

COMPONENT_NAME= gnome-session
COMPONENT_VERSION= 2.32.1
UPDATENUM = 0
COMPONENT_REVISION= 1
COMPONENT_SUMMARY= GNOME session manager
COMPONENT_SRC= $(COMPONENT_NAME)-$(COMPONENT_VERSION)
COMPONENT_ARCHIVE= $(COMPONENT_SRC).tar.bz2
COMPONENT_ARCHIVE_HASH= \
  sha256:22d93ce433fcf9c7ce6b5f36dd81f64e692ea0e41faaa0f61159ddac28c3686a
COMPONENT_ARCHIVE_URL= \
  http://download.gnome.org/sources/gnome-session/2.32/$(COMPONENT_ARCHIVE)
COMPONENT_PROJECT_URL = http://www.gnome.org
COMPONENT_FMRI = gnome/gnome-session
COMPONENT_CLASSIFICATION = Desktop (GNOME)/Sessions
COMPONENT_LICENSE = GPLv2, LGPLv2
COMPONENT_LICENSE_FILE = gnome-session.license

include ../../make-rules/prep.mk
include ../../make-rules/configure.mk
include ../../make-rules/ips.mk

PATH=/usr/gnu/bin:/usr/bin

COMPONENT_PREP_ACTION = 	( cd  $(@D) &&\
					libtoolize --force &&\
					intltoolize -c -f --automake &&\
					aclocal -I . &&\
					autoheader &&\
					automake -a -c -f &&\
					autoconf )

# Missing files in build dir for configure without this.
COMPONENT_PRE_CONFIGURE_ACTION =        ($(CLONEY) $(SOURCE_DIR) $(@D))
                                        
LDFLAGS += -lsecdb  -lsocket  -lnsl

CONFIGURE_OPTIONS += --sysconfdir=/etc
CONFIGURE_OPTIONS += --libexecdir=/usr/lib

COMPONENT_INSTALL_ENV += GCONF_DISABLE_MAKEFILE_SCHEMA_INSTALL=1

build: $(BUILD_32)

install: $(INSTALL_32)
