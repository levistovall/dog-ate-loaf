file(GLOB NUMERICAL_UTILITY_SOURCES "factorutil/*.cpp" "rational/*.cpp" "matrix/*.cpp")
add_library(NumericalUtility ${NUMERICAL_UTILITY_SOURCES})
