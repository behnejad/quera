package ir.javacup.convention;


public class CodeConventionUtil {
	
	public String getFieldsName(String... params){
		String s = params[0].toLowerCase();
		for (int i = 1; i < params.length; ++i) {
			s += params[i].substring(0, 1).toUpperCase() + params[i].toLowerCase().substring(1);
		}
		return s;
	}
	
	public String getMethodsName(String... params){
		return getFieldsName(params);
	}
	
	public String getClassName(String... params){
		String s = "";
		for (int i = 0; i < params.length; ++i) {
			s += params[i].substring(0, 1).toUpperCase() + params[i].substring(1).toLowerCase();
		}
		return s;
	}
	
	public String getConstantsName(String... params){
		if (params.length == 1) {
			return params[0].toUpperCase();
		} else {
			String s = "";
			for (int i = 0; i < params.length - 1; ++i) {
				s += params[i].toUpperCase() + "_";
			}
			s += params[params.length - 1].toUpperCase();
			return s;
		}
	}

}
