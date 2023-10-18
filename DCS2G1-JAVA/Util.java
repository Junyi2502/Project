/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package com.mycompany.assignmentoopt;

/**
 *
 * @author huifa
 */
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author huifa
 */
public class Util {
    public static int ROWS_TO_SHOW = 10;
    public static Selectable objectSelection(ArrayList<? extends Selectable> objectList) {
        Scanner sc = new Scanner(System.in);
        
        int selection = 0;
        int itemIndex = -1;
        
        for(int i = 0; i < objectList.size(); i+=ROWS_TO_SHOW){
            Selectable obj = objectList.get(0);
            
            for (int j = i; j < i + ROWS_TO_SHOW; j++)
            {
                if(j >= objectList.size())
                    break;
                
                System.out.println(objectList.get(j).toString());
            }                        
            boolean validSelection = false;
            do
            {
                System.out.printf("Enter selection (1 - 10), 11 for next page, 0 to exit: ");
                selection = sc.nextInt();
                
                if (selection == 11) //next input
                    break;
                
                else if (selection == 0){   //exit
                    validSelection = true;
                    break;
                }
                    
                
                if (selection < 1 || selection > 10)
                {
                    System.out.println("Enter number within range\n");
                }
                else
                {
                    validSelection = true;
                    itemIndex = i + selection - 1;
                }
                
            }while(!validSelection);
            
            if(validSelection == true)
                break;
        }
        
        if (selection != 0)
            return objectList.get(itemIndex);
        else
            return null;
    }
    
    public static ArrayList<String> readFile(String path){
        
        try{
            File fileObject = new File(path);
            Scanner file = new Scanner(fileObject);

            ArrayList<String>fileArr = new ArrayList<>();

            while(file.hasNextLine()){
                fileArr.add(file.nextLine());
            }

            file.close();
            return fileArr;
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
        
        return null;
    }
    
    public static ArrayList<ArrayList<String>> readCSV(String path) {
        ArrayList<String>fileArr = readFile(path);
        
        ArrayList<ArrayList<String>> output = new ArrayList<>();
        for(String line : fileArr){
            String[] splitLine = line.split(",");
            ArrayList<String> arrayListLine = new ArrayList<String>(Arrays.asList(splitLine));
                    
            output.add(arrayListLine);
        }
        
        return output;
    }
}

