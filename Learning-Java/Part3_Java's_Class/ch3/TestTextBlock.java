package ch3;

public class TestTextBlock {
  public static void main(String[] args) {
    
    String textBlocks = """
      Hello,
      hi,
      안녕하세요,
      Gonnijiwa""";

    System.out.println(textBlocks);
    System.out.println(GetBlockOfHtml());
  }

  public static String GetBlockOfHtml() {
    return """
      <html>

        <body>
          <span>example text</span>
        </body>
      </html>""";
  }

}
