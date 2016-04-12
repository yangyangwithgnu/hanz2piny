PROJECT(main)


SET( SRC_LIST ../src/main.cpp
              # helper ----
              ../src/lib/helper/CmdlineOption.cpp
              # self ----
              ../src/lib/self/libhanz2piny/Hanz2Piny.cpp )

# linux
#>>>>>>>>>>>>>>>>>>>>>>

## debug
#SET(CMAKE_CXX_COMPILER "clang++")
#SET(CMAKE_CXX_FLAGS "-std=c++11 -O0 -g -Werror -Weverything -Wno-documentation -Wno-deprecated-declarations -Wno-disabled-macro-expansion -Wno-float-equal -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-global-constructors -Wno-exit-time-destructors -Wno-missing-prototypes -Wno-padded -Wno-old-style-cast -Wno-weak-vtables -Wno-deprecated -Wno-shadow -Wno-sign-conversion")
#SET(CMAKE_BUILD_TYPE debug)
#ADD_EXECUTABLE(main ${SRC_LIST})

# release
SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_CXX_FLAGS "-std=c++11 -Ofast")
SET(CMAKE_BUILD_TYPE release)
ADD_EXECUTABLE(hanz2piny ${SRC_LIST})
INSTALL(PROGRAMS hanz2piny DESTINATION /usr/bin/)

#<<<<<<<<<<<<<<<<<<<<<<


## cygwin
##>>>>>>>>>>>>>>>>>>>>>>

#SET(CMAKE_CXX_COMPILER "g++")
#SET(CMAKE_CXX_FLAGS "-std=c++11 -Ofast -s -DCYGWIN")
#SET(CMAKE_BUILD_TYPE release)
#ADD_EXECUTABLE(hanz2piny ${SRC_LIST})

##<<<<<<<<<<<<<<<<<<<<<<
