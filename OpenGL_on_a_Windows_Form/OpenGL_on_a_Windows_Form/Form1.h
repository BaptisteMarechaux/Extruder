#pragma once

#include "OpenGL.h"

#include <iostream>

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
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  dzToolStripMenuItem;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		OpenGLForm::COpenGL ^ OpenGL;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;

	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  extrusionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  modificationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  rougeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  bleuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  vertToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  noirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  violetToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  modeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  filaireToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pleinToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  texturéToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  simpleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  revolutionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  generaliseeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  instructToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  creditsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  texturesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lapinToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  motifToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  artworkToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  blancToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  bezierToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  raccordementC1ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  raccordementC0ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  raccordementC2ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  remiseAZeroToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ameToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  extrusionTextBox;
	private: System::Windows::Forms::TextBox^  extrusionScaleTextBox;
	private: System::Windows::Forms::Label^  label2;
			 OpenGLForm::COpenGL ^ OpenGL2;





#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->bezierToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->raccordementC0ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->raccordementC1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->raccordementC2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->ameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->dzToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->rougeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->bleuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->vertToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->noirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->violetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->extrusionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->simpleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->revolutionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->generaliseeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->modeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->filaireToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->pleinToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->texturéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->texturesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->lapinToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->motifToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->artworkToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->blancToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->modificationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->remiseAZeroToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->helpToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->instructToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->creditsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->extrusionTextBox = (gcnew System::Windows::Forms::TextBox());
				 this->extrusionScaleTextBox = (gcnew System::Windows::Forms::TextBox());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->menuStrip1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
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
				 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
					 this->fileToolStripMenuItem,
						 this->helpToolStripMenuItem, this->dzToolStripMenuItem, this->extrusionToolStripMenuItem, this->modeToolStripMenuItem, this->texturesToolStripMenuItem,
						 this->modificationToolStripMenuItem, this->helpToolStripMenuItem1
				 });
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Size = System::Drawing::Size(1241, 24);
				 this->menuStrip1->TabIndex = 0;
				 this->menuStrip1->Text = L"menuStrip1";
				 // 
				 // fileToolStripMenuItem
				 // 
				 this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
				 this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
				 this->fileToolStripMenuItem->Size = System::Drawing::Size(54, 20);
				 this->fileToolStripMenuItem->Text = L"Fichier";
				 // 
				 // exitToolStripMenuItem
				 // 
				 this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
				 this->exitToolStripMenuItem->Size = System::Drawing::Size(92, 22);
				 this->exitToolStripMenuItem->Text = L"Exit";
				 this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
				 // 
				 // helpToolStripMenuItem
				 // 
				 this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
					 this->bezierToolStripMenuItem,
						 this->raccordementC0ToolStripMenuItem, this->raccordementC1ToolStripMenuItem, this->raccordementC2ToolStripMenuItem, this->ameToolStripMenuItem
				 });
				 this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
				 this->helpToolStripMenuItem->Size = System::Drawing::Size(63, 20);
				 this->helpToolStripMenuItem->Text = L"Courbes";
				 this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::helpToolStripMenuItem_Click);
				 // 
				 // bezierToolStripMenuItem
				 // 
				 this->bezierToolStripMenuItem->Name = L"bezierToolStripMenuItem";
				 this->bezierToolStripMenuItem->Size = System::Drawing::Size(168, 22);
				 this->bezierToolStripMenuItem->Text = L"Bezier";
				 this->bezierToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::bezierToolStripMenuItem_Click);
				 // 
				 // raccordementC0ToolStripMenuItem
				 // 
				 this->raccordementC0ToolStripMenuItem->Name = L"raccordementC0ToolStripMenuItem";
				 this->raccordementC0ToolStripMenuItem->Size = System::Drawing::Size(168, 22);
				 this->raccordementC0ToolStripMenuItem->Text = L"Raccordement C0";
				 this->raccordementC0ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::raccordementC0ToolStripMenuItem_Click);
				 // 
				 // raccordementC1ToolStripMenuItem
				 // 
				 this->raccordementC1ToolStripMenuItem->Name = L"raccordementC1ToolStripMenuItem";
				 this->raccordementC1ToolStripMenuItem->Size = System::Drawing::Size(168, 22);
				 this->raccordementC1ToolStripMenuItem->Text = L"Raccordement C1";
				 this->raccordementC1ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::raccordementC1ToolStripMenuItem_Click);
				 // 
				 // raccordementC2ToolStripMenuItem
				 // 
				 this->raccordementC2ToolStripMenuItem->Name = L"raccordementC2ToolStripMenuItem";
				 this->raccordementC2ToolStripMenuItem->Size = System::Drawing::Size(168, 22);
				 this->raccordementC2ToolStripMenuItem->Text = L"Raccordement C2";
				 this->raccordementC2ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::raccordementC2ToolStripMenuItem_Click);
				 // 
				 // ameToolStripMenuItem
				 // 
				 this->ameToolStripMenuItem->Name = L"ameToolStripMenuItem";
				 this->ameToolStripMenuItem->Size = System::Drawing::Size(168, 22);
				 this->ameToolStripMenuItem->Text = L"Ame";
				 this->ameToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ameToolStripMenuItem_Click);
				 // 
				 // dzToolStripMenuItem
				 // 
				 this->dzToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
					 this->rougeToolStripMenuItem,
						 this->bleuToolStripMenuItem, this->vertToolStripMenuItem, this->noirToolStripMenuItem, this->violetToolStripMenuItem
				 });
				 this->dzToolStripMenuItem->Name = L"dzToolStripMenuItem";
				 this->dzToolStripMenuItem->Size = System::Drawing::Size(66, 20);
				 this->dzToolStripMenuItem->Text = L"Couleurs";
				 // 
				 // rougeToolStripMenuItem
				 // 
				 this->rougeToolStripMenuItem->Name = L"rougeToolStripMenuItem";
				 this->rougeToolStripMenuItem->Size = System::Drawing::Size(108, 22);
				 this->rougeToolStripMenuItem->Text = L"Rouge";
				 this->rougeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::rougeToolStripMenuItem_Click);
				 // 
				 // bleuToolStripMenuItem
				 // 
				 this->bleuToolStripMenuItem->Name = L"bleuToolStripMenuItem";
				 this->bleuToolStripMenuItem->Size = System::Drawing::Size(108, 22);
				 this->bleuToolStripMenuItem->Text = L"Bleu";
				 this->bleuToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::bleuToolStripMenuItem_Click);
				 // 
				 // vertToolStripMenuItem
				 // 
				 this->vertToolStripMenuItem->Name = L"vertToolStripMenuItem";
				 this->vertToolStripMenuItem->Size = System::Drawing::Size(108, 22);
				 this->vertToolStripMenuItem->Text = L"Vert";
				 this->vertToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::vertToolStripMenuItem_Click);
				 // 
				 // noirToolStripMenuItem
				 // 
				 this->noirToolStripMenuItem->Name = L"noirToolStripMenuItem";
				 this->noirToolStripMenuItem->Size = System::Drawing::Size(108, 22);
				 this->noirToolStripMenuItem->Text = L"Noir";
				 this->noirToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::noirToolStripMenuItem_Click);
				 // 
				 // violetToolStripMenuItem
				 // 
				 this->violetToolStripMenuItem->Name = L"violetToolStripMenuItem";
				 this->violetToolStripMenuItem->Size = System::Drawing::Size(108, 22);
				 this->violetToolStripMenuItem->Text = L"Violet";
				 this->violetToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::violetToolStripMenuItem_Click);
				 // 
				 // extrusionToolStripMenuItem
				 // 
				 this->extrusionToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
					 this->simpleToolStripMenuItem,
						 this->revolutionToolStripMenuItem, this->generaliseeToolStripMenuItem
				 });
				 this->extrusionToolStripMenuItem->Name = L"extrusionToolStripMenuItem";
				 this->extrusionToolStripMenuItem->Size = System::Drawing::Size(67, 20);
				 this->extrusionToolStripMenuItem->Text = L"Extrusion";
				 // 
				 // simpleToolStripMenuItem
				 // 
				 this->simpleToolStripMenuItem->Name = L"simpleToolStripMenuItem";
				 this->simpleToolStripMenuItem->Size = System::Drawing::Size(134, 22);
				 this->simpleToolStripMenuItem->Text = L"Simple";
				 this->simpleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::simpleToolStripMenuItem_Click);
				 // 
				 // revolutionToolStripMenuItem
				 // 
				 this->revolutionToolStripMenuItem->Name = L"revolutionToolStripMenuItem";
				 this->revolutionToolStripMenuItem->Size = System::Drawing::Size(134, 22);
				 this->revolutionToolStripMenuItem->Text = L"Revolution";
				 this->revolutionToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::revolutionToolStripMenuItem_Click);
				 // 
				 // generaliseeToolStripMenuItem
				 // 
				 this->generaliseeToolStripMenuItem->Name = L"generaliseeToolStripMenuItem";
				 this->generaliseeToolStripMenuItem->Size = System::Drawing::Size(134, 22);
				 this->generaliseeToolStripMenuItem->Text = L"Generalisee";
				 this->generaliseeToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::generaliseeToolStripMenuItem_Click);
				 // 
				 // modeToolStripMenuItem
				 // 
				 this->modeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
					 this->filaireToolStripMenuItem,
						 this->pleinToolStripMenuItem, this->texturéToolStripMenuItem
				 });
				 this->modeToolStripMenuItem->Name = L"modeToolStripMenuItem";
				 this->modeToolStripMenuItem->Size = System::Drawing::Size(50, 20);
				 this->modeToolStripMenuItem->Text = L"Mode";
				 // 
				 // filaireToolStripMenuItem
				 // 
				 this->filaireToolStripMenuItem->Name = L"filaireToolStripMenuItem";
				 this->filaireToolStripMenuItem->Size = System::Drawing::Size(112, 22);
				 this->filaireToolStripMenuItem->Text = L"Filaire";
				 this->filaireToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::filaireToolStripMenuItem_Click);
				 // 
				 // pleinToolStripMenuItem
				 // 
				 this->pleinToolStripMenuItem->Name = L"pleinToolStripMenuItem";
				 this->pleinToolStripMenuItem->Size = System::Drawing::Size(112, 22);
				 this->pleinToolStripMenuItem->Text = L"Plein";
				 this->pleinToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::pleinToolStripMenuItem_Click);
				 // 
				 // texturéToolStripMenuItem
				 // 
				 this->texturéToolStripMenuItem->Name = L"texturéToolStripMenuItem";
				 this->texturéToolStripMenuItem->Size = System::Drawing::Size(112, 22);
				 this->texturéToolStripMenuItem->Text = L"Texture";
				 this->texturéToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::texturéToolStripMenuItem_Click);
				 // 
				 // texturesToolStripMenuItem
				 // 
				 this->texturesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
					 this->lapinToolStripMenuItem,
						 this->motifToolStripMenuItem, this->artworkToolStripMenuItem, this->blancToolStripMenuItem
				 });
				 this->texturesToolStripMenuItem->Name = L"texturesToolStripMenuItem";
				 this->texturesToolStripMenuItem->Size = System::Drawing::Size(62, 20);
				 this->texturesToolStripMenuItem->Text = L"Textures";
				 // 
				 // lapinToolStripMenuItem
				 // 
				 this->lapinToolStripMenuItem->Name = L"lapinToolStripMenuItem";
				 this->lapinToolStripMenuItem->Size = System::Drawing::Size(116, 22);
				 this->lapinToolStripMenuItem->Text = L"Lapin";
				 this->lapinToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::lapinToolStripMenuItem_Click);
				 // 
				 // motifToolStripMenuItem
				 // 
				 this->motifToolStripMenuItem->Name = L"motifToolStripMenuItem";
				 this->motifToolStripMenuItem->Size = System::Drawing::Size(116, 22);
				 this->motifToolStripMenuItem->Text = L"Motif";
				 this->motifToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::motifToolStripMenuItem_Click);
				 // 
				 // artworkToolStripMenuItem
				 // 
				 this->artworkToolStripMenuItem->Name = L"artworkToolStripMenuItem";
				 this->artworkToolStripMenuItem->Size = System::Drawing::Size(116, 22);
				 this->artworkToolStripMenuItem->Text = L"Artwork";
				 this->artworkToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::artworkToolStripMenuItem_Click);
				 // 
				 // blancToolStripMenuItem
				 // 
				 this->blancToolStripMenuItem->Name = L"blancToolStripMenuItem";
				 this->blancToolStripMenuItem->Size = System::Drawing::Size(116, 22);
				 this->blancToolStripMenuItem->Text = L"Blanc";
				 this->blancToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::blancToolStripMenuItem_Click);
				 // 
				 // modificationToolStripMenuItem
				 // 
				 this->modificationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->remiseAZeroToolStripMenuItem });
				 this->modificationToolStripMenuItem->Name = L"modificationToolStripMenuItem";
				 this->modificationToolStripMenuItem->Size = System::Drawing::Size(87, 20);
				 this->modificationToolStripMenuItem->Text = L"Modification";
				 // 
				 // remiseAZeroToolStripMenuItem
				 // 
				 this->remiseAZeroToolStripMenuItem->Name = L"remiseAZeroToolStripMenuItem";
				 this->remiseAZeroToolStripMenuItem->Size = System::Drawing::Size(146, 22);
				 this->remiseAZeroToolStripMenuItem->Text = L"Remise a zero";
				 this->remiseAZeroToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::remiseAZeroToolStripMenuItem_Click);
				 // 
				 // helpToolStripMenuItem1
				 // 
				 this->helpToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					 this->instructToolStripMenuItem,
						 this->creditsToolStripMenuItem
				 });
				 this->helpToolStripMenuItem1->Name = L"helpToolStripMenuItem1";
				 this->helpToolStripMenuItem1->Size = System::Drawing::Size(43, 20);
				 this->helpToolStripMenuItem1->Text = L"Aide";
				 // 
				 // instructToolStripMenuItem
				 // 
				 this->instructToolStripMenuItem->Name = L"instructToolStripMenuItem";
				 this->instructToolStripMenuItem->Size = System::Drawing::Size(136, 22);
				 this->instructToolStripMenuItem->Text = L"Instructions";
				 this->instructToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::instructToolStripMenuItem_Click);
				 // 
				 // creditsToolStripMenuItem
				 // 
				 this->creditsToolStripMenuItem->Name = L"creditsToolStripMenuItem";
				 this->creditsToolStripMenuItem->Size = System::Drawing::Size(136, 22);
				 this->creditsToolStripMenuItem->Text = L"Credits";
				 this->creditsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::creditsToolStripMenuItem_Click);
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Location = System::Drawing::Point(12, 27);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(600, 600);
				 this->pictureBox1->TabIndex = 2;
				 this->pictureBox1->TabStop = false;
				 // 
				 // pictureBox2
				 // 
				 this->pictureBox2->Location = System::Drawing::Point(632, 28);
				 this->pictureBox2->Name = L"pictureBox2";
				 this->pictureBox2->Size = System::Drawing::Size(600, 600);
				 this->pictureBox2->TabIndex = 3;
				 this->pictureBox2->TabStop = false;
				 this->pictureBox2->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &Form1::pictureBox2_PreviewKeyDown);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(32, 428);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(96, 13);
				 this->label1->TabIndex = 4;
				 this->label1->Text = L"Taille de l\'extrusion";
				 // 
				 // extrusionTextBox
				 // 
				 this->extrusionTextBox->Location = System::Drawing::Point(32, 452);
				 this->extrusionTextBox->Name = L"extrusionTextBox";
				 this->extrusionTextBox->Size = System::Drawing::Size(95, 20);
				 this->extrusionTextBox->TabIndex = 5;
				 this->extrusionTextBox->Text = L"0,5";
				 this->extrusionTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::extrusionTextBox_TextChanged);
				 // 
				 // extrusionScaleTextBox
				 // 
				 this->extrusionScaleTextBox->Location = System::Drawing::Point(32, 511);
				 this->extrusionScaleTextBox->Name = L"extrusionScaleTextBox";
				 this->extrusionScaleTextBox->Size = System::Drawing::Size(95, 20);
				 this->extrusionScaleTextBox->TabIndex = 7;
				 this->extrusionScaleTextBox->Text = L"1";
				 this->extrusionScaleTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::extrusionScaleTextBox_TextChanged);
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(32, 487);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(98, 13);
				 this->label2->TabIndex = 6;
				 this->label2->Text = L"Scale de l\'extrusion";
				 // 
				 // Form1
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1241, 640);
				 this->Controls->Add(this->extrusionScaleTextBox);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->extrusionTextBox);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->pictureBox2);
				 this->Controls->Add(this->pictureBox1);
				 this->Controls->Add(this->menuStrip1);
				 this->KeyPreview = true;
				 this->MainMenuStrip = this->menuStrip1;
				 this->Name = L"Form1";
				 this->Text = L"OpenGL on a Windows Form using Managed C++";
				 this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
				 this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
				 this->menuStrip1->ResumeLayout(false);
				 this->menuStrip1->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
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
		std::cout << "aaa" << "\n";
	}
	private: System::Void pictureBox2_PreviewKeyDown(System::Object^  sender, System::Windows::Forms::PreviewKeyDownEventArgs^  e) {
		std::cout << "aaa" << "\n";
	}

	private: System::Void Form1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		std::cout << "iii" << "\n";
	}
	private: System::Void rougeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenGL2->UpdateColor(1);
	}
	private: System::Void bleuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenGL2->UpdateColor(2);
	}
