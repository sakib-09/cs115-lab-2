COMPILER = g++ # or CC if you prefer it on Hercules
FLAGS = -std=c++11

DRIVER = main
FILE = LinkedList


$(DRIVER) : $(FILE).o $(DRIVER).o  #the first character on the next line is a tab 
	$(COMPILER)  -o  $(DRIVER) $(FILE).o $(DRIVER).o

$(DRIVER).o :  $(DRIVER).cpp  $(FILE).cpp $(FILE).h 
	$(COMPILER) -c -g $(FLAGS) $(DRIVER).cpp  -o $(DRIVER).o

$(FILE).o :  $(FILE).cpp $(FILE).h
	$(COMPILER) -c -g $(FLAGS) $(FILE).cpp  -o  $(FILE).o

main-debug : $(FILE).o $(DRIVER).o  #the first character on the next line is a tab 
	$(COMPILER)  -o  main-debug $(FILE).o $(DRIVER).o


clean:
	@ /bin/rm -f *.o main main-debug
