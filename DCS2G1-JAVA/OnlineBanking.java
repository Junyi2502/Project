/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.assignmentoopt;

/**
 *
 * @author User
 */
import static com.mycompany.assignmentoopt.SalesFunction.pressToContinue;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author User
 */
public class OnlineBanking extends SalesFunction{
       
    public void onlineBank() throws IOException{
        Scanner sc = new Scanner(System.in);
        Sales sales = new Sales();
        AssignmentOOPT ass = new AssignmentOOPT();
        
        System.out.println("We Support The Bank Below : ");
        System.out.println("1.Public Bank");
        System.out.println("2.RHB Bank");
        System.out.println("3.CIMB Bank");
        System.out.print("Please Enter Your Select (9 To Exit) : ");
        
         String choose1 = sc.nextLine();
        boolean exit = false;
        
        while(!exit){
            
        if(choose1.matches("\\d+")) {
        int choice1 = Integer.parseInt(choose1);      
        switch(choice1){
            case 1 -> {
                System.out.println("Jump To The Public Bank Page ... ");
                pressToContinue();
                sales.clearScreen();
                ass.logo();
                deleteFile();
                setPaymentName("Public Bank");
                Receipt receipt = new Receipt() {};
                receipt.generateReceipt();
                setTotal1(0);
                pressToContinue();
                sales.clearScreen();
                ass.logo();
                menuSelects();
            }
            
            case 2 ->{
                System.out.println("Jump To The RHB Bank Page ... ");
                pressToContinue();
                sales.clearScreen();
                ass.logo();
                deleteFile();
                setPaymentName("RHB Bank");
                Receipt receipt = new Receipt() {};
                receipt.generateReceipt();
                setTotal1(0);
                pressToContinue();
                sales.clearScreen();
                ass.logo();
                menuSelects();
            }
            case 3 ->{
                System.out.println("Jump To The CIMB Bank Page ... ");
                pressToContinue();
                sales.clearScreen();
                ass.logo();
                deleteFile();
                setPaymentName("CIMB Bank");
                Receipt receipt = new Receipt() {};
                receipt.generateReceipt();
                setTotal1(0);
                pressToContinue();
                sales.clearScreen();
                ass.logo();
                menuSelects();
            }
            case 9 ->{
                pressToContinue();
                sales.clearScreen();
                ass.logo();
                menuSelects();
            }
        }
        }
        else {
            sales.clearScreen();
            ass.logo();
            sales.errorMsg1();
            break;
        }
        }
       
    }
    
    @Override
    
    public String toString(){
            return super.toString() + "Payment By : " + getPaymentName();
    }
  
}

