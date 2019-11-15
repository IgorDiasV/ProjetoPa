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
   // Sculptor *matriz;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void putVoxel(int x,int y);

    ~MainWindow();
public slots:
    void mudarRaioEsfera(int r);
    void novoProjeto();
    void cores();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
