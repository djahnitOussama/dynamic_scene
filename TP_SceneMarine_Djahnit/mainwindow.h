#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QGraphicsView>
#include <QMenuBar>


#include "pageG.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    PageG *maPage;
    QGraphicsView * maVue;
    QMenu *fileMenu;
    QAction * restartAction;
    QAction *exitAction;
    QAction *timerAction;
    QMenu *aideMenu;
    QAction *aboutAct;

    // méthodes private (utilisées seulement par la classe)
    void createMenus();

private slots:
    void about();
    void initialiseScene();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
};

#endif // MAINWINDOW_H
