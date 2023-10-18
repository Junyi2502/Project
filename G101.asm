.model small
.stack 100
.data

a db "========================================================$"
b db "======================= Welcome ========================$"
c db "============= Health Lane Family Pharmacy ==============$"
d db "========================================================$"
e db 10,13,"	Pls Select 1 - 4 to Choose the Function : $"
f db "	1: Login Member $"
g db "	2: Register Member $"
h db "	3: Continue With Guest $"
i db "	4: Quit The Program $"
j db 10,13,"	Enter 1-4 : $"
k db 10,13,"        Pls Enter Your Member ID : $"
l db 10,13,"        Pls Enter Your PassWord : $"
m db 10,13,"        Member ID Wrong !!! $"
n db 10,13,10,13,"        Welcome Back !!!$"
o db 10,13,"        Member Password Wrong !!! $"
p db 10,13,"       Member Register : ",10,13,10,13,"       Pls Insert Your User Name(Only 5 Character/@ Back To Nenu) : $" 
q1 db 10,13,10,13,"       Pls Insert Your Phone Number : $" 
r4 db 10,13,"        Reg Wrong Phone Num $"
s db 10,13,10,13,"       Pls Enter Your IC Number : $" 
t db 10,13,10,13,"      Pls Enter Correct IC Number !!! $"
t2 db 10,13,10,13,"       Pls Enter Your Password(5 Words) : $"
u db 10,13,10,13,"        Register Success !!! $" 
v db 10,13,10,13,"      User ID : $"
w db 10,13,10,13,"      User Phone Number : $"
x db 10,13,10,13,"      User IC Number : $" 
y db 10,13,10,13,"      Comfirm Register ? [Yes(Y)/No(N)/Back To Menu(@)] : $"
z db 10,13,10,13,"      Only Enter Y / N / X : $" 
                           

a2 db 10,13,"      Pls Choose The 1 - 3 : ",10,13,10,13,"      1.Go To Shop",10,13,"      2.Check Membership Time Limit",10,13,"      3.Log Out ",10,13,10,13,"      Pls Enter Your Choose : $"
           
b1 db 10,13,10,13,"      Member Expire Day : $" 
b2 db 10,13,10,13,"     Do You Want To Extend Membership? [Yes(Y)/No(N)/Exit(X)] : $"          
           
year1 db '0$'
day1 db '240$'

year2 db 1
yearn db " Years $"
day2 db '0$'
dayn db " Days $" 

enter db 10,13,10,13,"        Enter Any Key To Continue...$" 
entervar db ?

newline db 10
choose db ? 
choose1 db ? 
memberfee db 0
memid db 5 dup (0)
mempass db 5 dup (0)
regmemid db '1','2','3','4','5'
regmempass db '1','2','3','4','5' 
regname db 5 dup (0)
regpn db 11 dup (0)
regic db 12 dup (0) 
regpass db 5 dup (0)
yon db ?
members db ? 
memextend db ?
member1pn db 0,1,1,2,0,7,8,5,8,5,1 
member1ic db 0,3,0,2,2,5,0,1,2,2,2,2

;cart-------------------------------------------------------------------------------------------
;error msg                                                                                
errormsg db 13,10,"                      Error input! Please re-enter again"
         db 13,10,"================================================================================$"
                                                                             
;menu desgin
dlogo db 13,10,"    _____         _ _   _      __                   _____           _ _       "
      db 13,10,"   |  |  |___ ___| | |_| |_   |  |   ___ ___ ___   |   __|___ _____|_| |_ _   "
      db 13,10,"   |     | -_| .'| |  _|   |  |  |__| .'|   | -_|  |   __| .'|     | | | | |  "
      db 13,10,"   |__|__|___|__,|_|_| |_|_|  |_____|__,|_|_|___|  |__|  |__,|_|_|_|_|_|_  |  "
      db 13,10,"                                                                       |___|  "  
      db 13,10,"                                                                               $"
     
;medicine menu
dmenu db 13,10,"                       ================================"
      db 13,10,"                      |         Medicine Menu          |" 
      db 13,10,"                       ================================"  
      db 13,10,"                      |  1.Tablet medicine             |" 
      db 13,10,"                      |  2.Liquid medicine             |"
      db 13,10,"                      |  3.Others                      |"
      db 13,10,"                      |  4.Cart list                   |" 
      db 13,10,"                      |  5.Back to member menu         |"
      db 13,10,"                       ================================"
      db 13,10,"                       Enter your option (1 to 5 only): $" 
      
;tablet medicine                                                                           
dtablet db 13,10,"                  ============================================"
        db 13,10,"                 |         Item                  |  Price(RM) |" 
        db 13,10,"                  ============================================"
        db 13,10,"                 |  1.Panadol                    |  RM15.00   |"
        db 13,10,"                 |  2.Stomach medicine           |  RM20.00   |" 
        db 13,10,"                 |  3.Berocca                    |  RM20.00   |" 
        db 13,10,"                  --------------------------------------------"
        db 13,10,"                 |  4.Exit and back to medicine menu          |"
        db 13,10,"                  ============================================"
        db 13,10,"                    Enter your option (1 to 4 only): $"  
                               
;liquid medicine                                  
dliquid db 13,10,"                  ============================================"
        db 13,10,"                 |         Item                  |  Price(RM) |" 
        db 13,10,"                  ============================================"
        db 13,10,"                 |  1.Cough syrup                |  RM10.00   |"
        db 13,10,"                 |  2.Cold potion                |  RM15.00   |" 
        db 13,10,"                 |  3.Fever potion               |  RM15.00   |" 
        db 13,10,"                  --------------------------------------------"
        db 13,10,"                 |  4.Exit and back to medicine menu          |"
        db 13,10,"                  ============================================"
        db 13,10,"                    Enter your option (1 to 4 only): $"
       
;others
dothers db 13,10,"                  ============================================"
        db 13,10,"                 |         Item                  |  Price(RM) |" 
        db 13,10,"                  ============================================"
        db 13,10,"                 |  1.Medical cotton             |  RM10.00   |"
        db 13,10,"                 |  2.Bandage                    |  RM10.00   |" 
        db 13,10,"                 |  3.Toothpaste                 |  RM15.00   |" 
        db 13,10,"                  --------------------------------------------"
        db 13,10,"                 |  4.Exit and back to medicine menu          |"
        db 13,10,"                  ============================================"        
        db 13,10,"                    Enter your option (1 to 4 only): $"   

