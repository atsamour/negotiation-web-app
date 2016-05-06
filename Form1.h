#include "IssueClass.h"
#include <vector>
#include <cliext/vector>

#include "stdafx.h" 
#include <string> 
#include <msclr\marshal_cppstd.h>

#include <iostream>

#include <sstream>
#include <cstdlib>

#pragma once

namespace Neg_vis_01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace System::Text::RegularExpressions;

	//using namespace System::IO;

	
	using namespace std;
	using namespace msclr::interop;

	// for ManagedTOSTL function
	//	using namespace System::String;

	/// <summary>
	/// Summary for Form1
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
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::Button^  button3;

	protected: 

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox3;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox2;
	private: System::Windows::Forms::Label^  issueNumLabel;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox4;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  issueNumLabel1;
	private: System::Windows::Forms::TextBox^  ResultsTextBox;

	private: System::Windows::Forms::Label^  issueNumLabel0;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  issueChild;

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  parentIssue;
	private: System::Windows::Forms::Label^  issueNumLabel2;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  issueNumLabel3;
	private: System::Windows::Forms::TextBox^  textBox2;

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
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->parentIssue = (gcnew System::Windows::Forms::Label());
			this->issueNumLabel2 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->issueNumLabel1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->ResultsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->issueNumLabel0 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox3 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->issueNumLabel = (gcnew System::Windows::Forms::Label());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->maskedTextBox4 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->issueChild = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->issueNumLabel3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->parentIssue);
			this->splitContainer1->Panel1->Controls->Add(this->issueNumLabel2);
			this->splitContainer1->Panel1->Controls->Add(this->label8);
			this->splitContainer1->Panel1->Controls->Add(this->panel3);
			this->splitContainer1->Panel1->Controls->Add(this->panel1);
			this->splitContainer1->Panel1->Controls->Add(this->panel2);
			this->splitContainer1->Panel1->Controls->Add(this->maskedTextBox4);
			this->splitContainer1->Panel1->Controls->Add(this->label4);
			this->splitContainer1->Panel1->Controls->Add(this->issueChild);
			this->splitContainer1->Panel1->Controls->Add(this->button2);
			this->splitContainer1->Panel1->Controls->Add(this->button1);
			this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer1_Panel1_Paint);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->issueNumLabel3);
			this->splitContainer1->Panel2->Controls->Add(this->textBox2);
			this->splitContainer1->Size = System::Drawing::Size(717, 428);
			this->splitContainer1->SplitterDistance = 433;
			this->splitContainer1->TabIndex = 0;
			// 
			// parentIssue
			// 
			this->parentIssue->AutoSize = true;
			this->parentIssue->Location = System::Drawing::Point(276, 91);
			this->parentIssue->Name = L"parentIssue";
			this->parentIssue->Size = System::Drawing::Size(0, 13);
			this->parentIssue->TabIndex = 21;
			// 
			// issueNumLabel2
			// 
			this->issueNumLabel2->AutoSize = true;
			this->issueNumLabel2->Location = System::Drawing::Point(177, 91);
			this->issueNumLabel2->Name = L"issueNumLabel2";
			this->issueNumLabel2->Size = System::Drawing::Size(93, 13);
			this->issueNumLabel2->TabIndex = 20;
			this->issueNumLabel2->Text = L"parent issue name";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(289, 63);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(87, 13);
			this->label8->TabIndex = 19;
			this->label8->Text = L"subissue counter";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label7);
			this->panel3->Controls->Add(this->label6);
			this->panel3->Controls->Add(this->label5);
			this->panel3->Controls->Add(this->textBox1);
			this->panel3->Controls->Add(this->button3);
			this->panel3->Location = System::Drawing::Point(4, 112);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(219, 316);
			this->panel3->TabIndex = 18;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(127, 6);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(49, 13);
			this->label7->TabIndex = 13;
			this->label7->Text = L"P 2 Rate";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(72, 6);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(49, 13);
			this->label6->TabIndex = 12;
			this->label6->Text = L"P 1 Rate";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 6);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(32, 13);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Issue";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(3, 22);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(213, 267);
			this->textBox1->TabIndex = 6;
			// 
			// button3
			// 
			this->button3->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->button3->Location = System::Drawing::Point(0, 295);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(65, 21);
			this->button3->TabIndex = 7;
			this->button3->Text = L"From file";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->issueNumLabel1);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->ResultsTextBox);
			this->panel1->Controls->Add(this->issueNumLabel0);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Location = System::Drawing::Point(229, 115);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(201, 313);
			this->panel1->TabIndex = 17;
			// 
			// issueNumLabel1
			// 
			this->issueNumLabel1->AutoSize = true;
			this->issueNumLabel1->Location = System::Drawing::Point(124, 51);
			this->issueNumLabel1->Name = L"issueNumLabel1";
			this->issueNumLabel1->Size = System::Drawing::Size(40, 13);
			this->issueNumLabel1->TabIndex = 16;
			this->issueNumLabel1->Text = L"Party 2";
			// 
			// button4
			// 
			this->button4->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->button4->Location = System::Drawing::Point(55, 3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(63, 45);
			this->button4->TabIndex = 15;
			this->button4->Text = L"Resolve Issues";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// ResultsTextBox
			// 
			this->ResultsTextBox->Location = System::Drawing::Point(6, 66);
			this->ResultsTextBox->Multiline = true;
			this->ResultsTextBox->Name = L"ResultsTextBox";
			this->ResultsTextBox->ReadOnly = true;
			this->ResultsTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->ResultsTextBox->Size = System::Drawing::Size(192, 238);
			this->ResultsTextBox->TabIndex = 16;
			// 
			// issueNumLabel0
			// 
			this->issueNumLabel0->AutoSize = true;
			this->issueNumLabel0->Location = System::Drawing::Point(58, 51);
			this->issueNumLabel0->Name = L"issueNumLabel0";
			this->issueNumLabel0->Size = System::Drawing::Size(40, 13);
			this->issueNumLabel0->TabIndex = 16;
			this->issueNumLabel0->Text = L"Party 1";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(3, 51);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(32, 13);
			this->label9->TabIndex = 13;
			this->label9->Text = L"Issue";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->maskedTextBox3);
			this->panel2->Controls->Add(this->maskedTextBox2);
			this->panel2->Controls->Add(this->issueNumLabel);
			this->panel2->Controls->Add(this->maskedTextBox1);
			this->panel2->Location = System::Drawing::Point(120, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(244, 55);
			this->panel2->TabIndex = 16;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(155, 12);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Party 2 Rate";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(83, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Party 1 Rate";
			// 
			// maskedTextBox3
			// 
			this->maskedTextBox3->Location = System::Drawing::Point(172, 32);
			this->maskedTextBox3->Name = L"maskedTextBox3";
			this->maskedTextBox3->Size = System::Drawing::Size(23, 20);
			this->maskedTextBox3->TabIndex = 3;
			// 
			// maskedTextBox2
			// 
			this->maskedTextBox2->Location = System::Drawing::Point(106, 32);
			this->maskedTextBox2->Name = L"maskedTextBox2";
			this->maskedTextBox2->Size = System::Drawing::Size(26, 20);
			this->maskedTextBox2->TabIndex = 2;
			// 
			// issueNumLabel
			// 
			this->issueNumLabel->AutoSize = true;
			this->issueNumLabel->Location = System::Drawing::Point(5, 12);
			this->issueNumLabel->Name = L"issueNumLabel";
			this->issueNumLabel->Size = System::Drawing::Size(72, 13);
			this->issueNumLabel->TabIndex = 1;
			this->issueNumLabel->Text = L"Issue Number";
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(17, 32);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(51, 20);
			this->maskedTextBox1->TabIndex = 0;
			// 
			// maskedTextBox4
			// 
			this->maskedTextBox4->Location = System::Drawing::Point(120, 79);
			this->maskedTextBox4->Name = L"maskedTextBox4";
			this->maskedTextBox4->Size = System::Drawing::Size(51, 20);
			this->maskedTextBox4->TabIndex = 14;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(177, 63);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Issues";
			// 
			// issueChild
			// 
			this->issueChild->AutoSize = true;
			this->issueChild->Location = System::Drawing::Point(377, 63);
			this->issueChild->Name = L"issueChild";
			this->issueChild->Size = System::Drawing::Size(13, 13);
			this->issueChild->TabIndex = 12;
			this->issueChild->Text = L"0";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(3, 63);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(115, 41);
			this->button2->TabIndex = 5;
			this->button2->Text = L"add subissues to issue...";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->button1->Location = System::Drawing::Point(3, 15);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 29);
			this->button1->TabIndex = 4;
			this->button1->Text = L"save issue";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// issueNumLabel3
			// 
			this->issueNumLabel3->AutoSize = true;
			this->issueNumLabel3->Location = System::Drawing::Point(5, 45);
			this->issueNumLabel3->Name = L"issueNumLabel3";
			this->issueNumLabel3->Size = System::Drawing::Size(63, 13);
			this->issueNumLabel3->TabIndex = 1;
			this->issueNumLabel3->Text = L"calculations";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(8, 63);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox2->Size = System::Drawing::Size(269, 353);
			this->textBox2->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(717, 428);
			this->Controls->Add(this->splitContainer1);
			this->Name = L"Form1";
			this->Text = L"Negotiation 1.0 GUI";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		private: int currentParent;
		private:
			static System::Collections::Generic::List<System::IntPtr> ^issues 
				= gcnew System::Collections::Generic::List<System::IntPtr>();
		
