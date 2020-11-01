package ir.javacup.exam;

import javafx.util.Pair;

import java.util.ArrayList;
import java.util.Comparator;

public class Examiner {
    public int solve(Question test) {
        double res;
        QuestionData questionData = test.getData();
        if (questionData.destination == null) {
            res = questionData.source.criticalAngle();
        } else {
            res = questionData.source.criticalAngle(questionData.destination);
        }

        ArrayList<Pair<Double, Integer>> opt = new ArrayList<>();
        for (Option i : test.getOptions()) {
            opt.add(new Pair<>(Math.abs(Double.parseDouble(i.getValue()) - res), i.getId()));
        }

        opt.sort(Comparator.comparing(Pair::getKey));

        return opt.get(0).getValue();
    }
}