;all item 
item1   db 13,10,"     |  1.Panadol                  |     $"
item2   db 13,10,"     |  2.Stomach medicine         |     $"
item3   db 13,10,"     |  3.Berocca                  |     $"
item4   db 13,10,"     |  4.Cough syrup              |     $"
item5   db 13,10,"     |  5.Cold potion              |     $"
item6   db 13,10,"     |  6.Fever potion             |     $"
item7   db 13,10,"     |  7.Medical cotton           |     $"
item8   db 13,10,"     |  8.Bandage                  |     $"
item9   db 13,10,"     |  9.Toothpaste               |     $" 
allitem dw item1,item2,item3,item4,item5,item6,item7,item8,item9

;cart list design         
dlist    db 13,10,"                                   CART LIST "
         db 13,10,"      ======================================================================"  
         db 13,10,"     |         Item                |  Quantity  |  Price(RM)  |  Total(RM)  |" 
         db 13,10,"      ======================================================================$"
blank    db "      |     $"
blank1   db "   |$"
blank2   db "   |    $"
blank3   db "     |     $"        
dlist1   db 13,10,"      ----------------------------------------------------------------------$"
printsub db 13,10,"     |                                          |  Subtotal:  |  RM$"   
dlist2   db 13,10,"      ----------------------------------------------------------------------$"
        
;item price  
price        dw 15,20,20,10,15,15,10,10,15
pricedp      db ".00$" 

;total price and decimal digit 
total        dw 9 dup (0) 
cancelttl    dw 9 dup (0)
subtotal     dw ?
showtotal    db 13,10,"                    Total cost: RM$"  
ten          db 10 
hundred      dw 100
quotient     db ?
remainder    db ?
remainder2   db ?
            
;quantity
qty          dw 9 dup (0)   
cancelqty    dw 9 dup (0)
enterqty     db 13,10,"                 Enter the quantity you want(1 to 9 only): $"                                                        
showqty      db 13,10,"                    The quantity is $"
chckqty      db ?    
noqty        dw ?                      

;exit
exit1        db 13,10,"                                Thank you.$"

;ask user comfirm
comfirm       db 13,10,"                 Do you want to add to cart(y/n): $"  
addorder      db 13,10,"                 Do you want to order other item?(y/n): $" 
addcartunsuc  db 13,10,"                        Add cart unsuccessful!!$"
addcartsuc    db 13,10,"                         Add cart successful!! $" 
completeorder db 13,10,"                  Complete the order?(y/n/0 back to menu): $" 
clearitem     db 13,10,"                          Want to delete item?(y/n): $"        
deletewhat    db 13,10,"                   What item you want to delete(1 to 9 only): $ " 
deletesucc    db 13,10,"                           Delete item successful!$"   
noitemdlt     db 13,10,"                             No have item that in cart$"
emptylist     db 13,10,"     |                           CART IS EMPTY NOW!!                        |$"
otherkey      db 13,10,13,10,"                             PRESS ANY KEY TO CONTINUE$"
     
;payment-------------------------------------------------------------------------------------------------------
mm db 10,13, "m$"

;payment list
list db 10,13, "  "
     db 10,13, "                ================================================     "
     db 10,13, "               |                  Payment List                   |    "
     db 10,13, "                ================================================     "
     db 10,13, "  $"
     
;choice
c1  db ?
c2  db ?  
c3  db ? 
c4  db ? 
 
discount1 dw 5
discount2 dw 100 
discountRM dw ? 
discountRM1 db ?  
discountRM2 db ? 
discountSen dw 0
discountSen1 db ?
discountSen2 db ? 
deliveryfee dw ? 
packagefee dw 4  
sen dw 0 
sen2 db 0 
q db ? ;quotient
r db ? ;remainder
rd db ? ;remainder

;cash 
cash1   db 10,13, "               |------------------------------------------------|    " 
        db 10,13, "               |                                                |    "
        db 10,13, "               |              * Cash on delivery *              |    "
        db 10,13, "               |                                                |    " 
        db 10,13, "                ================================================    $"

        
;card
card1   db 10,13, "               |------------------------------------------------|    " 
        db 10,13, "               |                                                |    "
        db 10,13, "               |                     * Card *                   |    "
        db 10,13, "               |                                                |    " 
        db 10,13, "                ================================================    $" 
        
;online 

online1 db 10,13, "               |------------------------------------------------|    " 
        db 10,13, "               |                                                |    "
        db 10,13, "               |                * Online banking *              |    "
        db 10,13, "               |                                                |    " 
        db 10,13, "                ================================================    $" 

;total amount
t1 db 10,13, "                            Total Amount : $" 

;error message
e1 db 10,13, "                This Input is invalid ! Enter only (Y/N)! " 
   db 10,13, " "
   db 10,13, "                $"  
e2 db 10,13, "                   This Input is invalid ! Enter only (1 - 2)! "  
   db 10,13, " "
   db 10,13, "                $" 
e3 db 10,13, "                   This Input is invalid ! Enter only (1 - 4)! "
   db 10,13, " "
   db 10,13, "                $"
e4 db 10,13, "                    This Input is invalid ! Enter only (Y/N)! " 
   db 10,13, " "
   db 10,13, "                $"   


;member?  
m1 db 10,13, "                You are a member $"
m2 db 10,13, "                You are not a member$"
m5 db 10,13, "                Are you a member? (Y/N): $"
m3 db 10,13, " "
   db 10,13, "                Member Discount: 5%"
   db 10,13, " "  
   db 10,13, "                Discount price : $" 
  

;delivery   
d1 db 10,13, "  "
   db 10,13, "                ================================================     "
   db 10,13, "               |                     Delivery                   |    "
   db 10,13, "               |================================================|    "
   db 10,13, "               |          Where to you want to delivery?        |    "
   db 10,13, "               |                                                |    "
   db 10,13, "               |               1.Malaysia - RM5                 |    "
   db 10,13, "               |               2.Overseas - RM20                |    "
   db 10,13, "               |------------------------------------------------|    "
   db 10,13, "                               >$                                    "
d2 db 10,13, "               |------------------------------------------------|    "
   db 10,13, "               |                                                |    "
   db 10,13, "               |           * Deliver to Malaysia. *             |    "
   db 10,13, "               |                                                |   $"
d3 db 10,13, "               |------------------------------------------------|    "
   db 10,13, "               |           * Deliver to overseas. *             |    "
   db 10,13, "               |                                                |   $"
   
;packagefee                                                               
package1 db 10,13, "               |                Pakage Fee : RM4                 |   "
         db 10,13, "               |      * (Members enjoy free pakage fees) *      |   "
         db 10,13, "               |                                                |   "
         db 10,13, "                ================================================   $"

