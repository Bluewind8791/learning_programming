package ch17;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

//                     직렬화 가능하다.
class Person implements Serializable {
  String name;
  String job;

  public Person() {}

  public Person(String name, String job) {
    this.name = name;
    this.job = job;
  }

  @Override
  public String toString() {
    return name + " ," + job;
  }
}


public class SerializationTest {
  
  public static void main(String[] args) {
    
    Person personLee = new Person("Lee", "CEO");
    Person personKim = new Person("Kim", "KEO");
    
    // writing
    try (FileOutputStream fos = new FileOutputStream("serial.txt");
    ObjectOutputStream oos = new ObjectOutputStream(fos)) {

      oos.writeObject(personLee);
      oos.writeObject(personKim);

    } catch (IOException e) {
      System.out.println(e);
    }


    // reading
    try (FileInputStream fis = new FileInputStream("serial.txt");
    ObjectInputStream ois = new ObjectInputStream(fis)) {

      Person pLee;
      try {
        pLee = (Person)ois.readObject();
        System.out.println(pLee);
      } catch (ClassNotFoundException e) {
        e.printStackTrace();
      }
      
      Person pKim;
      try {
        pKim = (Person)ois.readObject();
        System.out.println(pKim);
      } catch (ClassNotFoundException e) {
        e.printStackTrace();
      }

      // System.out.println(pLee);
      // System.out.println(pKim);
      
    } catch (IOException e) {
      System.out.println(e);
    }



  }
}
