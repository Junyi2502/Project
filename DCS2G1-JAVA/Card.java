/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.assignmentoopt;

/**
 *
 * @author User
 */
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author User
 */
public class Card extends SalesFunction{
        
        public void card() throws IOException{
        Sales sales = new Sales();
        AssignmentOOPT ass = new AssignmentOOPT();
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Total Amount : RM ");
        System.out.printf("%.2f \n",total);
        System.out.print("Please Enter Your 16-Digit Card Number (X To Exit) : ");
        String cardNumber = sc.nextLine(); // Read the card number as a string
        
        if("X".equals(cardNumber)||"x".equals(cardNumber)){
                pressToContinue();
                sales.clearScreen();
                ass.logo();
                menuSelects();
        } 

    // Check if the entered card number has exactly 16 digits
        if (cardNumber.length() == 16 && cardNumber.matches("\\d+")) {
            // The card number is valid (contains only digits and has 16 digits)
            // You can process it here
            System.out.println("Card Number entered: " + cardNumber);
            pressToContinue();
            sales.clearScreen();
            ass.logo();
            deleteFile();
            setPaymentName("Card");
            Receipt receipt = new Receipt() {};
            receipt.generateReceipt();
            setTotal1(0);
            pressToContinue();
            sales.clearScreen();
            ass.logo();
            menuSelects();
        } 
        else {
            System.out.println("Invalid Card Number. Please enter a 16-digit numeric card number.");
            // You can handle the error or prompt the user to re-enter the card number
        }
        
        

    }
        
    @Override
    public String toString(){
        return super.toString() + "Payment By : " + getPaymentName();
    }
}
