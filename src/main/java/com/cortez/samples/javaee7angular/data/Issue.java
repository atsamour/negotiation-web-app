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
}
