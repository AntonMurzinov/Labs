#include <iostream>
#include <stdio.h>
#include "Animals.h"
#include "Birds.h"
#include "Goose.h"
#include "BabyGoose.h"
#include"Fishes.h"
#include"Shark.h"
#include"BabyShark.h"
#include"mammals.h"
#include"Cheetah.h"
#include"BabyCheetah.h"

using namespace std;

int main()
{
	// Create animal's class
	Animals animals;
	animals.setcolor('r');
	animals.setclaws(true);
	animals.setwool(false);
	cout << "\tAnimals" << "\n";
	cout << "Colour of Animals: " << animals.getcolor() << endl;
	printf("Do they have claws? %s (%d)\n", (animals.getclaws()) ? "Yes" : "No", animals.getclaws());
	printf("Do they have wool? %s (%d)\n", (animals.getwool()) ? "Yes" : "No", animals.getwool());
	cout << endl;

	// Create bird's class
	Birds birds;
	birds.SetBeak(true);
	birds.Setlegs(2);
	birds.setcolor('r');
	birds.setclaws(true);
	birds.setwool(false);
	cout << "\tBirds" << endl;
	cout << "Colour of Birds: " << birds.getwool() << endl;
	printf("Do they have claws? %s (%d)\n", (birds.getclaws()) ? "Yes" : "No", birds.getclaws());
	printf("Do they have wool? %s (%d)\n", (birds.getwool()) ? "Yes" : "No", birds.getwool());
	cout << "*Special Bird's parametres*" <<endl;
	printf("Do they have legs? %s. How many? (%d)\n", (birds.Getlegs()) ? "Yes" : "No", birds.Getlegs());
	printf("Do they have beak? %s (%d)\n", (birds.GetBeak()) ? "Yes" : "No", birds.GetBeak());
	cout << endl;

	// Create the goose
	Goose goose;
	goose.SetBeak(true);
	goose.Setlegs(2);
	goose.setcolor('w');
	goose.setclaws(false);
	goose.setwool(true);
	goose.Settail(true);
	cout << "\t**Goose**" << endl;
	cout << "Colour of Goose: " << goose.getcolor() << endl;
	printf("Does it have claws? %s (%d)\n", (goose.getclaws()) ? "Yes" : "No", goose.getclaws());
	printf("Does it have wool? %s (%d)\n", (goose.getwool()) ? "Yes" : "No", goose.getwool());
	cout << "*Special Goose's parametres*" << endl;
	printf("Does it have legs? %s. How many? (%d)\n", (goose.Getlegs()) ? "Yes" : "No", goose.Getlegs());
	printf("Does it have beak? %s (%d)\n", (goose.GetBeak()) ? "Yes" : "No", goose.GetBeak());
	printf("Does it have tail? %s (%d)\n", (goose.Gettail()) ? "Yes" : "No", goose.Gettail());
	cout << "The Goose's voice: "<< goose.Voise() << endl;

	// Create baby goose
	BabyGoose baby_goose;
	baby_goose.SetBeak(true);
	baby_goose.Setlegs(2);
	baby_goose.setcolor('y');
	baby_goose.setclaws(false);
	baby_goose.setwool(false);
	baby_goose.Settail(true);
	baby_goose.SetWeight(6);
	cout << "\t*Baby Goose*" << endl;
	cout << "Colour of Baby Goose: " << baby_goose.getcolor() << endl;
	printf("Does it have claws? %s (%d)\n", (baby_goose.getclaws()) ? "Yes" : "No", baby_goose.getclaws());
	printf("Does it have wool? %s (%d)\n", (baby_goose.getwool()) ? "Yes" : "No", baby_goose.getwool());
	cout << "*Special Baby Goose's parametres*" << endl;
	printf("Does it have legs? %s. How many? (%d)\n", (baby_goose.Getlegs()) ? "Yes" : "No", baby_goose.Getlegs());
	printf("Does it have beak? %s (%d)\n", (baby_goose.GetBeak()) ? "Yes" : "No", baby_goose.GetBeak());
	printf("Does it have tail? %s (%d)\n", (baby_goose.Gettail()) ? "Yes" : "No", baby_goose.Gettail());
	printf("Does it have weight? %s. Which? (%d kg)\n", (baby_goose.GetWeight()) ? "Yes" : "No", baby_goose.GetWeight());
	cout << "The Goose's voice: " << baby_goose.Voise() << " I'am baby goose!" << endl;
	cout << endl;

	// Create mammal's class
	mammals Mammals;
	Mammals.setclaws(true);
	Mammals.setcolor('b');
	Mammals.setwool(true);
	Mammals.Setlegs(2);
	Mammals.Setarms(false);
	Mammals.Settail(true);
	cout << "\tMammals" << endl;
	cout << "Colour of Mammals: " << Mammals.getcolor() << endl;
	printf("Do they have claws? %s (%d)\n", (Mammals.getclaws()) ? "Yes" : "No", Mammals.getclaws());
	printf("Do they have wool? %s (%d)\n", (Mammals.getwool()) ? "Yes" : "No", Mammals.getwool());
	cout << "*Special Mammals's parametres*" << endl;
	printf("Do they have legs? %s. How many? (%d)\n", (Mammals.Getlegs()) ? "Yes" : "No", Mammals.Getlegs());
	printf("Do they have tail? %s (%d)\n", (Mammals.Gettail()) ? "Yes" : "No", Mammals.Gettail());
	printf("Do they have arms? %s (%d)\n", (Mammals.Getarms()) ? "Yes" : "No", Mammals.Getarms());

	// Create a cheetah
	Cheetah cheetah;
	cheetah.setclaws(true);
	cheetah.Setarms(false);
	cheetah.setcolor('o');
	cheetah.Setlegs(2);
	cheetah.SetSpotted_skin(55);
	cheetah.setwool(true);
	cheetah.Settail(true);
	cout << "\t*Cheetah*" << endl;
	cout << "Colour of Cheetah: " << cheetah.getcolor() << endl;
	printf("Does it have claws? %s (%d)\n", (cheetah.getclaws()) ? "Yes" : "No", cheetah.getclaws());
	printf("Does it have wool? %s (%d)\n", (cheetah.getwool()) ? "Yes" : "No", cheetah.getwool());
	printf("Does it have legs? %s. How many? (%d)\n", (cheetah.Getlegs()) ? "Yes" : "No", cheetah.Getlegs());
	printf("Does it have tail? %s (%d)\n", (cheetah.Gettail()) ? "Yes" : "No", cheetah.Gettail());
	printf("Does it have arms? %s (%d)\n", (cheetah.Getarms()) ? "Yes" : "No", cheetah.Getarms());
	cout << "*Special Cheetah's parametres*" << endl;
	printf("Does it have spots? %s. How many? (%d)\n", (cheetah.GetSpotted_skin()) ? "Yes" : "No", cheetah.GetSpotted_skin());

	// Create a baby Cheetah
	BabyCheetah baby_cheetah;
	baby_cheetah.setclaws(true);
	baby_cheetah.Setarms(false);
	baby_cheetah.setcolor('o');
	baby_cheetah.Setlegs(2);
	baby_cheetah.SetSpotted_skin(30);
	baby_cheetah.setwool(false);
	baby_cheetah.Settail(true);
	baby_cheetah.SetHeight(0.5);
	cout << "\t*Baby Cheetah*" << endl;
	cout << "Colour of Baby Cheetah: " << baby_cheetah.getcolor() << endl;
	printf("Does it have claws? %s (%d)\n", (baby_cheetah.getclaws()) ? "Yes" : "No", baby_cheetah.getclaws());
	printf("Does it have wool? %s (%d)\n", (baby_cheetah.getwool()) ? "Yes" : "No", baby_cheetah.getwool());
	printf("Does it have legs? %s. How many? (%d)\n", (baby_cheetah.Getlegs()) ? "Yes" : "No", baby_cheetah.Getlegs());
	printf("Does it have tail? %s (%d)\n", (baby_cheetah.Gettail()) ? "Yes" : "No", baby_cheetah.Gettail());
	printf("Does it have arms? %s (%d)\n", (baby_cheetah.Getarms()) ? "Yes" : "No", baby_cheetah.Getarms());
	printf("Does it have spots? %s. How many? (%d)\n", (baby_cheetah.GetSpotted_skin()) ? "Yes" : "No", baby_cheetah.GetSpotted_skin());
	cout << "*Special Baby Cheetah's parametres*" << endl;
	printf("Does it have height? %s. Which? (%.1f m)\n", (baby_cheetah.GetHeight()) ? "Yes" : "No", baby_cheetah.GetHeight());
	cout << endl;

	// Create Fishes class
	Fishes fishes;
	fishes.setclaws(false);
	fishes.setcolor('g');
	fishes.setwool(false);
	fishes.SetFin(true);
	fishes.SetFish_scales(true);
	cout << "\tFishes" << endl;
	cout << "Colour of  Fishes: " << fishes.getcolor() << endl;
	printf("Do they have claws? %s (%d)\n", (fishes.getclaws()) ? "Yes" : "No", fishes.getclaws());
	printf("Do they have wool? %s (%d)\n", (fishes.getwool()) ? "Yes" : "No", fishes.getwool());
	cout << "*Special Fishes parametres*" << endl;
	printf("Do they have fin? %s (%d)\n", (fishes.GetFin()) ? "Yes" : "No");
	printf("Do they have scales? %s (%d)\n", (fishes.GetFish_scales()) ? "Yes" : "No");

	// Create the Shark
	Shark shark;
	shark.setclaws(false);
	shark.setcolor('g');
	shark.setwool(false);
	shark.SetFin(true);
	shark.SetFish_scales(false);
	shark.Setpredator(true);
	shark.SetAge(4);
	cout << "\t**Shark**" << endl;
	cout << "Colour of Shark: " << shark.getcolor() << endl;
	printf("Does it have claws? %s (%d)\n", (shark.getclaws()) ? "Yes" : "No", shark.getclaws());
	printf("Does it have wool? %s (%d)\n", (shark.getwool()) ? "Yes" : "No", shark.getwool());
	printf("Does it have fin? %s (%d)\n", (shark.GetFin()) ? "Yes" : "No", shark.GetFin());
	printf("Does it have scales? %s (%d)\n", (shark.GetFish_scales()) ? "Yes" : "No", shark.GetFish_scales());
	cout << "*Special Shark's parametres*" << endl;
	printf("Does it have predators? %s (%d)\n", (shark.Getpredator()) ? "Yes" : "No", shark.Getpredator());
	printf("How old is it? %d\n", shark.GetAge());

	// Create the baby Shark
	BabyShark baby_shark;
	baby_shark.setclaws(false);
	baby_shark.setcolor('g');
	baby_shark.setwool(false);
	baby_shark.SetFin(true);
	baby_shark.SetFish_scales(false);
	baby_shark.Setpredator(true);
	baby_shark.SetAge(4);
	baby_shark.SetLength(3);
	cout << "\t*Baby Shark*" << endl;
	cout << "Colour of Baby Shark: " << baby_shark.getcolor() << endl;
	printf("Does it have claws? %s (%d)\n", (baby_shark.getclaws()) ? "Yes" : "No", baby_shark.getclaws());
	printf("Does it have wool? %s (%d)\n", (baby_shark.getwool()) ? "Yes" : "No", baby_shark.getwool());
	printf("Does it have fin? %s (%d)\n", (baby_shark.GetFin()) ? "Yes" : "No", baby_shark.GetFin());
	printf("Does it have scales? %s (%d)\n", (baby_shark.GetFish_scales()) ? "Yes" : "No", baby_shark.GetFish_scales());
	printf("Does it have predators? %s (%d)\n", (baby_shark.Getpredator()) ? "Yes" : "No", baby_shark.Getpredator());
	printf("How old is it? %d\n", baby_shark.GetAge());
	cout << "*Special Shark's parametres*" << endl;
	printf("Does it have length? %s. Which? (%d m)\n", (baby_shark.GetLength()) ? "Yes" : "No", baby_shark.GetLength());

	return 0;
}