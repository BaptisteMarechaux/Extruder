#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include "glview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // Création d'un widget qui servira de fenêtre
    QWidget fenetre;
    fenetre.setFixedSize(300, 150);

    // Création du bouton, ayant pour parent la "fenêtre"
    QPushButton bouton("Pimp mon bouton !", &fenetre);
    // Personnalisation du bouton
    bouton.setFont(QFont("Comic Sans MS", 14));
    w.show();
    fenetre.show();
    glview gl_;
    gl_.initializeGL();

    return a.exec();
}
