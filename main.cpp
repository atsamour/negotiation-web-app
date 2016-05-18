#include "IssueClass.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void resolveIssues(vector< IssueClass >&);
void printResult(vector< IssueClass >&);
void CalculateNormRates(vector< IssueClass >&);

int main()
{
	////////////////////////////////////////////
		//	ofstream outMeta1tFile( "metadata1.txt", ios::app );


	vector< IssueClass > issues;

	unsigned int IssuesCnt=0; //<---Need this??
	string Inum;
	double p1Rate;
	double p2Rate;
	
	//Initial issues input
	cout<<"Give Issues info, or Type '0' instate of <Issue Number> to continue"<<endl;
	while(true)
	{
		cout<<"Type <Issue Number>, then <Party 1 Rate>, then <Party 2 Rate>:"<<endl;
		cin>>Inum;
		//cout<<"before if"<<endl;
		if (Inum=="0") break;
		//cout<<"after if"<<endl;
		cin>>p1Rate;
		//cout<<"after cin p1"<<endl;
		cin>>p2Rate;
		//cout<<"after cin p2"<<endl;
		IssueClass tmpIssue(Inum, p1Rate, p2Rate);
		issues.push_back(tmpIssue);
		IssuesCnt++;
	}
	
	//Dividing initial issues
	cout<<"If any Issue can be divided, Type its <Issue Number> or Type '0' to continue"<<endl;
	while(true)
	{
		cout<<"Type <Issue Number> that should be divided"<<endl;
		cin>>Inum;
		if (Inum=="0") break;

		int IssueIndex=-1;
		for (IssueIndex=0; IssueIndex<issues.size(); IssueIndex++)
		{
			if (Inum==issues[IssueIndex].getIssueNum())
				break;
		}
		//Not found an issue with Inum IssueNum
		if (IssueIndex==-1)
		{
			cout<<"No Issue with number "<<Inum<<endl;
			continue;
		}
		string parentIssueNum = issues[IssueIndex].getIssueNum();
		unsigned int childCnt=0;
		childCnt++;
		string childIssueNum;
		cout<<"For the "<<childCnt<<" subIssue type <IssueNum>, <Party 1 Rate>, then <Party 2 Rate> "<<endl;
		cin>>childIssueNum>>p1Rate>>p2Rate;
		issues[IssueIndex].alterToSubIssue( childIssueNum, p1Rate, p2Rate );
		////////////////////////
		//		outMeta1tFile<<"Alter to subissue child issue name: "<<childIssueNum<<" p1Rate: "<<p1Rate<<" p2Rate: "<<p2Rate<<endl;
		while (childIssueNum!="0") {
			childCnt++;
			string childIssueNum;
			cout<<"For the "<<childCnt<<" subIssue type <IssueNum>, <Party 1 Rate>, then <Party 2 Rate> "<<endl;
			cout<<"or '0' to stop adding child Issues"<<endl;
			cin>>childIssueNum;
			if (childIssueNum=="0")
				break;
			cin>>p1Rate>>p2Rate;
			IssueClass tmpIssue( parentIssueNum+","+childIssueNum, p1Rate, p2Rate );
			//////////////////////////////////////
		//		outMeta1tFile<<"child issue name: "<<parentIssueNum+","+childIssueNum<<" p1Rate: "<<p1Rate<<" p2Rate: "<<p2Rate<<endl;
			
			issues.push_back(tmpIssue);
			IssuesCnt++;
		}
		
	}
	
	CalculateNormRates(issues);


	resolveIssues(issues);
	
	//printResult(issues);		

	//Prints final results
	cout<<"\nAll Issues' Details:"<<endl;
	for (unsigned int i=0; i<issues.size(); i++)
	{
		issues[i].printIssueDetails();
	}

	cout<<"\a\nBye!";

	int a;
	cin>>a;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
void resolveIssues(vector< IssueClass >& issues)
{
	ofstream outResultFile( "result.txt", ios::app );
	//At each iteration an Issue will be Resolved
	for (unsigned int genIndex=0; genIndex < issues.size(); genIndex++)
	{
		double maxDiff=0;
		unsigned int maxDiffIssueIndex;

		//Find an Issue to Resolve
		for (unsigned int i=0; i<issues.size(); i++)
		{
			if (issues[i].Resolved())
			{   //Issue already Resolved
				continue;
			}
			if ( issues[i].getMrkDiff() >= maxDiff )
			{
				maxDiff = issues[i].getMrkDiff();
				maxDiffIssueIndex = i;
			}
		}
		issues[maxDiffIssueIndex].setWinningParty(); //This Issue has just been resolved
		cout<<"\nIssue "<<issues[maxDiffIssueIndex].getIssueNum()<<
			" won by party "<<issues[maxDiffIssueIndex].getParty()<<endl;
		outResultFile<<"\nIssue "<<issues[maxDiffIssueIndex].getIssueNum()<<
			" won by party "<<issues[maxDiffIssueIndex].getParty()<<endl;
		
		//Calculating new Rates for other Issues after a Resolvement
		for (unsigned int i=0; i<issues.size(); i++)
		{
			if (issues[i].Resolved()) 
			{	//Does not have to Calculate new Rates for a resolved Issue
				continue;
			}

			issues[i].CalculateNewRates (	issues[maxDiffIssueIndex].getWiningPartyRate(),
											issues[maxDiffIssueIndex].getLoosingPartyRate(),
											issues[maxDiffIssueIndex].getParty()				);
		}
	}// end of for( genIndex
	
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
void CalculateNormRates(vector< IssueClass >& issues)
{
	ofstream outResultFile( "result.txt", ios::app );
	double p1sum=0;
	double p2sum=0;

	for (unsigned int i=0; i<issues.size(); i++)
	{
		p1sum += issues[i].getP1Rate();
		p2sum += issues[i].getP2Rate();
		///////////////////////////
		//outResultFile<<"CALCULAting SumS p1, p2:"<<setw(8)<<right<<setfill('.')<<p1sum<<", "<<p2sum<<endl;
		//outResultFile<<"     Issue name:"<<issues[i].IssueNum<<"  rates: "<<issues[i].getP1Rate()<<" "<<issues[i].getP2Rate()<<endl;
	}

	cout<<"\nSum of Party 1 Rates:"<<setw(8)<<right<<setfill('.')<<p1sum<<endl;
	outResultFile<<"\nSum of Party 1 Rates:"<<setw(8)<<right<<setfill('.')<<p1sum<<endl;
	
	cout<<"Sum of Party 2 Rates:"<<setw(8)<<p2sum<<endl;
	outResultFile<<"Sum of Party 2 Rates:"<<setw(8)<<p2sum<<endl;
	
	cout<<"Normalazing all rates in the scale of 100..."<<endl;
	outResultFile<<"Normalazing all rates in the scale of 100..."<<endl;
	
	for (unsigned int i=0; i<issues.size(); i++)
		issues[i].normalizeRates(p1sum, p2sum);


	for (unsigned int i=0; i<issues.size(); i++){
		cout<<"Normalized rates for Issue"<<setw(12)<<right<<issues[i].getIssueNum()<<": "
			<<setw(12)<<fixed<<setprecision(3)<<issues[i].getP1Rate()<<",   "<<setw(12)<<issues[i].getP2Rate()<<endl;
		outResultFile<<"Normalized rates for Issue"<<setw(12)<<right<<issues[i].getIssueNum()<<": "
			<<setw(12)<<fixed<<setprecision(3)<<issues[i].getP1Rate()<<",   "<<setw(12)<<issues[i].getP2Rate()<<endl;
	}
	
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
/*void printResult(vector< IssueClass >& issues)
{	
	cout<<"Results of Resolved Issues"<<endl;


	for (unsigned int i=0; i<issues.size(); i++)
	{
		issues[i].printIssueDetails();
	}

	cout<<"End of Results"<<endl;
}
*/