;payment
p1 db 10,13, "  "
   db 10,13, "                ================================================     "
   db 10,13, "               |                   Payment                      |    "
   db 10,13, "               |================================================|     "
   db 10,13, "               |       Which payment method do you prefer?      |     "
   db 10,13, "               |                                                |     "
   db 10,13, "               |               1.Cash on Delivery               |     "
   db 10,13, "               |               2.Card                           |     "
   db 10,13, "               |               3.Online Banking                 |     "
   db 10,13, "               |               4.Cancel                         |     " 
   db 10,13, "               |                                                |     "
   db 10,13, "               |------------------------------------------------|     " 
   db 10,13, "                               >$" 
p2 db 10,13, "                         Plese Enter the card information                  "  ;=====
   db 10,13, "               ----------------------------------------------------        "
   db 10,13, "               Card number (x for exit) :$   " 
p3 db 10,13, "               Name of card :$  "
p4 db 10,13, "               Expiry date [YY(Year)MM(Month)] :$   "
p5 db 10,13, "               Security code :$ "
p6  db 10,13, "                   Plese Enter the online banking information            "    ;=====
   db 10,13, "               ----------------------------------------------------       "
   db 10,13, "               User ID :$    " 
p7 db 10,13, "               Password :$ " 
   
   
    
;cancel
cancel1 db 10,13, "  "
        db 10,13, "                    Are you want to cancel the order? (Y/N): $ "  

;receipt
r1 db 10,13, "                     Health Lane Family Pharmacy      "
   db 10,13, "                        Adress:1,JALAN CXK            "   
   db 10,13, "                         Tel:012-3456789 $            " 
r2 db 10,13, "               **************************************$"
r3 db 10,13, " "
   db 10,13, "                             THANK YOU!              $"   
   
cardNum db 16 dup (0)
cardDate db 4 dup (0) 

errorcard db 10,13,"         Error Card Number!!! Pls Enter Again !!! $"
errordate db 10,13,"         Expiry Card Date !!! Pls Change A Card $" 

onlinebank db 10,13,"        Jumping To The Banking Scane !!!$" 
     
.code
main proc
mov ax,@data
mov ds,ax

menu:
	call clr

	mov ah,09       ;print logo
    lea dx,dlogo
    int 21h   


	mov ah,02h
	mov dl,newline
	int 21h

	mov ah,09h	;print main page
	lea dx,e
	int 21h

	mov ah,02h
	mov dl,newline
	int 21h

	mov ah,09h
	lea dx,f
	int 21h

	mov ah,02h
	mov dl,newline
	int 21h

	mov ah,09h
	lea dx,g
	int 21h

	mov ah,02h
	mov dl,newline
	int 21h

	mov ah,09h
	lea dx,h
	int 21h

	mov ah,02h
	mov dl,newline
	int 21h

	mov ah,09h
	lea dx,i
	int 21h

	mov ah,02h
	mov dl,newline
	int 21h

	mov ah,09h
	lea dx,j
	int 21h    
    
	mov ah,01h
	int 21h     
	

	
	cmp al,'1'	;go login
	je member 


	cmp al,'2' 	;go register
	je memberre_1
	
	cmp al,'3'	;go cart
	mov members,9
	je  menu_cart_1 
	             
	cmp al,'4' 	;end program
	je progressend             
	
	jne menu_0   
			
	mov ah,02h
	mov dl,newline
	int 21h

	menu_0:
	jmp menu

	menu_cart_1:
	call clr
	jmp menu_cart
	 
	    
  
member:
	call clr 
	
	mov ah,09    
    	lea dx,dlogo
    	int 21h 

	mov ah,02h
	mov dl,newline
	int 21h
	
	mov ah,09h
	lea dx,k
	int 21h
	
	    
	mov cx,5
	mov si,0
	     
	input_loop_id:  ;read id
	     
	mov ah,01h  
	int 21h 
	
	mov memid[si],al   
	inc si     

	
    loop input_loop_id
         
         
    mov si,0 
    
    jmp id_success
    
    
    memberre_1:
    jmp memberre
       
    id_success:  ;compare id
    
    cmp si,5
    je login_id_success 
                                  
    mov bl,regmemid[si]
    cmp bl,memid[si]  
    je id_check  
    
    mov bl,regname[si] 
    cmp bl,memid[si]
    je id_check1
         
    jne login_id_fail             
       
    id_check:
    inc si 
    mov members,1 ;confirm member1
    jmp id_success
    
    id_check1:
    inc si 
    mov members,2 ;confirm member2

    jmp id_success
                    
                    
    progressend:  ;end program

    mov ah,09h
    lea dx,enter
    int 21h
    
    mov ah,01h
    mov dl,entervar
    int 21h  
    
    mov ax,4c00h
    int 21h                 
       
                    
    login_id_success: ;display the line that read user password
    mov ah,02h
	mov dl,newline
	int 21h 
	
	mov ah,09h
	lea dx,l
	int 21h
            
    mov cx,5
    mov di,0
    
	jmp input_loop_pass
	
	login_id_fail: ;display error msg
	 
	mov ah,09h
	lea dx,m
	int 21h
	
	mov ah,09h
    lea dx,enter
    int 21h
    
    mov ah,01h
    mov dl,entervar
    int 21h
	 
    
    jmp menu
	        
	input_loop_pass:	;read input password
	     
	mov ah,01h  
	int 21h 
	
	mov mempass[di],al   
	inc di     

	
    loop input_loop_pass
         
         
    mov di,0 
    
    pass_success: 	;check password for member1 or member2
    
    cmp di,5
    je login_success
    
    cmp members,1
    je pass_member1
    
    cmp members,2
    je pass_member2
    
    pass_member1: 	;compare password for member1
                                  
    mov bl,regmempass[di]
    cmp bl,mempass[di]
    mov members,1   
    je pass_check
    jne login_pass_fail
    
    pass_member2: 	;compare password for member2
                                 
    mov bl,regpass[di]
    cmp bl,mempass[di]
    mov members,2   
    je pass_check
    jne login_pass_fail
         
    jmp login_pass_fail 
    
    
    pass_check:		
    inc di
    jmp pass_success 
    
    login_pass_fail:
    mov ah,09h
    lea dx,o
    int 21h 
    
    mov ah,09h
    lea dx,enter
    int 21h
    
    mov ah,01h
    mov dl,entervar
    int 21h
    
    jmp menu
    
    login_success:  ;display login success
    
    mov ah,09h
    lea dx,n
    int 21h 
    
    mov ah,09h
    lea dx,enter
    int 21h
    
    mov ah,01h
    mov dl,entervar
    int 21h
    
    call clr
    
    jmp memmenu 
    
    menu_1:
    jmp menu  
	
	
