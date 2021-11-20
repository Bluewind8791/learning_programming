package ch16.gamelevel;

public abstract class PlayerLevel {

  public abstract void run();
  public abstract void jump();
  public abstract void turn();
  public abstract void showLevelMessage();

  // 정답에선 final 붙임
  public void go(int count) {
    run();
    for (int i=0; i<count; i++) {
      jump();
    }
    turn();
  }

}
