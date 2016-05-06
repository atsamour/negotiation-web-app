#ifndef _ISSUECLASS_H_
#define _ISSUECLASS_H_

#include <iostream>
#include <string>

using namespace std;

class IssueClass
{

private:
	enum Party { NOPARTY, PARTY_1, PARTY_2 } IssueBelongs;
	static unsigned int IssuesCnt; //<---Need this??
	double p1_rate;
	double p2_rate;
	double CalculateWinningPartyRate(double, double) const;
	double CalculateLoosingPartyRate(double, double) const;

public:
	//IssueClass() {}
	~IssueClass() {IssuesCnt--;}//<---Need this??
	IssueClass(string INum, double m1, double m2) :
	  p1_rate(m1), p2_rate(m2), IssueNum(INum), IssueBelongs(NOPARTY)
	  { IssuesCnt++; }//<---Need this??
	void alterToSubIssue(string chldNum, double m1, double m2) { IssueNum=IssueNum+","+chldNum; p1_rate=m1; p2_rate=m2; }
	double getMrkDiff() { if( p1_rate>p2_rate ) return p1_rate-p2_rate;
								else return p2_rate-p1_rate; }
	void setWinningParty() { if( p1_rate>p2_rate ) IssueBelongs=PARTY_1; 
								else IssueBelongs=PARTY_2; 	}
	double getWiningPartyRate() { if ( IssueBelongs == PARTY_1 ) return p1_rate;
									else return p2_rate; }
	double getLoosingPartyRate() { if ( IssueBelongs == PARTY_1 ) return p2_rate;
									else return p1_rate; }
	bool Resolved() const { if (IssueBelongs==NOPARTY) return false; else return true; }
	int getParty() const { /*if (IssueBelongs==NOPARTY) return 0;
								else if (IssueBelongs==PARTY_1) return 1;
								else return 2;*/ return IssueBelongs; }
	void normalizeRates(double p1sum, double p2sum) { p1_rate=100.0*p1_rate/p1sum; p2_rate=100.0*p2_rate/p2sum; }
	string getIssueNum() const { return IssueNum; }
	double getP1Rate() const { return p1_rate; }
	double getP2Rate() const { return p2_rate; }

	void printIssueDetails();
	void CalculateNewRates(double, double, int);
	/////////////////////
	string IssueNum;
};


#endif