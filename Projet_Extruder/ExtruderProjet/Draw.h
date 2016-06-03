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

void Render();

void initMenu();

void Initialize();

void mouse(int button, int state, int x, int y);

void mouseMotion(int x, int y);

void keyboard(unsigned char key, int xmouse, int ymouse);

void specialInput(int key, int x, int y);

void _CreateWindow();

// Fonction qui permet d'afficher du texte
void drawText(int x, int y, char *string, void *font);