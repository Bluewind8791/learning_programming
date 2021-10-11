package ch06;

import java.util.ArrayList;

class Animal {

  public void move() {
    System.out.println("Animal is moving");
  }
}


class Human extends Animal {
  @Override
  public void move() {
    System.out.println("Human is walking by two foot.");
  }
  
  public void read() {
    System.out.println("Human read book.");
  }
}

class Tiger extends Animal {
  @Override
  public void move() {
    System.out.println("Tiger is running.");
  }
  public void hunting() {
    System.out.println("Human is hunting small animal.");
  }
}


class Eagle extends Animal {
  @Override
  public void move() {
    System.out.println("Eagle is flying.");
  }

  public void flying() {
    System.out.println("Eagle is flying by two wings.");
  }
}


public class AnimalTest {
  public static void main(String[] args) {
    
    Animal hAnimal = new Human();
    Animal tAnimal = new Tiger();
    Animal eAnimal = new Eagle();
    
    // AnimalTest test = new AnimalTest();
    // test.moveAnimal(hAnimal);
    // test.moveAnimal(tAnimal);
    // test.moveAnimal(eAnimal);

    ArrayList<Animal> animalList = new ArrayList<>();
    animalList.add(hAnimal);
    animalList.add(tAnimal);
    animalList.add(eAnimal);

    for (Animal animal : animalList) {
      animal.move();
    }
  }

  // public void moveAnimal(Animal animal) {
  //   animal.move();
  // }
}
