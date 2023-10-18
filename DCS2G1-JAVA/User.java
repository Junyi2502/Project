/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.assignmentoopt;

/**
 *
 * @author User
 */

public class User{
    private String loginID;
    private String password;

    public User(String loginID, String password) {
        this.loginID = loginID;
        this.password = password;
    }

    public String getLoginID() {
        return loginID;
    }

    public String getPassword() {
        return password;
    }
}