#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>

std::vector<int> pointsVec;
namespace KMeansClustering {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			centerPointArr   = nullptr;
			classesOfPoints  = nullptr;
			centerPointCount = 0;
			pictureBoxWidth  = pictureBox1->Width;
			pictureBoxHeight = pictureBox1->Height;
			pointsCount      = 0;
			randomPoints     = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
				for (int i = 0; i < centerPointCount; i++)
					delete[] centerPointArr[i];
				delete[] centerPointArr;
				delete[] classesOfPoints;
				pointsVec.clear();
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDownClusterCount;

	protected:

	private:
		/// <summary>
		int** centerPointArr;
		int* classesOfPoints;
		int centerPointCount;
		int pictureBoxWidth;
		int pictureBoxHeight;
		int pointsCount;
		int randomPoints;
		int tempCpCount;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label5;




	private: System::Windows::Forms::ListBox^  classList;
	private: System::Windows::Forms::Button^  buttonCluster;

	private: System::Windows::Forms::Button^  randomPointsButton;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel2;


			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->numericUpDownClusterCount = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->classList = (gcnew System::Windows::Forms::ListBox());
			this->buttonCluster = (gcnew System::Windows::Forms::Button());
			this->randomPointsButton = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownClusterCount))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Enabled = false;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(823, 562);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureBox1_Paint);
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseMove);
			// 
			// numericUpDownClusterCount
			// 
			this->numericUpDownClusterCount->Location = System::Drawing::Point(143, 12);
			this->numericUpDownClusterCount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDownClusterCount->Name = L"numericUpDownClusterCount";
			this->numericUpDownClusterCount->Size = System::Drawing::Size(57, 22);
			this->numericUpDownClusterCount->TabIndex = 1;
			this->numericUpDownClusterCount->ValueChanged += gcnew System::EventHandler(this, &MyForm::numericUpDownClusterCount_ValueChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label1->Location = System::Drawing::Point(100, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(20, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"--";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label2->Location = System::Drawing::Point(99, 8);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(20, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"--";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->panel5);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Location = System::Drawing::Point(841, 126);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(208, 110);
			this->panel1->TabIndex = 4;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel5->Controls->Add(this->label4);
			this->panel5->Controls->Add(this->label2);
			this->panel5->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel5->Location = System::Drawing::Point(0, 65);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(204, 41);
			this->panel5->TabIndex = 15;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label4->Location = System::Drawing::Point(43, 8);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 17);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Y:";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(204, 41);
			this->panel3->TabIndex = 14;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label3->Location = System::Drawing::Point(44, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(23, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"X:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label5->Location = System::Drawing::Point(3, 12);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(117, 18);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Cluster Count:";
			// 
			// classList
			// 
			this->classList->FormattingEnabled = true;
			this->classList->ItemHeight = 16;
			this->classList->Location = System::Drawing::Point(842, 250);
			this->classList->Name = L"classList";
			this->classList->Size = System::Drawing::Size(209, 324);
			this->classList->TabIndex = 10;
			// 
			// buttonCluster
			// 
			this->buttonCluster->Enabled = false;
			this->buttonCluster->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->buttonCluster->Location = System::Drawing::Point(6, 75);
			this->buttonCluster->Name = L"buttonCluster";
			this->buttonCluster->Size = System::Drawing::Size(194, 23);
			this->buttonCluster->TabIndex = 11;
			this->buttonCluster->Text = L"Cluster";
			this->buttonCluster->UseVisualStyleBackColor = true;
			this->buttonCluster->Click += gcnew System::EventHandler(this, &MyForm::buttonCluster_Click);
			// 
			// randomPointsButton
			// 
			this->randomPointsButton->Enabled = false;
			this->randomPointsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->randomPointsButton->Location = System::Drawing::Point(6, 50);
			this->randomPointsButton->Name = L"randomPointsButton";
			this->randomPointsButton->Size = System::Drawing::Size(194, 23);
			this->randomPointsButton->TabIndex = 12;
			this->randomPointsButton->Text = L"Random Points";
			this->randomPointsButton->UseVisualStyleBackColor = true;
			this->randomPointsButton->Click += gcnew System::EventHandler(this, &MyForm::randomPointsButton_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->randomPointsButton);
			this->panel2->Controls->Add(this->numericUpDownClusterCount);
			this->panel2->Controls->Add(this->buttonCluster);
			this->panel2->Location = System::Drawing::Point(842, 13);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(207, 107);
			this->panel2->TabIndex = 13;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->ClientSize = System::Drawing::Size(1068, 586);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->classList);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"MyForm";
			this->Text = L"K-Means Clustering";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDownClusterCount))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		label1->Text = (e->X - pictureBoxWidth / 2).ToString();
		label2->Text = (pictureBoxHeight / 2 - e->Y).ToString();
	}
	private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Pen^ pen = gcnew Pen(Color::Black);
		e->Graphics->DrawLine(pen, 0, pictureBoxHeight / 2, pictureBoxWidth, pictureBoxHeight / 2);
		e->Graphics->DrawLine(pen, pictureBoxWidth / 2, 0, pictureBoxWidth / 2, pictureBoxHeight);
		if (centerPointArr != nullptr) {
		
			int x, y;
			for (int i = 0; i < centerPointCount; i++) {
				switch (i)
				{
				case 0:
					pen = gcnew Pen(Color::Red,3);
					break;
				case 1:
					pen->Color = Color::Blue;
					break;
				case 2:
					pen->Color = Color::Green;
					break;
				case 3:
					pen->Color = Color::Yellow;
					break;
				case 4:
					pen->Color = Color::DarkOrange;
					break;
				}
				x = centerPointArr[i][0];
				y = centerPointArr[i][1];
				//std::cout <<x << "   " << y << std::endl;
				e->Graphics->DrawLine(pen, x + 8, y + 8, x - 8, y - 8);
				e->Graphics->DrawLine(pen, x - 8, y + 8, x + 8, y - 8);		
			}
		}
		if (classesOfPoints != nullptr) {
			int x, y;
			SolidBrush^ brush = gcnew SolidBrush(Color::Red);
			pen->Width = 1;
			for (int p = 0; p < pointsVec.size()/2; p++) {
				switch (classesOfPoints[p])
				{
				case 0:
					pen->Color = Color::Red;
					brush->Color = Color::Red;
					break;
				case 1:
					pen->Color = Color::Blue;
					brush->Color = Color::Blue;
					break;
				case 2:
					pen->Color = Color::Green;
					brush->Color = Color::Green;
					break;
				case 3:
					pen->Color = Color::Yellow;
					brush->Color = Color::Yellow;
					break;
				case 4:
					pen->Color = Color::DarkOrange;
					brush->Color = Color::DarkOrange;
					break;
				}
				x = pointsVec[2 * p];
				y = pointsVec[2 * p + 1];
				//std::cout <<x << "   " << y << std::endl;
				int c = classesOfPoints[p];
				e->Graphics->DrawLine(pen, x, y, centerPointArr[c][0], centerPointArr[c][1]);
				pen->Color = Color::Black;
				e->Graphics->DrawRectangle(pen, x, y, 5, 5);
				e->Graphics->FillRectangle(brush, x, y, 5, 5);
			}
		}
	}
	private: System::Void numericUpDownClusterCount_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		centerPointCount = (int)numericUpDownClusterCount->Value;
		pictureBox1->Enabled = true;
		randomPointsButton->Enabled = true;

		if (centerPointCount != 0) {
			srand(time(NULL));

			if (centerPointArr == nullptr) {
				centerPointArr = new int*[centerPointCount];
				for (int i = 0; i < centerPointCount; i++) {
					centerPointArr[i] = new int[2];
					centerPointArr[i][0] = (rand() % pictureBoxWidth);
					centerPointArr[i][1] = (rand() % pictureBoxHeight);
					//std::cout << i << "-->" << centerPointsVec[i][0] << " -- " << centerPointsVec[i][1] << std::endl;
					pictureBox1->Refresh();
				}
			}
			else {
				int* tempArr = new int[tempCpCount * 2];
				for (int i = 0; i < tempCpCount; i++) {
					tempArr[2 * i] = centerPointArr[i][0];
					tempArr[2 * i + 1] = centerPointArr[i][1];
				}
				for (int i = 0; i < tempCpCount; i++)
					delete[] centerPointArr[i];
				delete[] centerPointArr;

				centerPointArr = new int*[centerPointCount];
				for (int i = 0; i < centerPointCount; i++) {
					centerPointArr[i] = new int[2];
					if (i < tempCpCount) {
						centerPointArr[i][0] = tempArr[2 * i];
						centerPointArr[i][1] = tempArr[2 * i + 1];
					}
					else {
						centerPointArr[i][0] = (rand() % pictureBoxWidth);
						centerPointArr[i][1] = (rand() % pictureBoxHeight);
					}
				}
			}
			tempCpCount = centerPointCount;
		}
		else {
			MessageBox::Show("Sıfırdan farklı değer giriniz!!!");
		}
	}//
	private: System::Void pictureBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		Pen^ pen = gcnew Pen(Color::Black);
		Graphics^ g = pictureBox1->CreateGraphics();

		buttonCluster->Enabled = true;

		g->DrawRectangle(pen, e->X, e->Y, 5, 5);
		pointsVec.push_back(e->X );
		pointsVec.push_back(e->Y);

		pointsCount++;
	}//
	private: System::Void buttonCluster_Click(System::Object^  sender, System::EventArgs^  e) {
		float euclidian_dist, min;
		int x1, y1, x2, y2;
		int point_count;
		bool isCenterChange;
		int cycle = 0;
		
		point_count = pointsVec.size() / 2;

		classesOfPoints = new int[point_count];
		int** totalCoord = new int*[centerPointCount];
		for (int i = 0; i < centerPointCount; i++) {
			totalCoord[i] = new int[2];
			totalCoord[i][0] = 0; //x_total
			totalCoord[i][1] = 0; //y_total
		}
		
		std::vector<int> pointNumInClass(centerPointCount);
		for (int i = 0; i < centerPointCount; i++)
			pointNumInClass.push_back(0);

		do{
			for (int p = 0; p < point_count; p++) {
				min = 99999;
				x1 = pointsVec[2 * p];
				y1 = pointsVec[2 * p + 1];

				for (int c = 0; c < centerPointCount; c++) {
					x2 = centerPointArr[c][0];
					y2 = centerPointArr[c][1];

					euclidian_dist = std::sqrtf(pow(x2 - x1, 2) + pow(y2 - y1, 2));
					if (min > euclidian_dist) {
						min = euclidian_dist;
						classesOfPoints[p] = c;
					}
					//g->DrawLine(pen, x1, y1, x2, y2);
					//_sleep(5);
				}
			}
			pictureBox1->Refresh();
			_sleep(50);

			for (int p = 0; p < point_count; p++) {
				totalCoord[classesOfPoints[p]][0] += pointsVec[2 * p];
				totalCoord[classesOfPoints[p]][1] += pointsVec[2 * p + 1];
				//::cout << totalCoord[classesOfPoints[p]][0] << " " << totalCoord[classesOfPoints[p]][1] << std::endl;
				++pointNumInClass[classesOfPoints[p]];
			}
			//std::cout << "\n\n";
			for (int i = 0; i < centerPointCount; i++) {
				std::cout << pointNumInClass[i] << "   ";
			}
			classList->Items->Add("---------------CYCLE - " + (++cycle) + "-------------------");
			for (int c = 0; c < centerPointCount; c++) {
				//std::cout << pointNumInClass[c] << "\n";
				if (pointNumInClass[c] != 0) {
					int old_x, old_y;
					old_x = centerPointArr[c][0];
					old_y = centerPointArr[c][1];
					centerPointArr[c][0] = totalCoord[c][0] / pointNumInClass[c];
					centerPointArr[c][1] = totalCoord[c][1] / pointNumInClass[c];
					(old_x != centerPointArr[c][0] && old_y != centerPointArr[c][1])? 
						isCenterChange = true:isCenterChange = false;
					
					totalCoord[c][0]   = 0; 
					totalCoord[c][1]   = 0;
				}

				classList->Items->Add("Point Count of Class " + (c+1) + ": " + pointNumInClass[c]);
			    classList->Refresh();
				pointNumInClass[c] = 0;
				//std::cout << centerPointArr[c][0] << " " << centerPointArr[c][1] << std::endl;
			}
			pictureBox1->Refresh();
		} while (isCenterChange);
		classList->Items->Add("\n<<<-------------------------------------->>>");
		pointNumInClass.clear();
		for (int i = 0; i < centerPointCount; i++)
			delete[] totalCoord[i];
		delete[] totalCoord;
	}//
	private: System::Void randomPointsButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Pen^ pen = gcnew Pen(Color::Black);
		Graphics^ g = pictureBox1->CreateGraphics();

		buttonCluster->Enabled = true;

		srand(time(NULL));
		int begining = (randomPoints * 100) + pointsCount;
		int ending   = (randomPoints + 1) * 100 + pointsCount;
		for (int i = begining; i < ending; i++) {
			pointsVec.push_back((rand() % pictureBoxWidth));
			pointsVec.push_back((rand() % pictureBoxHeight));
			g->DrawRectangle(pen,pointsVec[2*i], pointsVec[2*i+1], 5, 5);
		}
		randomPoints++;
	}//
};
}
