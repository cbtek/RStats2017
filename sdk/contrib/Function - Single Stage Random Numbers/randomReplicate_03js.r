

#The below function replicates the operation of Rnd() from Visual Basic 6 when a positive input parameter is used.
ExcelRand64<-function(ExcelSeed,outputmax)
{
	vara = as.integer64(ExcelSeed)
	varb = as.integer64(1140671485)
	varc = as.integer64(12820163)
	firstflag<-TRUE
	ValueA<-0
	while(ValueA>=outputmax | firstflag){
		firstflag<-FALSE
		vara = as.integer64(ExcelSeed)
		ExcelSeed<-as.integer64(vara *varb +varc )%%as.integer64(2^24)
		ValueA<- outputmax*ExcelSeed/2^24+1
	}
	returnHelp<-list()
	returnHelp[["Step"]]<-ExcelSeed
	returnHelp[["ExcelOutput"]]<-ExcelSeed/2^24
	returnHelp[["RATSTAT"]]<-ValueA
	returnHelp
}

#The below function replicates the operation of the Visual Based 6 function Randomize()
ExcelRandomize64<-function(startingpoint,ExcelSeed){
	testhelptemp<-writeBin(as.double(startingpoint),raw(),size=8)
	bitlist<-rawToBits(testhelptemp)[33:64]
	bitseed<-intToBits(as.integer(ExcelSeed))
	vara<-packBits(c(bitlist[1:16],intToBits(0)[1:16]),"integer")
	varb<-packBits(c(bitlist[17:32],intToBits(0)[1:16]),"integer")
	moshedbitsA<-intToBits(bitwXor(vara,varb))
	finalmosh<-(c(intToBits(0)[1:8],moshedbitsA[1:16],intToBits(0)[1:8]) | c(bitseed[1:8],intToBits(0)[1:24]))
	newSeed<-packBits(finalmosh ,"integer")
	newSeed
}

#The below function replicates the operation of the Visual Basic 6 function Rnd() when a negative input parameter is used.  
ExcelRandInit<-function(initvar)
{
	testhelp<-writeBin(as.double(initvar),raw(),size=4)
	testhelp<-rawToBits(testhelp)
	packBits(c(testhelp[25:32],intToBits(0)[1:24]),"integer") +packBits( c(testhelp[1:24],intToBits(0)[1:8]),"integer")
}

#Sets the path for the relevant R library files
rootpath<-"C:/Partlist"
.libPaths(file.path(rootpath,"Library"))

#This replication requires the "bit64" library.
library(bit64)


#Emulates Rnd(-1)
CurrentSeed<-ExcelRandInit(-1)
#Emulates Rnd()
CurrentSeed<-ExcelRand64(CurrentSeed,30269)[["Step"]]
#The above two lines of code result in the value 3758214 which is listed in Step 1 of the detailed specification


#Emulates the Visual Basic function Randomize() given the seed entered by the user or the system clock if no seed is provided
CurrentSeed<-ExcelRandomize64(12345,CurrentSeed)
#The above line of code equates to steps 2 through 5 in the detailed specification document


#Emulates the three calls to the Visual Basic 6 function Rnd().
ResA<-ExcelRand64(CurrentSeed,30269)
ResB<-ExcelRand64(ResA[["Step"]],30307)
ResC<-ExcelRand64(ResB[["Step"]],30323)
#The above three lines of code equate to Steps 6 through 15 in the detailed specification document

#Given the three seed generated from the Excel functions Rnd() and Randomize(), RAT-STATS uses the standard Wichmann-Hill algorithm 
#to generate the actual random numbers. The below code emulates the algorithm using R.

Seed_A<-floor(ResA[["RATSTAT"]])
Seed_B<-floor(ResB[["RATSTAT"]])
Seed_C<-floor(ResC[["RATSTAT"]])
samsiz<-10
RandomNumber<-NA*(1:samsiz)
Lowb<-1
Upb<-1000
repcheck<-0*(1:(Upb-Lowb+1))
for(j in 1:samsiz){
	repflag=TRUE
	while(repflag){	
		Term_1=floor(Seed_A/177)
		Term_2=Seed_A - (177*Term_1)
		Seed_A = 171*Term_2 - 2*Term_1
		if (Seed_A <= 0) {Seed_A = Seed_A +30269}

		Term_1=floor(Seed_B/176)
		Term_2=Seed_B - (176*Term_1)
		Seed_B = 172*Term_2 - 35*Term_1
		if (Seed_B <= 0){Seed_B = Seed_B +30307}

		Term_1=floor(Seed_C/178)
		Term_2=Seed_C - (178*Term_1)
		Seed_C = 170*Term_2 - 63*Term_1
		if (Seed_C <= 0) {Seed_C = Seed_C +30323}
	
		Term_4 = Seed_A/30269 +  Seed_B/30307 + Seed_C/30323
		RandomNumber[j] = floor((Term_4 - floor(Term_4))*(Upb-Lowb+1))+Lowb
		if(repcheck[RandomNumber[j]-Lowb]==0)
		{
			repcheck[RandomNumber[j]-Lowb]=1
			repflag=FALSE
		}
	}
}

sum(RandomNumber)
print(RandomNumber)
print(sum(RandomNumber))

