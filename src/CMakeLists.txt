add_executable(${EXEC_NAME}
        main.cpp
)
add_subdirectory(weapons)

target_link_libraries(${EXEC_NAME} PRIVATE  WeaponsLib)