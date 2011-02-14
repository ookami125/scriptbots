#include "MainWindow.h"

#include "GLDrawer.h"

#include <QTimer>
#include <QDebug>
#include <QHBoxLayout>
#include <QApplication>

void doQt(int argc, char **argv) {
    
    QApplication app( argc, argv );
    World* world = new World();
    MainWindow foo(world);
    foo.show();
    app.exec();
}

MainWindow::MainWindow( World* w, QWidget *parent )  : QMainWindow(parent), mWorld(w)
{
    mGLWidget = new GLDrawer(this);
    mGLWidget->setWorld(w);
    
    setCentralWidget(mGLWidget);
    
//     QHBoxLayout *mainLayout = new QHBoxLayout;
//     mainLayout->addWidget(mGLWidget);
//     setLayout(mainLayout);
    QTimer* t = new QTimer( this );
    t->start( 50 );
    connect( t, SIGNAL( timeout(  ) ),
                   this, SLOT( timeout(  ) ) );
}

MainWindow::~MainWindow() 
{
}

void MainWindow::timeout()
{
    mWorld->update();
    mGLWidget->updateGL();
}

// #include "MainWindow.moc"