
LDFLAGS = -lboost_serialization -lboost_system -lboost_filesystem

noinst_LTLIBRARIES = libExampleObjects.la

libExampleObjects_la_SOURCES =

noinst_HEADERS = \
    accountexample.hpp

libExampleObjects_la_LIBADD = \
    Enumerations/libEnumerations.la \
    Serialization/libSerialization.la \
    ValueObjects/libValueObjects.la

EXTRA_DIST = \
    ExampleObjects.vcxproj \
    ExampleObjects.vcxproj.filters

