TEMPLATE = app
INCLUDEPATH += .

HEADERS     = bookdelegate.h bookwindow.h initdb.h \
    editwindow.h \
    maintaincewindow.h \
    settingswindow.h
RESOURCES   = books.qrc
SOURCES     = bookdelegate.cpp main.cpp bookwindow.cpp \
    editwindow.cpp \
    maintaincewindow.cpp \
    settingswindow.cpp
FORMS       = bookwindow.ui \
    editwindow.ui \
    maintaincewindow.ui \
    settingswindow.ui

QT += sql widgets widgets
requires(qtConfig(tableview))

target.path = ./
INSTALLS += target
