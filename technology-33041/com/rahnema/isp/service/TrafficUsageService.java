package com.rahnema.isp.service;

import java.util.List;

import com.rahnema.isp.domain.User;

public interface TrafficUsageService {

	public List<User> socialMediaLovers(int year, int month);

	public List<User> downloadLovers(int year, int month);
}
