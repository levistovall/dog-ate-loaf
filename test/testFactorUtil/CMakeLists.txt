file(GLOB SRCS *.cpp)

add_executable(testFactorUtil ${SRCS})

target_link_libraries(testFactorUtil
    NumericalUtility
    libgtest
    libgmock
)

install(TARGETS testFactorUtil DESTINATION bin)
