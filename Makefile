#
# $Id$
#

SRCDIR = src
BINDIR = Debug
JAVAH = javah
JAVAHFLAGS = -force
CPPFLAGS = -I/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers
CFLAGS = -nostartfiles -dynamiclib

.PHONY: all
all: $(BINDIR)/libtest-throw-from-native.dylib

$(BINDIR)/libtest-throw-from-native.dylib: $(SRCDIR)/com_example_Main.c headers
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $<

$(SRCDIR):
	mkdir -p $@

.PHONY: headers
headers: $(SRCDIR)
	$(JAVAH) -classpath ../test-throw-from-native-java/target/classes -d $(SRCDIR) $(JAVAHFLAGS) com.example.Main

.PHONY: clean
clean:
	$(RM) $(BINDIR)/*.dylib
