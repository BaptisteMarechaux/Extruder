#ifndef GLVIEW_H
#define GLVIEW_H

#include <QGLWidgets>

/* Qt 3D headers */

class GLView : public QGLView
{
 Q_OBJECT

public:
 GLView(QWidget *parent = 0);
 ~GLView();

protected:
 void initializeGL(QGLPainter *painter);
 void paintGL(QGLPainter *painter);

private:
 QGLSceneNode *m_rootNode;
};


GLView::GLView(QWidget *parent)
 : QGLView(parent)
 , m_rootNode(0)
{
 // Create the cube
 QGLBuilder builder;
 builder << QGL::Faceted << QGLCube(2);
 m_rootNode = builder.finalizedSceneNode();

 // Setup the camera
 camera()->setFieldOfView(45);
 camera()->setNearPlane(1);
 camera()->setFarPlane(500);
}

GLView::~GLView()
{
 delete m_rootNode;
}

void GLView::initializeGL(QGLPainter *painter)
{
 QGLLightParameters *lightParameters = new QGLLightParameters(this);
 QGLMaterial *material = new QGLMaterial(this);
 QColor color;

// Setup the lighting for the scene
 painter->setStandardEffect(QGL::LitMaterial);
 color.setRgbF(0.2, 0.2, 0.2, 1.0);
 lightParameters->setAmbientColor(color);
 color.setRgbF(1.0, 1.0, 1.0, 1.0);
 lightParameters->setSpecularColor(color);
 lightParameters->setDirection(QVector3D(0.0, 50.0, 50.0));
 painter->setMainLight(lightParameters);

// Apply a material
 color.setRgbF(1.0, 1.0, 1.0, 1.0);
 material->setSpecularColor(color);
 material->setShininess(60);
 color.setRgbF(0.0, 0.0, 1.0, 1.0);
 material->setAmbientColor(color);
 material->setDiffuseColor(color);
 painter->setFaceMaterial(QGL::AllFaces, material);
}

void GLView::paintGL(QGLPainter *painter)
{
 // Perform some transformations
 painter->modelViewMatrix().translate(0.0, 0.0, 5.0);
 painter->modelViewMatrix().rotate(15.0, 1.0, 0.0, 0.0);
 painter->modelViewMatrix().rotate(30.0, 0.0, 1.0, 0.0);
 painter->modelViewMatrix().rotate(15.0, 0.0, 0.0, 1.0);

// Draw the cube
 m_rootNode->draw(painter);
}


#endif // GLVIEW_H
