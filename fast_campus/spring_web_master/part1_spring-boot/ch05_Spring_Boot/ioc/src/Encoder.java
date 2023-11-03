package ioc.src;


public class Encoder {
    
    private IEncoder iEncoder;

    // apply DI
    public Encoder(IEncoder iEncoder) {
        this.iEncoder = iEncoder;

    }

    public String encode(String message) {
        return iEncoder.encode(message);
    }
}