memberre:
	call clr 
	
	mov ah,09    
    lea dx,dlogo
    int 21h 
	 
	mov ah,02h
	mov dl,newline
	int 21h

	mov ah,09h
	lea dx,p
	int 21h 
	            
	mov cx,5
	mov si,0  
	
	reg_name_loop:  ;register id          
	            
	mov ah,01h
	int 21h  
	mov regname[si],al 
	
	cmp regname[si],'@'
	je menu_1
	
	inc si
	       
	loop reg_name_loop 
	
	mov si,0
	mov cx,11  
	
	mov ah,09h
	lea dx,q1
	int 21h 

	
	reg_phone_num: 	;get register phone number
	
	mov ah,01h
	int 21h
	
	mov regpn[si],al
	                   
    cmp regpn[si],'0'
    jl reg_fail_pn
    
    cmp regpn[si],'9'
    jg reg_fail_pn 
    
    inc si

    
    loop reg_phone_num 
    
    mov ah,09h
    lea dx,s
    int 21h
    
    mov si,0
    mov cx,12
    
    jmp reg_ic
    
    reg_fail_pn:	;display register fail for phone number 
    
    mov ah,09h
    lea dx,r4
    int 21h
    
    mov ah,09h
    lea dx,enter
    int 21h
    
    mov ah,01h
    int 21h
    
    jmp menu
    
    reg_ic:	;get register ic
    
    mov ah,01h
    int 21h  
    
    mov regic[si],al
	                   
    cmp regic[si],'0'
    jl reg_fail_ic
    
    cmp regic[si],'9'
    jg reg_fail_ic 
    
    inc si

    loop reg_ic 
                
    mov ah,09h
    lea dx,t2
    int 21h 
    
    mov si,0
    mov cx,5           
                
    jmp reg_pass
    
    reg_fail_ic:  	;display register fail ic
    
    mov ah,09h
    lea dx,t
    int 21h 
    
    mov ah,09h
    lea dx,enter
    int 21h
    
    mov ah,01h
    int 21h
    
    jmp menu 
    
    reg_pass:	;get register password
    
    mov ah,01h
    int 21h   
    
    mov regpass[si],al
    
    inc si
    
    loop reg_pass
    
    reg_success:	;display register success
    
    mov ah,09h
    lea dx,u
    int 21h 
    
    
    call clr 
    
    mov ah,09    
    lea dx,dlogo
    int 21h
    
    mov si,0
    mov cx,5 
    
    mov ah,09h
    lea dx,v
    int 21h
    
    print_id:	;print out the information of member
    
    mov ah,02h
    mov dl,regname[si]  
    int 21h
    
    inc si
    
    loop print_id
    
    mov si,0
    mov cx,11 
    
    mov ah,09h
    lea dx,w
    int 21h
    
    print_pn:
        
    mov ah,02h
    mov dl,regpn[si]  
    int 21h
    
    inc si
    
    loop print_pn 
    
    mov si,0
    mov cx,12 
    
    mov ah,09h
    lea dx,x
    int 21h
    
    print_ic:
    

    mov ah,02h
    mov dl,regic[si]
    int 21h
    
    inc si
    
    loop print_ic 
    
    reg_comfirm: 	;confirm the register for  member 
    
    mov ah,09h
    lea dx,y
    int 21h
    
    mov ah,01h
    int 21h
    
    mov yon,al
    
    cmp yon,'y'
    je complete_reg
    
    cmp yon,'Y'
    je complete_reg
    
    cmp yon,'n'
    je cancel_reg
    
    cmp yon,'N'
    je cancel_reg 
    
    cmp yon,'@'
    je menu_2 
    
    jmp error_yon
    
    menu_2:
    jmp menu
    
    error_yon:	;validation of yes or no
    
    mov ah,09h
    lea dx,z
    int 21h
    
    mov ah,02h
    mov dl,newline
    int 21h
    
    jmp reg_comfirm
    
    cancel_reg:	;cancel register mov all variable used to 0
   
    mov regname,0
    mov regpn,0
    mov regic,0
    mov regpass,0
    
    mov ah,09h
    lea dx,enter
    int 21h
    
    mov ah,01h
    mov dl,entervar
    int 21h 
    
    call clr
    
    jmp memberre
    
    complete_reg:	;register complete
    
    mov ah,09h
    lea dx,u
    int 21h
    
    mov ah,09h
    lea dx,enter
    int 21h
    
    mov ah,01h
    mov dl,entervar
    int 21h 
    
    call clr  
    
    jmp menu
    
    memmenu: 	;member menu
    
    mov ah,09    
    lea dx,dlogo
    int 21h
    
    mov ah,09h
    lea dx,a2
    int 21h  
    
    mov ah,01h
    int 21h
    
    mov choose1,al
    
    cmp choose1,'1'	;go shop
    je cart
    
    choosefor2:
    
    cmp choose1,'2'	;go member extend
    
    call clr
    
    mov si,0
    mov cx,5
    
    je memextends
    
    cmp choose1,'3'	;go back menu
    
    mov ah,09h
    lea dx,enter
    int 21h
    
    mov ah,01h
    mov dl,entervar
    int 21h
    
    call clr
    je menu_3
    
    jmp memmenu
    
    menu_3:
    jmp menu 
    
    cart: 
    call clr
    jmp menu_cart
 
    memextends:
    
    mov ah,09    
    lea dx,dlogo
    int 21h
           
    mov ah,09h
    lea dx,v
    int 21h 
    
    mov si,0
    mov cx,5 
    
    cmp members,1	;check is member1 or not
    je member1_id
    
    cmp members,2 	;check is member2 or not
    je member2_id_1
    
    member2_id_1:
    jmp member2_id
    
    member1_id:
    
    mov ah,02h
    mov dl,regmemid[si]
    int 21h
    
    inc si
    
    loop member1_id
    
    mov si,0
    mov cx,11
    
    mov ah,09h
    lea dx,w
    int 21h
              
    member1_pn:
    
    mov ah,02h
    mov dl,member1pn[si]
    add dl,'0'  
    int 21h
    
    inc si
    
    loop member1_pn 
    
    mov si,0
    mov cx,12 
    
    mov ah,09h
    lea dx,x
    int 21h 
    
    member1_ic:
    
    mov ah,02h
    mov dl,member1ic[si]
    add dl,'0'
    int 21h
    
    inc si
    
    loop member1_ic
     
     
    member1_expireday:
    
    mov ah,09h
    lea dx,b1
    int 21h  
    
    mov ah,02h
    mov dl,year1 
    int 21h
    
    mov ah,09h
    lea dx,yearn
    int 21h
    
    mov ah,09h
    lea dx,day1
    int 21h
    
    mov ah,09h
    lea dx,dayn             
    int 21h 
    
    extend_Confirm1:
    
    mov ah,09h
    lea dx,b2
    int 21h
    
    mov ah,01h
    int 21h
    
    mov yon,al
    
    cmp yon,'Y'
    je payment_member1
    
    cmp yon,'y'
    je payment_member1
    
    cmp yon,'N'
    call clr
    je memmenu_1
    
    cmp yon,'n'
    call clr
    je memmenu_1
    
    cmp yon,'x'
    call clr
    je memmenu_1
    
    cmp yon,'X'
    call clr
    je memmenu_1
    
    jmp extend_Confirm1 
    
    memmenu_1:
    jmp memmenu
    
    payment_member1:
    
    add memberfee,30
    mov memextend,1
    jmp subtotal2
     
    call clr
    jmp choosefor2   
              
    
    member2_id:
    
    mov ah,02h
    mov dl,regname[si]  
    int 21h
    
    inc si
    
    loop member2_id
    
    mov si,0
    mov cx,11 
    
    mov ah,09h
    lea dx,w
    int 21h

    member2_pn: 
    
    mov ah,02h
    mov dl,regpn[si]  
    int 21h
    
    inc si
    
    loop member2_pn 
    
    mov si,0
    mov cx,12 
    
    mov ah,09h
    lea dx,x
    int 21h 

    member2_ic:
    
    mov ah,02h
    mov dl,regic[si]
    int 21h
    
    inc si
    
    loop member2_ic  
                  
    member2_expireday:
    
    mov ah,09h
    lea dx,b1
    int 21h  
    
    mov ah,02h
    mov dl,year2
    add dl,'0' 
    int 21h
    
    mov ah,09h
    lea dx,yearn
    int 21h
    
    mov ah,02h
    mov dl,day2
    int 21h
    
    mov ah,09h
    lea dx,dayn             
    int 21h  
    
    extend_Confirm:
    
    mov ah,09h
    lea dx,b2
    int 21h
    
    mov ah,01h
    int 21h
    
    mov yon,al
    
    cmp yon,'Y'
    je payment_member
    
    cmp yon,'y'
    je payment_member
    
    cmp yon,'N'
    call clr
    je memmenu_2
    
    cmp yon,'n'
    call clr
    je memmenu_2
    
    cmp yon,'x'
    call clr
    je memmenu_2
    
    cmp yon,'X'
    call clr
    je memmenu_2
    
    jmp extend_Confirm
    
    memmenu_2:
    jmp memmenu 
    
                           
    payment_member:
    
    add memberfee,30
    mov memextend,2
    jmp subtotal2
                                
    
    call clr
    
    mov ah,02h
    mov dl,newline
    int 21h
    
    jmp choosefor2 
    
    
