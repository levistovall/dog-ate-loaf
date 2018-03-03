file(GLOB SRCS *.cpp)

add_executable(testRational ${SRCS})

target_link_libraries(testRational
    PrimeRat
)

install(TARGETS testRational DESTINATION bin)
