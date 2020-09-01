package ir.javacup.dq;

import java.util.Collections;
import java.util.Deque;
import java.util.LinkedList;

public class DequeUtilImpl<T> implements DequeUtil<T> {
	private Deque<T> deque = new LinkedList<>();

	@Override
	public Deque<T> getDeque() {
		return deque;
	}

	@Override
	public T get(int index) {
		if (deque.size() > index && index >= 0) {
			return (T) ((LinkedList) deque).get(index);
		}
		throw new IllegalArgumentException("index should be between 0 and size-1");
	}

	@Override
	public boolean push(T element, int index) {
		if (deque.size() > index && index >= 0) {
			((LinkedList) deque).add(index, element);
			return true;
		}
		return false;
	}

	@Override
	public boolean replace(T element, int index) {
		if (deque.size() > index && index >= 0) {
			((LinkedList) deque).remove(index);
			((LinkedList) deque).add(index, element);
			return true;
		}
		return false;
	}

	@Override
	public boolean reverse(int first, int second) {
		if (deque.size() > second && second >= 0 &&
				deque.size() > first && first >= 0 &&
				first <= second) {
			if (first != second) {
				if (second - first == 1) {
					((LinkedList) deque).add(second, ((LinkedList) deque).remove(first));
				} else if ((second - first + 1) % 2 == 0) {
					for (int i = 0; i < (second - first + 1) / 2; ++i) {
						Object a, b;
						a = ((LinkedList) deque).remove(first + i);
						b = ((LinkedList) deque).remove(second - i - 1);
						((LinkedList) deque).add(first + i, b);
						((LinkedList) deque).add(second - i, a);
					}
				} else {
					for (int i = 0; i < (second - first + 1) / 2; ++i) {
						Object a, b;
						a = ((LinkedList) deque).remove(first + i);
						b = ((LinkedList) deque).remove(second - i - 1);
						((LinkedList) deque).add(first + i, b);
						((LinkedList) deque).add(second - i, a);
					}
				}
			}
			return true;
		}
		return false;
	}

	public static void main(String[] args) {
		DequeUtilImpl<Integer> dequeImpl = new DequeUtilImpl<>();
		for(int i=0; i<6; i++)
			dequeImpl.getDeque().push(i);
		for (Integer i : dequeImpl.deque) {
			System.out.print(i);
			System.out.print(" ");
		}
		System.out.println();
		dequeImpl.reverse(1, 3);
		for (Integer i : dequeImpl.deque) {
			System.out.print(i);
			System.out.print(" ");
		}
	}
}