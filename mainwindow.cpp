#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBoxLayout>
#include <QString>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(500,600);
    QWidget *view = new QWidget(this);
    setCentralWidget(view);
    infoLabel = new QLabel();
    infoLabel->setParent(view);
    infoLabel->setGeometry(0,0,100,100);
    infoLabel->setText("移动键盘");
    infoLabel->setAlignment(Qt::AlignCenter);
    infoLabel->setStyleSheet("background-color:#666666");

    setMouseTracking(true);
}

void MainWindow::keyPressEvent(QKeyEvent *evt){
    int x = infoLabel->x();
    int y = infoLabel->y();
    switch (evt->key()) {
    case Qt::Key_W:
        infoLabel->setGeometry(x,y-10,100,100);
        break;
    case Qt::Key_S:
        infoLabel->setGeometry(x,y+10,100,100);
        break;
    case Qt::Key_A:
        infoLabel->setGeometry(x-10,y,100,100);
        break;
    case Qt::Key_D:
        infoLabel->setGeometry(x+10,y,100,100);
        break;
    default:
        break;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *evt){
    infoLabel->setText(QObject::tr("%1,%2").arg(evt->x()).arg(evt->y()));
}

void MainWindow::mouseMoveEvent(QMouseEvent *evt){
    QPoint pos = evt->pos();
    infoLabel->setText(QObject::tr("%1,%2").arg(pos.x()).arg(pos.y()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

