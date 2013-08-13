add_definitions(-pthread)

add_executable(thread.x thread.cpp)

add_executable(producerConsumer.x producerconsumer.cpp)

target_link_libraries(thread.x pthread)

target_link_libraries(producerConsumer.x pthread)

