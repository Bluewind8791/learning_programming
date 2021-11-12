package com.company.design;


// import com.company.design.adapter.AirConditioner;
// import com.company.design.adapter.Cleaner;
// import com.company.design.adapter.HairDryer;
// import com.company.design.adapter.SocketAdapter;
import com.company.design.adapter.Electronic110V;
// import com.company.design.singleton.AClazz;
// import com.company.design.singleton.BClazz;
// import com.company.design.singleton.SocketClient;
import com.company.design.proxy.Brower;
import com.company.design.proxy.BrowerProxy;
import com.company.design.proxy.IBrowser;


public class Main {
    public static void main(String[] args) {
        
        /*
        // Singleton Example
        AClazz aClazz = new AClazz();
        BClazz bClazz = new BClazz();

        SocketClient aClient = aClazz.getSocketClient();
        SocketClient bClient = bClazz.getSocketClient();

        System.out.println("두개의 객체가 동일한가?");
        System.out.println(aClient.equals(bClient));
        */

        /*
        // Adapter Example
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

        // Proxy example
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

    }

    // 110v 콘센트만 있음
    public static void connect(Electronic110V electronic110v) {
        electronic110v.powerOn();
    }


}
