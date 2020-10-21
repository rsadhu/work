find_package(Qt5 COMPONENTS  Gui Core Widgets REQUIRED)
if (NOT Qt5_FOUND)
Message(FATAL "Qt5 not found")
endif()

if (Qt5_FOUND)
    Message("Found qt5 ")
   else()
    Message("Boo boo Qt not found")
endif()


include_directories(${Qt5Core_INCLUDE_DIRS} ${Qt5Widgets_INCLUDE_DIRS})
add_executable(testQt main.cpp)
target_link_libraries (testQt ${Qt5Widgets_LIBRARIES})