menu_cart:       
    mov ah,09       ;print logo
    lea dx,dlogo
    int 21h   

    mov ah,09       ;print menu
    lea dx,dmenu
    int 21h  
     
    mov ah,01       ;read user input
    int 21h
    sub al,48 
    
    cmp al,01      ;if(input == 1)go tablet menu if(input < 1)print error msg
    je jptablet 
        
    cmp al,02      ;if(input == 2)go liquid menu
    je jpliquid
    
    cmp al,03      ;if(input == 3)go others menu
    je jpothers
    
    cmp al,04      ;if(input == 4)go show cart list
    je jplist
    
    cmp al,05      ;if(input == 5)go back to resgister menu 
    je jpclose
    
    call errormsg1
    loop menu_cart
    
jptablet:   
    call clr
    jmp tablet
    
jpliquid:  
    call clr        ;borrow jump and clear screen
    jmp liquid  
     
jpothers:     
    call clr
    jmp others
        
jpclose:          
    jmp close
    
jplist:
    jmp cartlist    
   
tablet:   
    mov ah,09
    lea dx,dlogo	;print logo design
    int 21h

    mov ah,09
    lea dx,dtablet	;print tablet menu
    int 21h
       
    mov ah,01
    int 21h
    sub al,48 
    
    cmp al,04
    je jpmenu
     
    mov di,1
    mov si,0 
    mov ah,00
    mov cx,3 
    
    call checkitem 	;check user input to initialize what item user choice

    call errormsg1
    loop tablet
 
liquid:  
    mov ah,09
    lea dx,dlogo
    int 21h
    
    mov ah,09
    lea dx,dliquid
    int 21h 
     
    mov ah,01
    int 21h  
    sub al,48
   
    cmp al,04
    je jpmenu  
    
    mov di,1
    mov si,6 
    mov ah,00
    mov cx,3 
    
    call checkitem
    
    call errormsg1
    loop liquid

jpmenu: 
    call clr
    jmp menu_cart  

others:
    mov ah,09
    lea dx,dlogo
    int 21h
    
    mov ah,09
    lea dx,dothers
    int 21h 
    
    mov ah,01
    int 21h 
    sub al,48
  
    cmp al,04
    je jpmenu
    
    mov di,1
    mov si,12 
    mov ah,00
    mov cx,3 
    
    call checkitem 
     
    call errormsg1
    loop others    
  
errormsg3:
    mov ah,09
    lea dx,errormsg 
    int 21h
        
quantity1:              
    mov ah,09           ;print option to let user input qty
    lea dx,enterqty
    int 21h
             
    mov ah,01           ;read user input
    int 21h
    
    cmp al,'9'          ;if(input > 9 )print error msg
    jg errormsg3
    
    cmp al,'1'          ;if(input < 1 )print error msg
    jl errormsg3

    mov chckqty,al
    
    mov ah,09             
    lea dx,showqty	;print the quantity:
    int 21h
           
    mov ah,02           ;print out the qty user had enter
    mov dl,chckqty
    int 21h   

    mov ah,09           
    lea dx,showtotal
    int 21h
        
    sub chckqty,'0'     ;Convert ASCII to decimal can use 48 or 30h also
           
    mov ah,00           ;clear the ah register
    mov al,chckqty      ;move the qty to al to do the multiple
    mul price[si]       ;multiple the price with the qty

    mov cx,9
    mov di,0
    
    L1:                  ;loop to let (si == di)for next step to store the qty and total into the corresponding array
         cmp si,di       
         je checkdecimal
         add di,2
         loop L1
    