private: System::Void vertToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL2->UpdateColor(3);
}
private: System::Void noirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL2->UpdateColor(4);

}
private: System::Void violetToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL2->UpdateColor(5);
}

private: System::Void filaireToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL2->UpdateRenderType(0);
}
private: System::Void pleinToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL2->UpdateRenderType(1);
}
private: System::Void texturéToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL2->UpdateRenderType(2);
}
private: System::Void lapinToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL2->UpdateTexures(0);
}
private: System::Void motifToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL2->UpdateTexures(1);
}
private: System::Void artworkToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL2->UpdateTexures(2);
}
private: System::Void blancToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL2->UpdateTexures(4);
}
private: System::Void bezierToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL->UpdatePoly(1);
}
private: System::Void raccordementC0ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL->UpdatePoly(2);
}
private: System::Void raccordementC1ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL->UpdatePoly(3);
}
private: System::Void raccordementC2ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL->UpdatePoly(4);
}
private: System::Void remiseAZeroToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL->UpdateOptions(3);
}
private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void ameToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL->UpdatePoly(5);
}
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (MessageBox::Show("Exit application?", "Warning",
			MessageBoxButtons::YesNo) == ::DialogResult::Yes)
		{
			Application::Exit();
		}
	}
private: System::Void creditsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (MessageBox::Show("Bapstiste Marechaux\nJulien Geiger\nTristan Cailleau\nCharline Rochelle", "Credits",
		MessageBoxButtons::OK) == ::DialogResult::OK)
	{
	}
}
private: System::Void instructToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	if (MessageBox::Show("Le clic droit sert à déplacer les points créés et à déplacer la vue.", "Aide",
		MessageBoxButtons::OK) == ::DialogResult::OK)
	{
	}
}
		 private: System::Void extrusionTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 if (extrusionTextBox->Text != "") {
				 double z = 1.0;
				 if (Double::TryParse(extrusionTextBox->Text, z))
					 OpenGL->UpdateExtrudeSimpleLenght(z);
			 }
		 }
	private: System::Void extrusionScaleTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (extrusionScaleTextBox->Text != "") {
			double z = 1.0;
			if (Double::TryParse(extrusionScaleTextBox->Text, z))
				OpenGL->UpdateExtrudeSimpleScale(z-1);
		}
	}
			 private: System::Void simpleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 OpenGL->UpdateExtruder(0);
			 }
private: System::Void revolutionToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL->UpdateExtruder(1);
}
private: System::Void generaliseeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OpenGL->UpdateExtruder(2);
}
};
}

