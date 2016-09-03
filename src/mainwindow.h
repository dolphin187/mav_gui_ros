#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include "ros/ros.h"
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/PoseStamped.h>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(int argc, char** argv, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void clicked_takeOff();
    void clicked_hover();
    void clicked_auto();
    void clicked_landing();
    void clicked_stop();
    void clicked_auto_hover();
    void clicked_auto_slave();
    void clicked_auto_active();
    void clicked_auto_somersault();

private:
    QPushButton *buton_takeoff;
    QPushButton *buton_hover;
    QPushButton *buton_auto;
    QPushButton *buton_landing;
    QPushButton *buton_stop;
    QPushButton *buton_auto_hover;
    QPushButton *buton_auto_slave;
    QPushButton *buton_auto_active;
    QPushButton *buton_auto_somersault;

    ros::Subscriber s1;
    //= n.subscribe("keyboard_cmd", 10, keyboard_callback);
    ros::Publisher cmd_p;
    geometry_msgs::Vector3Stamped cmd;
};

#endif // MAINWINDOW_H

