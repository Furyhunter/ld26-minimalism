find_package(SFML REQUIRED COMPONENTS system graphics window)
include_directories(${SFML_INCLUDE_DIR})

add_executable(minimalism FlashText.cpp EndGameBackground.cpp 
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
    EndGameGate.cpp
    
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
    EndGameGate.h
    EndGameBackground.h
    FlashText.h
)

target_link_libraries(minimalism ${SFML_LIBRARIES})