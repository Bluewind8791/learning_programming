package ch06_Generic;

// <T> Generic type
// 나중에 클래스를 가져다가 쓸때 실질적으로 사용할 자료형을 <> 안에 집어넣음
public class GenericPrinter<T> {
  
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
