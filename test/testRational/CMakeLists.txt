file(GLOB SRCS *.cpp)

add_executable(testRational ${SRCS})

target_link_libraries(testRational
    PrimeRat
    libgtest
    libgmock
)

install(TARGETS testRational DESTINATION bin)
