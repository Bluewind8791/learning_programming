package ioc.src;


public class App {
    public static void main(String[] args) throws Exception {
        
        String url = "www.naver.com/books/it?page=10&size=20&anme=spring-boot";

        /*
        // base 64 encoding
        Base64Encoder encoder = new Base64Encoder();
        String result = encoder.encode(url);
        System.out.println(result);

        // url encoding
        UrlEncoder urlEncoder = new UrlEncoder();
        String urlResult = urlEncoder.encode(url);
        System.out.println(urlResult);*/

        /*
        // ** IEncoder interface 구현
        // base 64 encoding
        IEncoder encoder = new Base64Encoder();
        String result = encoder.encode(url);
        System.out.println(result);

        // url encoding
        IEncoder urlEncoder = new UrlEncoder();
        String urlResult = urlEncoder.encode(url);
        System.out.println(urlResult);*/


        // ** DI 구현을 위하여 추상화
        Encoder encoder64 = new Encoder(new Base64Encoder());
        Encoder encoderUrl = new Encoder(new UrlEncoder());
        
        String result2 = encoder64.encode(url);
        System.out.println(result2);
        String urlResult = encoderUrl.encode(url);
        System.out.println(urlResult);

    }
}
