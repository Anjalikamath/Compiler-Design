# encoding: utf-8

#new
import os
import re

regs=['R1','R2','R3','R4','R5','R6','R7','R8','R9','R10','R11','R12','R13','R14']
assigned={}
reg_avail={}

extrecord = {}
extidx = 0

variables=[]
sent = []

Assem=[]
bgtz=0
bgt=0
blt=0
bltz=0
beq=0
bneq=0
bn=0
reg_for_array=""
str_data=[]
used=[]
arr_data=[]
#Func to read the input file,every sentence appended into the list 'lines' and lines is returned
#lines contains the comma separated values of each line in the input file
#each line of the input file is converted into a list and appended to sent

def Load(filename):
    lines=[]
    block = []
    flag = False
    for line in open(filename,'r'):
        line=line.replace('\n','')
        linelist = line.split(' ')
        lines.append(linelist)
        block.append(line)
    sent.append(block)
    #print(sent," Sent \n")
    #print(lines," LINES \n ")
    return lines

f=open('objectcode5.txt','w')

#func to save the temporaries in the 3ac into variables list
def Getvar(Inter):
    global variables
    temp_re='(t\d+)' #regex to identify temporary in 3ac
    for line in Inter:
        temps=re.findall(temp_re,' '.join(line))
        variables+=temps #all varaibles in 3ac
    #print("Var  ",variables)

#function to initialize the registers
def init():
    global assigned,reg_avail,spill,spill_record,extrecord
    extrecord = {}
    spill_record = []
    spill = {}
    assigned = {}
    reg_avail = {}
    for reg in regs:
        reg_avail[reg] = 1  #Initialize all registers as available

GlobalRecord = {}
#function to get the register allocated to the temp/var
def GetReg(key):
    #if register is used again it is appended to the back of the list and becomes most recently used    
    if GlobalRecord[key][0] in used:
        used.remove(GlobalRecord[key][0])
        used.append(GlobalRecord[key][0])
        #print("usedddd",used)
        return GlobalRecord[key][0]
 
    else:
        if(GlobalRecord[key][0]=='R20'):
          return "R20"
          
        else:
          used.append(GlobalRecord[key][0])
          return GlobalRecord[key][0]

    
def usedup(key):
  used_up=used[0]
  used.remove(used_up)
  used.append(used_up)
  return used_up
    
   
def GetReg2(key):
    y=GetReg(key)
    if(y=='R20'):
      y=usedup('R20')
      GlobalRecord[key][0]=y
    return y


#reg_avail is a dictionary of all available registers as key and value as 1 which was initialized in the
#init() function
#this func is used to allocate registers to the temp/vars as per their availability.
#assign from reg_avail dict, change value to 1 and assign it to the assigned dict.
#assigned dict contains the key as temp/var and value is the reg allocated to it
def get_R(string):
    f=0
    #print(assigned,reg_avail)
    if string in assigned:
        return assigned[string]
    for reg in regs:
        if reg_avail[reg] == 1:
            reg_avail[reg] = 0
            assigned[string] = reg
            f=1
            return assigned[string]
    return 'R20' #hypothetical value,changed using lru
    #If R14 has been used up then we reinitialise all the registers as free and start using from R1 again
    '''
    value=reg_avail.get('R14')
    if(value==0):
        for reg in regs:
            if reg_avail[reg]==0:
                reg_avail[reg]=1    
    if f==0:
      for reg in reg_avail:
        reg_avail[reg]=1
      reg_avail['R1']=0
      assigned[string]='R1'
      return assigned[string]

    #print(assigned,reg_avail,"------")
    '''



