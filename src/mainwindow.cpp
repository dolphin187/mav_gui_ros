#include "mainwindow.h"
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/PoseStamped.h>

MainWindow::MainWindow(int argc, char **argv, QWidget *parent)
    : QMainWindow(parent)
{
    /** Set up the Control Buttons **/
    buton_takeoff = new QPushButton("Take Off", this);
    buton_takeoff->setGeometry(QRect(QPoint(24, 24),QSize(120, 70)));
    connect(buton_takeoff, SIGNAL (released()), this, SLOT (clicked_takeOff()));

    buton_hover = new QPushButton("Hover", this);
    buton_hover->setGeometry(QRect(QPoint(168, 24),QSize(120, 70)));
    connect(buton_hover, SIGNAL (released()), this, SLOT (clicked_hover()));

    buton_auto = new QPushButton("Auto", this);
    buton_auto->setGeometry(QRect(QPoint(312, 24),QSize(120, 70)));
    connect(buton_auto, SIGNAL (released()), this, SLOT (clicked_auto()));

    buton_auto_hover = new QPushButton("hover", this);
    buton_auto_hover->setGeometry(QRect(QPoint(24, 118),QSize(120, 70)));
    buton_auto_hover->setVisible(false);
    connect(buton_auto_hover, SIGNAL (released()), this, SLOT (clicked_auto_hover()));

    buton_auto_slave = new QPushButton("slave", this);
    buton_auto_slave->setGeometry(QRect(QPoint(168, 118),QSize(120, 70)));
    buton_auto_slave->setVisible(false);
    connect(buton_auto_slave, SIGNAL (released()), this, SLOT (clicked_auto_slave()));

    buton_auto_active = new QPushButton("active", this);
    buton_auto_active->setGeometry(QRect(QPoint(312, 118),QSize(120, 70)));
    buton_auto_active->setVisible(false);
    connect(buton_auto_active, SIGNAL (released()), this, SLOT (clicked_auto_active()));

    buton_auto_somersault = new QPushButton("somersault", this);
    buton_auto_somersault->setGeometry(QRect(QPoint(456, 118),QSize(120, 70)));
    buton_auto_somersault->setVisible(false);
    connect(buton_auto_somersault, SIGNAL (released()), this, SLOT (clicked_auto_somersault()));

    buton_landing = new QPushButton("Landing", this);
    buton_landing->setGeometry(QRect(QPoint(456, 24),QSize(120, 70)));
    connect(buton_landing, SIGNAL (released()), this, SLOT (clicked_landing()));

    buton_stop = new QPushButton("Stop", this);
    buton_stop->setGeometry(QRect(QPoint(24, 250),QSize(552, 116)));
    connect(buton_stop, SIGNAL (released()), this, SLOT (clicked_stop()));

    /** Set up the ROS **/
    ros::init(argc, argv, "keyboard_input");
    ros::NodeHandle n("~");
    cmd_p = n.advertise<geometry_msgs::Vector3Stamped>("command", 10);
    cmd.vector.x = 0;
    cmd.vector.y = 0;
    cmd.vector.z = 0;
}

void MainWindow::clicked_takeOff()
{
    QPalette pal = buton_takeoff->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    buton_takeoff->setAutoFillBackground(true);
    buton_takeoff->setPalette(pal);
    buton_takeoff->update();

    QPalette pal2 = buton_hover->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::white));
    buton_hover->setAutoFillBackground(true);
    buton_hover->setPalette(pal2);
    buton_hover->update();

    QPalette pal3 = buton_auto->palette();
    pal3.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto->setAutoFillBackground(true);
    buton_auto->setPalette(pal3);
    buton_auto_hover->setVisible(false);
    buton_auto_slave->setVisible(false);
    buton_auto_active->setVisible(false);
    buton_auto_somersault->setVisible(false);
    buton_auto->update();

    QPalette pal4 = buton_landing->palette();
    pal4.setColor(QPalette::Button, QColor(Qt::white));
    buton_landing->setAutoFillBackground(true);
    buton_landing->setPalette(pal4);
    buton_landing->update();

    QPalette pal5 = buton_stop->palette();
    pal5.setColor(QPalette::Button, QColor(Qt::white));
    buton_stop->setAutoFillBackground(true);
    buton_stop->setPalette(pal5);
    buton_stop->update();

    cmd.header.frame_id = "takeoff";
    //cmd.vector.x = 255.0;
    cmd_p.publish(cmd);
    ROS_INFO("takeoff");
}