checkdecimal:             
    mov dl,chckqty
    mov dh,00
    add qty[di],dx        ;add the qty into the corresponding array
    mov cancelqty[di],dx  ;store the qty into another array (cancel) to make sure when user cancel the current order can delete the correct qty
    
    add total[di],ax      
    mov cancelttl[di],ax  

    cmp ax,99              ;if(total > 99 ) go to 3 decimal function
    jg threedecimal       
           
twodecimal:                ;else go to 2 decimal function 
    call twodecimalcal     ;call the two decimal calculation formula  
    jmp comfirmorder

threedecimal:
    call threedecimalcal   ;call the three decimal calculation formula
  
comfirmorder: 
    mov cx,0
    mov ah,09
    lea dx,comfirm
    int 21h
    
    mov ah,01
    int 21h  
    
    cmp al,'y'			;if(input == 'y')go print add cart successful
    je addcartoder  
    
    cmp al,'n' 			;if(input == 'n')go print add cart unsuccessful
    je cancelorder 
     
    call errormsg2
    loop comfirmorder

cancelorder:                ;when user cancel the current order
    mov ax,cancelttl[di]     
    sub total[di],ax        ;(The current total price in array - the (cancel)array total) 
    mov bx,cancelqty[di]
    sub qty[di],bx		;(The current qty in array - the (cancel)array qty)
     
    mov ah,09
    lea dx,addcartunsuc
    int 21h 
    
    jmp otherorder
    
addcartoder:  

    mov ah,09
    lea dx,addcartsuc
    int 21h

    
otherorder:
    mov ah,09
    lea dx,addorder		;ask user want to add other item to cart
    int 21h  
    
    mov ah,01
    int 21h
    
    cmp al,'y'			;if(input == 'y') back to menu to let user choose
    je backmenu   
    
    cmp al,'n'			;if(input == 'n') jump to cartlist
    je cartlist
    
    call errormsg2
    loop otherorder 
      
backmenu: 
    call clr
    jmp menu_cart  
     
qty2decimal:
    call twodecimalcalqty	;calculation and print 2 decimal place of qty
    
    mov ah,09
    lea dx,blank3
    int 21h
    
    jmp qty0
    
cartlist: 
    call clr
    mov subtotal,00  
    mov si,0
    mov cx,9                   ;initialized loop 13 time
    
    mov ah,09                   ;print design
    lea dx,dlist
    int 21h 
    
    Linfor:                     ;loop for print out the item name, qty, price and total one by one by using array
         cmp qty[si],0          ;if(qty(item1) == 0)jump to the Lcheckqty looping
         je checkqty
         
         mov ah,09              ;loop to print the item name by using array
         mov dx,allitem[si]
         int 21h   
         
         mov ax,qty[si]
         
         cmp ax,9               ;(qty > 9)go to print two decimal qty function
         jg qty2decimal 
         
         mov ah,02              ;else print one decimal of qty
         add al,'0'
         mov dl,al 
         int 21h 
 
         mov ah,09              ;print design
         lea dx,blank
         int 21h 
           
         qty0:    
            mov ax,price[si]
         
            call twodecimalcal     ;print each item price
         
            mov ah,09
            lea dx,blank2
            int 21h
            
            mov bh,00              ;add each item price into subtotal
            mov bx,total[si] 
            add subtotal,bx
     
            mov ax,total[si] 
         
            call threedecimalcal   ;print the item total price(qty * each price)in three decimal place
  
            mov ah,09
            lea dx,blank1
            int 21h

         checkqty:                  ;increase si and di and loop back the Linfor looping for check the next item qty  
            mov ax,qty[si] 
            add noqty,ax
            add si,2
            add di,2  

            loop Linfor          
          
    cmp noqty,0		
    mov ax,noqty	;check user had input any qty or not
    je empty 		;if(input == 0) go to cart list empty printing
     
    mov ah,09
    lea dx,dlist1
    int 21h
    
    mov ah,09
    lea dx,printsub	;print subtotal design
    int 21h 
    
    mov ax,subtotal
    call threedecimalcal 	;print out the subtotal in theree decimal place
    
    mov ah,09
    lea dx,blank1
    int 21h
    
    mov ah,09
    lea dx,dlist2
    int 21h  
    
    jne deleteitem	;if(input != 0) go to ask user delete item function

empty:
    mov ah,09 
    lea dx,emptylist	 ;if not  print out the cart list empty condition
    int 21h
    
    mov ah,09
    lea dx,dlist1
    int 21h 
    
    call pressanykey
    
    jmp menu_cart
    
deleteitem: 
    mov ah,09
    lea dx,clearitem	;ask user want to delete item or not
    int 21h
             
    mov ah,01
    int 21h
             
    cmp al,'y'		;(input == 'y')go to clear item function
    je clear
    
    cmp al,'n'		
    je complor		;(input == 'n')go to ask user complete order function
    
    call errormsg2
    loop deleteitem
    
jpmenu2: 
    call clr
    jmp menu_cart

complor: 
    mov ah,09
    lea dx,completeorder
    int 21h
    
    mov ah,01
    int 21h
    
    cmp al,'0'		;(input == '0')go back to medicine menu
    je jpmenu2  
    
    cmp al,'y'		;(input == 'y')go to payment function
    je payment_list 
    
    cmp al,'n' 		;(input == 'n')go to print cart list again
    je jplist2
    
    call errormsg2
    loop complor
          
jplist2:
    jmp cartlist 
    
errormsg4:
    mov ah,09
    lea dx,errormsg
    int 21h
             
clear: 
    mov ah,09
    lea dx,deletewhat
    int 21h
    
    mov ah,01
    int 21h  

    cmp al,'9'
    jg errormsg4
    
    cmp al,'1'
    jl errormsg4 
    
    mov ah,00
    sub al,'0'
    sub noqty,ax
  
    mov si,1
    mov di,0
    mov cx,9
       
    Lcheckitem:                  ;loop check what item user want to delete
       cmp ax,si 
       je delete

       inc si
       add di,2
       loop Lcheckitem
       
    delete:    
       cmp qty[di],00
       je noitem 
         
       mov bh,00
       mov bx,total[di]
       sub subtotal,bx 	       ;The current total price in corresponding array minus the subtotal
       mov total[di],00        ;The current total price in corresponding array become 0 
       mov qty[di],00          ;The current quantity in corresponding array become 0 
   
    mov ah,09
    lea dx,deletesucc
    int 21h
    
    call pressanykey
   
    jmp cartlist
    
