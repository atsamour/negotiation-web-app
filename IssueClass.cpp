#include "IssueClass.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

unsigned int IssueClass::IssuesCnt; //<---Need this??

///////////////////////////////////////////////////////////////////////////////////////////////////////
void IssueClass::CalculateNewRates(double WinnersResolvedIssueRate, double LoosersResolvedIssueRate, int WinningParty )
{
	ofstream outResultFile( "result.txt", ios::app );
	cout<<"Old Rates for Issue "<<setw(12)<<right<<IssueNum<<": "<<setw(10)
		<<fixed<<setprecision(3)<<p1_rate<<", "<<setw(10)<<p2_rate<<endl;
	outResultFile<<"Old Rates for Issue "<<setw(12)<<right<<IssueNum<<": "<<setw(10)
		<<fixed<<setprecision(3)<<p1_rate<<", "<<setw(10)<<p2_rate<<endl;\

	if (WinningParty==PARTY_1)
	{																	//fabs( x ) - absolute value of x
		p1_rate *= 1 + CalculateWinningPartyRate(WinnersResolvedIssueRate, fabs( WinnersResolvedIssueRate - p1_rate));
		p2_rate *= 1 + CalculateLoosingPartyRate(LoosersResolvedIssueRate, fabs( LoosersResolvedIssueRate - p2_rate));
		cout<<"New Rates for Issue "<<setw(12)<<right<<IssueNum<<": "<<setw(10)
		<<fixed<<setprecision(3)<<p1_rate<<", "<<setw(10)<<p2_rate<<endl;
		outResultFile<<"New Rates for Issue "<<setw(12)<<right<<IssueNum<<": "<<setw(10)
		<<fixed<<setprecision(3)<<p1_rate<<", "<<setw(10)<<p2_rate<<endl;
		
	}
	else if (WinningParty==PARTY_2)
	{
		p2_rate *= 1 + CalculateWinningPartyRate(WinnersResolvedIssueRate, fabs( WinnersResolvedIssueRate - p2_rate));
		p1_rate *= 1 + CalculateLoosingPartyRate(LoosersResolvedIssueRate, fabs( LoosersResolvedIssueRate - p1_rate));
		cout<<"New Rates for Issue "<<setw(12)<<right<<IssueNum<<": "<<setw(10)
		<<fixed<<setprecision(3)<<p1_rate<<", "<<setw(10)<<p2_rate<<endl;
		outResultFile<<"New Rates for Issue "<<setw(12)<<right<<IssueNum<<": "<<setw(10)
		<<fixed<<setprecision(3)<<p1_rate<<", "<<setw(10)<<p2_rate<<endl;
		
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
double IssueClass::CalculateWinningPartyRate(double WinningIssueRate, double Difference) const
{	
	double Factor;
	if ( WinningIssueRate <= 10 )
	{
		if ( Difference >= 0 && Difference < 30 ) Factor = (1.0/0.3) * Difference;
		else if ( Difference >=30 && Difference <= 100 ) Factor = 100;
	}
	else if (WinningIssueRate > 10 && WinningIssueRate <= 20 )
	{
		if( Difference >= 0 && Difference < 10 ) Factor = 1.25 * Difference + 12.5;
		else if( Difference >= 10 && Difference < 20 ) Factor = 25;
		else if( Difference >= 20 && Difference < 40 ) Factor = ( 1.0 / 2.0 ) * Difference + 15;
		else if( Difference >= 40 && Difference < 60 ) Factor = - ( 3.5 / 2.0 ) * Difference + 105;
		else if( Difference >= 60 && Difference <= 100 ) Factor = - ( 0.5 / 4.0 ) * Difference + 7.5;
	}
	else if ( WinningIssueRate > 20 && WinningIssueRate <= 35 )
	{
		if( Difference >= 0 && Difference < 10 ) Factor = 5;
		else if( Difference >= 10 && Difference < 20 ) Factor = 0.75 * Difference - 2.5;
		else if( Difference >= 20 && Difference < 40 ) Factor = 12.5;
		else if( Difference >= 40 && Difference < 60 ) Factor = - ( 2.5 / 4.0 ) * Difference + 37.5;
		else if( Difference >= 60 && Difference <= 100 ) Factor = - ( 1.0 / 4.0 ) * Difference + 15;
	}
	else if( WinningIssueRate > 35 && WinningIssueRate <= 55 ) {
		if( Difference >= 0 && Difference < 10 ) Factor = ( 1.0 / 1.0 ) * Difference - 5;
		else if( Difference >= 10 && Difference < 20 ) Factor = 5;
		else if( Difference >= 20 && Difference < 40 ) Factor = - ( 0.5 / 1.0 ) * Difference + 20;
		else if( Difference >= 40 && Difference <= 100 ) Factor = - 0.25 * Difference + 10;
	}
	else if( WinningIssueRate > 55 )
	{
		if( Difference >= 0 && Difference <= 100 ) Factor = ( 1.0 / 1.0 ) * Difference - 100;
	}

	return Factor/100.0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
double IssueClass::CalculateLoosingPartyRate(double WinningIssueRate, double Difference) const
{
	double Factor;
	if ( WinningIssueRate <= 10 )
	{
		if( Difference >= 0 && Difference < 20 ) Factor = 25;
		else if( Difference >= 20 && Difference < 30 ) Factor = ( 2.5 / 1.0 ) * Difference - 25;
		else if( Difference >= 30 && Difference <= 100) Factor = 50;
	}
	else if (WinningIssueRate > 10 && WinningIssueRate <= 20 )
	{
		if( Difference >= 0 && Difference < 30 ) Factor = 25;
		else if( Difference >= 30 && Difference <= 100 ) Factor = -( 2.5 / 7.0 ) * Difference + 250 / 7;
	}
	else if ( WinningIssueRate > 20 && WinningIssueRate <= 35 )
	{
		if( Difference >= 0 && Difference < 40 ) Factor = 50;
		else if( Difference >= 40 && Difference < 50 ) Factor = -( 2.5 / 1.0 ) * Difference + 150;
		else if( Difference >= 50 && Difference <= 100 ) Factor = -( 0.5 / 1.0 ) * Difference + 50;
	}
	else if( WinningIssueRate > 35 && WinningIssueRate <= 55 ) {
		if( Difference >= 0 && Difference < 20 ) Factor = 75;
		else if( Difference >= 20 && Difference < 30 ) Factor = -( 2.5 / 1.0 ) * Difference + 125;
		else if( Difference >= 30 && Difference < 55 ) Factor = 50;
		else if( Difference >= 55 && Difference < 60 ) Factor = -5 * Difference + 325;
		else if( Difference >= 60 && Difference <= 100 ) Factor = -( 2.5 / 4.0 ) * Difference + 62.5;
	}
	else if( WinningIssueRate > 55 )
	{
		if( Difference >= 0 && Difference < 30 ) Factor = 100;
		else if( Difference >= 30 && Difference < 40 ) Factor = -( 2.5 / 1.0 ) * Difference + 175;
		else if( Difference >= 40 && Difference < 50 ) Factor = 75;
		else if( Difference >= 50 && Difference < 60 ) Factor = -( 2.5 / 1.0 ) * Difference + 200;
		else if( Difference >= 60 && Difference <= 100 ) Factor = -( 5.0 / 4.0 ) * Difference + 125;
	}

	return Factor/100.0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
void IssueClass::printIssueDetails()
{
	ofstream outResultFile( "result.txt", ios::app );
	cout<<"Issue "<<IssueNum<<" won by party: "<<IssueBelongs<<endl;
	outResultFile<<"Issue "<<IssueNum<<" won by party: "<<IssueBelongs<<endl;
	
}
