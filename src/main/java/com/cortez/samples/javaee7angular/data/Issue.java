package com.cortez.samples.javaee7angular.data;

import java.io.Serializable;
import java.math.BigDecimal;
import javax.persistence.*;

/**
 * Simple entity.
 *
 * @author Roberto Cortez
 */
@Entity
@Table(name = "ISSUE")
@NamedQueries({
    @NamedQuery(name = "Issue.findAll", query = "SELECT m FROM Issue m")})
public class Issue implements Serializable {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    //@GeneratedValue(strategy = GenerationType.SEQUENCE)
    //@SequenceGenerator(name = "ID", sequenceName = "ID")
    private Long id;

    @Column(name = "ISSUENUM")
    private String issueNum;

    @Column(name = "P1RATE", precision = 7, scale = 5)
    private BigDecimal p1Rate;

    @Column(name = "P2RATE", precision = 7, scale = 5)
    private BigDecimal p2Rate;
    
    @Column(name = "BELONGS", columnDefinition="smallint(1) default '0'")
    private short belongs;

    public short getBelongs() {
        return belongs;
    }

    public void setBelongs(short belongs) {
        this.belongs = belongs;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getIssueNum() {
        return issueNum;
    }

    public void setIssueNum(String issueNum) {
        this.issueNum = issueNum;
    }

    public BigDecimal getP1Rate() {
        return p1Rate;
    }

    public BigDecimal getP2Rate() {
        return p2Rate;
    }

    public void setP1Rate(BigDecimal p1Rate) {
        this.p1Rate = p1Rate;
    }

    public void setP2Rate(BigDecimal p2Rate) {
        this.p2Rate = p2Rate;
    }
    
    public double getMrkDiff() { 
        if( p1Rate.doubleValue()>p2Rate.doubleValue() ) return p1Rate.doubleValue()-p2Rate.doubleValue();
	else return p2Rate.doubleValue()-p1Rate.doubleValue(); 
    }
    
    public void setWinningParty() { 
        if( p1Rate.doubleValue()>p2Rate.doubleValue() ) belongs=1; 
        else belongs=2;
    }

    @Override
    public int hashCode() {
        return id.hashCode();
    }
    
    public double getWiningPartyRate() { 
        if ( belongs == 1 ) return p1Rate.doubleValue();
	else return p2Rate.doubleValue();
    }
    
    public double getLoosingPartyRate() { 
        if ( belongs == 1 ) return p2Rate.doubleValue();
	else return p1Rate.doubleValue();
    }
    
    public String CalculateNewRates(double WinnersResolvedIssueRate, double LoosersResolvedIssueRate, int WinningParty ) {
	//ofstream outResultFile( "result.txt", ios::app );
        String output="";
	output+="Old Rates for Issue "+issueNum+": "+p1Rate+", "+p2Rate+"\n";
//	outResultFile<<"Old Rates for Issue "<<setw(12)<<right<<IssueNum<<": "<<setw(10)
//		<<fixed<<setprecision(3)<<p1Rate<<", "<<setw(10)<<p2Rate<<endl;

	if (WinningParty==1)
	{										//fabs( x ) - absolute value of x
		p1Rate = BigDecimal.valueOf( p1Rate.doubleValue()* (1 + CalculateWinningPartyRate(WinnersResolvedIssueRate, Math.abs( WinnersResolvedIssueRate - p1Rate.doubleValue())) ) );
		p2Rate = BigDecimal.valueOf( p2Rate.doubleValue()* (1 + CalculateLoosingPartyRate(LoosersResolvedIssueRate, Math.abs( LoosersResolvedIssueRate - p2Rate.doubleValue())) ) );
		output+="New Rates for Issue "+issueNum+": "+p1Rate+", "+p2Rate+"\n";
//		outResultFile<<"New Rates for Issue "<<setw(12)<<right<<IssueNum<<": "<<setw(10)
//		<<fixed<<setprecision(3)<<p1Rate<<", "<<setw(10)<<p2Rate<<endl;
		
	}
	else if (WinningParty==2)
	{
		p2Rate = BigDecimal.valueOf( p2Rate.doubleValue()* (1 + CalculateWinningPartyRate(WinnersResolvedIssueRate, Math.abs( WinnersResolvedIssueRate - p2Rate.doubleValue()))));
		p1Rate = BigDecimal.valueOf( p1Rate.doubleValue()* (1 + CalculateLoosingPartyRate(LoosersResolvedIssueRate, Math.abs( LoosersResolvedIssueRate - p1Rate.doubleValue()))));
		output+="New Rates for Issue "+issueNum+": "+p1Rate+", "+p2Rate+"\n";
//		outResultFile<<"New Rates for Issue "<<setw(12)<<right<<IssueNum<<": "<<setw(10)
//		<<fixed<<setprecision(3)<<p1Rate<<", "<<setw(10)<<p2Rate<<endl;
		
	}
        return output;
    }
    
    private double CalculateWinningPartyRate(double WinningIssueRate, double Difference) {	
	double Factor=1;
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
    
    private double CalculateLoosingPartyRate(double WinningIssueRate, double Difference) {
	double Factor=1;
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
    
}
