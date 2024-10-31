# Dependency libraries
#find_package(LIBRARY_NAME REQUIRED)

# tests
# add_executable(app_scout_demo scout_demo/scout_demo.cpp)
# target_link_libraries(app_scout_demo ugv_sdk)

# add_executable(app_scout_discharge scout_demo/scout_discharge.cpp)
# target_link_libraries(app_scout_discharge ugv_sdk)

# add_executable(app_hunter_demo hunter_demo/hunter_demo.cpp)
# target_link_libraries(app_hunter_demo ugv_sdk)

add_executable(app_show_demo show_demo/show_demo.cpp)
target_link_libraries(app_show_demo ugv_sdk)

add_executable(app_move_demo move_demo/move_demo.cpp)
target_link_libraries(app_move_demo ugv_sdk)

# if(BUILD_MONITOR)
#     add_subdirectory(scout_monitor)
# endif()
