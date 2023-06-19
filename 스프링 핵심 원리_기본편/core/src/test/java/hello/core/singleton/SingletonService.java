package hello.core.singleton;

public class SingletonService {

    // 자기자신을 내부에 private static으로 가지고 있음. -> 한개만 생성
    private static final SingletonService instance = new SingletonService();

    public static SingletonService getInstance() {
        return instance;
    }

    // new 로 객체 생성 private으로 막아버림
    private SingletonService() {}

    public void logic() {
        System.out.println("싱글톤 객체 로직 호출");
    }
}
