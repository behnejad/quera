package com.rahnema.isp.domain;

public class TrafficUsage {

	private User user;
	private boolean internal;
	private boolean nightly;
	private int usage;
	private String date;
	
	public TrafficUsage(User user, boolean internal, boolean nightly, int usage, String date) {
		this.user = user;
		this.internal = internal;
		this.nightly = nightly;
		this.usage = usage;
		this.date = date;
	}

	public User getUser() {
		return user;
	}
	public void setUser(User user) {
		this.user = user;
	}
	public boolean isInternal() {
		return internal;
	}
	public void setInternal(boolean internal) {
		this.internal = internal;
	}
	public boolean isNightly() {
		return nightly;
	}
	public void setNightly(boolean nightly) {
		this.nightly = nightly;
	}
	public int getUsage() {
		return usage;
	}
	public void setUsage(int usage) {
		this.usage = usage;
	}
	public String getDate() {
		return date;
	}
	public void setDate(String date) {
		this.date = date;
	}
	
	
}
