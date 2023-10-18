/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.assignmentoopt;

/**
 *
 * @author User
 */

/**
 *
 * @author huifa
 */
public class Member extends Selectable {
    public String memberID;
    public String memberName;
    public int memberAge;
    public String memberContactNo;
    public char memberGender;
    
    public Member(){
        
    }

    public Member(String memberID, String memberName, int memberAge, char memberGender, String memberContactNo) {
        this.memberID = memberID;
        this.memberName = memberName;
        this.memberAge = memberAge;
        this.memberGender = memberGender;
        this.memberContactNo = memberContactNo;
    }

    public String getMemberID() {
        return memberID;
    }

    public void setMemberID(String memberID) {
        this.memberID = memberID;
    }

    public String getMemberName() {
        return memberName;
    }

    public void setMemberName(String memberName) {
        this.memberName = memberName;
    }

    public int getMemberAge() {
        return memberAge;
    }

    public void setMemberAge(int memberAge) {
        this.memberAge = memberAge;
    }

    public String getMemberContactNo() {
        return memberContactNo;
    }

    public void setMemberContactNo(String memberContactNo) {
        this.memberContactNo = memberContactNo;
    }

    public char getMemberGender() {
        return memberGender;
    }

    public void setMemberGender(char memberGender) {
        this.memberGender = memberGender;
    }
    
    public String toString() {
        return String.format("%-8s%-20s%-15d%-15c%-20s", memberID, memberName, memberAge, memberGender, memberContactNo);
    }

    public String getFORMATHEADER() {
        return String.format("%-8s%-20s%-15s%-15s%-20s", "MemberID", "MemberName", "Age", "Gender", "Contact Number");
    }
}