void MainWindow::clicked_hover()
{
    QPalette pal = buton_hover->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    buton_hover->setAutoFillBackground(true);
    buton_hover->setPalette(pal);
    buton_hover->update();

    QPalette pal2 = buton_takeoff->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::white));
    buton_takeoff->setAutoFillBackground(true);
    buton_takeoff->setPalette(pal2);
    buton_takeoff->update();

    QPalette pal3 = buton_auto->palette();
    pal3.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto->setAutoFillBackground(true);
    buton_auto->setPalette(pal3);
    buton_auto_hover->setVisible(false);
    buton_auto_slave->setVisible(false);
    buton_auto_active->setVisible(false);
    buton_auto_somersault->setVisible(false);
    buton_auto->update();

    QPalette pal4 = buton_landing->palette();
    pal4.setColor(QPalette::Button, QColor(Qt::white));
    buton_landing->setAutoFillBackground(true);
    buton_landing->setPalette(pal4);
    buton_landing->update();

    QPalette pal5 = buton_stop->palette();
    pal5.setColor(QPalette::Button, QColor(Qt::white));
    buton_stop->setAutoFillBackground(true);
    buton_stop->setPalette(pal5);
    buton_stop->update();
}

void MainWindow::clicked_auto()
{
    QPalette pal = buton_auto->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    buton_auto->setAutoFillBackground(true);
    buton_auto->setPalette(pal);
    buton_auto_hover->setVisible(true);
    buton_auto_slave->setVisible(true);
    buton_auto_active->setVisible(true);
    buton_auto_somersault->setVisible(true);
    buton_auto->update();

    QPalette pal1 = buton_hover->palette();
    pal1.setColor(QPalette::Button, QColor(Qt::white));
    buton_hover->setAutoFillBackground(true);
    buton_hover->setPalette(pal1);
    buton_hover->update();

    QPalette pal2 = buton_takeoff->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::white));
    buton_takeoff->setAutoFillBackground(true);
    buton_takeoff->setPalette(pal2);
    buton_takeoff->update();

    QPalette pal4 = buton_landing->palette();
    pal4.setColor(QPalette::Button, QColor(Qt::white));
    buton_landing->setAutoFillBackground(true);
    buton_landing->setPalette(pal4);
    buton_landing->update();

    QPalette pal5 = buton_stop->palette();
    pal5.setColor(QPalette::Button, QColor(Qt::white));
    buton_stop->setAutoFillBackground(true);
    buton_stop->setPalette(pal5);
    buton_stop->update();

    QPalette pal8 = buton_auto_hover->palette();
    pal8.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_hover->setAutoFillBackground(true);
    buton_auto_hover->setPalette(pal8);
    buton_auto_hover->update();

    QPalette pal0 = buton_auto_slave->palette();
    pal0.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_slave->setAutoFillBackground(true);
    buton_auto_slave->setPalette(pal0);
    buton_auto_slave->update();

    QPalette pal6 = buton_auto_active->palette();
    pal6.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_active->setAutoFillBackground(true);
    buton_auto_active->setPalette(pal6);
    buton_auto_active->update();

    QPalette pal7 = buton_auto_somersault->palette();
    pal7.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_somersault->setAutoFillBackground(true);
    buton_auto_somersault->setPalette(pal7);
    buton_auto_somersault->update();
}

