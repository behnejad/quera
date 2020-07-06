public class SpamDetector {

    public SpamType[] detectSpams(Message[] messages) {
		if (messages == null) {
			return null;
		}
		if (messages.length == 0) {
			return new SpamType[0];
		}
        SpamType[] res = new SpamType[messages.length];

        for (int i = 0; i < messages.length; ++i) {
            boolean sender = false;
            boolean content = false;
            boolean has_spam = false;
            boolean has_invalid = false;

            int sender_number_count = 0;
            String send = messages[i].getSenderId();

            for (int j = 0; j < send.length(); ++j) {
                if (send.charAt(j) >= '0' && send.charAt(j) <= '9') {
                    ++sender_number_count;
                }
            }

            if (sender_number_count == send.length()) {
                sender = true;
            }

            send = messages[i].getContent();
            has_spam = send.contains("spam");

            sender_number_count = 0;
            for (int j = 0; j < send.length(); ++j) {
                if ((send.charAt(j) >= '0' && send.charAt(j) <= '9') ||
                        (send.charAt(j) >= 'a' && send.charAt(j) <= 'z') ||
                        (send.charAt(j) >= 'A' && send.charAt(j) <= 'Z') ||
                        send.charAt(j) == ' ' || send.charAt(j) == '\t') {
                } else {
                    ++sender_number_count;
                }
            }

            if (sender_number_count > (send.length() / 2)) {
                has_invalid = true;
            }

            content = has_spam && has_invalid;

            if (sender) {
                if (content) {
                    res[i] = SpamType.FULLY_INVALID;
                } else {
                    res[i] = SpamType.INVALID_SENDER;
                }
            } else {
                if (content) {
                    res[i] = SpamType.INVALID_CONTENT;
                } else {
                    res[i] = SpamType.NOT_SPAM;
                }
            }
        }

        return res;
    }
}