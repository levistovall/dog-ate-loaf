file(GLOB SRCS *.cpp)

add_executable(testMatrix ${SRCS})

target_link_libraries(testMatrix
    NumericalUtility
    libgtest
    libgmock
)

install(TARGETS testMatrix DESTINATION bin)