void MainWindow::clicked_landing()
{
    QPalette pal = buton_landing->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    buton_landing->setAutoFillBackground(true);
    buton_landing->setPalette(pal);
    buton_landing->update();

    QPalette pal1 = buton_hover->palette();
    pal1.setColor(QPalette::Button, QColor(Qt::white));
    buton_hover->setAutoFillBackground(true);
    buton_hover->setPalette(pal1);
    buton_hover->update();

    QPalette pal2 = buton_takeoff->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::white));
    buton_takeoff->setAutoFillBackground(true);
    buton_takeoff->setPalette(pal2);
    buton_takeoff->update();

    QPalette pal3 = buton_auto->palette();
    pal3.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto->setAutoFillBackground(true);
    buton_auto->setPalette(pal3);
    buton_auto_hover->setVisible(false);
    buton_auto_slave->setVisible(false);
    buton_auto_active->setVisible(false);
    buton_auto_somersault->setVisible(false);
    buton_auto->update();

    QPalette pal4 = buton_stop->palette();
    pal4.setColor(QPalette::Button, QColor(Qt::white));
    buton_stop->setAutoFillBackground(true);
    buton_stop->setPalette(pal4);
    buton_stop->update();

    cmd.header.frame_id = "landing";
    cmd_p.publish(cmd);
    ROS_INFO("landing");
}

void MainWindow::clicked_stop()
{
    QPalette pal = buton_stop->palette();
    pal.setColor(QPalette::Button, QColor(Qt::red));
    buton_stop->setAutoFillBackground(true);
    buton_stop->setPalette(pal);
    buton_stop->update();

    QPalette pal4 = buton_landing->palette();
    pal4.setColor(QPalette::Button, QColor(Qt::white));
    buton_landing->setAutoFillBackground(true);
    buton_landing->setPalette(pal4);
    buton_landing->update();

    QPalette pal1 = buton_hover->palette();
    pal1.setColor(QPalette::Button, QColor(Qt::white));
    buton_hover->setAutoFillBackground(true);
    buton_hover->setPalette(pal1);
    buton_hover->update();

    QPalette pal2 = buton_takeoff->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::white));
    buton_takeoff->setAutoFillBackground(true);
    buton_takeoff->setPalette(pal2);
    buton_takeoff->update();

    QPalette pal3 = buton_auto->palette();
    pal3.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto->setAutoFillBackground(true);
    buton_auto->setPalette(pal3);
    buton_auto_hover->setVisible(false);
    buton_auto_slave->setVisible(false);
    buton_auto_active->setVisible(false);
    buton_auto_somersault->setVisible(false);
    buton_auto->update();

    QPalette pal8 = buton_auto_hover->palette();
    pal8.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_hover->setAutoFillBackground(true);
    buton_auto_hover->setPalette(pal8);
    buton_auto_hover->update();

    QPalette pal5 = buton_auto_slave->palette();
    pal5.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_slave->setAutoFillBackground(true);
    buton_auto_slave->setPalette(pal5);
    buton_auto_slave->update();

    QPalette pal6 = buton_auto_active->palette();
    pal6.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_active->setAutoFillBackground(true);
    buton_auto_active->setPalette(pal6);
    buton_auto_active->update();

    QPalette pal7 = buton_auto_somersault->palette();
    pal7.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_somersault->setAutoFillBackground(true);
    buton_auto_somersault->setPalette(pal7);
    buton_auto_somersault->update();

    cmd.vector.x = 255.0;
    cmd.header.frame_id = "stop";
    cmd_p.publish(cmd);
    ROS_INFO("stop");
}

