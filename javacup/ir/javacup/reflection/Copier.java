package ir.javacup.reflection;


import java.lang.reflect.Field;
import java.lang.reflect.Method;

public class Copier {
    String[] names;

    public Copier(String... names) {
    	this.names = names;
    }

    public void copy(Object o1, Object o2) {
		if (names != null && names.length != 0) {
			for(String fieldName : names) {
				try {
					Field f = o1.getClass().getDeclaredField(fieldName);
					Field t = o2.getClass().getDeclaredField(fieldName);
					f.setAccessible(true);
					t.setAccessible(true);
					t.set(t, f);
//					Method i = o1.getClass().getMethod("get" + fieldName.substring(0, 1).toUpperCase() + fieldName.substring(1));
//					Method j = o2.getClass().getMethod("set" + fieldName.substring(0, 1).toUpperCase() + fieldName.substring(1), ia.getType());
//					j.invoke(i.invoke(null));
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		}
    }

	public static void main(String[] args) {
		Copier copier = new Copier("name", "age");
		item a = new item("shalgham", "paskmaki");
		item b = new item();
		copier.copy(a, b);
		System.out.println(b);
	}

	static class item {
    	String name;
    	String age;

		public item() {
		}

		public item(String name, String age) {
			this.name = name;
			this.age = age;
		}

		public String getName() {
			return name;
		}

		public void setName(String name) {
			this.name = name;
		}

		public String getAge() {
			return age;
		}

		public void setAge(String age) {
			this.age = age;
		}

		@Override
		public String toString() {
			return "item{" +
					"name='" + name + '\'' +
					", age='" + age + '\'' +
					'}';
		}
	}
}