#function for translating into assembly code
def translate(line):
    global bgtz
    global bgt
    global blt
    global bltz
    global beq
    global bneq
    global bn
    global reg_for_array
    global GlobalRecord
    print(line)
    #i.e if ip is LABEL L1 , return L1:
    if len(line)==1:
        return '\t%s'%(line[0][1:].upper())

    if len(line)==3 and line[0]=='ELSE':
        return '\tBR %s'%(line[2])
    if len(line)==3 and line[1]=='=' and line[2][0]=='"':
        str_data.append(line[0][1:])
        str_data.append(line[1])
        str_data.append(line[2])
        pass
    if len(line)==4 and line[2]=='not' and line[1]=='=':
        bneq=1
        #return '\tSUB %s,%s,%s\t'%(GetReg2(line[0]),GetReg2(line[0]),GetReg2(line[3]))
        return '\t%s = NOT %s'%(GetReg2(line[0]),GetReg2(line[2]))

    if len(line)>4 and line[0][0]=='$' and line[1]=='=' and line[2]=='[':
        req_data=[line[0][1:],line[3:]]
 
        req_data[1].remove(']')
        for i in range(0,len(req_data[1])):
            if len(req_data[1][i])==2:
                req_data[1][i]=req_data[1][i].strip('#')        

        arr_data.append(req_data)


    if line[0]=='LABEL':
        return line[1]+':'
 
    #check for operations
    if len(line)==5:
            #print("in ops\n")
            if line[3]=='+':
                #print("in plus\n")
                if line[-1][0]=='#':
                  if(line[0][0]=='$'):
                    return '\tADD %s,%s,%s\n\tSTR %s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''),GetReg2(line[0]),line[0])
                  else:
                    return '\tADD %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''))
                else:
                    if(line[0][0]=='$'):
                      return '\tADD %s,%s,%s\n\tSTR %s,%s'%(GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]),GetReg2(line[0]),line[0])
                    else:
                      return '\tADD %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[1]), GetReg2(line[-1]))


            elif line[3]=='-':
                #print("in minus\n")
                if line[-1][0]=='#':
                  if(line[0][0]=='$'):
                    return '\tSUB %s,%s,%s\n\tSTR %s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''),GetReg2(line[0]),line[0])
                  else: 
                    return '\tSUB %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''))
                else:
                  if(line[0][0]=='$'):
                    return '\tSUB %s,%s,%s\n\tSTR %s,%s'%(GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]),GetReg2(line[0]),line[0])
                  else:
                      return '\tSUB %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]))

            elif line[3]=='*':
              if line[-1][0]=='#':
                  if(line[0][0]=='$'):
                    return '\tMUL %s,%s,%s\n\tSTR %s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''),GetReg2(line[0]),line[0])
                  else:
                    return '\tMUL %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''))
              else:
                  if(line[0][0]=='$'):
                    return '\tMUL %s,%s,%s\n\tSTR %s,%s'%(GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]),GetReg2(line[0]),line[0])
                  else:
                      return '\tMUL %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]))

            elif line[3]=='/':
              if line[-1][0]=='#':
                  if(line[0][0]=='$'):
                    return '\tDIV %s,%s,%s\n\tSTR %s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''),GetReg2(line[0]),line[0])
                  else:
                    return '\tDIV %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''))
              else:
                if(line[0][0]=='$'):
                    return '\tDIV %s,%s,%s\n\tSTR %s,%s'%(GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]),GetReg2(line[0]),line[0])
                else:
                      return '\tDIV %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]))

            elif line[3]=='<':
                blt=1
                if line[-1][0]=='#':
                  return '\tSUB %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''))
                else:
                  return '\tSUB %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]))

            elif line[3]=='>':
                bgt=1
                if line[-1][0]=='#':
                  return '\tSUB %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''))
                else:
                  return '\tSUB %s,%s,%s'%( GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]))

            elif line[3]=='==':
                beq=1
                if line[-1][0]=='#':
                  return '\tSUB %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''))
                else:
                  return '\tSUB %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]))

            elif line[3]=='<=':
                bltz=1
                if line[-1][0]=='#':
                  return '\tSUB %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''))
                else:
                  return '\tSUB %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]))

            elif line[3]=='>=':
                bgtz=1
                if line[-1][0]=='#':
                  return '\tSUB %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''))
                else:
                  return '\tSUB %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]))

            elif line[3]=='!=':
                bneq=1
                if line[-1][0]=='#':
                  return '\tSUB %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''))
                else:
                  return '\tSUB %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]))
  
            elif line[3]=='&&':
                if line[-1][0]=='#':
                  return '\tAND %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''))
                else:
                  return '\tAND %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]))

            elif line[3]=='||':
                if line[-1][0]=='#':
                  return '\tOR %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''))
                else:
                  return '\tOR %s,%s,%s'%( GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]))
            elif line[3] == '!':
                if line[-1][0]=='#':
                  return '\tNOT %s,%s,%s'%(GetReg2(line[0]), GetReg2(line[2]), line[-1].replace('#', ''))
                else:
                  return '\tNOT %s,%s,%s'%( GetReg2(line[0]), GetReg2(line[2]), GetReg2(line[-1]))
    #if '=' , if 2nd operator is a number, we load from memory, otherwise ,if the operator is a temporary, we MOVE(numbers start with #)
    if line[1]=='=' and line[-1][-1]!='"':
        if len(line)==3:
            if line[-1][0]=='$':
                return '\tLOAD %s,%s'%(GetReg2(line[0]), line[-1])

            elif line[-1][0]=='#':
              if line[0][0]=='$':
                return '\tMOV %s,%s\n\tSTR %s,%s'%(GetReg2(line[0]), line[-1].replace('#', ''),GetReg2(line[0]),line[0])

              else:
                
                return '\tMOV %s,%s'%(GetReg2(line[0]), line[-1].replace('#', ''))

            elif line[0][0]=='$':

                return '\tSTR %s,%s'%(line[0],GetReg2(line[-1]))

            else:
                return '\tMOV %s,%s'%(GetReg2(line[0]), GetReg2(line[2]))    


    if len(line)==6:
            
            if line[3]=='[' and line[5]==']':
                #reg_for_array=GetReg2(line[0])
                return '\tLOAD %s,%s[%s]'%(GetReg2(line[0]), line[2][1:].upper(), GetReg2(line[4]))
    
            elif line[1]=='[' and line[3]==']':
                
                if line[5][0]=='$':
                    #reg_for_array=GetReg2(line[2])
                    return '\tLOAD %s,%s,\n\tSTR %s,%s[%s]'%(GetReg2(line[-1]), line[-1],GetReg2(line[-1]),line[0][1:].upper(),GetReg2(line[2]))


    if(len(line)==2):
      if(line[1]=='++'):
        if(line[0][0]=='$'):
            return '\tADD %s,%s,1\n\tSTR %s,%s'%(GetReg2(line[0]),GetReg2(line[0]),GetReg2(line[0]),line[0])
        return '\tADD %s,%s,1'%(GetReg2(line[0]),GetReg2(line[0]))

      elif(line[1]=='--' ):
        if(line[0][0]=='$'):
            return '\tADD %s,%s,1\n\tSTR %s,%s'%(GetReg2(line[0]),GetReg2(line[0]),GetReg2(line[0]),line[0])
        return '\tSUB %s,%s,1'%(GetReg2(line[0]),GetReg2(line[0]))

      elif(line[0]=='--'):
        if(line[1][0]=='$'):
            return '\tSUB %s,%s,1\n\tSTR %s,%s'%(GetReg2(line[1]),GetReg2(line[1]),GetReg2(line[1]),line[1])
        return '\tSUB %s,%s,1'%(GetReg2(line[1]),GetReg2(line[1]))

      elif(line[0]=='++'):
          if(line[1][0]=='$'):
            return '\tADD %s,%s,1\n\tSTR %s,%s'%(GetReg2(line[1]),GetReg2(line[1]),GetReg2(line[1]),line[1])
          return '\tADD %s,%s,1'%(GetReg2(line[1]),GetReg2(line[1]))
      

    #if 'IF' operation, check the flag which was set for conditional operators.Based on the flag,
    #use corresponding conditional branch statements
    if line[0]=='IF':
          if beq==1:
            beq=0
            return '\tBEQ %s %s %s' % (GetReg2(line[1]),"GOTO", line[-1])
          elif blt==1:
            blt=0
            return '\tBLT %s %s %s' % (GetReg2(line[1]),"GOTO", line[-1])
          elif bneq==1:
            bneq=0
            return '\tBNEZ %s %s %s' % (GetReg2(line[1]),"GOTO", line[-1])
          elif bgt==1:
            bgt=0
            return '\tBGT %s %s %s' % (GetReg2(line[1]),"GOTO", line[-1])
          elif bgtz==1:
            bgtz=0
            return '\tBGTZ %s %s %s' % (GetReg2(line[1]),"GOTO", line[-1])
          elif bltz==1:
            bltz=0
            return '\tBLTZ %s %s %s' % (GetReg2(line[1]),"GOTO", line[-1])
          else:
            return '\t %s %s %s'% (GetReg2(line[1]),"GOTO", line[-1])
    #if 1st word is goto, it is an unconditional branch, so we use BR operation
    if line[0]=='GOTO':
        return '\tBR %s'%line[1]
    return ''




