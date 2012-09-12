HEADERS= gll.h \
	sll.h \
	cll.h \
	dll.h
SOURCES= sll.cpp\
	cll.cpp\
	dll.cpp\
	gll.cpp\
	main.cpp
TARGET=llApp

output:
	g++ -g -o $(TARGET)  $(HEADERS) $(SOURCES) --save-temps

indent:
	indent *.cpp *.h
clean:
	rm *~ *.*.gch .*.swp *.o  $(TARGET) *.ii *.s
		
