/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.assignmentoopt;

/**
 *
 * @author User
 */
public class Receipt extends SalesFunction {
    public Receipt() {

    }

    public void generateReceipt() {

        System.out.println("Receipt:");
        System.out.println("------------------------------");
        System.out.println(toString());
        System.out.println("Thank You For Purchase !!!");
        System.out.println("------------------------------");
    }

    @Override
    
    public String toString(){
        return "Payment By : " + getPaymentName() + super.toString() ;
    }
}