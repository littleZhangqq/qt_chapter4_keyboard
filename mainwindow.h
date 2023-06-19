#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWidget>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseMoveEvent(QMouseEvent *) override;

private slots:


private:
    Ui::MainWindow *ui;
    QLabel *infoLabel;
};
#endif // MAINWINDOW_H
