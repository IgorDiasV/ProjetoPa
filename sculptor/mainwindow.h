#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sculptor.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int tx,ty,tz;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void novoProjeto();
    void cores();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
