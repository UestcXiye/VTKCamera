#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VTKCamera.h"

#include <QVTKOpenGLNativeWidget.h>

class VTKCamera : public QMainWindow
{
	Q_OBJECT

public:
	VTKCamera(QWidget* parent = nullptr);
	~VTKCamera();

private:
	Ui::VTKCameraClass ui;

	QVTKOpenGLNativeWidget* _pVTKWidget = nullptr;
};