noitem:  			;if user input the item is empty,print out that item not in cart
    mov ah,09
    lea dx,noitemdlt		
    int 21h 
    
    call pressanykey
    
    jmp cartlist

payment_list: ;-------------------------------------------------------------------------------------------
    call clr 
    mov ah,09h
    lea dx,list
    int 21h 
    
;----------------------------------------------- : 

    cmp members,1     
    je  member_discount_1  ;member1
    
    cmp members,2 
    je  member_discount_1  ;member2
    
    cmp members,9          ;not member
    je  delivery_1   

delivery_1:
    mov ah,09h
    lea dx,m2
    int 21h
    
    mov ah,09h
    lea dx,enter
    int 21h
    
    mov ah,01
    int 21h
    
    jmp delivery
    
member_discount_1:

    mov ah,09h
    lea dx,m1
    int 21h

   
;----------------------------------------------- 
    
member_discount: 
    mov ah,09h
    lea dx,m3
    int 21h 


    mov ax,subtotal 

    mul discount1 
    div discount2 
    
    mov ah,00
    mov discountRM,ax
    div ten  
    
    mov discountRM1,al
    mov discountRM2,ah

    mov ax,dx 
    mov ah,0 
    mov discountSen,ax
    div ten

    mov discountSen1,al
    mov discountSen2,ah

    mov ah,02h 
    mov dl,discountRM1
    add dl,30h
    int 21h     
           
    mov ah,02h 
    mov dl,discountRM2
    add dl,30h
    int 21h 
    
    mov dl, 2Eh
    int 21h
        
    mov ah,02h 
    mov dl,discountSen1 
    add dl,30h
    int 21h 

    mov ah,02h 
    mov dl,discountSen2
    add dl,30h 
    int 21h 
    
    mov ah,01h 
    int 21h 
    
delivery: 
    call clr
    
    mov ah,09h
    lea dx,d1
    int 21h 

    mov ah,01h 
    int 21h    

    mov c2,al

    cmp c2,'1' 
    je  malaysia

    cmp c2,'2' 
    je  overseas
    
    jne c2_error_1
              
    
    c2_error_1:
    jmp c2_error


malaysia: 
    mov ah,09h
    lea dx,d2
    int 21h  
    
    call package 

    mov deliveryfee,5 

    mov ah,01h 
    int 21h 
        
    call clr

    jmp subtotal1

overseas:
    mov ah,09h
    lea dx,d3
    int 21h  
    
    call package 

    mov deliveryfee,20 
    
    mov ah,01h 
    int 21h 
    
    call clr
     
subtotal1:
    call clr
       
    mov ah,09h
    lea dx,t1
    int 21h 

    mov ax,deliveryfee
    add subtotal,ax   
    mov bx,packagefee
    add subtotal,bx
    
    mov ax,discountSen
    cmp discountSen,00
    je calRM   
    jg calSen
    
subtotal2:
    
    call clr
       
    mov ah,09h
    lea dx,t1
    int 21h  

    mov ah,0
    mov al,memberfee
    add subtotal,ax
    mov memberfee,0 
    
    mov ax,discountSen
    cmp discountSen,00
    je calRM   
    jg calSen    

calSen:
    sub subtotal,1 
    add sen,100
    mov ax,discountSen
    sub sen,ax
    
calRM:    
    mov bh,0
    mov bx,discountRM
    sub subtotal,bx 
    mov ax,subtotal
    
    cmp subtotal,99 
    jg display3de
    
dispaly2de:  
    div ten
             
    mov r,ah 
    
    mov ah,02 
    add al,'0'
    mov dl,al
    int 21h  
    
    mov ah,02
    mov al,r
    add al,'0'  
    mov dl,al
    int 21h
    
    jmp displaySen

display3de:
    mov dx,0
    div hundred
    
    mov q,al
    mov al,dl
    div ten
    
    mov r,ah
    mov rd,al
    
    mov ah,02 
    add q,'0'
    mov dl,q
    int 21h  
    
    mov ah,02 
    add rd,'0'
    mov dl,rd
    int 21h
    
    mov ah,02 
    add r,'0'
    mov dl,r
    int 21h 
    
displaySen:
    mov dl, 2Eh
    int 21h
        
    mov ax,sen
    div ten
    
    mov sen2,ah
    
    mov ah,02 
    add al,'0'
    mov dl,al
    int 21h
    
    mov ah,02
    add sen2,'0'
    mov dl,sen2
    int 21h
    
payment: 
    call pressanykey
    
    mov ah,09h
    lea dx,p1
    int 21h

    mov ah,01h 
    int 21h 

    mov c3,al 

    cmp c3,'1' 
    je  cash

    cmp c3,'2' 
    je  card

    cmp c3,'3' 
    je  online 

    cmp c3,'4' 
    je  cancel
              
    jne c3_error_1
    
    c3_error_1:
    jmp c3_error

cash:
    mov ah,09h
    lea dx,cash1
    int 21h 
        
    mov ah,01h 
    int 21h  

    call clr 
    
    jmp receipt
 
card: 
    mov ah,09h
    lea dx,card1
    int 21h 
        
    mov ah,01h 
    int 21h  

    call clr 

    jmp cardPayment

online:
    mov ah,09h
    lea dx,online1
    int 21h 
    
    mov ah,01h 
    int 21h 
    
    call clr 

    jmp onlinePayment
  
cancel: 
    call clr
    mov ah,09h
    lea dx,cancel1
    int 21h

    mov ah,01h 
    int 21h  

    mov c4,al

    cmp c4,'Y'
    je  menu_1l ;main menu

    cmp c4,'N'  
    je  payment_list_1  

    cmp c4,'y' 
    je  menu_1l ;main menu

    cmp c4,'n' 
    je  payment_list_1

    jne c4_error_1
    
    c4_error_1:
    jmp c4_error
    
    menu_1l:
    mov si,0
    mov cx,9
   
    clear_item1:
    mov qty[si],0
    mov total[si],0000h
    add si,2
    loop clear_item1 
    
    mov subtotal,0000h
    mov sen,0
    mov discountRM,0
    mov discountSen,0
    
    jmp menu 
    
    payment_list_1:
    jmp payment_list
    
    payment_1:
    jmp payment  

