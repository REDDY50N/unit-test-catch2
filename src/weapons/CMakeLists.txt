add_library(WeaponsLib STATIC
        G36.cpp
)

target_include_directories(WeaponsLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(WeaponsLib PUBLIC cxx_std_17)