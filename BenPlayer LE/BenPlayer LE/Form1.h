#pragma once
#include "AboutForm.h"

namespace BenPlayerLE {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			// Set the volume to half (50%)
            int halfVolume = 400; // 50% of the maximum volume (800)
            axWindowsMediaPlayer1->settings->volume = halfVolume;
            UpdateVolumeIndicator(halfVolume); // Update the volume indicator
			//
			//TODO: Add the constructor code here
			//
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
	private: System::Windows::Forms::Button^  btnPlay;
	protected: 
	private: System::Windows::Forms::Button^  btnPause;
	private: System::Windows::Forms::Button^  btnStop;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::Button^  buttonUnmute;
	private: System::Windows::Forms::Panel^  panelVolume;
	private: AxWMPLib::AxWindowsMediaPlayer^  axWindowsMediaPlayer1;
	private: System::Windows::Forms::Label^  CurrentlyPlaying;
    private: bool isPaused;
	private: bool isDraggingVolume;
    private: int initialXVolume;
    private: int initialVolume;
	private: System::Windows::Forms::Panel^  panel1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			this->btnPause = (gcnew System::Windows::Forms::Button());
			this->btnStop = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->buttonUnmute = (gcnew System::Windows::Forms::Button());
			this->panelVolume = (gcnew System::Windows::Forms::Panel());
			this->axWindowsMediaPlayer1 = (gcnew AxWMPLib::AxWindowsMediaPlayer());
			this->CurrentlyPlaying = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->axWindowsMediaPlayer1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnPlay
			// 
			this->btnPlay->Location = System::Drawing::Point(12, 153);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(75, 23);
			this->btnPlay->TabIndex = 2;
			this->btnPlay->Text = L"Play";
			this->btnPlay->UseVisualStyleBackColor = true;
			this->btnPlay->Click += gcnew System::EventHandler(this, &Form1::btnPlay_Click);
			// 
			// btnPause
			// 
			this->btnPause->Location = System::Drawing::Point(105, 153);
			this->btnPause->Name = L"btnPause";
			this->btnPause->Size = System::Drawing::Size(75, 23);
			this->btnPause->TabIndex = 3;
			this->btnPause->Text = L"Pause";
			this->btnPause->UseVisualStyleBackColor = true;
			this->btnPause->Click += gcnew System::EventHandler(this, &Form1::btnPause_Click);
			// 
			// btnStop
			// 
			this->btnStop->Location = System::Drawing::Point(205, 153);
			this->btnStop->Name = L"btnStop";
			this->btnStop->Size = System::Drawing::Size(75, 23);
			this->btnStop->TabIndex = 4;
			this->btnStop->Text = L"Stop";
			this->btnStop->UseVisualStyleBackColor = true;
			this->btnStop->Click += gcnew System::EventHandler(this, &Form1::btnStop_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(48, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(205, 40);
			this->label2->TabIndex = 10;
			this->label2->Text = L"the BenPlayer";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(114, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Welcome to";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->aboutToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(292, 24);
			this->menuStrip1->TabIndex = 12;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(60, 20);
			this->aboutToolStripMenuItem->Text = L"About...";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::aboutToolStripMenuItem_Click);
			// 
			// buttonUnmute
			// 
			this->buttonUnmute->Location = System::Drawing::Point(122, 216);
			this->buttonUnmute->Name = L"buttonUnmute";
			this->buttonUnmute->Size = System::Drawing::Size(75, 19);
			this->buttonUnmute->TabIndex = 15;
			this->buttonUnmute->Text = L"Unmute";
			this->buttonUnmute->UseVisualStyleBackColor = true;
			this->buttonUnmute->Visible = false;
			this->buttonUnmute->Click += gcnew System::EventHandler(this, &Form1::buttonUnmute_Click);
			// 
			// panelVolume
			// 
			this->panelVolume->BackColor = System::Drawing::Color::Blue;
			this->panelVolume->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelVolume->Location = System::Drawing::Point(12, 216);
			this->panelVolume->Name = L"panelVolume";
			this->panelVolume->Size = System::Drawing::Size(104, 19);
			this->panelVolume->TabIndex = 16;
			this->panelVolume->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panelVolume_MouseDown);
			this->panelVolume->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panelVolume_MouseMove);
			this->panelVolume->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panelVolume_MouseUp);
			// 
			// axWindowsMediaPlayer1
			// 
			this->axWindowsMediaPlayer1->Enabled = true;
			this->axWindowsMediaPlayer1->Location = System::Drawing::Point(247, 243);
			this->axWindowsMediaPlayer1->Name = L"axWindowsMediaPlayer1";
			this->axWindowsMediaPlayer1->OcxState = (cli::safe_cast<System::Windows::Forms::AxHost::State^  >(resources->GetObject(L"axWindowsMediaPlayer1.OcxState")));
			this->axWindowsMediaPlayer1->Size = System::Drawing::Size(44, 23);
			this->axWindowsMediaPlayer1->TabIndex = 17;
			this->axWindowsMediaPlayer1->Visible = false;
			// 
			// CurrentlyPlaying
			// 
			this->CurrentlyPlaying->AutoSize = true;
			this->CurrentlyPlaying->Location = System::Drawing::Point(12, 119);
			this->CurrentlyPlaying->Name = L"CurrentlyPlaying";
			this->CurrentlyPlaying->Size = System::Drawing::Size(0, 13);
			this->CurrentlyPlaying->TabIndex = 18;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Location = System::Drawing::Point(12, 216);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(104, 19);
			this->panel1->TabIndex = 19;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(292, 266);
			this->Controls->Add(this->CurrentlyPlaying);
			this->Controls->Add(this->axWindowsMediaPlayer1);
			this->Controls->Add(this->panelVolume);
			this->Controls->Add(this->buttonUnmute);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnStop);
			this->Controls->Add(this->btnPause);
			this->Controls->Add(this->btnPlay);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(300, 300);
			this->MinimumSize = System::Drawing::Size(300, 300);
			this->Name = L"Form1";
			this->Text = L"BenPlayer LE";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->axWindowsMediaPlayer1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btnPlay_Click(System::Object^  sender, System::EventArgs^  e) {
            openFileDialog1->Filter = "Audio Files|*.mp3;*.wav;*.wma";
            openFileDialog1->Title = "Select an audio file";
            if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                axWindowsMediaPlayer1->URL = openFileDialog1->FileName;
                axWindowsMediaPlayer1->Ctlcontrols->play();
                CurrentlyPlaying->Text = "Currently playing: " + System::IO::Path::GetFileName(openFileDialog1->FileName);
                btnPause->Enabled = true; // Enable pause button when a track is played
                isPaused = false;
            }
        }
