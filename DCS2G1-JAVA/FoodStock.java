/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.assignmentoopt;

/**
 *
 * @author User
 */

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;


public class FoodStock {

    //Pls Change The Location Of The File Below And Modify File Also Need To Change The Location
    
    public static final String FILENAME = "C:\\Users\\User\\Desktop\\java\\practical 5\\AssignmentOOPT\\src\\main\\java\\com\\mycompany\\assignmentoopt\\FoodStock.txt";
    
    public static Scanner input = new Scanner(System.in);
    
    public static int Id;
    public static String Name;
    public static int Price;
    public static int Quantity;
    public static int choose;
    
    public int getId() {
        return Id;
    }
    
    public void setId(int Id) {
        FoodStock.Id = Id;
    }
    
    public String getName() {
        return Name;
    }

    public void setName(String Name) {
        FoodStock.Name = Name;
    }
    
    public int getPrice() {
        return Price;
    }
    
    public void setPrice(int Price) {
        FoodStock.Price = Price;
    }
    
    public int getQuantity() {
        return Quantity;
    }
    
    public void setQuantity(int Quantity) {
        FoodStock.Quantity = Quantity;
    }
    
    public static List<String> getAll(){
        List<String> lst = null;
        try {
            lst = Files.readAllLines(Paths.get(FILENAME));
        } catch (IOException ex) {
            Logger.getLogger(FoodStock.class.getName()).log(Level.SEVERE, null, ex);
        }
        return lst;
    }
    
    public void addNew(){
        String line = String.join("|", Integer.toString(this.getId()), this.getName(), Integer.toString(this.getPrice()), Integer.toString(this.getQuantity()));
        line += System.lineSeparator();
        writeTo(line, StandardOpenOption.CREATE, StandardOpenOption.APPEND);
    }
    
    public void edit(){
        String newline = String.join("|", Integer.toString(this.getId()), this.getName(), Integer.toString(this.getPrice()), Integer.toString(this.getQuantity()));
        update(Integer.toString((this.getId())), newline);
    }
    
