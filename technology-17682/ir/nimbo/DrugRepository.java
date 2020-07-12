package ir.nimbo;

import java.util.*;

public class DrugRepository {
    private static final DrugRepository single_instance = new DrugRepository();

    private final Set<Drug> drugs = new HashSet<>();

    private DrugRepository() {
    }

    public static DrugRepository getInstance() {
        return single_instance;
    }

    public Set<Drug> getDrugs() {
        return drugs;
    }

    public void addDrug(Drug drug) {
        boolean flag = true;
        for (Drug drugg : drugs) {
            if (drugg.name.equals(drug.name))
                flag = false;
        }
        if (flag) {
            drugs.add(drug);
        }
    }

    public Drug findDrugByExactName(String name) {
        for (Drug drug : drugs) {
            if (drug.getName().equals(name)) {
                return drug;
            }
        }
        return null;
    }

    public List<String> search(String query) {
        //TODO
        List<String> list = new ArrayList<String>();
		
		/*for (Drug drug : drugs) {
			boolean flag = true;
			String temp="";
			StringTokenizer mytoken = new StringTokenizer(query, "%");
			while (mytoken.hasMoreTokens())
			{
				temp= mytoken.nextToken();
				if(drug.getName().contains(temp)==false)
				{
					flag=false;
					break;
				}
			}
			if (flag)
			{
				list.add(drug.getName());
			}
		}
		*/
        String temp = "";
        StringTokenizer mytoken = new StringTokenizer(query, "%");
        while (mytoken.hasMoreTokens()) {
            temp = mytoken.nextToken();
            for (Drug drug : drugs) {
                if (drug.getName().toLowerCase().contains(temp.toLowerCase())) {
                    list.add(drug.name);
                } else {
                    list.remove(drug.name);
                }
            }

        }

        return list;

    }

}
