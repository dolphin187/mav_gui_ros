cmake_minimum_required(VERSION 2.8.9)
project(ros_qt_gui)

find_package(catkin REQUIRED COMPONENTS roscpp)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)

catkin_package(
  CATKIN_DEPENDS roscpp geometry_msgs
  DEPENDS system-lib
)

qt5_wrap_cpp(QT_MOC_HPP src/mainwindow.h)

include_directories(src ${catkin_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})

add_executable(fly_demo src/mainwindow.cpp
						   src/main.cpp
              			   ${QT_MOC_HPP})

target_link_libraries(fly_demo ${QT_LIBRARIES}
            		  ${catkin_LIBRARIES} Qt5::Widgets)

install(
  TARGETS fly_demo
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
