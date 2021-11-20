package ch08;

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
    
    AnimalTest test = new AnimalTest();
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

    test.testDownCasting(animalList);
  }


  public void testDownCasting(ArrayList<Animal> list) {
    
    for (int i=0; i<list.size(); i++) {
      Animal animal = list.get(i);
      
      if (animal instanceof Human) {
        Human human = (Human) animal;
        human.read();
      }
      else if (animal instanceof Tiger) {
        Tiger tiger = (Tiger)animal;
        tiger.hunting();
      }
      else if (animal instanceof Eagle) {
        Eagle eagle = (Eagle) animal;
        eagle.flying();
      }
    }
  }



  public void moveAnimal(Animal animal) {
    animal.move();
  }
}
