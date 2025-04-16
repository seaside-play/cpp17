file(GLOB CPP [^.]*.cpp)
file(GLOB HPP [^.]*.hpp)

GLOBAL_ADD_INCLUDE(sun/cpp17 ${HPP})
GLOBAL_ADD_SRC(${CPP})

message("*****************$ENV{GLOBAL_LIBRARY_SRCS}")
