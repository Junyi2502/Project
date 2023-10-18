/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.assignmentoopt;

/**
 *
 * @author User
 */
import static com.mycompany.assignmentoopt.SalesFunction.itemList;
import static com.mycompany.assignmentoopt.SalesFunction.pressToContinue;
import static com.mycompany.assignmentoopt.SalesFunction.total;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 *
 * @author User
 */
public class Cash extends SalesFunction {
    

    public void cash() throws FileNotFoundException, IOException{
           Sales sales = new Sales();
           AssignmentOOPT ass = new AssignmentOOPT();
           Scanner sc = new Scanner(System.in);
           FoodStock fs = new FoodStock();

           System.out.print("Total Amount : RM ");
           System.out.printf("%.2f \n",total);
           System.out.print("How Much Payed With Cash? (0 To Exit) : RM ");
           double cash = sc.nextDouble();
           if(cash == 0){
               pressToContinue();
               sales.clearScreen();
               menuSelects();
           }
           cash -= total;

           if(cash >= 0){
               System.out.println("Payment Successful !!!");
               System.out.print("Cash Need To Back : RM ");
               System.out.printf("%.2f",cash);
               setPaymentName("Cash");
               pressToContinue();
               sales.clearScreen();
               ass.logo();
               deleteFile();
               Receipt receipt = new Receipt() {};
               receipt.generateReceipt();
               setTotal1(0);
               pressToContinue();
               sales.clearScreen();
               ass.logo();
               updateQuantityInStockFile(fs.Id, qty);
               menuSelects();
           }
           if(cash < 0){
               System.out.println("Payment Unsuccessfull !!!");
               pressToContinue();
               sales.clearScreen();
               ass.logo();
               menuSelects();
           }

       }
    
     private void updateQuantityInStockFile(int itemId, int quantitySold) {
         FoodStock fs = new FoodStock();
        try {
            File inputFile = new File("C:\\Users\\User\\Desktop\\java\\practical 5\\AssignmentOOPT\\src\\main\\java\\com\\mycompany\\assignmentoopt\\FoodStock.txt");
            File tempFile = new File("temp_sales.txt");
            
            try (BufferedReader reader = new BufferedReader(new FileReader(inputFile));
                 BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile))) {
                String line;
                while ((line = reader.readLine()) != null) {
                    String[] salesDetails = line.split("\t");
                    if (salesDetails.length == 4) {
                        itemList = Integer.parseInt(salesDetails[0]);
                        if (itemList == itemId) {
                            fs.Quantity -= quantitySold;  // Update the quantity
                            line = salesDetails[0] + "\t" + salesDetails[1] + "\t" + salesDetails[2] + "\t" + fs.Quantity + "\t" + salesDetails[4] + "\t" + salesDetails[5] + "\t" + salesDetails[6];
                        }
                    }
                    writer.write(line + System.getProperty("line.separator"));
                }
            }
            
            // Rename the temp file to the original file
            if (tempFile.renameTo(inputFile)) {
                System.out.println("Item quantity updated successfully!");
            } else {
                System.err.println("Error updating item quantity.");
            }
        } catch (FileNotFoundException e) {
            System.err.println("Error reading the stock file.");
        } catch (IOException e) {
            System.err.println("Error while processing the file.");
        }
    }

    
    @Override
    public String toString(){
        return super.toString() + "Payment By : " + getPaymentName();
    }

}

