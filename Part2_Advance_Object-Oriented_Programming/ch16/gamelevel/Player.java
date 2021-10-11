package ch16.gamelevel;

public class Player {
  
  PlayerLevel lv;

  public Player() {
    lv = new BeginnerLevel();
    lv.showLevelMessage();
  }

  public PlayerLevel getLevel() {
    return lv;
  }

  public void upgradeLevel(PlayerLevel level) {
    this.lv = level;
    lv.showLevelMessage();
  }

  public void play(int count) {
    lv.go(count);
  }

}
