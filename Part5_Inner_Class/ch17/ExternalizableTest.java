package ch17;

import java.io.Externalizable;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInput;
import java.io.ObjectInputStream;
import java.io.ObjectOutput;
import java.io.ObjectOutputStream;

//                       직렬화 직접 구현
class EPerson implements Externalizable {
  String name;
  String job;

  public EPerson() {}

  public EPerson(String name, String job) {
    this.name = name;
    this.job = job;
  }

  @Override
  public String toString() {
    return name + " ," + job;
  }

  @Override
  public void readExternal(ObjectInput in) throws IOException, ClassNotFoundException {
    
    name = in.readUTF();
    job = in.readUTF();
  }

  @Override
  public void writeExternal(ObjectOutput out) throws IOException {

    out.writeUTF(name);
    out.writeUTF(job);
  }
}


public class ExternalizableTest {
  
  public static void main(String[] args) {
    
    EPerson personLee = new EPerson("Lee", "CEO");
    EPerson personKim = new EPerson("Kim", "KEO");
    
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

      EPerson pLee;
      try {
        pLee = (EPerson)ois.readObject();
        System.out.println(pLee);
      } catch (ClassNotFoundException e) {
        e.printStackTrace();
      }
      
      EPerson pKim;
      try {
        pKim = (EPerson)ois.readObject();
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
