package ch07;

// <T> Generic type가 Material를 상속받음으로써 T 자료형의 범위를 제한함.
public class GenericPrinter<T extends Material> {
  
  private T material;

  public T getMaterial() {
    return material;
  }
  public void setMaterial(T material) {
    this.material = material;
  }
  @Override
  public String toString() {
    return material.toString();
  }

}
