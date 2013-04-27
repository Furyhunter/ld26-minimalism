find_package(SFML REQUIRED COMPONENTS graphics window)

add_executable(minimalism
    main.cpp
    Entity.cpp
    Player.cpp
    
    Entity.h
    Player.h
    main.h)

target_link_libraries(minimalism ${SFML_LIBRARIES})
