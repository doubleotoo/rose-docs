#-------------------------------------------------------------------------------
# Variables
#-------------------------------------------------------------------------------

# make ROSE_INSTALL=/path/to/rose/install BOOST_INSTALL=/path/to/boost/install
ROSE_INSTALL    =
BOOST_INSTALL   =

INPUT           = input.cpp
OUTPUT          = rose_input.cpp
EXPECTED_OUTPUT = output.cpp
TRANSLATOR      = translator

#-------------------------------------------------------------------------------
# Rules - build
#-------------------------------------------------------------------------------

all: $(TRANSLATOR)

$(TRANSLATOR): check-variables $(TRANSLATOR).lo
	libtool --mode=link g++ -o $(TRANSLATOR) $(TRANSLATOR).lo \
		-L$(ROSE_INSTALL)/lib -lrose

$(TRANSLATOR).lo:
	libtool --mode=compile g++ -c -o $(TRANSLATOR).lo \
		-I$(ROSE_INSTALL)/include \
		-I$(BOOST_INSTALL)/include \
		$(TRANSLATOR).cpp

#-------------------------------------------------------------------------------
# Rules - test
#-------------------------------------------------------------------------------

check: $(TRANSLATOR)
	./$(TRANSLATOR) $(INPUT)
	diff $(EXPECTED_OUTPUT) $(OUTPUT)
	./a.out

check-variables:
	@[ -z "$(ROSE_INSTALL)" ] && echo "\$$ROSE_INSTALL is not set" && exit 1 || exit 0
	@[ -z "$(BOOST_INSTALL)" ] && echo "\$$BOOST_INSTALL is not set" && exit 1 || exit 0

#-------------------------------------------------------------------------------
# Rules - clean
#-------------------------------------------------------------------------------

clean:
	rm -f $(TRANSLATOR)
	rm -f    \
		a.out  \
		*.o    \
		*.lo   \
		rose_*.cpp \
		*.ti
