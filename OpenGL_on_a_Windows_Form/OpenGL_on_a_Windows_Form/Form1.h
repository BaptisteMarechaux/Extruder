#pragma once

#include "OpenGL.h"

namespace OpenGL_on_a_Windows_Form {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace OpenGLForm;



	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->timer1->Enabled = false;
			//Initialize();
			OpenGL = gcnew COpenGL(pictureBox1, pictureBox1->Width, pictureBox1->Height, 1);
			OpenGL2 = gcnew COpenGL(pictureBox2, pictureBox2->Width, pictureBox2->Height, 3);
			this->timer1->Enabled = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fdeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  dzdzToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ddedeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  dzToolStripMenuItem;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		OpenGLForm::COpenGL ^ OpenGL;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
			 OpenGLForm::COpenGL ^ OpenGL2;





#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->fdeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->dzdzToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->ddedeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->dzToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
				 this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
				 this->menuStrip1->SuspendLayout();
				 this->toolStrip1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // timer1
				 // 
				 this->timer1->Enabled = true;
				 this->timer1->Interval = 10;
				 this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
				 // 
				 // menuStrip1
				 // 
				 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
					 this->fdeToolStripMenuItem,
						 this->dzToolStripMenuItem, this->helpToolStripMenuItem
				 });
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Size = System::Drawing::Size(790, 24);
				 this->menuStrip1->TabIndex = 0;
				 this->menuStrip1->Text = L"menuStrip1";
				 // 
				 // fdeToolStripMenuItem
				 // 
				 this->fdeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
					 this->dzdzToolStripMenuItem,
						 this->ddedeToolStripMenuItem, this->exitToolStripMenuItem
				 });
				 this->fdeToolStripMenuItem->Name = L"fdeToolStripMenuItem";
				 this->fdeToolStripMenuItem->Size = System::Drawing::Size(37, 20);
				 this->fdeToolStripMenuItem->Text = L"File";
				 // 
				 // dzdzToolStripMenuItem
				 // 
				 this->dzdzToolStripMenuItem->Name = L"dzdzToolStripMenuItem";
				 this->dzdzToolStripMenuItem->Size = System::Drawing::Size(152, 22);
				 this->dzdzToolStripMenuItem->Text = L"New";
				 this->dzdzToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::dzdzToolStripMenuItem_Click);
				 // 
				 // ddedeToolStripMenuItem
				 // 
				 this->ddedeToolStripMenuItem->Name = L"ddedeToolStripMenuItem";
				 this->ddedeToolStripMenuItem->Size = System::Drawing::Size(152, 22);
				 this->ddedeToolStripMenuItem->Text = L"hah";
				 // 
				 // exitToolStripMenuItem
				 // 
				 this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
				 this->exitToolStripMenuItem->Size = System::Drawing::Size(152, 22);
				 this->exitToolStripMenuItem->Text = L"Exit";
				 // 
				 // dzToolStripMenuItem
				 // 
				 this->dzToolStripMenuItem->Name = L"dzToolStripMenuItem";
				 this->dzToolStripMenuItem->Size = System::Drawing::Size(34, 20);
				 this->dzToolStripMenuItem->Text = L"He";
				 // 
				 // helpToolStripMenuItem
				 // 
				 this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
				 this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
				 this->helpToolStripMenuItem->Text = L"Help";
				 // 
				 // toolStrip1
				 // 
				 this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripButton1 });
				 this->toolStrip1->Location = System::Drawing::Point(0, 24);
				 this->toolStrip1->Name = L"toolStrip1";
				 this->toolStrip1->Size = System::Drawing::Size(790, 25);
				 this->toolStrip1->TabIndex = 1;
				 this->toolStrip1->Text = L"toolStrip1";
				 // 
				 // toolStripButton1
				 // 
				 this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
				 this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
				 this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
				 this->toolStripButton1->Name = L"toolStripButton1";
				 this->toolStripButton1->Size = System::Drawing::Size(23, 22);
				 this->toolStripButton1->Text = L"toolStripButton1";
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Location = System::Drawing::Point(12, 52);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(442, 485);
				 this->pictureBox1->TabIndex = 2;
				 this->pictureBox1->TabStop = false;
				 // 
				 // pictureBox2
				 // 
				 this->pictureBox2->Location = System::Drawing::Point(460, 52);
				 this->pictureBox2->Name = L"pictureBox2";
				 this->pictureBox2->Size = System::Drawing::Size(318, 223);
				 this->pictureBox2->TabIndex = 3;
				 this->pictureBox2->TabStop = false;
				 // 
				 // pictureBox3
				 // 
				 this->pictureBox3->ImageLocation = L"C:\\Users\\Julien Geiger\\Documents\\ESGI\\Documents 4A\\Maths\\Projet_Extruder\\Projet_E"
					 L"xtruder\\textures\\images";
				 this->pictureBox3->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.InitialImage")));
				 this->pictureBox3->Location = System::Drawing::Point(460, 281);
				 this->pictureBox3->Name = L"pictureBox3";
				 this->pictureBox3->Size = System::Drawing::Size(318, 256);
				 this->pictureBox3->TabIndex = 4;
				 this->pictureBox3->TabStop = false;
				 // 
				 // Form1
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(790, 549);
				 this->Controls->Add(this->pictureBox3);
				 this->Controls->Add(this->pictureBox2);
				 this->Controls->Add(this->pictureBox1);
				 this->Controls->Add(this->toolStrip1);
				 this->Controls->Add(this->menuStrip1);
				 this->MainMenuStrip = this->menuStrip1;
				 this->Name = L"Form1";
				 this->Text = L"OpenGL on a Windows Form using Managed C++";
				 this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
				 this->menuStrip1->ResumeLayout(false);
				 this->menuStrip1->PerformLayout();
				 this->toolStrip1->ResumeLayout(false);
				 this->toolStrip1->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		UNREFERENCED_PARAMETER(sender);
		UNREFERENCED_PARAMETER(e);
		OpenGL2->Render();
		OpenGL2->SwapOpenGLBuffers();

		OpenGL->Render();
		OpenGL->SwapOpenGLBuffers();
	}
	private: System::Void dzdzToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
	}
	private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e) {
		OpenGL->ReSizeGLScene(pictureBox1->Width, pictureBox1->Height);
		OpenGL2->ReSizeGLScene(pictureBox2->Width, pictureBox2->Height);
	}
	};
}

