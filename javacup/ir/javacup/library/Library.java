package ir.javacup.library;

public class Library {

    private Member[] members;
    private final int capacity;
    private IdGenerator idGenerator;

    public Library(int capacity, IdGenerator idGenerator) {
        this.capacity = capacity;
        this.members = new Member[capacity];
        this.idGenerator = idGenerator;
    }

    public void register(Member member) throws LibraryFullException {
        if (member == null) {
        	throw new IllegalArgumentException("member is null");
        }
        if (member.getFirstName() == null) {
            throw new IllegalArgumentException("member.firstName is null");
        }
        if (member.getLastName() == null) {
            throw new IllegalArgumentException("member.lastName is null");
        }
        for (int i = 0; i < members.length; ++i) {
            if (members[i] == null) {
                member.setId(idGenerator.generate());
                members[i] = member;
                return;
            }
        }
        throw new LibraryFullException("Library is full");
    }

    public Member unregister(int id) {
        Member t;
        for (int i = 0; i < members.length; ++i) {
            if (members[i] != null && members[i].getId() == id) {
                t = members[i];
                members[i] = null;
                return t;
            }
        }
        throw new MemberNotFoundException("No member found with the given id");
    }

    public int getMemberCount() {
        int c = 0;
        for (Member member : members) {
            if (member != null) {
                ++c;
            }
        }
        return c;
    }

    public boolean isFull() {
        for (Member member : members) {
            if (member == null) {
                return false;
            }
        }
        return true;
    }

    public Member[] getMembers() {
        return members;
    }

    public int getCapacity() {
        return capacity;
    }

}
