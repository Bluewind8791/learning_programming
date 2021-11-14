package com.company.design;


// import java.util.concurrent.atomic.AtomicLong;

// import com.company.design.adapter.AirConditioner;
// import com.company.design.adapter.Cleaner;
// import com.company.design.adapter.HairDryer;
// import com.company.design.adapter.SocketAdapter;
import com.company.design.adapter.Electronic110V;
import com.company.design.facade.Ftp;
import com.company.design.facade.Reader;
import com.company.design.facade.SftpClient;
import com.company.design.facade.Writer;
import com.company.design.strategy.Base64Strategy;
// import com.company.design.aop.AopBrower;
// import com.company.design.decorator.A3;
// import com.company.design.decorator.A4;
// import com.company.design.decorator.A5;
// import com.company.design.decorator.Audi;
// import com.company.design.decorator.ICar;
// import com.company.design.observer.Button;
// import com.company.design.observer.IButtonListener;
// import com.company.design.singleton.AClazz;
// import com.company.design.singleton.BClazz;
// import com.company.design.singleton.SocketClient;
// import com.company.design.proxy.Brower;
// import com.company.design.proxy.BrowerProxy;
// import com.company.design.proxy.IBrowser;
import com.company.design.strategy.Encoder;
import com.company.design.strategy.EncodingStrategy;
import com.company.design.strategy.NormalStrategy;


public class Main {
    public static void main(String[] args) {
        /*
        //** Singleton Pattern Example **
        AClazz aClazz = new AClazz();
        BClazz bClazz = new BClazz();

        SocketClient aClient = aClazz.getSocketClient();
        SocketClient bClient = bClazz.getSocketClient();

        System.out.println("두개의 객체가 동일한가?");
        System.out.println(aClient.equals(bClient));
        */
        /*
        //** Adapter Pattern Example **
        HairDryer hairDryer = new HairDryer();
        connect(hairDryer);

        Cleaner cleaner = new Cleaner();
        // connect(cleaner); // 220v 여야하는데 110v라 오류 so, need adapter
        Electronic110V adapter = new SocketAdapter(cleaner);
        connect(adapter); // 어댑터 사용하여 연결 완료

        AirConditioner airConditioner = new AirConditioner();
        Electronic110V airAdapter = new SocketAdapter(airConditioner);
        connect(airAdapter);
        */
        /*
        //** Proxy Pattern example **
        Brower browser = new Brower("www.naver.com");
        browser.show();
        browser.show();
        browser.show();
        browser.show(); // 매번 보여줄때마다 url로부터 매번 호출해야함 이럴떄 캐쉬 기능 사용

        IBrowser cacheBrowser = new BrowerProxy("www.naver.com");
        cacheBrowser.show(); // Brower Proxy loading HTML from : www.naver.com
        cacheBrowser.show(); // Brower Proxy use CACHE! HTML : www.naver.com
        cacheBrowser.show();
        cacheBrowser.show();
        */
        /*
        // AOP: Aspect Oriented Programming (측면/양상 지향) : 여러군데서 사용되는 중복 코드 = aspect
        AtomicLong start = new AtomicLong(); // AtomicLong : Long 자료형을 갖고있는 Wrapping class
        AtomicLong end = new AtomicLong();   // thread-safe로 구현, 동시성 보장

        IBrowser aopBrowser = new AopBrower("www.naver.com",
        () -> {
            System.out.println("Before.");
            start.set(System.currentTimeMillis());
        },
        () -> {
            long now = System.currentTimeMillis();
            end.set(now - start.get());
        });

        aopBrowser.show();                // AtomicLong 값 읽기
        System.out.println("Loading time : " + end.get()); // loading time 1.5 sec
        aopBrowser.show();
        System.out.println("Loading time : " + end.get()); // using cahce: loading time 0 sec
        */

        /*
        //** Decorator Pattern Example **
        ICar audi = new Audi(1000);
        audi.showPrice();

        // a3
        ICar audi3 = new A3(audi, "A3");
        audi3.showPrice();
        // a4
        ICar audi4 = new A4(audi, "A4");
        audi4.showPrice();
        // a5
        ICar audi5 = new A5(audi, "A5");
        audi5.showPrice();*/

        /*
        //** Observer Pattern Example **
        Button button = new Button("BUTTON");

        button.addListener(new IButtonListener() {
            @Override
            public void clickEvent(String event) {
                System.out.println(event);
            }
        });

        button.click("Send message : click 1");
        button.click("Send message : click 2");
        button.click("Send message : click 3");
        button.click("Send message : click 4");*/

        /*
        //** Facade Pattern Example **
        // before facade pattern
        Ftp ftpClient = new Ftp("www.naver.com", 22, "/home/etc");
        ftpClient.connect();
        ftpClient.moveDirectory();
        // writing
        Writer writer = new Writer("test.txt");
        writer.fileConnect();
        writer.fileWrite();
        // reading
        Reader reader = new Reader("test.txt");
        reader.fileConnect();
        reader.fileRead();
        // disconnecting
        reader.fileDisconnect();
        writer.fileDisconnect();
        ftpClient.disconnect();

        // after facade pattern
        SftpClient sftpClient = new SftpClient("www.foo.co.kr", 22, "/home/etc", "test.txt");
        sftpClient.connect();
        sftpClient.write();
        sftpClient.read();
        sftpClient.disconnect();*/


        //** Strategy Pattern Example ** */

        Encoder encoder = new Encoder();

        // base 64 strategy
        EncodingStrategy base64 = new Base64Strategy();

        // normal
        EncodingStrategy normal = new NormalStrategy();

        String message = "Hello Java";
        encoder.setEncodingStrategy(base64);
        String base64Result = encoder.getMessage(message);

    }

    // 110v 콘센트만 있음 (Adapter Example)
    public static void connect(Electronic110V electronic110v) {
        electronic110v.powerOn();
    }


}
