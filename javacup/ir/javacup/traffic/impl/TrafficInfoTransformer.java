package ir.javacup.traffic.impl;

import ir.javacup.traffic.Transformer;

import java.util.Base64;

public class TrafficInfoTransformer implements Transformer<TrafficInfo, String> {
    @Override
    public TrafficInfo transform(String input) {
        Base64.Decoder decoder = Base64.getDecoder();
        try {
            String[] res = new String(decoder.decode(input)).split(",");
            TrafficInfo r = new TrafficInfo();
            r.setLocationCode(res[0]);
            r.setTrafficLevel(Integer.parseInt(res[1]));
            return r;
        } catch (Exception e) {
            throw new IllegalArgumentException();
        }
    }
}
