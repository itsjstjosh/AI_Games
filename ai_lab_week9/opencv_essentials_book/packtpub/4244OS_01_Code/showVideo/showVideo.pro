TARGET: showVideo
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
   showVideo.cpp
INCLUDEPATH += C:\\opencv-buildQt\\install\\include
LIBS += -LC:\\opencv-buildQt\\install\\x64\mingw\\lib \
    -lopencv_core249 \
    -lopencv_highgui249

