package ir.nimbo;

import java.time.Instant;
import java.time.ZonedDateTime;
import java.util.Date;
import java.util.HashSet;
import java.util.Set;

public class PrescriptionService {
    private LocationService locationService;
    private Set<Pharmacy> pharmacies;
    private DrugRepository drugRepository = DrugRepository.getInstance();

    public PrescriptionService(LocationService locationService, Set<Pharmacy> pharmacies) {
        this.locationService = locationService;
        this.pharmacies = pharmacies;
    }

    public Pharmacy primaryRegisteration(Prescription prescription) {
        Instant dbInstant = prescription.getDate().toInstant();
        Instant aMonthAgo = ZonedDateTime.now().minusDays(30).toInstant();

        if (!dbInstant.isAfter(aMonthAgo)) {
            throw new RuntimeException("Prescription is expired.");
        }

        Pharmacy bestPH = null;
        double min = Double.MAX_VALUE;

        for (Pharmacy pharmacy : pharmacies) {
            int drugCount = 0;
            for (PrescriptionItem item : prescription.getItems()) {
                if (pharmacy.getDrugInventory(item.getName()) >= item.getNumber()) {
                    ++drugCount;
                }
            }
            if (drugCount == prescription.getItems().size()) {
                if (bestPH == null) {
                    bestPH = pharmacy;
                }
                double tmp = locationService.distance(pharmacy.getLocation(), prescription.getLocation());
                if (tmp < min) {
                    bestPH = pharmacy;
                    min = tmp;
                }
            }
        }

        if (bestPH == null) {
            throw new RuntimeException("No Pharmacy Found. Try Later...");
        } else {
            return bestPH;
        }
    }

    public int finalRegisteration(Prescription prescription, Pharmacy pharmacy) {
        int cost = 0;
        for (PrescriptionItem item : prescription.getItems()) {
            if (pharmacy.getDrugInventory(item.getName()) >= item.getNumber()) {
                cost += pharmacy.consume(item.getName(), item.getNumber());
            }
        }

        return cost;
    }
}
