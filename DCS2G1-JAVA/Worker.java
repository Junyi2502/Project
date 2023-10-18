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
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.ArrayList;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Worker {
    public static ArrayList<Staff> staffArray = new ArrayList<Staff>();
    public static ArrayList<Member> memberArray = new ArrayList<Member>();
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
   
    }
    public void memberMain() throws IOException{
        // TODO code application logic here
        Scanner sc = new Scanner(System.in);
        Sales sales = new Sales();
        mainFunction mf = new mainFunction();
        AssignmentOOPT ass = new AssignmentOOPT();
        
        for (ArrayList<String> a : Util.readCSV("src/main/java/com/mycompany/assignmentoopt/user.txt")) {
            System.out.println(a.get(0));
        }

        while (true) {
            System.out.println("**********MAIN MENU**********");
            System.out.println("|   1. Staff Management     |");
            System.out.println("|   2. Member Management    |");
            System.out.println("|   3. Exit                 |");
            System.out.println("*****************************");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    sales.clearScreen();
                    ass.logo();
                    staffMenu();
                    break;
                case 2:
                    sales.clearScreen();
                    ass.logo();
                    memberMenu();
                    break;
                case 3:
                    sales.clearScreen();
                    ass.logo();
                    System.out.println("Exiting the program.");
                    mf.menu();
                default:
                    System.out.println("Invalid choice. Please Try Again.");
            }
        }
    }

    public void staffMenu() throws IOException {
        Scanner sc = new Scanner(System.in);
        Sales sales = new Sales();
        AssignmentOOPT ass = new AssignmentOOPT();

        while (true) {
            System.out.println("**********STAFF MENU**********");
            System.out.println("|   1. Add Staff             |");
            System.out.println("|   2. Search Staff          |");
            System.out.println("|   3. Delete Staff          |");
            System.out.println("|   4. Back to Main Menu     |");
            System.out.println("******************************");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    sales.clearScreen();
                    ass.logo();
                    addStaff();
                    break;
                case 2:
                    sales.clearScreen();
                    ass.logo();
                    searchStaff();
                    break;
                case 3:
                    sales.clearScreen();
                    ass.logo();
                    deleteStaff();
                    break;
                case 4:
                    sales.clearScreen();
                    ass.logo();
                    memberMain(); // Return to the main menu
                default:
                    System.out.println("Invalid choice. Please Try Again.");
            }
        }
    }

    public void memberMenu() throws IOException {
        Scanner sc = new Scanner(System.in);
        Sales sales = new Sales();
        AssignmentOOPT ass = new AssignmentOOPT();

        while (true) {
            System.out.println("**********MEMBER MENU**********");
            System.out.println("|   1. Add Member            |");
            System.out.println("|   2. Search Member         |");
            System.out.println("|   3. Delete Member         |");
            System.out.println("|   4. Back to Main Menu     |");
            System.out.println("*******************************");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();

            switch (choice) {
                case 1:
                    sales.clearScreen();
                    ass.logo();
                    addMember();
                    break;
                case 2:
                    sales.clearScreen();
                    ass.logo();
                    searchMember();
                    break;
                case 3:
                    sales.clearScreen();
                    ass.logo();
                    deleteMember();
                    break;
                case 4:
                    sales.clearScreen();
                    ass.logo();
                    memberMain(); // Return to the main menu
                default:
                    System.out.println("Invalid choice. Please Try Again.");
            }
        }
    }

    public void addStaffForm() throws IOException{
        String newID;
        String newName;
        String newPosition;
        String newContactNo;
        int age;
        char gender;
        String newPassword;

        String prompt = "Enter New ID: ";
        newID = validateStaffIDFormat(prompt);

        String promptName = "Enter New Name: ";
        newName = isValidName(promptName);

        String promptPosition = "Enter New Position : ";
        newPosition = isValidString(promptPosition);

        String promptAge = "Enter Age: ";
        age = isValidAge(promptAge);

        String promptGender = ("Enter Gender (M or F) : ");
        gender = isValidGender(promptGender);

        String promptContactNo = "Enter New Contact Number: ";
        newContactNo = isValidContactNo(promptContactNo);

        String promptPassword = ("Enter New Password : ");
        newPassword = isValidString(promptPassword);

        Staff newStaff = new Staff(newID, newName, newPosition, age, newContactNo, gender, newPassword);
        staffArray.add(newStaff);

        fileStore(newStaff);
        System.out.println("Staff Record Added Successfully!\n");
    }

    public void addStaff() throws IOException {
        Sales sales = new Sales();
        addStaffForm();
        
        // Ask if the user wants to add another staff member
        System.out.print("Do you want to add another staff? (yes/no): ");
        String addAnother = scanner.next().toLowerCase();
        
        if("Y".equals(addAnother)){
            sales.clearScreen();
            addStaff();
              
        }
        else if ("N".equals(addAnother)){
            sales.clearScreen();
            staffMenu();
        }
        else{
            sales.clearScreen();
            staffMenu();
        }
            
    }

    private void searchStaff() {
        Scanner sc = new Scanner(System.in);
        Staff staff = new Staff();
        System.out.print("Enter Staff ID to search: ");
        String searchID = sc.nextLine();
        
        readFiles(staff,searchID);

//        boolean found = false;
//
//        System.out.println("=======================================================================================");
//        System.out.printf("%-8s%-20s%-15s%-15s%-15s%-20s","StaffID", "StaffName","Position","Age","Gender","Contact Number");
//        System.out.println("=======================================================================================");
//
//        for (int i = 0; i < staffArray.size(); i++) {
//            Staff staff = staffArray.get(i);
//            if (staff.getStaffID().equalsIgnoreCase(searchID)) {
//                System.out.printf("%-8s%-20s%-15s%-15s%-15s%-20s\n",
//                i + 1, staff.getStaffID(), staff.getStaffName(), 
//                staff.getStaffPosition(), staff.getStaffContactNo(), 
//                staff.getStaffAge(), staff.getStaffGender());
//                found = true;
//            }
//        }
//        if (!found) {
//            System.out.println("No Staff with ID " + searchID + " found.");
//        }
    }

    private void deleteStaff() {
        Staff staff = new Staff();
        System.out.print("Please Enter The Staff ID That You Need To Delete : ");
        String staffID = scanner.nextLine();
        
        delete(staffID,staff);
        
//        Staff selected = (Staff) Util.objectSelection(staffArray);
//
//        if (selected != null) {
//            staffArray.remove(selected);
//            System.out.println("Staff with ID " + selected.getStaffID() + " deleted.");
//        }
//
//        System.out.println("No Staff Selected");
    }

    private void addMember() throws IOException {
        Sales sales = new Sales();
        AssignmentOOPT ass = new AssignmentOOPT();
        String newID;
        String newName;
        String newContactNo;
        int age;
        char gender;

        String promptId = "Enter New ID: ";
        newID = verifyMemberID(promptId);

        String promptName = "Enter New Name: ";
        newName = isValidName(promptName);

        String promptAge = "Enter Age: ";
        age = isValidAge(promptAge);

        String promptGender = ("Enter Gender (M or F) : ");
        gender = isValidGender(promptGender);

        String promptContactNo = "Enter New Contact Number: ";
        newContactNo = isValidContactNo(promptContactNo);

        Member newMember = new Member(newID, newName, age, gender, newContactNo);
        memberArray.add(newMember);
        
        System.out.println("Member Record Added Successfully!\n");
        fileStore1(newMember);
        
        // Ask if the user wants to add another member
        System.out.print("Do you want to add another member? (yes/no): ");
        String addAnother = scanner.next().toLowerCase();
        
         if("Y".equals(addAnother)){
            sales.clearScreen();
            ass.logo();
            addMember();
              
        }
        else if ("N".equals(addAnother)){
            sales.clearScreen();
            ass.logo();
            memberMenu();
        }
        else{
            sales.clearScreen();
            ass.logo();
            memberMenu();
        }
    }

    private void searchMember() {
        
        Scanner sc = new Scanner(System.in);
        Member member = new Member();
        System.out.print("Enter Member ID to search: ");
        String searchIDs = sc.nextLine();
        
        readFiles1(member,searchIDs);
//        Scanner sc = new Scanner(System.in);
//        System.out.print("Enter Member ID to search: ");
//        String searchID = sc.next();
//
//        boolean found = false;
//
//        for (int i = 0; i < memberArray.size(); i++) {
//            Member member = memberArray.get(i);
//            if (member.getMemberID().equalsIgnoreCase(searchID)) {
//                System.out.printf("%-8s%-20s%-15s%-15s%-15s%-20s\n",
//                i + 1, member.getMemberID(), member.getMemberName(), member.getMemberContactNo(), 
//                member.getMemberAge(), member.getMemberGender());
//                found = true;
//            }
//        }
//        if (!found) {
//            System.out.println("No Member with ID " + searchID + " found.");
//        }
    }

    private void deleteMember() {
        Member member = new Member();
        Scanner sc = new Scanner(System.in);
        System.out.print("Please Enter The Member ID That You Need To Delete : ");
        String memberID = sc.nextLine();
        
        delete1(memberID,member);
    }

    // Validate Name and ID
    private static String validateStaffIDFormat(String prompt) {
        String staffID;
        String idFormat = "^ST[\\d]{3}";
        while(true){
            System.out.print(prompt);
            staffID = scanner.nextLine();
            if (!staffID.isEmpty() && Character.isUpperCase(staffID.charAt(0)) && staffID.matches(idFormat)){
                break;
            }else {
                System.out.println("Staff ID must consists of uppercase alphabet 'ST' and 3 digit number.\n");
            }
        }
        return staffID;
    }

    private static String isValidName(String prompt) {
        String name;
        String namePattern = "^[A-Za-z\\s\\-]{2,50}$";
        while(true){
            System.out.print(prompt);
            name = scanner.nextLine();
            if(name.matches(namePattern) && !name.isEmpty()){
                break;
            }else {
                System.out.println("Invalid name format. Please enter a valid name.");
            }
        }
        return name;
    }

    private static int isValidAge(String prompt) {
        int age = -1;
        while (true) {
            System.out.print(prompt);
            try{
                age = Integer.parseInt(scanner.nextLine());
                if (age >= 18 && age <= 100) {
                    break;
                }else{
                    System.out.println("Invalid age. Please enter a valid age.");
                }
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Please enter a valid integer age.");
            }
        }
        return age;
    }

    private static char isValidGender(String prompt) {
        char gender;
        while (true) {
            System.out.print(prompt);
            String input = scanner.nextLine().trim(); // Trim to remove leading/trailing whitespace
            if (!input.isEmpty()) {
                gender = Character.toUpperCase(input.charAt(0));
                if (gender == 'M' || gender == 'F') {
                    break;
                }
            }
            System.out.println("Please enter a valid gender (M or F)!");
        }
        return gender;
    }

    private static String isValidString(String prompt) {
        String input;
        while (true) {
            System.out.print(prompt);
            input = scanner.nextLine();
            if (!input.isEmpty()) {
                break;
            }
            System.out.println("Please enter a valid input!");
        }
        return input;
    }

    private static String isValidContactNo(String prompt) {
        String contactNo;
        String contactNoPattern = "\\d{3}-\\d{7,}";
        while(true){
            System.out.print(prompt);
            contactNo = scanner.nextLine();
            if(contactNo.matches(contactNoPattern) && !contactNo.isEmpty()){
                break;
            }else {
                System.out.println("Invalid contact number format. Please enter a valid format (e.g., 123-1234567).");
            }
        }
        return contactNo;
    }

    private static String verifyMemberID(String prompt) {
        String idFormat = "^MEM[\\d]{3}";
        String memberID;

        while(true){
            System.out.print(prompt);
            memberID = scanner.nextLine();
            if (!memberID.isEmpty() && Character.isUpperCase(memberID.charAt(0)) && memberID.matches(idFormat)){
                break;
            }else {
                System.out.println("Member ID must consists of uppercase alphabet 'MEM' and 3 digit number.\n");
            }
        }
        return memberID;
    }
    
        public boolean fileExists(String filePath){
            File file = new File(filePath);
            return file.exists();
        }
    
     public void fileStore(Staff staff){


        if (!fileExists("staff.txt")) {
            try {
                FileWriter writer = new FileWriter("staff.txt");
                writer.close();
            } catch (IOException e) {
                System.err.println("Error crea11ting the file: " + e.getMessage());
            }
        }  

        try (FileWriter writer = new FileWriter("staff.txt", true)) {
            writer.write(staff.getStaffID() + "\t");
            writer.write(staff.getStaffName()+ "\t");
            writer.write(staff.getStaffAge()+ "\t");
            writer.write(staff.getStaffPosition()+ "\t");
            writer.write(staff.getStaffGender()+ "\t");
            writer.write(staff.getStaffContactNo() + "\t");
            writer.write(staff.getPassword() + "\t");
            writer.write("\n");
            writer.close();
        } catch (IOException e) {
            System.err.println("Error writing to the file: " + e.getMessage());
        }
    }
     
      public void fileStore1(Member member){


        if (!fileExists("member.txt")) {
            try {
                FileWriter writer = new FileWriter("member.txt");
                writer.close();
            } catch (IOException e) {
                System.err.println("Error crea11ting the file: " + e.getMessage());
            }
        }  

        try (FileWriter writer = new FileWriter("member.txt", true)) {
            writer.write(member.getMemberID() + "\t");
            writer.write(member.getMemberName()+ "\t");
            writer.write(member.getMemberAge()+ "\t");
            writer.write(member.getMemberGender()+ "\t");
            writer.write(member.getMemberContactNo() + "\t");
            writer.write("\n");
            writer.close();
        } catch (IOException e) {
            System.err.println("Error writing to the file: " + e.getMessage());
        }
    }

    public void readFiles(Staff staff, String searchID) {
        boolean found = false; // Flag to track if a matching staff ID is found

        try (Scanner sc = new Scanner(new File("staff.txt"))) {
            while (sc.hasNextLine()) {
                String staffLine = sc.nextLine(); // Read the entire line

                String[] staffDetails = staffLine.split("\t");// Extract individual staff details

                if (staffDetails.length == 7) {
                    staff.staffID = staffDetails[0];
                    staff.staffName = staffDetails[1];
                    staff.staffAge = Integer.parseInt(staffDetails[2]);
                    staff.staffPosition = staffDetails[3];
                    staff.staffGender = staffDetails[4].charAt(0);
                    staff.staffContactNo = staffDetails[5];
                    staff.password = staffDetails[6];
                }

                if (staff.staffID.equals(searchID)) {
                    System.out.println("=======================================================================================");
                    System.out.printf("%-8s%-20s%-15s%-15s%-15s%-20s","ID", "StaffName","Age","Position","Gender","Contact Number");
                    System.out.println("\n=======================================================================================");
                    System.out.printf("%-8s%-20s%-15s%-15s%-15s%-20s\n", staff.staffID, staff.staffName, staff.staffAge, staff.staffPosition, staff.staffGender, staff.staffContactNo);
                    staff.setPassword(staff.password);
                    found = true; // Set the flag to indicate a match was found
                    break;
                }
            }

            if (!found) {
                System.out.println("Staff not found.");
            }

        } catch (FileNotFoundException e) {
            System.err.println("Error reading the staff file.");
        }
    }


    public void readFiles1(Member member, String searchID) {
        boolean found = false;

        try (Scanner sc = new Scanner(new File("member.txt"))) {
            while (sc.hasNextLine()) {
                String memberLine = sc.nextLine(); // Read the entire line

                String[] memberDetails = memberLine.split("\t");// Extract individual member details

                if (memberDetails.length == 5) {
                    member.memberID = memberDetails[0];
                    member.memberName = memberDetails[1];
                    member.memberAge = Integer.parseInt(memberDetails[2]);
                    member.memberGender = memberDetails[3].charAt(0);
                    member.memberContactNo = memberDetails[4];
                }

                if (member.memberID.equals(searchID)) {
                    found = true;
                    break;
                }
            }

            if (found) {
                System.out.println("=======================================================================================");
                System.out.printf("%-8s%-20s%-15s%-15s%-15s\n","ID", "MemberName","Age","Gender","Contact Number");
                System.out.println("=======================================================================================");
                System.out.printf("%-8s%-20s%-15s%-15s%-15s\n",member.memberID,member.memberName,member.memberAge, member.memberGender,member.memberContactNo);
            } else {
                System.out.println("Member not found.");
            }
        } catch (FileNotFoundException e) {
            System.err.println("Error reading the member file.");
        }
    }

    public void delete(String staffToDelete, Staff staff) {

    
    try {
        File inputFile = new File("staff.txt");
        File tempFile = new File("temp_staff.txt");

        boolean found = false;
        String staffIDToDelete = null;

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile));
             BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile))) {

            String line;
            
            while ((line = reader.readLine()) != null) {
                String[] staffDetails = line.split("\t");
                
                if (staffDetails.length == 7) {
                    staff.staffID = staffDetails[0];
                    
                    if (staff.staffID.equals(staffToDelete)) {
                        staffIDToDelete = staffDetails[0]; // Store the staff ID to delete
                        System.out.println("Staff Remove Successful !!!");
                        found = true;
                        continue;
                    }
                }
                writer.write(line + System.getProperty("line.separator"));
            }
        }

        if (!found) {
            System.out.println("Delete Staff Unsuccessful !!! ");
        }

        if (!inputFile.delete()) {
            System.out.println("Could not delete the original file.");
        }

        if (!tempFile.renameTo(inputFile)) {
            System.out.println("Could not rename the temporary file.");
        }
    } catch (FileNotFoundException e) {
        System.err.println("Error reading the staff file.");
    } catch (IOException e) {
        System.err.println("Error while processing the file.");
    }
} 
  
  public void delete1(String memberToDelete, Member member) {

    
    try {
        File inputFile = new File("member.txt");
        File tempFile = new File("temp_member.txt");

        boolean found = false;
        String memberIDToDelete = null;

        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile));
             BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile))) {

            String line;
            
            while ((line = reader.readLine()) != null) {
                String[] memberDetails = line.split("\t");
                
                if (memberDetails.length == 5) {
                    member.memberID = memberDetails[0];
                    
                    if (member.memberID.equals(memberToDelete)) {
                        memberIDToDelete = memberDetails[0]; // Store the staff ID to delete
                        System.out.println("Item Remove Successful !!!");
                        found = true;
                        continue;
                    }
                }
                writer.write(line + System.getProperty("line.separator"));
            }
        }

        if (!found) {
            System.out.println("Delete Item Unsuccessful !!! ");
        }

        if (!inputFile.delete()) {
            System.out.println("Could not delete the original file.");
        }

        if (!tempFile.renameTo(inputFile)) {
            System.out.println("Could not rename the temporary file.");
        }
    } catch (FileNotFoundException e) {
        System.err.println("Error reading the staff file.");
    } catch (IOException e) {
        System.err.println("Error while processing the file.");
    }
} 
  
   public void addStaffLogin() throws IOException {
        Sales sales = new Sales();
        addStaffForm();
        
        mainFunction mf = new mainFunction();
        
        sales.clearScreen();
        mf.login();
 
    }
}








