#
# This file and its contents are supplied under the terms of the
# Common Development and Distribution License ("CDDL)". You may
# only use this file in accordance with the terms of the CDDL.
#
# A full copy of the text of the CDDL should have accompanied this
# source. A copy of the CDDL is also available via the Internet at
# http://www.illumos.org/license/CDDL.
#

#
# Copyright (c) 2014 Alexander Pyhalov
# Copyright (c) 2015 Aurelien Larcher
#

include ../../make-rules/shared-macros.mk

COMPONENT_NAME=		libcompizconfig
COMPONENT_VERSION=	0.8.10
COMPONENT_FMRI=	 	desktop/compiz/library/libcompizconfig
COMPONENT_CLASSIFICATION=Desktop (GNOME)/Libraries
COMPONENT_PROJECT_URL=	http://www.northfield.ws/
COMPONENT_SUMMARY=	compizconfig libraries - is an alternative configuration system for compiz
COMPONENT_SRC=		$(COMPONENT_NAME)
COMPONENT_ARCHIVE=	$(COMPONENT_NAME)-$(COMPONENT_VERSION).tar.gz
COMPONENT_ARCHIVE_HASH=	\
    sha256:fd6815bbd11b5d2a7d55d8da6957cee5ecd302e3ee55b23183e96cb46b42d875
COMPONENT_ARCHIVE_URL=	http://www.northfield.ws/projects/compiz/releases/$(COMPONENT_VERSION)/$(COMPONENT_SRC).tar.gz
COMPONENT_LICENSE_FILE=	libcompizconfig.license	
COMPONENT_LICENSE=	GPLv2

include $(WS_TOP)/make-rules/prep.mk
include $(WS_TOP)/make-rules/configure.mk
include $(WS_TOP)/make-rules/ips.mk

PATH=/usr/gnu/bin:/usr/bin

# Missing files in build dir without this.
COMPONENT_PRE_CONFIGURE_ACTION =        ($(CLONEY) $(SOURCE_DIR) $(@D))

COMPONENT_PREP_ACTION =        ( cd $(@D) && \
					rm -f ltmain.sh &&\
			                libtoolize --automake --copy --force && \
					intltoolize --force --copy &&\
					aclocal -I. && \
				        autoheader && \
					automake -a -f -c &&\
					autoconf )


CONFIGURE_OPTIONS+=	--sysconfdir=/etc

CONFIGURE_ENV+= INTLTOOL_PERL=$(PERL)

# common targets
build:		$(BUILD_32)

install:	$(INSTALL_32)

test:		$(NO_TESTS)

BUILD_PKG_DEPENDENCIES = $(BUILD_TOOLS)

include $(WS_TOP)/make-rules/depend.mk
