#ifndef OPNGLWIDGET_H
#define OPNGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>


class OpnGLWidget : public QOpenGLWidget
{
public:
    OpnGLWidget(QWidget *parent = nullptr);
    ~OpnGLWidget();
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
};

#endif // OPNGLWIDGET_H
