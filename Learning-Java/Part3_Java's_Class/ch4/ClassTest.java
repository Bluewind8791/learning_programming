package ch4;

import java.lang.reflect.Constructor;

public class ClassTest {
  public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException {
    
    Class c1 = Class.forName("ch04.Person");
    
    Person person = (Person)c1.newInstance();

    person.setName("Lee");
    System.out.println(person); // Lee

    Class c2 = person.getClass();
    Person p = (Person)c2.newInstance();
    System.out.println(p); // null

    // 동적
    Class[] parameterTypes = {String.class}
    Constructor cons = c2.getConstructor(parameterTypes);

    Object[] initargs = {"Kim"};
    Person kimPerson = (Person)cons.newInstance(initargs);
    System.out.println(kimPerson);

    // 자주 쓰는 방식
    Person kim2 = new Person("Kim");
  }
}