void MainWindow::clicked_auto_hover()
{
    QPalette pal3 = buton_auto_hover->palette();
    pal3.setColor(QPalette::Button, QColor(Qt::blue));
    buton_auto_hover->setAutoFillBackground(true);
    buton_auto_hover->setPalette(pal3);
    buton_auto_hover->update();

    QPalette pal5 = buton_auto_slave->palette();
    pal5.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_slave->setAutoFillBackground(true);
    buton_auto_slave->setPalette(pal5);
    buton_auto_slave->update();

    QPalette pal6 = buton_auto_active->palette();
    pal6.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_active->setAutoFillBackground(true);
    buton_auto_active->setPalette(pal6);
    buton_auto_active->update();

    QPalette pal7 = buton_auto_somersault->palette();
    pal7.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_somersault->setAutoFillBackground(true);
    buton_auto_somersault->setPalette(pal7);
    buton_auto_somersault->update();

    QPalette pal = buton_stop->palette();
    pal.setColor(QPalette::Button, QColor(Qt::white));
    buton_stop->setAutoFillBackground(true);
    buton_stop->setPalette(pal);
    buton_stop->update();

    QPalette pal4 = buton_landing->palette();
    pal4.setColor(QPalette::Button, QColor(Qt::white));
    buton_landing->setAutoFillBackground(true);
    buton_landing->setPalette(pal4);
    buton_landing->update();

    QPalette pal1 = buton_hover->palette();
    pal1.setColor(QPalette::Button, QColor(Qt::white));
    buton_hover->setAutoFillBackground(true);
    buton_hover->setPalette(pal1);
    buton_hover->update();

    QPalette pal2 = buton_takeoff->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::white));
    buton_takeoff->setAutoFillBackground(true);
    buton_takeoff->setPalette(pal2);
    buton_takeoff->update();

    cmd.vector.x = 255.0;
    cmd.vector.y = 0.0;//hover
    cmd.header.frame_id = "auto";
    cmd_p.publish(cmd);
    ROS_INFO("auto_hover");
}

void MainWindow::clicked_auto_slave()
{
    QPalette pal5 = buton_auto_slave->palette();
    pal5.setColor(QPalette::Button, QColor(Qt::blue));
    buton_auto_slave->setAutoFillBackground(true);
    buton_auto_slave->setPalette(pal5);
    buton_auto_slave->update();

    QPalette pal3 = buton_auto_hover->palette();
    pal3.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_hover->setAutoFillBackground(true);
    buton_auto_hover->setPalette(pal3);
    buton_auto_hover->update();

    QPalette pal6 = buton_auto_active->palette();
    pal6.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_active->setAutoFillBackground(true);
    buton_auto_active->setPalette(pal6);
    buton_auto_active->update();

    QPalette pal7 = buton_auto_somersault->palette();
    pal7.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_somersault->setAutoFillBackground(true);
    buton_auto_somersault->setPalette(pal7);
    buton_auto_somersault->update();

    QPalette pal = buton_stop->palette();
    pal.setColor(QPalette::Button, QColor(Qt::white));
    buton_stop->setAutoFillBackground(true);
    buton_stop->setPalette(pal);
    buton_stop->update();

    QPalette pal4 = buton_landing->palette();
    pal4.setColor(QPalette::Button, QColor(Qt::white));
    buton_landing->setAutoFillBackground(true);
    buton_landing->setPalette(pal4);
    buton_landing->update();

    QPalette pal1 = buton_hover->palette();
    pal1.setColor(QPalette::Button, QColor(Qt::white));
    buton_hover->setAutoFillBackground(true);
    buton_hover->setPalette(pal1);
    buton_hover->update();

    QPalette pal2 = buton_takeoff->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::white));
    buton_takeoff->setAutoFillBackground(true);
    buton_takeoff->setPalette(pal2);
    buton_takeoff->update();

    cmd.vector.x = 255.0;
    cmd.vector.y = 1.0;//slave
    cmd.header.frame_id = "auto";
    cmd_p.publish(cmd);
    ROS_INFO("auto_slave");
}

