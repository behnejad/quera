package ir.javacup.onlinetaxi;

public class TripHandler {
    private static final TripHandler instange = new TripHandler();

    private TripHandler() {

    }

    public static TripHandler getInstance() {
        return instange;
    }

    public int calcPrice(String type, TripParam params) {
        if (type.equals("bike")) {
            return new BikeTripMethod().calcPrice(params);
        } else if (type.equals("economic")) {
            return new EconomicTripMethod().calcPrice(params);
        } else if (type.equals("vip")) {
            return new VIPTripMethod().calcPrice(params);
        } else {
        	return 0;
		}
    }

    public static void main(String[] args) {
        TripHandler taxi = TripHandler.getInstance();

//سفر ویژه از ناحیه 1 به 1 در ساعت اوج ترافیک و هوای غیربارانی
        int price = taxi.calcPrice("vip", new TripParam(1, 1, true, false));
        int price2 = new VIPTripMethod().calcPrice(new TripParam(1, 1, true, false));
        System.out.println(price + " = " + price2);

//سفر با موتور از ناحیه 2 به 4 در ساعت اوج ترافیک و در هوای بارانی
        price = taxi.calcPrice("bike", new TripParam(2, 4, true, true));
        price2 = new BikeTripMethod().calcPrice(new TripParam(2, 4, true, true));
        System.out.println(price + " = " + price2);
    }

}
