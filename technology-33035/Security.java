public class Security {
    public String truename;

    public String encrypt(String info) {
        String res = "";
        if (info.length() == 0) {
            return res;
        }
        char base = info.charAt(0);
        int count = 0;

        for (int i = 0; i < info.length(); ++i) {
            if (info.charAt(i) == base) {
                ++count;
            } else {
                int c = base - 96;
                for (int j = 0; j < count; ++j) {
                    res += c;
                    c += (base - 96);
                }
                base = info.charAt(i);
                count = 1;
            }
        }

        int c = base - 96;
        for (int j = 0; j < count; ++j) {
            res += c;
            c += (base - 96);
        }

        return res;
    }

    public boolean isSocialAccountInfo(String param) {
        int i = param.indexOf(":");
        if (i == -1 || i == 0) {
            return false;
        }
        String social = param.substring(0, i);
        if (Character.isLowerCase(social.charAt(0))) {
            return false;
        }
        int j = param.indexOf("/", i + 1);
        if (j == -1) {
            return false;
        }
        String url = param.substring(i + 1, j);
        if (url.length() <= 4 || !url.startsWith("www.")) {
            return false;
        }
        for (int p = 4; p < url.length(); ++p) {
            if (Character.isLowerCase(url.charAt(p))) {
                continue;
            } else if (url.charAt(p) == '.') {
                continue;
            } else if (url.charAt(p) >= '0' || url.charAt(p) <= '9') {
                continue;
            } else {
                return false;
            }
        }
        String name = param.substring(j + 1);
        if (name.length() == 0) {
            return false;
        }
        for (int p = 0; p < name.length(); ++p) {
            if (name.charAt(p) != '_' && !Character.isAlphabetic(name.charAt(p)) && (url.charAt(p) < '0' || url.charAt(p) > '9')) {
                return false;
            }
        }
        this.truename = name;
        return true;
    }

    public String secure(String s) {
        if (s == null) {
            return null;
        }
        if (s.length() == 0) {
            return "";
        }
        String a[] = s.split(" ");
        String res = "";
        for (String i : a) {
            if (isSocialAccountInfo(i)) {
                res += i.replaceFirst(truename, encrypt(truename));
            } else {
                res += i;
            }
            res += " ";
        }
        return res.substring(0, res.length() - 1);
    }

    public static void main(String[] args) {
        Security s = new Security();
        System.out.println(s.encrypt(""));
        System.out.println(s.secure("FirstName:Ali, LastName:Alavi, BirthDate:1990/02/02 Gender:male Instagram:www.instagram.com/aalavi Degree:Master Twitter:www.twiter.com/alaviii imdb:www.imdb.com/alavi"));
    }
}
