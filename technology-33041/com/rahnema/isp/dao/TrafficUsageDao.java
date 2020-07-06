package com.rahnema.isp.dao;

import java.util.List;

import com.rahnema.isp.domain.TrafficUsage;

public interface TrafficUsageDao {
	public List<TrafficUsage> loadAll();
}
