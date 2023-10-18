/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.assignmentoopt;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author User
 */
public class mainFunction {
//    public void pass() throws IOException{
//        Sales sales = new Sales();
//        SalesFunction sf = new SalesFunction();
//        int pass = 9999;
//        Scanner sc = new Scanner(System.in);
//        System.out.println("===================================================================");
//        System.out.print("Please Enter The POS System Pass : ");
//        int passId = sc.nextInt();
//        if(passId == pass){
//            System.out.println("===================================================================");
//            System.out.println("Welcome Back !!!");
//            System.out.println("===================================================================");
//            sf.pressToContinue();
//            sales.clearScreen();
//            menu();
//        }
//        else{
//            System.out.println("Error Pass !!!");
//            sf.pressToContinue();
//            sales.clearScreen();
//            System.exit(-1);
//        }
//    }
    public void login() throws IOException {
    Scanner sc = new Scanner(System.in);
    Worker worker = new Worker();
    Staff staff = new Staff();
    AssignmentOOPT ass = new AssignmentOOPT();
    ass.logo();
    System.out.println("==================================================================================");
        System.out.println("!!! If New Using This POS System Pls Enter Randomly And Register !!!");
    System.out.print("Enter Login ID: ");
    String loginID = sc.nextLine();
    System.out.print("Enter Password: ");
    String password = sc.nextLine();
    if (!fileExists("staff.txt")) {
            try {
                FileWriter writer = new FileWriter("staff.txt");
                writer.close();
            } catch (IOException e) {
                System.err.println("Error crea11ting the file: " + e.getMessage());
            }
        }  
    
    worker.readFiles(staff,loginID);
    
    if(staff.staffID == null ? loginID == null : staff.staffID.equals(loginID)){
    
        if(staff.password == null ? password == null : staff.password.equals(password)){
            System.out.println("Login successful!");
            // Perform actions after successful login
            menu(); // You can call your menu function here or perform other actions.
        }
        else {
            System.out.println("Login failed.");
            System.out.print("Do You Want To Register A Staff ? (Y/N) :");
            String choose = sc.nextLine();
            if("Y".equals(choose)||"y".equals(choose)){
                worker.addStaffLogin();
            }
            else{
                System.exit(0);
            }
        }
    }
    else {
        System.out.println("Login failed.");
        System.out.print("Do You Want To Register A Staff ? (Y/N) :");
            String choose = sc.nextLine();
            if("Y".equals(choose)||"y".equals(choose)){
                worker.addStaffLogin();
            }
            else{
                System.exit(0);
            }
    }
}
       
    public void menu() throws IOException{
        Worker wk = new Worker();
        FoodStock fs = new FoodStock();
        Sales sales = new Sales();
        AssignmentOOPT ass = new AssignmentOOPT();
        SalesFunction sf = new SalesFunction();
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Please Select Funtion Below : ");
        System.out.println("1.Staff and Member Function");
        System.out.println("2.Sales Function");
        System.out.println("3.Stock Function");
        System.out.println("4.Exit The POS System");
        System.out.print("Please Enter Your Choice : ");
        String choose = sc.nextLine();

        if (choose.matches("\\d+")) {
            int choice = Integer.parseInt(choose);      

                switch(choice){

                    case 1 ->  {
                        sales.clearScreen();
                        ass.logo();
                        wk.memberMain();
                    }
                    case 2 ->  {
                       sales.clearScreen();
                       ass.logo();
                       sf.menuSelects();
                    }
                    case 3 ->  {
                        sales.clearScreen();
                        ass.logo();
                        fs.stock();
                    }
                    case 4 ->  {
                        System.out.println("Thank You !!!");
                        sf.pressToContinue();
                        sales.clearScreen();
                        System.exit(0);
                    }

                    default ->  {
                        sales.clearScreen();
                        
                    }

                }
        }
         else {
                sales.clearScreen();
                sales.errorMsg();
        }
        
        
    }   
        public boolean fileExists(String filePath){
            File file = new File(filePath);
            return file.exists();
        }
    
}

