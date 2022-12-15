.SILENT:

CLASSES=Classes/
OBJS=Classes/Voiture.o Classes/Modele.o Classes/Option.o
CO=g++ -I $(CLASSES) -D DEBUG
PROGRAMS=Test3

Test3:	Test3.cpp $(CLASSES)Voiture.o $(CLASSES)Modele.o $(CLASSES)Option.o
	$(CO) $(OBJS) Test3.cpp -o Test3
	echo "Création de Test3"

Classes/Modele.o:	$(CLASSES)Modele.h $(CLASSES)Modele.cpp
	$(CO) $(CLASSES)Modele.cpp -c -o $(CLASSES)Modele.o
	echo "Création de Modele.o"

Classes/Voiture.o:	$(CLASSES)Voiture.h $(CLASSES)Voiture.cpp
	$(CO) $(CLASSES)Voiture.cpp -c -o $(CLASSES)Voiture.o
	echo "Création de Voiture.o"

Classes/Option.o:	$(CLASSES)Option.h $(CLASSES)Option.cpp
	$(CO) $(CLASSES)Option.cpp -c -o $(CLASSES)Option.o
	echo "Création de Option.o"

clean:
	rm $(CLASSES)*.o

clobber:
	clean
	rm -f $(PROGRAMS)