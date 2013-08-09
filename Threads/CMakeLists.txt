add_definitions(-pthread)

add_executable(thread.x thread.cpp)

target_link_libraries(thread.x pthread)

