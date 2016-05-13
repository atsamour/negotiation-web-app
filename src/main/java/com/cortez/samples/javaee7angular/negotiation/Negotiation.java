/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.cortez.samples.javaee7angular.negotiation;

import com.cortez.samples.javaee7angular.data.Issue;
import java.math.BigDecimal;
import java.util.List;
import javax.ejb.LocalBean;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

/**
 *
 * @author Arkadios.Tsamourliadis
 */
@Stateless
@LocalBean
public class Negotiation {
    
    
    @PersistenceContext(unitName = "myPU")
    private EntityManager em;
    
    
    public List<Issue> getAllIssues() {
        Query query = em.createNamedQuery("Issue.findAll");
        List<Issue> results = query.getResultList();
        return results;
    }

    private void normalizeRates(Issue issue, double p1sum, double p2sum){
        issue.setP1Rate(new BigDecimal(100.0*issue.getP1Rate().doubleValue()/p1sum));
        issue.setP2Rate(new BigDecimal(100.0*issue.getP2Rate().doubleValue()/p2sum));
    }
    
    private String CalculateNormRates(List<Issue> issues) {
	//ofstream outResultFile( "result.txt", ios::app );
	double p1sum=0;
	double p2sum=0;
	String calcTextBox="";

        for (Issue issue : issues) {
            p1sum += issue.getP1Rate().doubleValue();
            p2sum += issue.getP2Rate().doubleValue();
            ///////////////////////////
            calcTextBox=calcTextBox+"Calculating SumS p1, p2: "+p1sum+", "+p2sum+"\r\n";
            calcTextBox=calcTextBox+"     Issue name: "+issue.getIssueNum()+"  rates: "+issue.getP1Rate()+" "+issue.getP2Rate()+"\r\n";
        }
	//cout<<"\nSum of Party 1 Rates:"<<setw(8)<<right<<setfill('.')<<p1sum<<endl;
	calcTextBox=calcTextBox+"\r\nSum of Party 1 Rates:"+p1sum+"\r\n";
	//cout<<"Sum of Party 2 Rates:"<<setw(8)<<p2sum<<endl;
	calcTextBox=calcTextBox+"\r\nSum of Party 2 Rates:"+p2sum+"\r\n";
	//cout<<"Normalizing all rates in the scale of 100..."<<endl;
	calcTextBox=calcTextBox+"Normalizing all rates in the scale of 100..."+"\r\n";
        for (Issue issue : issues) {
            normalizeRates(issue, p1sum, p2sum);
            //cout<<"Normalized rates for Issue"<<setw(12)<<right<<issues[i].getIssueNum()<<": "
            //	<<setw(12)<<fixed<<setprecision(3)<<issues[i].getP1Rate()<<",   "<<setw(12)<<issues[i].getP2Rate()<<endl;
            calcTextBox=calcTextBox+"\r\nNormalized rates for Issue "+issue.getIssueNum()+" : "+
                    issue.getP1Rate()+",   "+issue.getP2Rate()+"\r\n";
        }
	return calcTextBox;
    }
    
    private: void resolveIssues(List<Issue> issues) {
	//ofstream outResultFile( "result.txt", ios::app );	

	//At each iteration an Issue will be Resolved
	for (int genIndex=0; genIndex < issues.size(); genIndex++)
	{
            double maxDiff=0;
            int maxDiffIssueIndex=-1;

            //Find an Issue to Resolve
            for (int i=0; i<issues.size(); i++)
            {
                if (issues.get(i).getBelongs()!=0){   //Issue already Resolved
                    continue;
                }
                if ( issues.get(i).getMrkDiff() >= maxDiff ) {
                    maxDiff = issues.get(i).getMrkDiff();
                    maxDiffIssueIndex = i;
                }
            }
            issues.get(maxDiffIssueIndex).setWinningParty(); //This Issue has just been resolved


            String tmptextbox="";
            tmptextbox = tmptextbox+"\r\nIssue "+issues.get(maxDiffIssueIndex).getIssueNum()+
                    " won by party "+issues.get(maxDiffIssueIndex).getParty()+"\r\n";
            //outResultFile<<"\nIssue "<<issues[maxDiffIssueIndex].getIssueNum()<<
            //	" won by party "<<issues[maxDiffIssueIndex].getParty()<<endl;
            //Calculating new Rates for other Issues after a Resolvement
            for (Issue issue : issues) {
                if (issue.getBelongs()!=0) {//Does not have to Calculate new Rates for a resolved Issue
                    continue;
                }
                IssueClass* ptrtmpIssuemaxDiffIssueIndex = reinterpret_cast<IssueClass*> (issues[maxDiffIssueIndex].ToPointer());;

                String tmpstringtextbox = ptrtmpIssue->CalculateNewRates (	ptrtmpIssuemaxDiffIssueIndex->getWiningPartyRate(),
                        ptrtmpIssuemaxDiffIssueIndex->getLoosingPartyRate(),
                        ptrtmpIssuemaxDiffIssueIndex->getParty()				);
                String tmptextbox+= tmpstringtextbox;
            }
	}// end of for( genIndex
	
    }
    
}
