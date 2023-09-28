add_executable(FIO main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype)
find_package(JPEG)
find_package(SFML 2 COMPONENTS window graphics system)

target_compile_features(FIO PUBLIC cxx_std_17)
target_compile_definitions(FIO PRIVATE SFML_STATIC)

target_link_libraries(FIO ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})