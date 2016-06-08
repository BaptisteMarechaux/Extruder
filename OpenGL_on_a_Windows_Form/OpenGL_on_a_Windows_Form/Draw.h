#pragma once

#include <vector>
#include "Bezier.h"
#include "libs\glm\glm.hpp"

using std::vector;

class CurveObject {

public:
	vector<glm::vec3> controlPoints;
	vector<glm::vec3> curvePoints;
	vector<vector<glm::vec3>> splineControlPoints;
	vector<vector<glm::vec3>> splineCurvePoints;
	vector<int> paramPoints;

	CurveObject() {
		controlPoints = vector<glm::vec3>();
		curvePoints = vector<glm::vec3>();
	}
};

namespace draw {
	double camAngle = 1.0;
	double camera_x = cos(camAngle) , camera_y = sin(camAngle), camera_z = sin(camAngle);
	double x_direction = -cos(camAngle), y_direction = -sin(camAngle), z_direction = -sin(camAngle);
	double upX, upY, upZ;
	double zoom = 2;
}

void DrawRender();

void initMenu();

void Initialize();

void _mouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

void mouseMotion(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

void keyboard(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e);

//void specialInput(int key, int x, int y);

void _CreateWindow();

// Fonction qui permet d'afficher du texte
void drawText(int x, int y, char *string, void *font);

void _mouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

void _mouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

void setDim(int _w, int _h);

void UpdateCam();
