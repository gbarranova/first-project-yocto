
SUMMARY = "This is a C program for blinking and LED on nano-pi"
DESCRIPTION = "My description"

LICENSE = "CLOSED"

SRC_URI = "file://mygpio.c"

S = "${WORKDIR}"

DEPENDS = "libgpiod"

TARGET_CC_ARCH += "${LDFLAGS}"

do_compile () {
    ${CC} mygpio.c -o mygpio -lgpiod
}

do_install () {
    install -d ${D}${bindir}
    install -m 0775 mygpio ${D}${bindir}/
}
