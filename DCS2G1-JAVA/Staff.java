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
public class Staff extends Selectable{
    public String staffID;
    public String staffName;
    public String staffPosition;
    public int staffAge;
    public String staffContactNo;
    public char staffGender; 
    public String loginID;
    public String password;

    public Staff(){}
    
    public Staff(String staffID, String staffName, String staffPosition, int staffAge, String staffContactNo, char staffGender, String loginID, String password) {
        this.staffID = staffID;
        this.staffName = staffName;
        this.staffPosition = staffPosition;
        this.staffAge = staffAge;
        this.staffContactNo = staffContactNo;
        this.staffGender = staffGender;
        this.loginID = loginID;
        this.password = password;
    }

    public Staff(String staffID, String staffName, String staffPosition, int staffAge, String staffContactNo, char staffGender, String password) {
        this.staffID = staffID;
        this.staffName = staffName;
        this.staffPosition = staffPosition;
        this.staffAge = staffAge;
        this.staffContactNo = staffContactNo;
        this.staffGender = staffGender;
        this.password = password;
    }

    public String getStaffID() {
        return staffID;
    }

    public void setStaffID(String staffID) {
        this.staffID = staffID;
    }

    public String getStaffName() {
        return staffName;
    }

    public void setStaffName(String staffName) {
        this.staffName = staffName;
    }

    public String getStaffPosition() {
        return staffPosition;
    }

    public void setStaffPosition(String staffPosition) {
        this.staffPosition = staffPosition;
    }

    public int getStaffAge() {
        return staffAge;
    }

    public void setStaffAge(int staffAge) {
        this.staffAge = staffAge;
    }

    public String getStaffContactNo() {
        return staffContactNo;
    }

    public void setStaffContactNo(String staffContactNo) {
        this.staffContactNo = staffContactNo;
    }

    public char getStaffGender() {
        return staffGender;
    }

    public void setStaffGender(char staffGender) {
        this.staffGender = staffGender;
    }

    public String getLoginID() {
        return loginID;
    }

    public void setLoginID(String loginID) {
        this.loginID = loginID;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
    
    
    public String toString() {
        return String.format("%-10s%-8s%-20s%-15s%-15c%-20s", staffID, staffName,staffPosition,
                staffAge,staffGender,staffContactNo);
    }


    public String getFORMATHEADER() {
        return String.format("%-10s%-8s%-20s%-15s%-15s%-20s","No", "StaffID", "StaffName","Position",
                "Age","Gender","Contact Number");
    }

}