///////////////////////////////////////////////////////////////////////////////////////////////////////
private: System::String^ CalculateNormRates(System::Collections::Generic::List<System::IntPtr> ^issues)
{
	//ofstream outResultFile( "result.txt", ios::app );
	double p1sum=0;
	double p2sum=0;
	IssueClass* ptrtmpIssue;
	System::String^ calcTextBox="";

	for (int i=0; i<issues->Count; i++)
	{
		ptrtmpIssue = reinterpret_cast<IssueClass*> (issues[i].ToPointer());
		p1sum += ptrtmpIssue->getP1Rate();
		p2sum += ptrtmpIssue->getP2Rate();
		///////////////////////////
		
		System::String^ tmpIsnum= gcnew String(ptrtmpIssue->IssueNum.c_str());
		calcTextBox=calcTextBox+"Calculating SumS p1, p2: "+p1sum+", "+p2sum+"\r\n";
		calcTextBox=calcTextBox+"     Issue name: "+tmpIsnum+"  rates: "+ptrtmpIssue->getP1Rate()+" "+ptrtmpIssue->getP2Rate()+"\r\n";
	}
	//cout<<"\nSum of Party 1 Rates:"<<setw(8)<<right<<setfill('.')<<p1sum<<endl;
	calcTextBox=calcTextBox+"\r\nSum of Party 1 Rates:"+p1sum+"\r\n";
	//cout<<"Sum of Party 2 Rates:"<<setw(8)<<p2sum<<endl;
	calcTextBox=calcTextBox+"\r\nSum of Party 2 Rates:"+p2sum+"\r\n";
	//cout<<"Normalizing all rates in the scale of 100..."<<endl;
	calcTextBox=calcTextBox+"Normalizing all rates in the scale of 100..."+"\r\n";
	for (int i=0; i<issues->Count; i++) {
		ptrtmpIssue = reinterpret_cast<IssueClass*> (issues[i].ToPointer());
		ptrtmpIssue->normalizeRates(p1sum, p2sum);
		//cout<<"Normalized rates for Issue"<<setw(12)<<right<<issues[i].getIssueNum()<<": "
		//	<<setw(12)<<fixed<<setprecision(3)<<issues[i].getP1Rate()<<",   "<<setw(12)<<issues[i].getP2Rate()<<endl;
		System::String^ tmpIsnum= gcnew String(ptrtmpIssue->IssueNum.c_str());
		calcTextBox=calcTextBox+"\r\nNormalized rates for Issue "+tmpIsnum+" : "+
			ptrtmpIssue->getP1Rate()+",   "+ptrtmpIssue->getP2Rate()+"\r\n";
	
	}
	return calcTextBox;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
private: void resolveIssues(System::Collections::Generic::List<System::IntPtr> ^issues)
{
	//ofstream outResultFile( "result.txt", ios::app );
	
	IssueClass* ptrtmpIssue;

	//At each iteration an Issue will be Resolved
	for (int genIndex=0; genIndex < issues->Count; genIndex++)
	{
		double maxDiff=0;
		int maxDiffIssueIndex;

		//Find an Issue to Resolve
		for (int i=0; i<issues->Count; i++)
		{
			ptrtmpIssue = reinterpret_cast<IssueClass*> (issues[i].ToPointer());
			if (ptrtmpIssue->Resolved())
			{   //Issue already Resolved
				continue;
			}
			if ( ptrtmpIssue->getMrkDiff() >= maxDiff )
			{
				maxDiff = ptrtmpIssue->getMrkDiff();
				maxDiffIssueIndex = i;
			}
		}
		ptrtmpIssue = reinterpret_cast<IssueClass*> (issues[maxDiffIssueIndex].ToPointer());
		ptrtmpIssue->setWinningParty(); //This Issue has just been resolved
		
		
		System::String^ tmptextbox="";
		tmptextbox = tmptextbox+"\r\nIssue "+ptrtmpIssue->getIssueNum()+
			" won by party "+ptrtmpIssue->getParty()+"\r\n";
		textBox2->Text +=tmptextbox;
		//outResultFile<<"\nIssue "<<issues[maxDiffIssueIndex].getIssueNum()<<
		//	" won by party "<<issues[maxDiffIssueIndex].getParty()<<endl;
		
		//Calculating new Rates for other Issues after a Resolvement
		for (int i=0; i<issues->Count; i++)
		{
			ptrtmpIssue = reinterpret_cast<IssueClass*> (issues[i].ToPointer());
			if (ptrtmpIssue->Resolved()) 
			{	//Does not have to Calculate new Rates for a resolved Issue
				continue;
			}

			IssueClass* ptrtmpIssuemaxDiffIssueIndex = reinterpret_cast<IssueClass*> (issues[maxDiffIssueIndex].ToPointer());;
			
			string tmpstringtextbox = ptrtmpIssue->CalculateNewRates (	ptrtmpIssuemaxDiffIssueIndex->getWiningPartyRate(),
											ptrtmpIssuemaxDiffIssueIndex->getLoosingPartyRate(),
											ptrtmpIssuemaxDiffIssueIndex->getParty()				);
			System::String^ tmptextbox= gcnew String(tmpstringtextbox.c_str());
			textBox2->Text +=tmptextbox;
		}
	}// end of for( genIndex
	
}

//save issue
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			IssueClass* ptrtmpIssue;
			if(this->issueChild->Text=="1") {//prwto paidi
				ptrtmpIssue = reinterpret_cast<IssueClass*> (issues[currentParent].ToPointer());
				ptrtmpIssue->alterToSubIssue( marshal_as<std::string>(this->parentIssue->Text)+","+
					marshal_as<std::string>(this->maskedTextBox1->Text),
					marshal_as<std::string>(this->maskedTextBox2->Text), 
					marshal_as<std::string>(this->maskedTextBox3->Text) );
					//Kratame ton ari8mo tou paidiou sto Label issueChild, xrhsimopoiontas to ws counter
					std::istringstream chldTxt;
					double chldDbl;
					chldTxt.str(marshal_as<std::string>(this->issueChild->Text));
					chldTxt>>chldDbl;
					chldDbl++;
					this->issueChild->Text = System::Convert::ToString(chldDbl);
					//currentParent=IssueIndex;
			}
			else if(this->issueChild->Text=="0") {//kanonikh eisagwgh
			ptrtmpIssue = new IssueClass( 
				marshal_as<std::string>(this->maskedTextBox1->Text),
				marshal_as<std::string>(this->maskedTextBox2->Text), 
				marshal_as<std::string>(this->maskedTextBox3->Text) );
				issues->Add(System::IntPtr(ptrtmpIssue));
			}
			else {//eisagwgh deuerou paidiou kai meta
			ptrtmpIssue = new IssueClass( marshal_as<std::string>(this->parentIssue->Text)+","+
				marshal_as<std::string>(this->maskedTextBox1->Text),
				marshal_as<std::string>(this->maskedTextBox2->Text), 
				marshal_as<std::string>(this->maskedTextBox3->Text) );
				issues->Add(System::IntPtr(ptrtmpIssue));
				//Kratame ton ari8mo tou paidiou sto Label issueChild, xrhsimopoiontas to ws counter
				std::istringstream chldTxt;
				double chldDbl;
				chldTxt.str(marshal_as<std::string>(this->issueChild->Text));
				chldTxt>>chldDbl;
				chldDbl++;
				this->issueChild->Text = System::Convert::ToString(chldDbl);
				//currentParent=IssueIndex;
			
			}

			//!!!!!!!se periptwsh prwtou paidiou na diagrafetai o goneas apo to textbox!!!<--add
			
			
			//Convert the string
			String^ MSIssueNum = gcnew String(ptrtmpIssue->IssueNum.c_str());
			this->textBox1->Text+=MSIssueNum+"\t\t"
				+this->maskedTextBox2->Text+"\t"+this->maskedTextBox3->Text+"\r\n";
			this->maskedTextBox1->Clear();
			this->maskedTextBox2->Clear();
			this->maskedTextBox3->Clear();

		 }

		 //add subissues to issue...
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			this->issueChild->Text="0";
			//this->maskedTextBox1->Hide();

			bool foundFlag=0;
			int IssueIndex;
			for (IssueIndex=0; IssueIndex<issues->Count; IssueIndex++)
			{
				IssueClass* ptrtmpIssue = reinterpret_cast<IssueClass*> (issues[IssueIndex].ToPointer());
				if (this->maskedTextBox4->Text==ptrtmpIssue->getIssueNum()) {
					foundFlag=1; break; }
			}
			//Not found an issue with Inum IssueNum
			if (!foundFlag)
			{
				this->label4->Text="No such Issue found "; //+this->maskedTextBox4->Text;
				this->maskedTextBox2->Clear();
				this->maskedTextBox3->Clear();
				this->maskedTextBox4->Clear();
				return;
			}
			this->label4->Text="subissues";
			this->parentIssue->Text=this->maskedTextBox4->Text;
			//Kratame ton ari8mo tou paidiou sto Label issueChild, xrhsimopoiontas to ws counter
			std::istringstream chldTxt;
			double chldDbl;
			chldTxt.str(marshal_as<std::string>(this->issueChild->Text));
			chldTxt>>chldDbl;
			chldDbl++;
			this->issueChild->Text = System::Convert::ToString(chldDbl);
			currentParent=IssueIndex;
		 }

		 //From file
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;
			 if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 System::IO::StreamReader ^ sr = gcnew
					System::IO::StreamReader(openFileDialog1->FileName);
				IssueClass* ptrtmpIssue;
				 while(sr->Peek()>=0) {
					 String ^line = sr->ReadLine();
					 this->textBox1->Text+=line+"\r\n";
					 array<Char>^chars = {'\t'};
					 array<String^>^ s = line->Split( chars );					 
					 String^ s1=s[0];
					 String^ p1=s[1];
					 String^ p2=s[2];
			 		 ptrtmpIssue = new IssueClass( marshal_as<std::string>(s1),
						marshal_as<std::string>(p1), marshal_as<std::string>(p2) );
					 issues->Add(System::IntPtr(ptrtmpIssue));
				 }
				 //MessageBox::Show(sr->ReadToEnd());
				 sr->Close();
			 }

		 }
private: System::Void splitContainer1_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }

		 //Resolve Issues
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 textBox2->Text = CalculateNormRates(issues);
			 //issues->Order(
			 resolveIssues(issues);

			 IssueClass* ptrtmpIssue;

			 //Printing final results
			for (int i=0; i<issues->Count; i++)
			{
				ptrtmpIssue = reinterpret_cast<IssueClass*> (issues[i].ToPointer());
				//ptrtmpIssue->printIssueDetails();

				System::String^ TextBoxString = gcnew System::String(ptrtmpIssue->IssueNum.c_str());
				
				if ( ptrtmpIssue->getParty()==1 )
					ResultsTextBox->Text=ResultsTextBox->Text+TextBoxString+"\t\t"+"1"+"\t"+"0"+"\r\n"; 
				else if ( ptrtmpIssue->getParty()==2 )
					ResultsTextBox->Text=ResultsTextBox->Text+TextBoxString+"\t\t"+"0"+"\t"+"1"+"\r\n";
				else 
					ResultsTextBox->Text=ResultsTextBox->Text+TextBoxString+"\r\n";
			}
			 
		 }
};
}

