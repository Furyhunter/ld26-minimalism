find_package(SFML REQUIRED COMPONENTS graphics window)

add_executable(minimalism
    main.cpp
    Entity.cpp
    Player.cpp
    util.cpp
    Tile.cpp
    Camera.cpp
    LevelLoader.cpp
    BackgroundA.cpp
    
    Entity.h
    Player.h
    main.h
    util.h
    Tile.h
    Camera.h
    LevelLoader.h
    BackgroundA.h
)

target_link_libraries(minimalism ${SFML_LIBRARIES})
