#include "myVTKCamera.h"

#include <vtkConeSource.h>
#include <vtkShrinkPolyData.h>
#include <vtkCamera.h>
#include <vtkLight.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>

VTKCamera::VTKCamera(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	_pVTKWidget = new QVTKOpenGLNativeWidget();
	this->setCentralWidget(_pVTKWidget);
	// this->showMaximized();

	// 1. generate data
	vtkSmartPointer<vtkConeSource> cone = vtkSmartPointer<vtkConeSource>::New();
	cone->SetResolution(20);
	// or, read data
	// vtkSmartPointer<vtkSTLReader> reader = vtkSmartPointer<vtkSTLReader>::New();
	// reader->SetFileName("42400-IDGH.stl");

	// 2. filter
	vtkSmartPointer<vtkShrinkPolyData> shrink = vtkSmartPointer<vtkShrinkPolyData>::New();
	shrink->SetShrinkFactor(0.6);
	// 3. mapper
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();

	// 4. actor
	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

	// 5. renderer
	vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
	renderer->SetBackground(0.3, 0.6, 0.3);

	// 6. connect
	// shrink->SetInputConnection(cone->GetOutputPort());
	// mapper->SetInputConnection(cone->GetOutputPort());
	mapper->SetInputConnection(cone->GetOutputPort());
	actor->SetMapper(mapper);
	renderer->AddActor(actor);

	vtkCamera* camera = renderer->GetActiveCamera();
	camera->SetFocalPoint(0, 0, 0); // 设置焦点，默认为 (0, 0, 0)
	camera->SetPosition(0, 0, 5); // 设置相机位置，默认为 (0, 0, 1)
	camera->SetViewUp(1, 0, 0); // 设置相机的朝上方向，默认为 (0, 1, 0)
	camera->Zoom(0.8); // 缩放视角
	camera->Elevation(60); // 垂直旋转相机

	this->_pVTKWidget->renderWindow()->AddRenderer(renderer);
	this->_pVTKWidget->renderWindow()->Render();
}

VTKCamera::~VTKCamera()
{}