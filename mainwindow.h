#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define POSX 40
#define POSY 70
#define WIDTH 800
#define HEIGHT 700


#include <QMainWindow>

#include <fuzzy.h>
#include "painter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Fuzzy* fuzzy;
    Painter* painter;
};
#endif // MAINWINDOW_H