void MainWindow::clicked_auto_active()
{
    QPalette pal3 = buton_auto_active->palette();
    pal3.setColor(QPalette::Button, QColor(Qt::blue));
    buton_auto_active->setAutoFillBackground(true);
    buton_auto_active->setPalette(pal3);
    buton_auto_active->update();

    QPalette pal5 = buton_auto_slave->palette();
    pal5.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_slave->setAutoFillBackground(true);
    buton_auto_slave->setPalette(pal5);
    buton_auto_slave->update();

    QPalette pal6 = buton_auto_hover->palette();
    pal6.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_hover->setAutoFillBackground(true);
    buton_auto_hover->setPalette(pal6);
    buton_auto_hover->update();

    QPalette pal7 = buton_auto_somersault->palette();
    pal7.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_somersault->setAutoFillBackground(true);
    buton_auto_somersault->setPalette(pal7);
    buton_auto_somersault->update();

    QPalette pal = buton_stop->palette();
    pal.setColor(QPalette::Button, QColor(Qt::white));
    buton_stop->setAutoFillBackground(true);
    buton_stop->setPalette(pal);
    buton_stop->update();

    QPalette pal4 = buton_landing->palette();
    pal4.setColor(QPalette::Button, QColor(Qt::white));
    buton_landing->setAutoFillBackground(true);
    buton_landing->setPalette(pal4);
    buton_landing->update();

    QPalette pal1 = buton_hover->palette();
    pal1.setColor(QPalette::Button, QColor(Qt::white));
    buton_hover->setAutoFillBackground(true);
    buton_hover->setPalette(pal1);
    buton_hover->update();

    QPalette pal2 = buton_takeoff->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::white));
    buton_takeoff->setAutoFillBackground(true);
    buton_takeoff->setPalette(pal2);
    buton_takeoff->update();

    cmd.vector.x = 255.0;
    cmd.vector.y = 2.0;//active
    cmd.header.frame_id = "auto";
    cmd_p.publish(cmd);
    ROS_INFO("auto_active");
}

void MainWindow::clicked_auto_somersault()
{
    QPalette pal7 = buton_auto_active->palette();
    pal7.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_active->setAutoFillBackground(true);
    buton_auto_active->setPalette(pal7);
    buton_auto_active->update();

    QPalette pal5 = buton_auto_slave->palette();
    pal5.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_slave->setAutoFillBackground(true);
    buton_auto_slave->setPalette(pal5);
    buton_auto_slave->update();

    QPalette pal6 = buton_auto_hover->palette();
    pal6.setColor(QPalette::Button, QColor(Qt::white));
    buton_auto_hover->setAutoFillBackground(true);
    buton_auto_hover->setPalette(pal6);
    buton_auto_hover->update();

    QPalette pal3 = buton_auto_somersault->palette();
    pal3.setColor(QPalette::Button, QColor(Qt::blue));
    buton_auto_somersault->setAutoFillBackground(true);
    buton_auto_somersault->setPalette(pal3);
    buton_auto_somersault->update();

    QPalette pal = buton_stop->palette();
    pal.setColor(QPalette::Button, QColor(Qt::white));
    buton_stop->setAutoFillBackground(true);
    buton_stop->setPalette(pal);
    buton_stop->update();

    QPalette pal4 = buton_landing->palette();
    pal4.setColor(QPalette::Button, QColor(Qt::white));
    buton_landing->setAutoFillBackground(true);
    buton_landing->setPalette(pal4);
    buton_landing->update();

    QPalette pal1 = buton_hover->palette();
    pal1.setColor(QPalette::Button, QColor(Qt::white));
    buton_hover->setAutoFillBackground(true);
    buton_hover->setPalette(pal1);
    buton_hover->update();

    QPalette pal2 = buton_takeoff->palette();
    pal2.setColor(QPalette::Button, QColor(Qt::white));
    buton_takeoff->setAutoFillBackground(true);
    buton_takeoff->setPalette(pal2);
    buton_takeoff->update();

    cmd.vector.x = 255.0;
    cmd.vector.y = 3.0;//somersault
    cmd.header.frame_id = "auto";
    cmd_p.publish(cmd);
    ROS_INFO("auto_somersault");
}

MainWindow::~MainWindow()
{
    delete buton_takeoff;
    delete buton_hover;
    delete buton_auto;
    delete buton_landing;
    delete buton_stop;
    delete buton_auto_hover;
    delete buton_auto_slave;
    delete buton_auto_active;
    delete buton_auto_somersault;
}

