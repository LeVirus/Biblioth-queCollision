TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    vector2d.cpp \
    segment.cpp \
    rectbox.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    vector2d.hpp \
    collisionconstants.hpp \
    segment.hpp \
    rectbox.hpp

