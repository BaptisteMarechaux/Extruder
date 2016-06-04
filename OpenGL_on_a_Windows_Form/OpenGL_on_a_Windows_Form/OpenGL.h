#pragma once

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Draw.h"

using namespace System::Windows::Forms;
using namespace System::Collections;
namespace OpenGLForm
{
	public ref class COpenGL : public System::Windows::Forms::Panel
	{
	public:
		HGLRC m_hglrc;
	private:
		HDC m_hDC;

		GLfloat	rtri;				// Angle for the triangle
		GLfloat	rquad;				// Angle for the quad
									//  Camera position, look at position, up vector
		double eyeX, eyeY, eyeZ;
		double centerX, centerY, centerZ;
		double upX, upY, upZ;

		int cameraType;

	public:
		COpenGL(System::Windows::Forms::PictureBox ^ parentForm, GLsizei iWidth, GLsizei iHeight, int vcameraType)
		{
			this->Cursor = System::Windows::Forms::Cursors::Cross;
			this->Location = System::Drawing::Point(20, 20);

			//this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, keyboard);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(mouse);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(mouseMove);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(mouseMotion);
			//this->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(mouseMotion);

			// Specify the form as the parent.
			this->Parent = parentForm;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			this->CreateParams->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			cameraType = vcameraType;

			/*CreateParams^ cp = gcnew CreateParams;

			// Set the position on the form
			cp->X = 0;
			cp->Y = 0;
			cp->Height = parentForm->Height;//iHeight;
			cp->Width = parentForm->Width;//iWidth;

			// Specify the form as the parent.
			cp->Parent = parentForm->Handle;

			// Create as a child of the specified parent and make OpenGL compliant (no clipping)
			cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

			// Create the actual window
			this->CreateHandle(cp);*/

			m_hDC = GetDC((HWND)this->Handle.ToPointer());

			if (m_hDC)
			{
				//wglCreateContext(m_hDC);//atau panggil 2x u wglCreateContext ...//or change to clr
				MySetPixelFormat(m_hDC);
				//MySetCurrentGLRC();
				ReSizeGLScene(iWidth, iHeight);
				InitGL();
			}
			else {
				MessageBox::Show("Can not get HDC");
			}

			rtri = 0.0f;
			rquad = 0.0f;
		}


		System::Void Render()
		{
			MySetCurrentGLRC();
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			//display(1);

			//---------draw grid XZ-planes----------//
			glLoadIdentity();
			glBegin(GL_LINES);
			glColor3f(0, 0, 0);
			for (float z = -10; z <= 10; z += 0.4) {
				glVertex3d(-10, 0, z);
				glVertex3d(10, 0, z);
			}
			glEnd();

			glBegin(GL_LINES);
			glColor3f(0, 0, 0);
			for (float x = -10; x <= 10; x += 0.4) {
				glVertex3d(x, 0, -10);
				glVertex3d(x, 0, 10);
			}
			glEnd();
			//---------draw grid XZ-planes----------//

			//---------draw grid XY-planes----------//
			//glLoadIdentity();
			//glBegin(GL_LINES);
			//glColor3f(0,0,0);
			//for(float x=-10; x <=10; x+=0.4){
			//	glVertex3d(x,-10,0);
			//	glVertex3d(x,10,0);
			//}	
			//glEnd();

			//glBegin(GL_LINES);
			//glColor3f(0,0,0);
			//for(float y=-10; y <=10; y+=0.4){
			//	glVertex3d(-10,y,0);
			//	glVertex3d(10,y,0);
			//}	
			//glEnd();
			//---------draw grid XY-planes----------//

			//--------------axis----------------//
			glLoadIdentity();
			glColor3f(0, 0, 1);
			glBegin(GL_LINES);
			glVertex3d(0, 0, 0);
			glVertex3d(0, 0.5, 0);
			glEnd();

			glColor3f(0, 1, 0);
			glBegin(GL_LINES);
			glVertex3d(0, 0, 0);
			glVertex3d(0.5, 0, 0);
			glEnd();

			glColor3f(1, 0, 0);
			glBegin(GL_LINES);
			glVertex3d(0, 0, 0);
			glVertex3d(0, 0, 0.5);
			glEnd();

			DrawRender();
		}

		System::Void SwapOpenGLBuffers(System::Void)
		{
			SwapBuffers(m_hDC);
		}


	protected:
		~COpenGL(System::Void)
		{
			this->DestroyHandle();
		}


		GLint MySetPixelFormat(HDC hdc)
		{
			static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
			{
				sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
				1,											// Version Number
				PFD_DRAW_TO_WINDOW |						// Format Must Support Window
				PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
				PFD_DOUBLEBUFFER,							// Must Support Double Buffering
				PFD_TYPE_RGBA,								// Request An RGBA Format
				16,										// Select Our Color Depth
				0, 0, 0, 0, 0, 0,							// Color Bits Ignored
				0,											// No Alpha Buffer
				0,											// Shift Bit Ignored
				0,											// No Accumulation Buffer
				0, 0, 0, 0,									// Accumulation Bits Ignored
				16,											// 16Bit Z-Buffer (Depth Buffer)  
				0,											// No Stencil Buffer
				0,											// No Auxiliary Buffer
				PFD_MAIN_PLANE,								// Main Drawing Layer
				0,											// Reserved
				0, 0, 0										// Layer Masks Ignored
			};

			GLint  iPixelFormat;

			// get the device context's best, available pixel format match 
			if ((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
			{
				MessageBox::Show("ChoosePixelFormat Failed");
				return 0;
			}

			// make that match the device context's current pixel format 
			if (SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
			{
				MessageBox::Show("SetPixelFormat Failed");
				return 0;
			}

			if ((m_hglrc = wglCreateContext(m_hDC)) == NULL)//m_hDC
			{
				MessageBox::Show("wglCreateContext Failed");
				return 0;
			}

			//wglShareLists(m_oldHglrc,m_hglrc);
			if ((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
			{
				MessageBox::Show("wglMakeCurrent Failed");
				return 0;
			}


			return 1;
		}
		virtual System::Void MySetCurrentGLRC()
		{
			if (m_hDC)
			{
				//these two lines aren't working...
				wglMakeCurrent(NULL, NULL);
				//wglShareLists(m_oldHglrc,m_hglrc);	
				if ((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
				{
					MessageBox::Show("wglMakeCurrent Failed");
				}

			}
		}

		bool InitGL(GLvoid)										// All setup for opengl goes here
		{
			MySetCurrentGLRC();
			glShadeModel(GL_SMOOTH);							// Enable smooth shading
			glClearColor(1.0f, 1.0f, 1.0f, 0.0f);				// Black background
			glClearDepth(1.0f);									// Depth buffer setup
			glEnable(GL_DEPTH_TEST);							// Enables depth testing
			glDepthFunc(GL_LEQUAL);								// The type of depth testing to do
			glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really nice perspective calculations
			Initialize();
			return TRUE;										// Initialisation went ok
		}

	public:
		GLvoid ReSizeGLScene(GLsizei width, GLsizei height) {		// Resize and initialise the gl window
			MySetCurrentGLRC();
			if (height == 0)										// Prevent A Divide By Zero By
			{
				height = 1;										// Making Height Equal One
			}
			setDim(width, height);

			glViewport(0, 0, width, height);						// Reset The Current Viewport

			glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
			glLoadIdentity();									// Reset The Projection Matrix


																// Calculate The Aspect Ratio Of The Window
			switch (cameraType) {
			case 1:
				gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
				gluLookAt(
					-2, 2, 2,//eye -4,4,4,
					0, 0, 0,//center
					0, 1, 0);//up
				break;
			case 2://front : texture rendered correctly
				glOrtho(-2, 2, -2, 2, -50, 50);
				gluLookAt(
					0, 0, 2,//eye 0,0,2
					0, 0, 0,//center 0,0,0
					0, 1, 0);//up 0,1,0
				break;
			case 3://top
				glOrtho(-2, 2, -2, 2, -50, 50);
				gluLookAt(
					0, 2, 0,//eye 0,2,0,
					0, 0, 0,//center, 0
					0, 0, -1);//up
				break;
			}


			glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
			glLoadIdentity();									// Reset The Modelview Matrix


			UINT flags = SWP_NOZORDER | SWP_NOACTIVATE;
			SetWindowPos((HWND)this->Handle.ToPointer(), 0, 0, 0,
				width, height, flags);
		}

	};
}