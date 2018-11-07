#include <QtWidgets>

#include "mainWindow.h"
#include "pageG.h"
#include "elementG.h"


// Constructeur de la fenêtre principale
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),maPage(NULL),maVue(NULL)
{
    createMenus();
    setWindowTitle("TP 2017");

    initialiseScene();      // initialisation de la scene graphique
}

void MainWindow::initialiseScene()
{
    if (maPage)      // dans le cas d'une réinitialisation
        delete maPage;
    if (maVue)
        delete maVue;

    // création d'une nouvelle PageG en utilisant le fichier ini
    maPage = new PageG(this,"FeuilleGraph.ini");
    maPage->setBackgroundBrush(QBrush(QColor(255,237,200),Qt::Dense5Pattern));
    setGeometry(200,100,maPage->width()+6,maPage->height()+52);

    // pour figer la taille de la scène lorsque tous les éléments sont chargés
    // remarque : par défaut la scene englobe ses éléments, sa dimension est réactualisée en permanence
    maPage->setSceneRect(maPage->sceneRect());


    // la scène n'est qu'un container d'éléments, il faut créer une vue pour le rendu graphique et l'affichage
    maVue = new QGraphicsView ( maPage);
    maVue->setRenderHint(QPainter::Antialiasing);
    setCentralWidget(maVue);  // la vue devient la région centrale de la fenetre d'applicati
}


MainWindow::~MainWindow()
{
    // les éléments 'enfants' sont automatiquement libérés
    // donc rien à faire dans cette version

}


void MainWindow::createMenus()
{
    // création et configuration de la barre des menus

    // menu 'fichier'
    fileMenu = menuBar()->addMenu("&Fichier");
    restartAction = fileMenu->addAction(tr("&Redémarrer"),this,&MainWindow::initialiseScene,QKeySequence("Ctrl+r"));
    restartAction->setToolTip(tr("Recharge l'ensemble de la scène graphique"));
    exitAction = fileMenu->addAction(tr("&Quitter"),this,&MainWindow::close,QKeySequence("Ctrl+q"));
    fileMenu->setToolTipsVisible(true);
 //   timerAction = fileMenu->addAction(tr("Stop &Timer"),this,&MainWindow::stopTimer,QKeySequence("Ctrl+t"));



    // menu 'Aide'
    aideMenu = menuBar()->addMenu("&Aide");
    aboutAct = aideMenu->addAction(tr("A &propos de"),this,&MainWindow::about,QKeySequence(tr("Ctrl+p")));
    aboutAct->setToolTip(tr("A propos de"));
    aideMenu->setToolTipsVisible(true);
}

void MainWindow::about()
{
    // la fonction affiche quelques informations sur le logiciel

    QString explications(" Version initiale : <b>TD de démonstration </b>"
                         "<blockquote style=color:blue>Noter l'utilisation du fichier 'FeuilleGraph.Ini' à l'initialisation<br> "
                         "modifiez-le, puis rechargez avec menu Redémarrer"
                         "</blockquote><p><i>TP Master 1 AII Mulhouse 2017 </i>");
    QMessageBox::about(this, "A propos de FeuilleGraphique", explications);


}