#function for writing the assembly code to .txt file.Assem list has the content.
def write_asem(Assem):
    #print(Assem)
    f.write('.TEXT\n')
    for line in Assem:
        f.write(line+'\n')
    f.close()


def goth():
    Inter=Load('icgg.txt')  #optimized three address code ip file
    Getvar(Inter)    #Scan the input and record all variables in the input-- as mentioned above

    #sent is a list of lists-each line of the inout file is stored in a list which is stored in sent
    for block in sent:
        init() #initialize the registers
        reguse = []
        #regarray=[]
        for line in block:
            #find the temporaries and the variables and store it in reguse list 
            #reguse stores every instance of the temporaries and the variables
            if(line[-1]=="]"):
                pass
            else:
              pattern = re.compile(r't\d+|[$(a-z)][a-z]*')
              list = re.findall(pattern, line)
              reguse += list
        #print("reguse--",reguse,"\n")

	      #reguse has all the temporaries and vars in thhe whole i/p
        #key is the temporary/variable, value is a list of the temporary name  i.e for eg:
        #{Temp0:['Temp0]} is the output of the below loop
        regdict = {}
        for i in range(len(reguse)):
            thisreg = reguse[i]
            if thisreg not in regdict:
                regdict[thisreg] = [thisreg]
        #print("regdict --",regdict,"\n")

        global GlobalRecord
        GlobalRecord = regdict
        
        #this is used to allocate registers to the distinct remp/vars present in regdict
        for reg in regdict:
            regdict[reg] = [get_R(reg)] #replace the key which was initially the temp name with the register allocated to it
        print(GlobalRecord)
        print("\n")
        for line in block:
            linelist = line.split(" ")
            #print(linelist)
            s = translate(linelist) #translate the sentence

            if len(s) > 0: #if len of the generated stg is greater than 0,append it to Assem list
                Assem.append(s)
        
    write_asem(Assem)
    f1=open('objectcode5.txt','a')
    f1.write('\n')
    f1.write('.DATA')
    f1.write('\n')

    for i in arr_data:
       f1.write('\t'+(i[0].upper())+' : '+'.WORD') 
       for e in i[1]:
           f1.write(' '+e)
       f1.write('\n')

    for i in range(len(str_data)):
      if i==0:
        f1.write('\t'+(str_data[i].upper())+' : '+'.ASCIZ')
      if(i==1):
        pass
      if(i==2):
        f1.write('\t'+str_data[i])
    f1.write('\n')

    f1.close()

goth()
