file(GLOB SRCS *.cpp)

add_executable(testPrimeAssistant ${SRCS})

target_link_libraries(testPrimeAssistant
    PrimeRat
    libgtest
    libgmock
)

install(TARGETS testPrimeAssistant DESTINATION bin)
