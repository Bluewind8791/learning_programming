package ch06;

public class MazeTest {
  
  public static void main(String[] args) {
    
    Robot robot;
    System.out.println("Exit : (7.7)");

    robot = new Robot();

    robot.findPath(0, 0, 7, 7);
    robot.showPath();
  }
}