cardPayment:           ;===================================================loop 
    mov ah,09h
    lea dx,p2
    int 21h 
            
    mov cx,16
    mov si,0        
    
cardRead: 
    
    mov ah,01h 
    int 21h  
    
    mov cardNum[si],al
    
    cmp cardNum[si],'x'
    je payment_1
    
    cmp cardNum[si],'X'
    je payment_1
  
    
    cmp cardNum[si],'0'
    jl error_card
    
    cmp cardNum[si],'9'
    jg error_card
    
   
    inc si              
                  
    loop cardRead 
 
    mov ah,09h
    lea dx,p4
    int 21h  
    
    mov cx,4
    mov si,0
    
cardReadDate:
    
    mov ah,01h
    int 21h   
    
    mov cardDate[si],al
    
    inc si
    
    loop cardReadDate 
             
    mov si,0
    
cardDate_check:

    cmp cardDate[si],'2'
    jg cardDate_check_2
    mov si,1
    je cardDate_check_1
                                             
    jl error_date
    
cardDate_check_1: 

    cmp cardDate[si],'3'
    jl error_date 
    mov si,2
    je cardDate_check_2
     
    
cardDate_check_2:
    
    cmp cardDate[si],'2'
    mov si,3
    jl cardDate_check_3
    je error_date
    jg error_date
    
    
cardDate_check_3:
    
    cmp cardDate[si],'3'
    jl receipt
    jg error_date
    je error_date
    jmp receipt     
    
error_date:
    
    mov ah,09h
    lea dx,errordate
    int 21h 
        
    mov ah,01h
    int 21h
    
    call clr 
    
    mov ah,09h
    lea dx,p2
    int 21h
   
    
    
    mov al,0   
    mov cx,16
    mov si,0 
    
    jmp cardRead 
    
error_card:
    
    mov ah,09h
    lea dx, errorcard
    int 21h
    
    mov ah,01h
    int 21h
    
    call clr
    
    mov ah,09h
    lea dx,p2
    int 21h
      
    mov al,0   
    mov cx,16
    mov si,0 
    
    jmp cardRead     
   
onlinePayment:         ;=================================================== 
    
    mov ah,09h
    lea dx,onlinebank
    int 21h  
    
    mov ah,01h 
    int 21h 
    
    jmp receipt

receipt:

    cmp memextend,1
    je addyear1
    cmp memextend,2
    je addyear2  
    
receipt1:
    
    mov ah,09h
    lea dx,r1
    int 21h 

    mov ah,09h
    lea dx,r2 
    int 21h 

    mov ah,09h
    lea dx,r3
    int 21h  

    mov ah,01h 
    int 21h 
    
    mov si,0
    mov cx,9
   
    clear_item:
    mov qty[si],0
    mov total[si],0000h 
    mov discountRM,0000h
    mov discountSen,0000h
    add si,2
    loop clear_item 
    
    mov subtotal,0000h
    mov sen,0
    mov discountRM,0
    mov discountSen,0
    
    call clr
    jmp menum   ;main menu 
    
addyear1:
    add year1,1
    jmp receipt1
    
addyear2:
    add year2,1
    jmp receipt1    

;----------------------------------------------- 
menum:             
    call clr
    mov ah,09h
    lea dx,enter
    int 21h 
    
    mov ah,01h 
    int 21h      
    
    call clr 
    
    jmp menu
    
    hlt
;----------------------------------------------- 
c1_error: 
    mov ah,09h
    lea dx,e1
    int 21h 
        
    mov ah,01h 
    int 21h  
    
    jmp payment_list_1  

c2_error: 
    mov ah,09h
    lea dx,e2
    int 21h 

    mov ah,01h 
    int 21h  

    jmp delivery

c3_error: 
    mov ah,09h
    lea dx,e3
    int 21h 
    
    mov ah,01h 
    int 21h 
    
    jmp subtotal1

c4_error: 
    mov ah,09h
    lea dx,e4
    int 21h 

    jmp cancel


    mov ax,4c00h
    int 21h 
    
close:     
    call pressanykey
    jmp memmenu   

package:
    mov ah,09h
    lea dx,package1
    int 21h  
    
    ret
   
errormsg1:           ;eror msg
    call clr
    
    mov ax,0600h
    mov bh,0dh
    mov cx,0000h
    mov dx,184fh 
    int 10h 
    
    mov ah,09        
    lea dx,errormsg
    int 21h
    
    ret 
    
errormsg2:           ;eror msg
    mov ah,09        
    lea dx,errormsg
    int 21h
    
    ret 
    
checkitem:    
    cmp ax,di         ;check what item user want
    je storeprice 
    
    inc di
    add si,2
    loop checkitem
 
    ret   
    
storeprice:           
    jmp quantity1 
        
pressanykey:         ;press any key
    mov ah,09
    lea dx,otherkey
    int 21h
    
    mov ah,01
    int 21h
     
    call clr  
    
    ret  
    
twodecimalcalqty:        ;two decimal calculation
    div ten
    mov quotient,al  
    mov remainder,ah 
    add quotient,'0'
    add remainder,'0'
    
    mov ah,02
    mov dl,quotient
    int 21h  

    mov ah,02
    mov dl,remainder
    int 21h   
     
    ret 
       
twodecimalcal:        ;two decimal calculation
    div ten
    mov quotient,al  
    mov remainder,ah 
    add quotient,'0'
    add remainder,'0'
    
    mov ah,02
    mov dl,quotient
    int 21h  

    mov ah,02
    mov dl,remainder
    int 21h   
    
    mov ah,09              ;print the .00
    lea dx,pricedp
    int 21h
    
    ret
    
threedecimalcal:       ;three decimal calculation
    mov dx,0000 
    div hundred
    mov quotient,al
    
    mov al,dl      
    cmp quotient,00
    je twodecimal1
          
    div ten 
    
    mov remainder,al
    mov remainder2,ah 
    add remainder,'0'
    add remainder2,'0'
    
    mov ah,02    
    add quotient,'0'
    mov dl,quotient
    int 21h  
                                         
    mov ah,02
    mov dl,remainder
    int 21h
    
    mov ah,02
    mov dl,remainder2
    int 21h
    
    mov ah,09              ;print the .00
    lea dx,pricedp
    int 21h
    
    ret
                                         
twodecimal1:
    jmp twodecimalcal

clr:                   ;clear screen
    mov ah,00
    mov al,02
    int 10h

    mov ax,0600h
    mov bh,03h
    mov cx,0000h
    mov dx,184fh 
    int 10h

    ret
                     

mov ax,4c00h
int 21h

main endp
end main