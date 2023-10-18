/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.assignmentoopt;

/**
 *
 * @author User
 */
import java.util.Scanner;
import java.awt.Robot;
import java.awt.AWTException;
import java.awt.event.KeyEvent;
import java.io.FileNotFoundException;
import java.io.IOException;

public class Sales{

    /**
     * @param args the command line arguments
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws IOException {
       SalesFunction sf = new SalesFunction(); 
       sf.deleteFile();
       menuSelect();
    }
    
    public void salesMenu(){        
        System.out.println("Welcome to the LSM Market !!! ");
        System.out.println("Plese select 1 - 5 to select the funcion : ");
        System.out.println("1. Add Products To Cart");
        System.out.println("2. Shopping Cart");
        System.out.println("3. Make Payment");
        System.out.println("4. Delete Orders");
        System.out.println("5. Go Back To Menu");
        System.out.print("Plese select Your Choice (1-5) : ");
    }
    
    public static void menuSelect() throws FileNotFoundException, IOException{
       SalesFunction function = new SalesFunction();   
       function.menuSelects();
    }

    public void addProd() throws FileNotFoundException, IOException{
        
        SalesFunction function = new SalesFunction();
        
        System.out.println("Plese Select The Product You Need To Add To Cart :");
        System.out.println("1.Vegetable");
        System.out.println("2.Fresh Fruit");
        System.out.println("3.Long Bread");
        System.out.println("4.Soft Drink");
        System.out.println("5.Toiletries");
        System.out.println("6.Canned Food");
        System.out.println("7.Medicine");
        System.out.print("Plese Select The Product(0 to Exit) : ");
        
        function.addProds();
        
    }
    
    public void cart() throws FileNotFoundException, IOException{
        System.out.println("===========================================================");
        System.out.println("============================Cart===========================");
        System.out.println("===========================================================");
        System.out.println("List\t ID\tProduct Name\t Qty\t Price\t Disc\t Total");
        SalesFunction function = new SalesFunction();
        function.checkCart();
        
    }
    
    public void payment() throws FileNotFoundException, IOException{ 
        SalesFunction function = new SalesFunction();
        function.paymentFunction();
    }
    
    public void deleteOrder() throws FileNotFoundException, IOException{
        System.out.println("===========================================================");
        System.out.println("============================Cart===========================");
        System.out.println("===========================================================");
        SalesFunction function = new SalesFunction();
        function.readFile();
        
       SalesFunction sf = new SalesFunction();
       Scanner sc = new Scanner(System.in); 
       System.out.print("Please Enter The Item List That You Want To Remove (0 to Exit) : ");
       int itemListToDelete = sc.nextInt();
       sf.delete(itemListToDelete);       
    }
    public void errorMsg() throws FileNotFoundException, IOException{
        System.out.println("Error Input only 1 - 5 : ");
        menuSelect();
    }
    
    public void errorMsg1() throws FileNotFoundException, IOException{
        System.out.println("Error Input Please Enter only 1 - 7 Or 0 To Exit : ");
        addProd();
    }
    

    public void clearScreen() {
            try {
                Robot robot = new Robot();
                robot.setAutoDelay(1);
                robot.keyPress(KeyEvent.VK_CONTROL);
                robot.keyPress(KeyEvent.VK_L);
                robot.keyRelease(KeyEvent.VK_CONTROL);
                robot.keyRelease(KeyEvent.VK_L);
            } catch (AWTException ex) {
            }
    }



}

