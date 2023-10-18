/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.assignmentoopt;

/**
 *
 * @author User
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class SalesFunction {
    public int qty,prodId;
    public static int itemList = 0;
    private double price,totalPrice;
    public static double total;
    private double discount;
    private String itemName;
    public static String paymentName;
    
    public SalesFunction(){
        
    }

    public SalesFunction(int qty, int prodId, double price, double totalPrice, double discount, String itemName,double total, String paymentName){
        this.qty = qty;
        this.price = price;
        this.prodId = prodId;
        this.totalPrice = totalPrice;
        this.discount = discount;
        itemList++;
        this.itemName = itemName;
        this.total = total;
        this.paymentName = paymentName;
        
    }

    public String getItemName() {
        return itemName;
    }

    public void setItemName(String itemName) {
        this.itemName = itemName;
    }

    public int getQty() {
        return qty;
    }

    public void setQty(int qty) {
        this.qty = qty;
    }

    public int getProdId() {
        return prodId;
    }

    public void setProdId(int prodId) {
        this.prodId = prodId;
    }

    public double getPrice() {
        return price;
    }
    
    public void setPrice(double price) {
        this.price = price;
    }


    public double getTotalPrice() {
        return totalPrice;
    }

    public void setTotalPrice(int qty,double price) {
        this.totalPrice = price * qty;
    }

    public double getDiscount() {
        return discount;
    }

    public void setDiscount(double discount) {
        this.discount = discount;
    }

    public int getItemList() {
        return itemList;
    }
    
    public void setItemList(int itemList){
        SalesFunction.itemList = itemList;
    }

    public double getTotal() {
        return total;
    }
    
    public void setTotal(double total,double totalPrice){
        SalesFunction.total = total - totalPrice;
    }

    public void setTotal(double total) {
        SalesFunction.total += total;
    }
    
    public void setTotal1(double total){
        SalesFunction.total = total;
    }

    public String getPaymentName() {
        return paymentName;
    }

    public void setPaymentName(String paymentName) {
        this.paymentName = paymentName;
    }
    
    public void menuSelects() throws FileNotFoundException, IOException{
        Sales sales = new Sales();
        mainFunction mf = new mainFunction();
        AssignmentOOPT ass = new AssignmentOOPT();
        boolean exit = false;
        
        Scanner sc = new Scanner(System.in);
        
        while(!exit){
            sales.salesMenu();
             String choose = sc.nextLine();

        if (choose.matches("\\d+")) {
            int choice = Integer.parseInt(choose);      

                switch(choice){

                    case 1 ->  {
                        sales.clearScreen();
                        ass.logo();
                        addProd();
                    }
                    case 2 ->  {
                        sales.clearScreen();
                        ass.logo();
                        sales.cart();
                    }
                    case 3 ->  {
                        sales.clearScreen();
                        ass.logo();
                        sales.payment();
                    }
                    case 4 ->  {
                        sales.clearScreen();
                        ass.logo();
                        sales.deleteOrder();
                    }
                    case 5 ->  {
                        sales.clearScreen();
                        ass.logo();
                        mf.menu();
                    }

                    default ->  {
                        sales.clearScreen();
                        ass.logo();
                        sales.errorMsg();
                    }

                }
        }
         else {
                sales.clearScreen();
                ass.logo();
                sales.errorMsg();
                break;
        }
    }
    }
    
    
    public void addProds() throws FileNotFoundException, IOException{
        Scanner sc = new Scanner(System.in);
        Sales sales = new Sales();
        AssignmentOOPT ass = new AssignmentOOPT();
        String choose1 = sc.nextLine();
        boolean exit = false;
        
        while(!exit){
            
        if(choose1.matches("\\d+")) {
        int choice1 = Integer.parseInt(choose1);      
        switch(choice1){
            case 1 -> {
                setProdId(1001);
                setPrice(5.00);
                System.out.print("Plese Enter Quantity Of The Product : ");
                String qty1 = sc.nextLine();
                if (qty1.matches("\\d+")) {
                    int qty2 = Integer.parseInt(qty1);
                    setQty(qty2);
                    setTotalPrice(qty2, 5.00);
                }
                else{
                    System.out.println("Error !!! Please Enter Integer !!! : ");
                    pressToContinue();
                    sales.clearScreen();
                    ass.logo();
                    addProd();
                }
                totalPrice = getTotalPrice();
                setTotal(totalPrice);
                setItemList(SalesFunction.itemList+1);
                setItemName("Vegetable");
                filestore();
                sales.clearScreen();
                ass.logo();
                addProd();

                break;
            
            }   
        
            case 2 ->{
                setProdId(1002);
                setPrice(6.00);
                System.out.print("Plese Enter Quantity Of The Product : ");
                String qty1 = sc.nextLine();
                if (qty1.matches("\\d+")) {
                    int qty2 = Integer.parseInt(qty1);
                    setQty(qty2);
                    setTotalPrice(qty2, 6.00);
                }
                else{
                    System.out.println("Error !!! Please Enter Integer !!! : ");
                    pressToContinue();
                    sales.clearScreen();
                    ass.logo();
                    addProd();
                }
                totalPrice = getTotalPrice();
                setTotal(totalPrice);
                setItemList(SalesFunction.itemList+1);
                setItemName("Fresh Fruit");
                filestore();
                sales.clearScreen();
                ass.logo();
                addProd();

                break;
            }
        
            case 3 ->{
                setProdId(1003);
                setPrice(2.00);
                System.out.print("Plese Enter Quantity Of The Product : ");
                String qty1 = sc.nextLine();
                if (qty1.matches("\\d+")) {
                    int qty2 = Integer.parseInt(qty1);
                    setQty(qty2);
                    setTotalPrice(qty2, 2.00);
                }
                else{
                    System.out.println("Error !!! Please Enter Integer !!! : ");
                    pressToContinue();
                    sales.clearScreen();
                    ass.logo();
                    addProd();
                }
                totalPrice = getTotalPrice();
                setTotal(totalPrice);
                setItemList(SalesFunction.itemList+1);
                setItemName("Long Bread");
                filestore();
                sales.clearScreen();
                ass.logo();
                addProd();

                break;
            }
        
            case 4 ->{
                setProdId(1004);
                setPrice(3.50);   
                System.out.print("Plese Enter Quantity Of The Product : ");
                String qty1 = sc.nextLine();
                if (qty1.matches("\\d+")) {
                    int qty2 = Integer.parseInt(qty1);
                    setQty(qty2);
                    setTotalPrice(qty2, 3.50);
                }
                else{
                    System.out.println("Error !!! Please Enter Integer !!! : ");
                    pressToContinue();
                    sales.clearScreen();
                    ass.logo();
                    addProd();
                }
                totalPrice = getTotalPrice();
                setTotal(totalPrice);
                setItemList(SalesFunction.itemList+1);
                setItemName("Soft Drink");
                filestore();
                sales.clearScreen();
                ass.logo();
                addProd();

                break;
            }
            
            case 5 ->{
                setProdId(1005);
                setPrice(15.00);
                System.out.print("Plese Enter Quantity Of The Product : ");
                String qty1 = sc.nextLine();
                if (qty1.matches("\\d+")) {
                    int qty2 = Integer.parseInt(qty1);
                    setQty(qty2);
                    setTotalPrice(qty2, 15.00);
                }
                else{
                    System.out.println("Error !!! Please Enter Integer !!! : ");
                    pressToContinue();
                    sales.clearScreen();
                    ass.logo();
                    addProd();
                }
                totalPrice = getTotalPrice();
                setTotal(totalPrice);
                setItemList(SalesFunction.itemList+1);
                setItemName("Toiletries");
                filestore();
                sales.clearScreen();
                ass.logo();
                addProd();

                break;
            }
            
            case 6 ->{
                setProdId(1006);
                setPrice(9.00);
                System.out.print("Plese Enter Quantity Of The Product : ");
                String qty1 = sc.nextLine();
                if (qty1.matches("\\d+")) {
                    int qty2 = Integer.parseInt(qty1);
                    setQty(qty2);
                    setTotalPrice(qty2, 9.00);
                }
                else{
                    System.out.println("Error !!! Please Enter Integer !!! : ");
                    pressToContinue();
                    sales.clearScreen();
                    ass.logo();
                    addProd();
                }
                totalPrice = getTotalPrice();
                setTotal(totalPrice);
                setItemList(SalesFunction.itemList+1);
                setItemName("Canned Food");
                filestore();
                sales.clearScreen();
                ass.logo();
                addProd();

                break;
            }
            
            case 7 ->{
                setProdId(1007);
                setPrice(35.00);
                System.out.print("Plese Enter Quantity Of The Product : ");
                String qty1 = sc.nextLine();
                if (qty1.matches("\\d+")) {
                    int qty2 = Integer.parseInt(qty1);
                    setQty(qty2);
                    setTotalPrice(qty2, 35.00);
                }
                else{
                    System.out.println("Error !!! Please Enter Integer !!! : ");
                    pressToContinue();
                    sales.clearScreen();
                    ass.logo();
                    addProd();
                }
                totalPrice = getTotalPrice();
                setTotal(totalPrice);
                setItemList(SalesFunction.itemList+1);
                setItemName("Medicine");
                filestore();
                sales.clearScreen();
                ass.logo();
                addProd();

                break;
            }
            case 8 ->{
                sales.clearScreen();
                ass.logo();
                sales.errorMsg1();
                sales.addProd();
                break;
            }
            case 9 ->{
                sales.clearScreen();
                ass.logo();
                sales.errorMsg1();
                sales.addProd();
                break;
            }
            case 0 ->{
                exit = true;
                sales.clearScreen();
                ass.logo();
                sales.menuSelect();
                break;
            }

            default ->{
                sales.clearScreen();
                ass.logo();
                sales.errorMsg1();
                sales.addProd();
                break;
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
    
    public void deleteFile() throws IOException{
        new FileWriter("sales.txt", false).close();
    }
    
    
    public void filestore(){

        if (!fileExists("sales.txt")) {
            try {
                FileWriter writer = new FileWriter("sales.txt");
                writer.close();
            } catch (IOException e) {
                System.err.println("Error creating the file: " + e.getMessage());
            }
        }  

        try (FileWriter writer = new FileWriter("sales.txt", true)) {
            writer.write(getItemList()+ "\t");
            writer.write(getProdId()+ "\t");
            writer.write(getItemName()+ "\t");
            writer.write(getQty()+ "\t");
            writer.write(getPrice()+ "\t");
            writer.write(getDiscount() + "\t");
            writer.write(getTotalPrice()+ "\t");
            writer.write("\n");
            writer.close();
        } catch (IOException e) {
            System.err.println("Error writing to the file: " + e.getMessage());
        }
    }

    public boolean fileExists(String filePath){
        File file = new File(filePath);
        return file.exists();
    }
    
    public void addProd() throws FileNotFoundException, IOException{
        Sales s = new Sales();
        
        s.addProd();
    }
        
    
    public void readFile(){
        
        try (Scanner sc = new Scanner(new File("sales.txt"))) {

            while (sc.hasNextLine()) {
                String salesLine = sc.nextLine(); // Read the entire line
                
                String[] salesDetails = salesLine.split("\t");// Extract individual stock details
                
                if (salesDetails.length == 7) {
                    itemList = Integer.parseInt(salesDetails[0]);
                    prodId = Integer.parseInt(salesDetails[1]);
                    itemName = salesDetails[2];
                    qty = Integer.parseInt(salesDetails[3]);
                    price = Double.parseDouble(salesDetails[4]);
                    discount = Double.parseDouble(salesDetails[5]);
                    totalPrice = Double.parseDouble(salesDetails[6]);     
                }
                System.out.printf("%d\t %d\t %s\t %d\t %.2f\t %.2f\t %.2f \n",itemList,prodId,itemName, qty, price,discount,totalPrice); 
            }
        } catch (FileNotFoundException e) {
            System.err.println("Error reading the stock file.");
        }
        System.out.println("\n===========================================================");
        System.out.println("===========================================================");
    }
    
    public void checkCart() throws FileNotFoundException, IOException{
        Sales sales = new Sales();
        AssignmentOOPT ass = new AssignmentOOPT();
        readFile();
        pressToContinue();
        sales.clearScreen();    
        ass.logo();
     }
    
    
   public void delete(int itemListToDelete) throws FileNotFoundException {
       
       Sales sales = new Sales();
       AssignmentOOPT ass = new AssignmentOOPT();

    try {
        File inputFile = new File("sales.txt");
        File tempFile = new File("temp_sales.txt");

        boolean found;
        double totalPriceToDelete = 0.0;
        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile)); BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile))) {
            String line;
            found = false;
            while ((line = reader.readLine()) != null) {
                String[] salesDetails = line.split("\t");
                if (salesDetails.length == 7) {
                    itemList = Integer.parseInt(salesDetails[0]);
                    if (itemList == itemListToDelete) {
                            totalPriceToDelete = Double.parseDouble(salesDetails[6]);
                            System.out.println("Item Remove Successful !!!");
                            pressToContinue();
                            sales.clearScreen();
                            ass.logo();
                            found = true;
                            continue;
                        
                    }
                }
                writer.write(line + System.getProperty("line.separator"));
            }
        }
        if(itemListToDelete == 0){
            pressToContinue();
            sales.clearScreen();
            ass.logo();
            sales.menuSelect();
        }

        if (!found) {
            System.out.println("Delete Item Unsuccessful !!! ");
            pressToContinue();
            sales.clearScreen();
            ass.logo();
            return;
        }
        setTotal(total,totalPriceToDelete);

        if (!inputFile.delete()) {
            System.out.println("Could not delete the original file.");
            return;
        }

        if (!tempFile.renameTo(inputFile)) {
            System.out.println("Could not rename the temporary file.");
        }

    } catch (FileNotFoundException e) {
        System.err.println("Error reading the stock file.");
    } catch (IOException e) {
        System.err.println("Error while processing the file.");
    }
}
   
   
    public void paymentFunction() throws FileNotFoundException, IOException{
        
        Sales sales = new Sales();
        Scanner sc = new Scanner(System.in);
        AssignmentOOPT ass = new AssignmentOOPT();
        
        System.out.println("===========================================================");
        System.out.println("===========================Payment=========================");
        System.out.println("===========================================================");
        System.out.println("List\t ID\tProduct Name\t Qty\t Price\t Disc\t Total");
        readFile();
        System.out.print("Total Amount :");
        System.out.printf("%.2f",total);
        if(total == 0){
            System.out.println("\nError!!! Not Things Inside The Cart !!! ");
            pressToContinue();
            sales.clearScreen();
            ass.logo();
            menuSelects();   
        }
        pressToContinue();
        
        System.out.println("Please Select Which Method You Need To Use : ");
        System.out.println("1.Cash");
        System.out.println("2.Card");
        System.out.println("3.Online Banking");
        System.out.print("Please Select Your Method (0 To Exit) : ");
        
        String choose1 = sc.nextLine();
        boolean exit = false;
        
        while(!exit){
            
        if(choose1.matches("\\d+")) {
        int choice1 = Integer.parseInt(choose1);      
        switch(choice1){
            case 0 ->{
                pressToContinue();
                sales.clearScreen();
                ass.logo();
                menuSelects();
            }
            case 1 -> {
                Cash c = new Cash();
                sales.clearScreen();
                ass.logo();
                c.cash();   
                
            }
            
            case 2 ->{
                Card cd = new Card();
                sales.clearScreen();
                ass.logo();
                cd.card();
            }
            case 3 ->{
                OnlineBanking ob = new OnlineBanking();
                sales.clearScreen();
                ass.logo();
                ob.onlineBank();
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
    
     
   

    public static void pressToContinue() {
        System.out.print("\nPress Enter to continue...");
        Scanner sc = new Scanner(System.in);
        sc.nextLine(); 
    }

    
    
    @Override
    public String toString(){
        return "\nTotal Amount : RM" + getTotal();
    }
    
    
}