    protected void writeTo(String line, StandardOpenOption... mode){
        try {
            Files.write(Paths.get(FILENAME), line.getBytes(), mode);
            System.out.println("Done!");
        } catch (IOException ex) {
            Logger.getLogger(FoodStock.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    protected void update(String Id, String newRecord){
        
        List<String> lstAll = FoodStock.getAll();
        
        List<String> newLst = new ArrayList();
        
        for (String oldLine : lstAll) {
            if (oldLine.startsWith( Id )) {
                newLst.add(newRecord);
            }else{
                newLst.add(oldLine);
            }
        }
        
        if (newLst.size() > 0) {
            this.writeTo(newLst.get(0)+System.lineSeparator(), StandardOpenOption.TRUNCATE_EXISTING, StandardOpenOption.CREATE);
            for (int i = 1; i < newLst.size(); i++) {
                this.writeTo(newLst.get(i)+System.lineSeparator(), StandardOpenOption.CREATE, StandardOpenOption.APPEND);
            }
        }
    }
    
    public static void getDetail(){
        
        System.out.println("ID | NAME | PRICE | QUANTITY");
        
        try {

            BufferedReader br = new BufferedReader(new FileReader(FILENAME));

            String line;

            while ((line = br.readLine()) != null) {

                String[] parts = line.split("\\|");

                int i = 0;
                
                
                
                for (String part : parts ) {
                    if (i >= 0){
                        System.out.print(part + " | ");
                        i++;
                    }
                    if (i == 4){
                        System.out.println();
                        i = 0;
                    }
                    
                }
            }

            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    
    public static void stock(){
        mainFunction mf = new mainFunction();
        AssignmentOOPT ass = new AssignmentOOPT();
        Sales sales = new Sales();
        
        System.out.println("========== Stock ========== ");
        
        System.out.println("Enter 1 for Add New Stock");
        System.out.println("Enter 2 for Display Stock");
        System.out.println("Enter 3 for Modify Stock");
        System.out.println("Enter 4 for Delete Stock");
        System.out.println("Enter 5 for Exit To Menu");
        
        System.out.print("Enter the Number : ");
        
        choose = input.nextInt();
        switch(choose){
            case 1 -> {
                sales.clearScreen();
                ass.logo();
                addStock();
            }
            case 2 -> {
                sales.clearScreen();
                ass.logo();
                displayStock();
            }
            case 3 -> {
                sales.clearScreen();
                ass.logo();
                modifyStock();
            }
            case 4 -> {
                sales.clearScreen();
                ass.logo();
                deleteStock();
            }
            case 5 -> {
                exitSystem();
            }
        }
    }
    
    public static void addStock(){
        
        FoodStock newStock = new FoodStock();
        
        System.out.print("Enter the Id of the item : ");
        newStock.setId(input.nextInt());
        System.out.print("Enter the Name of the item : ");
        newStock.setName(input.next());
        System.out.print("Enter the Price of the item (Integer only): ");
        newStock.setPrice(input.nextInt());
        System.out.print("Enter the Quantity of the item (Integer only): ");
        newStock.setQuantity(input.nextInt());
        System.out.println(Id + "|" + Name + "|" + Price + "|" + Quantity);
        newStock.addNew();
        
        stock();
    }
    
    public static void displayStock(){

        getDetail();
        
        stock();
    }
    
    public static void modifyStock(){

        getDetail();
        
        Scanner edt = new Scanner(System.in);
        String edtId;
        System.out.print("Enter the ID of the stock to modify : ");
        edtId = edt.next();
        
        if (edtId != null) {
        
        String delimiter = "[|]";
        
        String filepath = "C:\\Users\\User\\Desktop\\java\\practical 5\\AssignmentOOPT\\src\\main\\java\\com\\mycompany\\assignmentoopt\\FoodStock.txt";
        String tempFile = "C:\\Users\\User\\Desktop\\java\\practical 5\\AssignmentOOPT\\src\\main\\java\\com\\mycompany\\assignmentoopt\\temp_FoodStock.txt";
        File newFile = new File(tempFile);
        File oldFile = new File(filepath);
        
        String currentLine;
        String data[];
        
        try{
            
            FileWriter fw = new FileWriter(tempFile);
            BufferedWriter bw = new BufferedWriter(fw);
            PrintWriter pw = new PrintWriter(bw);
            
            FileReader fr = new FileReader(filepath);
            BufferedReader br = new BufferedReader(fr);
            
            while((currentLine = br.readLine()) != null){
                data = currentLine.split(delimiter);
                System.out.println(data[0]);
                if(!(data[0].equalsIgnoreCase(edtId))){
                    pw.println(currentLine);
                }
            }
            
            pw.flush();
            pw.close();
            fr.close();
            br.close();
            bw.close();
            fw.close();
            
            oldFile.delete();
            File dump = new File(filepath); 
            newFile.renameTo(dump);
        }catch(Exception e){
            
        }
        
        addStock();
        
        } else {
            System.out.println("Invalid Input... Please try again..!");
        }

    }
    
    public static void deleteStock(){
        
        getDetail();
        
        Scanner dlt = new Scanner(System.in);
        String dltId;
        System.out.print("Enter the ID of the stock to delete : ");
        dltId = dlt.next();
        
        if (dltId != null) {
        
        String delimiter = "[|]";
        
        String filepath = "C:\\Users\\User\\Desktop\\java\\practical 5\\AssignmentOOPT\\src\\main\\java\\com\\mycompany\\assignmentoopt\\FoodStock.txt";
        String tempFile = "C:\\Users\\User\\Desktop\\java\\practical 5\\AssignmentOOPT\\src\\main\\java\\com\\mycompany\\assignmentoopt\\temp.txt";
        File newFile = new File(tempFile);
        File oldFile = new File(filepath);
        
        String currentLine;
        String data[];
        
        try{
            
            FileWriter fw = new FileWriter(tempFile);
            BufferedWriter bw = new BufferedWriter(fw);
            PrintWriter pw = new PrintWriter(bw);
            
            FileReader fr = new FileReader(filepath);
            BufferedReader br = new BufferedReader(fr);
            
            while((currentLine = br.readLine()) != null){
                data = currentLine.split(delimiter);
                System.out.println(data[0]);
                if(!(data[0].equalsIgnoreCase(dltId))){
                    pw.println(currentLine);
                }
            }
            
            pw.flush();
            pw.close();
            fr.close();
            br.close();
            bw.close();
            fw.close();
            
            oldFile.delete();
            File dump = new File(filepath); 
            newFile.renameTo(dump);
        }catch(Exception e){
            
        }
        }
        getDetail();
        
        stock();
    }
    
    private static void exitSystem() {
        Scanner exitNum = new Scanner(System.in);
        mainFunction mf = new mainFunction();
        AssignmentOOPT ass = new AssignmentOOPT();
        Sales sales = new Sales();
        sales.clearScreen();
        ass.logo();
        System.out.print("Do You Want Go the Menu?[Y/N] >");
        String yesNo = exitNum.next();
        switch (yesNo) {
            case "y", "Y" -> {
                try {
                    mf.menu();
                } catch (IOException ex) {
                    Logger.getLogger(FoodStock.class.getName()).log(Level.SEVERE, null, ex);
                }
            }

            case "n", "N" -> {
                stock();
            }
            default -> {
                System.out.println("Invalid Input... Please try again..!");
                exitSystem();
            }
        }
    }
    
    public static void main(String[] args) {
        stock();
    }
}
