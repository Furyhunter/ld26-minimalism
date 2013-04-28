find_package(SFML REQUIRED COMPONENTS graphics window)
include_directories(${SFML_INCLUDE_DIR})

add_executable(minimalism
    main.cpp
    Entity.cpp
    Player.cpp
    util.cpp
    Tile.cpp
    Camera.cpp
    LevelLoader.cpp
    BackgroundA.cpp
    Spring.cpp
    Switch.cpp
    SwitchedTile.cpp
    SmallTile.cpp
    AboveTile.cpp
    NextLevel.cpp
    BackgroundB.cpp
    
    Entity.h
    Player.h
    main.h
    util.h
    Tile.h
    Camera.h
    LevelLoader.h
    BackgroundA.h
    Spring.h
    Direction.h
    Switch.h
    ISwitchable.h
    SwitchedTile.h
    SmallTile.h
    AboveTile.h
    NextLevel.h
    BackgroundB.h
)

target_link_libraries(minimalism ${SFML_LIBRARIES})