private: System::Void btnPause_Click(System::Object^  sender, System::EventArgs^  e) {
            if (!isPaused) {
                axWindowsMediaPlayer1->Ctlcontrols->pause();
                btnPause->Text = "Resume";
                isPaused = true;
            } else {
                axWindowsMediaPlayer1->Ctlcontrols->play();
                btnPause->Text = "Pause";
                isPaused = false;
            }
        }


private: System::Void btnStop_Click(System::Object^  sender, System::EventArgs^  e) {
            axWindowsMediaPlayer1->Ctlcontrols->stop();
            CurrentlyPlaying->Text = "Currently playing: None";
            btnPause->Enabled = false; // Disable pause button when the track is stopped
            isPaused = false;
		 }
private: System::Void panelVolume_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    isDraggingVolume = true;
    initialXVolume = e->X;
    initialVolume = axWindowsMediaPlayer1->settings->volume;
}

private: System::Void panelVolume_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    if (isDraggingVolume) {
        int halfWidth = 104 / 2; // Half of the initial width
        int deltaX = e->X - initialXVolume;

        if (panelVolume->Width <= 0.5) { // If the width is very small
            // Show the unmute button
            buttonUnmute->Visible = true;
        }
        else {
            buttonUnmute->Visible = false; // Hide the unmute button
            int newVolume = initialVolume + deltaX * 200 / halfWidth; // Adjust volume based on mouse movement
            // Double the adjustment factor from 200 to 400

            // Adjust the volume within valid range
            newVolume = Math::Max(0, Math::Min(800, newVolume)); // Adjusted maximum volume
            axWindowsMediaPlayer1->settings->volume = newVolume;
            UpdateVolumeIndicator(newVolume);
        }
    }
}
private: System::Void panelVolume_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
    isDraggingVolume = false;
}

private: System::Void UpdateVolumeIndicator(int volume) {
    // Adjust the width of the volume panel to represent the volume level
    int width = (volume * 104) / 800; // Adjusted maximum volume
    panelVolume->Size = System::Drawing::Size(width, panelVolume->Height);
}
private: System::Void buttonUnmute_Click(System::Object^ sender, System::EventArgs^ e) {
    // Set volume to a predefined value (e.g., half)
    int unmuteVolume = 400; // Assuming 50% volume
    axWindowsMediaPlayer1->settings->volume = unmuteVolume;
    
    // Update volume indicator and panel width
    UpdateVolumeIndicator(unmuteVolume);
    buttonUnmute->Visible = false;
}
private: 
    // Event handler for About menu item click
    System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Create an instance of the AboutForm
        AboutForm^ aboutForm = gcnew AboutForm();

        // Show the AboutForm as a modal dialog
        aboutForm->ShowDialog();
    }
};
}

